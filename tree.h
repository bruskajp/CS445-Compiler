#ifndef TREE_H
#define TREE_H

typedef struct tree_s {
	int type;		/* INUM, RNUM, ADDOP, MULOP, RELOP, ASSIGNOP, IF, WHILE, FOR */
	int effective_type; /* INUM, RNUM */
	union {
		int ival;	/* INUM */
		float rval;	/* RNUM */
		node_t *sval;	/* ID FUNCTION */
		int opval; 	/* ADDOP, MULOP, RELOP, ASSIGNOP*/
		void *noval; /* IF, WHILE, FOR, PROCEDURE */
	} attribute;
	struct tree_s *left;
	struct tree_s *right;
}
tree_t;

/* constructor */
tree_t *make_tree(int type, int effective_type, tree_t *left, tree_t *right);
tree_t *make_op(int type, int attribute, tree_t *left, tree_t *right);
//tree_t *make_assign_op(int type, int attribute, node_t *node, tree_t *right);
tree_t *make_id(node_t *node);
tree_t *make_func(node_t *node);
tree_t *make_proc(node_t *node);
tree_t *make_loop(int type, tree_t *left, tree_t *right);
tree_t *make_if(int type, tree_t *left, tree_t *right);
tree_t *make_else(int type, tree_t *left, tree_t *right);
tree_t *make_inum(int ival);
tree_t *make_rnum(float rval);
tree_t *make_bool(int val);
tree_t *make_link(int type, tree_t *left, tree_t *right);

int same_types(tree_t *head);

void print_tree(tree_t *t, int spaces);


#endif
