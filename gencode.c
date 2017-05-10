#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "gencode.h"
#include "y.tab.h"

char *top_reg(char* regs[6], int used_regs[6])
{
	int i = 0;
	for (; i < 6; ++i){
		if ( !used_regs[i] ){
			return regs[i];
		}
	}
	return NULL;
}

void push_reg(char* regs[6], int used_regs[6])
{
	int i = 0;
	for (; i < 6; ++i){
		if ( !used_regs[i] ){
			used_regs[i-1] = 0;
			return;
		}
	}
}

char *pop_reg(char* regs[6], int used_regs[6])
{
	int i = 0;
	for (; i < 6; ++i){
		if ( !used_regs[i] ){
			used_regs[i] = 1;
			return regs[i];
		}
	}
}

void swap(char* regs[6], int used_regs[6])
{
	int i = 0;
	for (; i < 6; ++i){
		if ( !used_regs[i] ){
			char* temp = regs[i];
			regs[i] = regs[i+1];
			regs[i+1] = temp;
			return;
		}
	}
}


void gen_asm_init()
{
	fp = fopen(filename , "w+");
	fprintf(fp, "\t.file \"indsa.p\"\n");
}

void gen_asm_subprog_decl_fini(scope_t *scope)
{
	fprintf(fp, "\t.text\n");
	fprintf(fp, "\t.globl\tmain\n");
	fprintf(fp, "\t.type\tmain, @function\n");
	fprintf(fp, "main:\n");
	fprintf(fp, "\tpushq\t%%rbp\n");
	fprintf(fp, "\tmovq\t%%rsp, %%rbp\n");
	fprintf(fp, "\tsubq\t$%d, %%rsp\n", scope->offset);
}

void gen_asm_fini(scope_t *scope)
{
	fprintf(fp, "\taddq\t$%d, %%rsp\n", scope->offset);
	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tpopq\t%%rbp\n");	
	fprintf(fp, "\tret\n");	
	fprintf(fp, "\t.size\tmain, .-main\n");	
	fprintf(fp, "\t.ident\t\"GCC: (Ubuntu 5.4.0-6ubuntu~16.04.4) 5.4.0 20160609\"\n");
	fprintf(fp, "\t.section\t.note.GNU-stack,\"\",@progbits\n");
	fclose(fp);
}

void gen_asm_write_decl()
{
	fprintf(fp, "\t.section\t.rodata\n");
	fprintf(fp, ".LC0:\n");
	fprintf(fp, "\t.string\t\"%%d\"\n");
}

void gen_asm_write(char* output)
{
	// push all of both types of regs to the stack
	fprintf(fp, "\tmovl\t%s, %%esi\n", output);
	fprintf(fp, "\tmovl\t$.LC0, %%edi\n");
	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tcall\tprintf\n");	
	// pull all of both types of regs from the stack
}

void gen_asm_read_decl()
{
	fprintf(fp, "\t.section\t.rodata\n");
	fprintf(fp, ".LC1:\n");
	fprintf(fp, "\t.string\t\"%%d\"\n");
}

void gen_asm_read()
{
	// push all of both types of regs to the stack
	fprintf(fp, "\tmovq\t%%fs:40, %%rax\n");
	fprintf(fp, "\tmovq\t%%rax, -8(%%rbp)\n");
	fprintf(fp, "\txorl\t%%eax, %%eax\n");
	fprintf(fp, "\tleaq\t-12(%%rbp), %%rax\n");
	fprintf(fp, "\tmovq\t%%rax, %%rsi\n");	
	fprintf(fp, "\tmovl\t$.LC1, %%edi\n");
	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tcall\t__isoc99_scanf\n");	
	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tmovq\t-8(%%rbp), %%rdx\n");
	fprintf(fp, "\txorq\t%%fs:40, %%rdx\n");
	fprintf(fp, "\tje\t.L3\n");
	fprintf(fp, "\tcall\t__stack_chk_fail\n");	
	fprintf(fp, ".L3:\n");
	fprintf(fp, "\tleave:\n");
	// pull all of both types of regs from the stack
}


void gen_asm_push_exp_regs()
{
	// push all registers into stack
}

void gen_asm_pull_exp_regs()
{
	// pull all registers from stack
}

void gen_asm_func_decl(node_t *node, scope_t *scope)
{
	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tcall\tpush_exp_regs\n");

	fprintf(fp, "\t.text\n");
	fprintf(fp, "\t.globl\t%s\n", node->name);
	fprintf(fp, "\t.type\t%s, @function\n", node->name);
	fprintf(fp, "%s:\n", node->name);
	fprintf(fp, "\tpushq\t%%rbp\n");
	fprintf(fp, "\tmovq\t%%rsp, %%rbp\n");
	fprintf(fp, "\tsubq\t$%d, %%rsp\n", scope->offset);
	int i = 0;
	for(; i < node->parameter_types->size; ++i){ // TODO: seg fault if more than 6 args
		fprintf(fp, "\tmovl\t%s, -%d(%%rbp)\n", res_regs[i], i*4); // TODO: dif sizes for dif types
	}
	//fprintf(fp, "%s", node->expression); // TODO:FIX
	fprintf(fp, "\tpopq\t%%rbp\n");
	fprintf(fp, "\tmovl\t$0, %%eax\n");

	fprintf(fp, "\tmovl\t$0, %%eax\n");
	fprintf(fp, "\tcall\tpull_exp_regs\n");	
}

void gen_asm_func(node_t *node)
{
	if ( node->parameter_types->size == 0 ){
		fprintf(fp, "\tmovl\t$0, %%eax\n");
	} else {
		int i = node->parameter_types->size - 1;
		for(; i >= 0 ; ++i){ // TODO: seg fault if more than 6 args
			fprintf(fp, "\tmovl\t VALTHING  %s\n", res_regs[i]); // TODO: NEED TO CHANGE FOR REAL VAL
		}
	}
	fprintf(fp, "\tcall\t%s\n", node->name);
	
}

void gen_asm_code(tree_t *tree)
{
	if ( tree == NULL ){
		return;
	}
	switch(tree->type){
		case ASSIGNOP:
			gen_asm_exp(tree);
			gen_asm_top_reg_to_stack(ASSIGNOP, tree->left);
			return;
		case LINK:
			break;
		case PROCEDURE:
			if ( strcmp((tree->attribute.sval)->name, "write") == 0 ){
				gen_asm_stack_to_top_reg(ASSIGNOP, tree->left);
				gen_asm_write(top_reg(exp_regs, used_exp_regs));
			} else if ( strcmp((tree->attribute.sval)->name, "read") == 0 ){
				gen_asm_read();
				gen_asm_stack_to_top_reg(ASSIGNOP, tree->left);
				gen_asm_write(top_reg(exp_regs, used_exp_regs));
			} else {
				fprintf(stderr, "Non-IO functions are not allowed");
			}
			break;
		default:
			return;
	}
	if (tree->left != NULL){ gen_asm_code(tree->left); }
	if (tree->right != NULL){ gen_asm_code(tree->right); }
	
}

char *gen_asm_op(int op, char* reg1, char* reg2)
{
	switch(op){
		case PLUS:
			fprintf(fp, "\t%s\t%s, %s\n", "addl", reg1, reg2);
			break;
		case MINUS:
			fprintf(fp, "\t%s\t%s, %s\n", "subl", reg1, reg2);
			break;
		case OR:
			fprintf(fp, "\t%s\t%s, %s\n", "orl", reg1, reg2);
			break;
		case AND:
			fprintf(fp, "\t%s\t%s, %s\n", "andl", reg1, reg2);
			break;
		case STAR:
			fprintf(fp, "\t%s\t%s, %s\n", "imull", reg1, reg2);
			break;
		case SLASH:
			fprintf(fp, "\t%s\t%s, %s\n", "movl", "$0", "%edx");
			fprintf(fp, "\t%s\t%s, %s\n", "movl", reg2, "%eax");
			fprintf(fp, "\t%s\t%s, %s\n", "movl", reg1, reg2);
			fprintf(fp, "\t%s\t%s\n", "idivl", reg2);
			fprintf(fp, "\t%s\t%s, %s\n", "movl", "%eax", reg2);
			break;
		case EQ:	
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsete\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case NE:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsetne\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case LT:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsetl\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case LE:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsetle\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case GT:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsetg\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case GE:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsetge\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;
		case ASSIGNOP:
			fprintf(fp, "\t%s\t%s, %s\n", "movl", reg1, reg2);
			break;
		case NOTOP:
			fprintf(fp, "\tcmpl\t%s, %s\n", reg1, reg2);
			fprintf(fp, "\tsete\t%%al\n");
			fprintf(fp, "\tmozbl\t%%al, %s\n", reg2);
			break;	
		case REFOP:
			fprintf(fp, "\t%s\t%s, %s\n", "leal", reg1, reg2);
			break;
		case DEREFOP:
			push_reg(exp_regs, used_exp_regs);
			fprintf(fp, "\t%s\t-0(%s), %s\n", "movl", top_reg(exp_regs, used_exp_regs), reg2);
			pop_reg(exp_regs, used_exp_regs);
			break;
		case DOTDOT:
			fprintf(stderr, "\n\nOperation \"..\" not implemnted yet.\n\n");
			break;		
		default:
				fprintf(stderr, "\n\nWE DON'T HANDLE THAT OPERATION: %d\n\n", op);
				//exit(0);
	}
}

void gen_asm_top_reg_to_stack(int op, tree_t *tree)
{
	char* msg;
	switch(tree->type){
			case ID:
				asprintf(&msg, "-%d(%%rbp)", tree->attribute.sval->offset);
				gen_asm_op(op, top_reg(exp_regs, used_exp_regs), msg);
				break;
			case INUM: case BOOL:
				asprintf(&msg, "$%d", tree->attribute.ival);
				gen_asm_op(op, top_reg(exp_regs, used_exp_regs), msg);
				break;
			default:
				fprintf(stderr, "\n\nWE DON'T HANDLE THAT TYPE: %d\n\n", tree->type);
				exit(0);
		}
}

void gen_asm_stack_to_top_reg(int op, tree_t *tree)
{
	char* msg;
	switch(tree->type){
			case ID:
				asprintf(&msg, "-%d(%%rbp)", tree->attribute.sval->offset);
				//gen_asm_op(op, "WHY", "ME");
				gen_asm_op(op, msg, top_reg(exp_regs, used_exp_regs));
				break;
			case INUM: case BOOL:
				asprintf(&msg, "$%d", tree->attribute.ival);
				gen_asm_op(op, msg, top_reg(exp_regs, used_exp_regs));
				break;
			default:
				fprintf(stderr, "\n\nWE DON'T HANDLE THAT TYPE: %d\n\n", tree->type);
				exit(0);
		}
}

void gen_asm_exp(tree_t *tree)
{
	if ( tree == NULL ){
		return;
	}
	/*
	if ( tree->left == NULL ){
		fprintf(stderr, "left");
	}
	if ( tree->right == NULL ){
		fprintf(stderr, "right");
	}
	*/
	if (tree->left_leaf == 1){
		fprintf(stderr, "C1: %d | ", tree->type);
		gen_asm_stack_to_top_reg(ASSIGNOP, tree);
	} else if ( tree->right->left == NULL && tree->right->right == NULL) {
		fprintf(stderr, "C2: %d | ", tree->type);
		//if ( tree->left != NULL ){
			gen_asm_exp(tree->left);
		//}else{
		//	gen_asm_exp(tree->right);	
		//}	
		gen_asm_stack_to_top_reg(tree->attribute.opval, tree->right);
	} else if ( (1 <= tree->left->label) && (tree->left->label < tree->right->label) &&
	            (tree->left->label < 6) ){
		fprintf(stderr, "C3: %d | ", tree->type);
		swap(exp_regs, used_exp_regs);
		gen_asm_exp(tree->right);
		char *r = pop_reg(exp_regs, used_exp_regs);
		gen_asm_exp(tree->left);
		gen_asm_op(tree->attribute.opval, r, top_reg(exp_regs, used_exp_regs));
		push_reg(exp_regs, used_exp_regs);	
		swap(exp_regs, used_exp_regs);
	} else if ( tree->right->label <= tree->left->label && tree->right->label < 6 ){
		fprintf(stderr, "C4: %d | ", tree->type);
		gen_asm_exp(tree->left);
		char *r = pop_reg(exp_regs, used_exp_regs);
		gen_asm_exp(tree->right);
		gen_asm_op(tree->attribute.opval, top_reg(exp_regs, used_exp_regs), r);
		push_reg(exp_regs, used_exp_regs);
	} else if ( tree->left->label > 6 && tree->right->label > 6 ){
		fprintf(stderr, "C5 ");
		//gen_asm_exp(tree->right);
		//char *r = pop_reg(exp_regs, used_exp_regs);
		//gen_asm_exp(tree->left);
		//push_reg(exp_regs, used_exp_regs);
		//fprintf(fp, "\tmovl\t%d, %s\n", tree->attribute.ival, open_reg(exp_regs, used_exp_regs));	
	} else {
		fprintf(stderr, "ERROROROROR");
		exit(1);
	}
}


void gen_label(tree_t *tree)
{	
	if ( tree == NULL ){
		return;
	}
	if ( tree->left != NULL) {
		gen_label(tree->left);
	}
	if ( tree->right != NULL) {
		gen_label(tree->right);
	}

	if ( tree->left == NULL || tree->right == NULL ){
		// do nothing
	} else if ( tree->left->label == tree->right->label ){
		tree->label = tree->left->label + 1;
	} else {
		if ( tree->left->label > tree->right->label ){
			tree->label = tree->left->label;
		} else {
			tree->label = tree->right->label;
		}
	}
}







