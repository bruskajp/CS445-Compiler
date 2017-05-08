/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INUM = 258,
    BOOL = 259,
    RNUM = 260,
    ID = 261,
    ASSIGNOP = 262,
    RELOP = 263,
    ADDOP = 264,
    MULOP = 265,
    LOOP = 266,
    NOT = 267,
    LT = 268,
    LE = 269,
    GT = 270,
    GE = 271,
    EQ = 272,
    NE = 273,
    OR = 274,
    PLUS = 275,
    MINUS = 276,
    AND = 277,
    STAR = 278,
    SLASH = 279,
    PROGRAM = 280,
    VAR = 281,
    ARRAY = 282,
    OF = 283,
    DOTDOT = 284,
    INTEGER = 285,
    REAL = 286,
    BOOLEAN = 287,
    FUNCTION = 288,
    PROCEDURE = 289,
    BBEGIN = 290,
    END = 291,
    IF = 292,
    THEN = 293,
    ELSE = 294,
    THENELSE = 295,
    WHILE = 296,
    DO = 297,
    FOR = 298,
    TO = 299,
    LINKFOR = 300,
    FUNCTION_CALL = 301,
    ARRAY_ACCESS = 302,
    LINK = 303
  };
#endif
/* Tokens.  */
#define INUM 258
#define BOOL 259
#define RNUM 260
#define ID 261
#define ASSIGNOP 262
#define RELOP 263
#define ADDOP 264
#define MULOP 265
#define LOOP 266
#define NOT 267
#define LT 268
#define LE 269
#define GT 270
#define GE 271
#define EQ 272
#define NE 273
#define OR 274
#define PLUS 275
#define MINUS 276
#define AND 277
#define STAR 278
#define SLASH 279
#define PROGRAM 280
#define VAR 281
#define ARRAY 282
#define OF 283
#define DOTDOT 284
#define INTEGER 285
#define REAL 286
#define BOOLEAN 287
#define FUNCTION 288
#define PROCEDURE 289
#define BBEGIN 290
#define END 291
#define IF 292
#define THEN 293
#define ELSE 294
#define THENELSE 295
#define WHILE 296
#define DO 297
#define FOR 298
#define TO 299
#define LINKFOR 300
#define FUNCTION_CALL 301
#define ARRAY_ACCESS 302
#define LINK 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "pc.y" /* yacc.c:1909  */

	/* scanner */
	int ival;
	float rval;
	char *sval;
	int opval;

	/* semantic + gencode */
	node_t *nval;
	tree_t *tval;
	types_t *types;

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
