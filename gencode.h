#ifndef GENCODE_H
#define GENCODE_H

#include "node.h"
#include "scope.h"
#include "tree.h"

extern char *filename;
extern FILE *fp;

extern char* res_regs[6];
extern int used_res_regs[6];
extern char* exp_regs[6];
extern int used_exp_regs[6];

char *top_reg(char* regs[6], int used_regs[6]);
void push_reg(char* regs[6], int used_regs[6]);
char *pop_reg(char* regs[6], int used_regs[6]);
void swap(char* regs[6], int used_regs[6]);

void gen_asm_init();
void gen_asm_subprog_decl_fini(scope_t *scope);
void gen_asm_fini(scope_t *scope);
void gen_asm_write_decl();
void gen_asm_write(char *output);
void gen_asm_push_exp_regs();
void gen_asm_pull_exp_regs();
void gen_asm_func_decl(node_t *node, scope_t *scope);
void gen_asm_func(node_t *node);
char *gen_asm_op(int op, char* reg1, char* reg2);
void gen_asm_top_reg_to_stack(int op, tree_t *tree);
void gen_asm_stack_to_top_reg(int op, tree_t *tree);
void gen_asm_code(tree_t *tree);
void gen_asm_exp(tree_t *tree);


void gen_label(tree_t *tree);


#endif
