%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "scope.h"
#include "tree.h"
#include "types.h"
#include "y.tab.h"

void echo(char *);
void print_line_number();
extern int line_number;

%}

ident				[a-zA-Z][a-zA-Z0-9]*
number			[0-9]+
whitespace	[ \t]+
comment			\(\*(.*\n*)*\*\)|\/\/.*
boolean			true|false

%%

{comment} { /* do nothing */ }

"program"	{ print_line_number(); echo("PROGRAM"); return PROGRAM; }
"var"		{ echo("VAR"); return VAR; }
"array"		{ echo("ARRAY"); return ARRAY; }
"of"		{ echo("OF"); return OF; }
"integer"	{ echo("INTEGER"); return INTEGER; }
"^integer"	{ echo("INTEGER_POINTER"); return INTEGER_PTR; }
"real"		{ echo("REAL"); return REAL; }
"boolean" { echo("BOOLEAN"); return BOOLEAN; }
"function"	{ echo("FUNCTION"); return FUNCTION; }
"procedure"	{ echo("PROCEDURE"); return PROCEDURE; }
"begin"		{ echo("BBEGIN"); return BBEGIN; }
"end"		{ echo("END"); return END; }
"if"		{ echo("IF"); return IF; }
"then"		{ echo("THEN"); return THEN; }
"else"		{ echo("ELSE"); return ELSE; }
"while"		{ echo("WHILE"); return WHILE; }
"do"		{ echo("DO"); return DO; }
"for"		{ echo("FOR"); return FOR; }
"to"		{ echo("TO"); return TO; }

".."		{ echo("DOTDOT"); return DOTDOT; }
":="		{ echo("ASSIGNOP"); return ASSIGNOP; }

"="		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = EQ; return RELOP; }
"<>"		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = NE; return RELOP; }
"<"		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = LT; return RELOP; }
"<="		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = LE; return RELOP; }
">"		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = GT; return RELOP; }
">="		{ fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = GE; return RELOP; }

"or"		{ fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = OR; return ADDOP; }
"+"		{ fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = PLUS; return ADDOP; }
"-"		{ fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = MINUS; return ADDOP; }
"and"		{ fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = AND; return MULOP; }
"*"		{ fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = STAR; return MULOP; }
"/"		{ fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = SLASH; return MULOP; }

"not"		{ fprintf(stderr, "NOTOP[%s]", yytext); yylval.opval = NOT; return NOTOP; }
"^"		{ fprintf(stderr, "DEREFOP[%s]", yytext); yylval.opval = DEREF; return DEREFOP; }
"@"		{ fprintf(stderr, "REFOP[%s]", yytext); yylval.opval = REF; return REFOP; }


"true" { fprintf(stderr, "BOOLEAN[%d]",  yylval.ival = 1); return BOOL; } 
"false" { fprintf(stderr, "BOOLEAN[%d]",  yylval.ival = 0); return BOOL; } 

{number}		{ fprintf(stderr, "INUM[%d]", yylval.ival = atoi(yytext)); return INUM; }
{number}"."{number}	{ fprintf(stderr, "RNUM[%f]", yylval.rval = atof(yytext)); return RNUM; }
{ident}			{ fprintf(stderr, "ID[%s]", yylval.sval = strdup(yytext)); return ID; }
{whitespace}	{ ; }
\n		{ fprintf(stderr,"%s", yytext); print_line_number(); }
.		{ fprintf(stderr, "{%c}", yytext[0]); return yytext[0]; }

%%

void echo(char *message)
{
	fprintf(stderr, "{%s}", message);
}

void print_line_number()
{
	++line_number; 
	fprintf(stderr, " %d ", line_number);
}




