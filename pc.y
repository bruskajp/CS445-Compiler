%{
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "node.h"
#include "scope.h"
#include "tree.h"
#include "types.h"
#include "gencode.h"
#include "y.tab.h"

extern scope_t *top_scope;
extern node_t *tmp;
extern char *filename;
extern FILE *fp;
extern int line_number;
 
extern char* res_regs[6];
extern int used_res_regs[6];
extern char* exp_regs[6];
extern int used_exp_regs[6];

extern int yylex();
extern int yyerror(char *message);
%}

%union {
	/* scanner */
	int ival;
	float rval;
	char *sval;
	int opval;

	/* semantic + gencode */
	node_t *nval;
	tree_t *tval;
	types_t *types;
}

%token <ival>	INUM
%token <ival> BOOL
%token <rval>	RNUM
%token <ival>	IPTR
%token <sval>	ID

%token <opval>	ASSIGNOP 
%token <opval>	RELOP
%token <opval>	ADDOP
%token <opval>	MULOP
%token <opval>	NOTOP
%token <opval>	REFOP
%token <opval>	DEREFOP
%token <noval>  LOOP

%token	NOT REF DEREF

%token	LT LE GT GE EQ NE
%token	OR PLUS MINUS
%token	AND STAR SLASH

%token	PROGRAM
%token	VAR
%token	ARRAY OF DOTDOT
%token	INTEGER INTEGER_PTR REAL BOOLEAN
%token	FUNCTION PROCEDURE
%token	BBEGIN END
%token	IF THEN ELSE THENELSE
%token	WHILE DO
%token	FOR TO LINKFOR

%token	FUNCTION_CALL
%token	ARRAY_ACCESS

%token	LINK

%type <tval> identifier_list
%type <tval> standard_type
%type <tval> type
%type <tval> INTEGER
%type <tval> INTEGER_PTR
%type <tval> REAL
%type <tval> BOOLEAN
%type <tval> variable
%type <tval> statement
%type <tval> statement_list

%type <tval> optional_statements
%type <tval> compound_statement
%type <tval> procedure_statement
%type <tval> subprogram_declaration
%type <tval> subprogram_head
%type <nval> scoped_name
%type <types> parameter_list
%type <types> function_arguments
%type <types> procedure_arguments

%type <types> expression_list
%type <tval> expression
%type <tval> simple_expression
%type <tval> term
%type <tval> factor
%type <tval> reference

%%

program:
	{ 
		gen_asm_init();
		top_scope = scope_push(top_scope);
	}
	PROGRAM ID '(' identifier_list ')' ';' 
	declarations
	subprogram_declarations
	compound_statement
		{ gen_asm_subprog_decl_fini(top_scope); 
		}
	'.'
	{ 
		fprintf(stderr, "\n\nPROGRAM START:\n");
		gen_label($10);
		print_tree($10, 0);
		fprintf(stderr, "\n\n");
		gen_asm_code($10);
		gen_asm_fini(top_scope);
		//free_tree($10);
		top_scope = scope_pop(top_scope);
	}
	;



identifier_list
	: ID
		{	
			$$ = $1;
		}
	| identifier_list ',' ID
		{ 
			$$ = $3;
		}
	;

declarations
	: declarations VAR identifier_list ':' type ';'
		{
			if ((tmp = scope_search(top_scope, (char *) $3)) != NULL) {
				char* msg;
				asprintf(&msg, "\"%s\" is already declared", (char *) $3);
				semError(msg);
			}
			scope_insert(top_scope, (char *) $3, VAR, (uintptr_t) $5);
			++line_number;
			fprintf(stderr, " %d ", line_number);
		}
	| /* empty */
	;

type
	: standard_type
		{ $$ = $1; }
	| ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
		{ $$ = $8; }
	;

standard_type
	: INTEGER
		{ $$ = INUM; }
	| INTEGER_PTR
		{ $$ = IPTR; }
	| BOOLEAN
		{ $$ = BOOL; }
	| REAL
		{ $$ = RNUM; }
	;

subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'	
	| /* empty */
	;

subprogram_declaration
	: subprogram_head declarations subprogram_declarations compound_statement
		{
			if ( top_scope->return_needed != 0 ){
				semError("Function missing return statement");
			} 
			fprintf(stderr, "\n\nPRINTING TREE:\n");
			gen_label($1);
			print_tree($1,0);
			gen_label($4);
			fprintf(stderr, "\n\n");
			gen_asm_code($4);
			//free_tree($4);
			top_scope = scope_pop(top_scope); 
		}
	;

subprogram_head
	: scoped_name function_arguments ':' standard_type ';'
		{	
			$1->effective_type = (uintptr_t) $4;
			$1->parameter_types = $2;
			tmp = scope_insert(top_scope, (char *) $1->name, FUNCTION, (uintptr_t) $4);
			tmp->parameter_types = $2;
			top_scope->return_name = strdup($1->name);
			top_scope->return_needed = 1;
			$$ = make_func($1);
		}
	| scoped_name procedure_arguments ';'
		{ 
			$1->effective_type = -1;
			$1->parameter_types = $2;
			tmp = scope_insert(top_scope, (char *) $1->name, PROCEDURE, -1);
			tmp->parameter_types = $2;
			top_scope->return_name = NULL;
			top_scope->return_needed = 0;
			$$ = make_proc($1, $2->expression_list);
		}
	;

scoped_name
	: FUNCTION ID
		{
			if ((tmp = scope_search(top_scope, $2)) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", $2);
				semError(msg);
			}
			$$ = scope_insert(top_scope, (char *) $2, FUNCTION, (uintptr_t) INTEGER);
			top_scope = scope_push(top_scope);
			top_scope->type = 0; // function
		}
	| PROCEDURE ID
		{
			if ((tmp = scope_search(top_scope, $2)) != NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", $2);
				semError(msg);
			}
			$$ = scope_insert(top_scope, $2, PROCEDURE, -1); // -1 cuz proc doesn't have ret val	
			top_scope = scope_push(top_scope);
			top_scope->type = 1; // procedure
		}
	;

function_arguments
	: '(' parameter_list ')'
		{ $$ = $2; }
	;

procedure_arguments
	: '(' parameter_list ')'
		{ $$ = $2; }
	| /* empty */
		{
			types_t *empty = make_types();
			$$ = empty; 
		}
	;

parameter_list
	: identifier_list ':' type
		{
			if ((tmp = scope_search(top_scope, (char *) $1)) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (char *) $1);
				semError(msg);
			}
			scope_insert(top_scope, (char *) $1, VAR, (uintptr_t) $3);
			types_t *parameter_types = make_types();
			insert_type(parameter_types, (uintptr_t) $3, $1);
			$$ = parameter_types;
		}
	| parameter_list ';' identifier_list ':' type
		{
			if ((tmp = scope_search(top_scope, (char *) $3)) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (char *) $3);
				semError(msg);
			}
			scope_insert(top_scope, (char *) $3, VAR, (uintptr_t) $5);
			insert_type($1, (uintptr_t) $5, make_link(LINK, $1->expression_list, $3));
			$$ = $1;
		}
	| /* empty */
		{
			types_t *empty = make_types();
			$$ = empty;
		}
	;


/* statement */

compound_statement
	: BBEGIN optional_statements END 
		{
			$$ = $2;
		}
	;

optional_statements
	: statement_list
		{
			$$ = $1;
		}
	| /* empty */
		{
			$$ = NULL;
		}
	;

statement_list
	: statement
		{
			$$ = $1;
		}
	| statement_list ';' statement
		{
			$$ = make_link(LINK, $1, $3);
		}
	;

statement
	: IF expression THEN statement 
		{
			$$ = make_if(IF, $2, $4);
			if ( $2->effective_type != BOOL ){
				semError("If expression must evaluate to a boolean");
			}
		}
	| IF expression THEN statement ELSE statement ';'
		{
			tree_t *tree1 = make_else(THENELSE, $4, $6);
			$$ = make_if(IF, $2, tree1);
			if ( $2->effective_type != BOOL ){
				semError("If expression must evaluate to a boolean");
			}
		}
	| variable ASSIGNOP expression
		{
			if ( top_scope->return_name != NULL){
				if ( strcmp(($1->attribute.sval)->name, top_scope->return_name)==0 ){
					top_scope->return_needed = 0; //TODO: Handle if this is in a "if" statement
				}
			}
			$$ = make_op(ASSIGNOP, ASSIGNOP, $1, $3);
			$1->left_leaf = 1;
			$1->label = 1;
		}
	| procedure_statement
		{
			$$ = $1;
		}
	| compound_statement
		{
			$$ = $1;
		}
	| WHILE expression DO statement_list
		{
			$$ = make_loop(WHILE, $2, $4);
			if ( $2->effective_type != BOOL ){
				semError("While loop expression must evaluate to a boolean");
			}
			fprintf(stderr, "\n\n");
		}
	| FOR variable ASSIGNOP expression TO expression DO statement_list
		{
			tree_t *tree7 = make_inum(1);
			tree_t *tree6 = make_op(ADDOP, ADDOP, $2, tree7);
			tree_t *tree5 = make_op(ASSIGNOP, ASSIGNOP, $2, tree6);
			tree_t *tree4 = make_loop(LINKFOR, $8, tree5);	
			tree_t *tree3 = make_op(RELOP, RELOP, $2, $6);
			tree_t *tree2 = make_loop(WHILE, tree3, tree4);
			tree_t *tree1 = make_op(ASSIGNOP, ASSIGNOP, $2, $4);	
			$$ = make_loop(FOR, tree1, tree2);

			if ( $2->effective_type != INUM ){
				semError("Indexing variable must be an integer");
			}
			if ( $4->effective_type != INUM ){
				semError("Expression must use integers (1st value)");
			}
			if ( $6->effective_type != INUM ){
				semError("Expression must use integers (2nd value)");
			}
		
		} 
	;

variable 
	: ID
		{
			if (top_scope->type == 1){ // procedure
				if ( (tmp = scope_search_all(top_scope, $1)) == NULL ){
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
					semError(msg);
				}
			} else { // function
				if ( ((tmp = scope_search(top_scope, $1)) == NULL ) ){ 
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
					semError(msg);
				} 	
			}
			$$ = make_id(tmp);
		}
	| ID '[' expression ']'
		{
			if (top_scope->type == 1){ // procedure
				if ((tmp = scope_search_all(top_scope, $1)) == NULL) {
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
					semError(msg);
				} else { // function
					if ( $3->effective_type != INUM ){
						semError("Non-integer type for array index");
					}
				}
			} else {
				if ((tmp = scope_search(top_scope, $1)) == NULL) {
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
					semError(msg);
				} else {
					if ( $3->effective_type != INUM ){
						semError("Non-integer type for array index");
					}
				}
			}
			$$ = make_id(tmp);
		}
	;

procedure_statement
	: ID
		{
			if ((tmp = scope_search(top_scope, $1)) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
				semError(msg);
			}
			$$ = make_proc(tmp, NULL);
		}
	| ID '(' expression_list ')'
		{	
			if ( (strcmp($1, "read") == 0) && (scope_search_all(top_scope, $1) == NULL) ){
				tmp = scope_insert(top_scope, $1, PROCEDURE, -1); // no return type
				tmp->parameter_types = $3;
				top_scope->offset += 8;
				gen_asm_write_decl();
				gen_asm_read_decl();
				if (tmp->parameter_types->size != 1){
					semError("Procedure \"read\" only takes one argument");
				}
			}
			if ( (strcmp($1, "write") == 0) && (scope_search_all(top_scope, $1) == NULL) ){
				tmp = scope_insert(top_scope, $1, PROCEDURE, -1); // no return type
				tmp->parameter_types = $3;
				gen_asm_write_decl();
				if (tmp->parameter_types->size != 1){
					semError("Procedure \"write\" only takes one argument");
				}
			}
			if ( (tmp = scope_search_all(top_scope, $1)) == NULL ){
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
				semError(msg);
			}
			compare_types(tmp->parameter_types, $3);
			$$ = make_proc(tmp, $3->expression_list);
		}
	;


/* expression */

expression_list
	: expression
		{ 	
			$$ = make_types();
			insert_type($$, $1->effective_type, $1);
		}
	| expression_list ',' expression
		{ 
			insert_type($$, $3->effective_type, make_link(LINK, $1->expression_list, $3));
		}
	;

expression
	: simple_expression
		{ $$ = $1; }
	| simple_expression RELOP simple_expression
		{ 
			$$ = make_op(RELOP, $2, $1, $3); 
			if ( $1->left == NULL && $1->right == NULL ){
				$1->left_leaf = 1;
				$1->label = 1;
			}
		}
	;

simple_expression
	: term
		{ $$ = $1; }
	| simple_expression ADDOP term
		{ 
			$$ = make_op(ADDOP, $2, $1, $3); 
			if ( $1->left == NULL && $1->right == NULL ){
				$1->left_leaf = 1;
				$1->label = 1;
			}
		}
	;

term
	: factor
		{ $$ = $1; }
	| term MULOP factor
		{ 
			$$ = make_op(MULOP, $2, $1, $3); 
			if ( $1->left == NULL && $1->right == NULL ){
				$1->left_leaf = 1;
				$1->label = 1;
			}
		}
	;

factor
	: DEREFOP reference
		{ $$ = make_op(DEREFOP, deref_type($2->effective_type), NULL, $2); }
	| REFOP reference
		{ $$ = make_op(REFOP, ref_type($2->effective_type), NULL, $2); } 
	| NOTOP reference 
		{ $$ = make_op(NOT, BOOL, NULL, $2); }
	| reference
		{ $$ = $1;}
	;

reference
	: ID
		{ 
			if ((tmp = scope_search_all(top_scope, $1)) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
				semError(msg);
			}
			$$ = make_id(tmp); 
		}
	| ID '[' expression ']'
		{ 
			if ((tmp = scope_search_all(top_scope, $1)) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
				semError(msg);
			}
			$$ = make_tree(ARRAY_ACCESS, tmp->effective_type, make_id(tmp), $3); 
		}
	| ID '(' expression_list ')'
		{ 
			if ((tmp = scope_search_all(top_scope, $1)) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", $1);
				semError(msg);
			}
			compare_types(tmp->parameter_types, $3);
			$$ = make_func(tmp);
		}
	| INUM
		{ $$ = make_inum($1); }
	| RNUM
		{ $$ = make_rnum($1); }
	| BOOL
		{ $$ = make_bool($1); }
	| '(' expression ')'
		{ $$ = $2; }
	;


%%
	
scope_t *top_scope;
node_t *tmp;
char *filename = "indsa.s";
FILE *fp; 
int line_number = 0;

char* res_regs[6] = {"%edi","%esi","%edx","%ecx","%r8d","%r9d"};
int used_res_regs[6] = {0,0,0,0,0,0};
char* exp_regs[6] = {"%r10d","%r11d","%r12d", "%r13d", "%r14d", "%r15d"};
int used_exp_regs[6] = {0,0,0,0,0,0};


int main()
{
	top_scope = NULL;
	tmp = NULL;

	yyparse();
}

int yyerror(char *message)
{
	fprintf(stderr, "\n\nSyntax Error: %s\n", message);
	exit(1);
}







