#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "types.h"
#include "node.h"
#include "tree.h"
#include "y.tab.h"

/* constructors */
tree_t *make_tree(int type, int effective_type, tree_t *left, tree_t *right)
{
	tree_t *p = (tree_t *)malloc(sizeof(tree_t));
	assert(p != NULL);

	p->type = type;
	p->effective_type = effective_type;
	p->left = left;
	p->right = right;

	//fprintf(stderr, " (CURR: %d, LEFT: %d) ", effective_type, left->effective_type);
	if ( effective_type != LINK ){	
		if ( left != NULL ){ // TODO: bools cannot be used except relational
			if ( effective_type == BOOL && right != NULL && 
			     left->effective_type == right->effective_type ){
				// do nothing (this is an exception)
			} else if ( effective_type == LOOP  || effective_type == IF){
				// do nothing (this is an exception)	
			} else if ( left->effective_type != effective_type ){ 
				char* msg;
				asprintf(&msg, "Objects of different types appear in the same expression: %d and %d", 
				         left->effective_type, effective_type);
				semError(msg);
			} else if ( left->effective_type == -1 ){ // This should never happen
				semError("Procedures don't return values");
			}
		}
	
		if ( right != NULL ){
			if ( effective_type == BOOL && left != NULL &&
			     left->effective_type == right->effective_type ){
				// do nothing (this is an exception)
			} else if ( type == NOT && right->effective_type == BOOL ){
				// do nothing (this is an exception)
			} else if ( effective_type == LOOP  || effective_type == IF ){
				// do nothing (this is an exception)
			} else if (	right->effective_type != effective_type ){ 
				char* msg;
				asprintf(&msg, "Objects of different types appear in the same expression: %d and %d", 
				         right->effective_type, effective_type);
				semError(msg);
			} else if ( right->effective_type == -1 ){
				semError("Procedures don't return values");
			}
		}
	}

	return p;
}

tree_t *make_op(int type, int attribute, tree_t *left, tree_t *right)
{
	tree_t *p;
	if ( type == RELOP  || type == NOT){
		p = make_tree(type, BOOL, left, right);	
	} else if ( right == NULL ){
		p = make_tree(type, left->effective_type, left, right);
	} else {
		p = make_tree(type, right->effective_type, left, right);
	}
	p->attribute.opval = attribute;
	return p;
}

tree_t *make_inum(int val)
{
	tree_t *p = make_tree(INUM, INUM, NULL, NULL);
	p->attribute.ival = val;
	return p;
}

tree_t *make_rnum(float val)
{
	tree_t *p = make_tree(RNUM, RNUM, NULL, NULL);
	p->attribute.rval = val;
	return p;
}

tree_t *make_bool(int val)
{
	tree_t *p = make_tree(BOOL, BOOL, NULL, NULL);
	p->attribute.ival = val;
	return p;
}

tree_t *make_id(node_t *node)
{
	tree_t *p = make_tree(ID, node->effective_type, NULL, NULL);
	p->attribute.sval = node;
	return p;
}

tree_t *make_func(node_t *node)
{
	tree_t *p = make_tree(FUNCTION, node->effective_type, NULL, NULL);
	p->attribute.sval = node;
	return p;
}

tree_t *make_proc(node_t *node)
{
	tree_t *p = make_tree(PROCEDURE, node->effective_type, NULL, NULL);
	p->attribute.sval = node;
	return p;
}

tree_t *make_loop(int type, tree_t *left, tree_t *right)
{
	tree_t *p = make_tree(type, LOOP, left, right);	
	p->attribute.noval = NULL;
	return p;
}

tree_t *make_if(int type, tree_t *left, tree_t *right)
{
	tree_t *p = make_tree(IF, IF, left, right);	
	p->attribute.noval = NULL;
	return p;
}

tree_t *make_else(int type, tree_t *left, tree_t *right)
{
	tree_t *p = make_tree(THENELSE, IF, left, right);	
	p->attribute.noval = NULL;
	return p;
}

tree_t *make_link(int type, tree_t *left, tree_t *right)
{
	tree_t *p = make_tree(LINK, LINK, left, right);	
	p->attribute.noval = NULL;
	return p;
}

/* preorder */
void print_tree(tree_t *t, int spaces)
{
	int i;

	if (t == NULL)
		return;

	for (i=0; i<spaces; i++) {
		fprintf(stderr, " ");
	}

	/* process root */
	switch(t->type) {
	case ID:
		fprintf(stderr, "[ID:%s]", (t->attribute.sval)->name);
		break;
	case FUNCTION:
		fprintf(stderr, "[FUNCTION:%s", (t->attribute.sval)->name);
		print_types((t->attribute.sval)->parameter_types);
		fprintf(stderr, ":%d]", (t->attribute.sval)->effective_type);
		break;
	case PROCEDURE:
		fprintf(stderr, "[PROCEDURE:%s", (t->attribute.sval)->name);
		print_types((t->attribute.sval)->parameter_types);
		fprintf(stderr, "]");
		break;
	case WHILE:
		fprintf(stderr, "[WHILE:%d]", t->effective_type);
		break;
	case FOR:
		fprintf(stderr, "[FOR:%d]", t->effective_type);
		break;
	case LINKFOR:
		fprintf(stderr, "[LINKFOR:%d]", t->effective_type);
		break;
	case IF:
		fprintf(stderr, "[IF:%d]", t->effective_type);
		break;
	case THENELSE:
		fprintf(stderr, "[THENELSE:%d]", t->effective_type);
		break;
	case INUM:
		fprintf(stderr, "[INUM:%d]", t->attribute.ival);
		break;
	case RNUM:
		fprintf(stderr, "[RNUM:%f]", t->attribute.rval);
		break;
	case BOOL:
		fprintf(stderr, "[BOOL:%d]", t->attribute.ival);
		break;
	case ADDOP:
		fprintf(stderr, "[ADDOP:%d]", t->attribute.opval);
		break;
	case MULOP:
		fprintf(stderr, "[MULOP:%d]", t->attribute.opval);
		break;
	case RELOP:
		fprintf(stderr, "[RELOP:%d]", t->effective_type);
		break;
	case ASSIGNOP:
		fprintf(stderr, "[ASSGINOP:%d]", t->attribute.opval);
		break;
	case NOT:
		fprintf(stderr, "[NOT:%d]", t->effective_type);
		break;
	case LINK:
		fprintf(stderr, "[LINK]");
		break;
	default:
		fprintf(stderr, "[UNKNOWN: %d]", t->type);
		break;
	}
	fprintf(stderr, " || %d || ", t->effective_type);
	fprintf(stderr, "\n");

	/* go left */
	print_tree(t->left, spaces+4);
	/* go right */
	print_tree(t->right, spaces+4);

}



