/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pc.y" /* yacc.c:339  */

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
#include "y.tab.h"

extern scope_t *top_scope;
extern node_t *tmp;
extern int procedure;

extern int yylex();
extern int yyerror(char *message);


#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 23 "pc.y" /* yacc.c:355  */

	/* scanner */
	int ival;
	float rval;
	char *sval;
	int opval;

	/* semantic + gencode */
	node_t *nval;
	tree_t *tval;
	types_t *types;

#line 237 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,     2,     2,    53,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    97,   114,   118,   125,   134,   138,   140,
     145,   147,   149,   154,   155,   159,   173,   183,   196,   207,
     221,   226,   229,   236,   248,   260,   270,   277,   282,   288,
     292,   299,   306,   314,   323,   327,   331,   339,   364,   381,
     409,   418,   448,   453,   460,   462,   467,   469,   476,   478,
     485,   494,   503,   513,   515,   517,   519,   521
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INUM", "BOOL", "RNUM", "ID", "ASSIGNOP",
  "RELOP", "ADDOP", "MULOP", "LOOP", "NOT", "LT", "LE", "GT", "GE", "EQ",
  "NE", "OR", "PLUS", "MINUS", "AND", "STAR", "SLASH", "PROGRAM", "VAR",
  "ARRAY", "OF", "DOTDOT", "INTEGER", "REAL", "BOOLEAN", "FUNCTION",
  "PROCEDURE", "BBEGIN", "END", "IF", "THEN", "ELSE", "THENELSE", "WHILE",
  "DO", "FOR", "TO", "LINKFOR", "FUNCTION_CALL", "ARRAY_ACCESS", "LINK",
  "'('", "')'", "';'", "'.'", "','", "':'", "'['", "']'", "$accept",
  "program", "$@1", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "scoped_name", "function_arguments",
  "procedure_arguments", "parameter_list", "compound_statement",
  "optional_statements", "statement_list", "statement", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    40,
      41,    59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -82,    32,     9,   -82,    46,     4,    53,   -82,   -40,    18,
      61,   -82,   -82,    47,    53,    28,   -34,    66,    68,     2,
      24,   -82,    27,    25,    -1,   -82,   -82,     0,    11,    11,
      72,   -82,    43,    30,   -82,    75,   -82,   -82,    47,    53,
      29,    33,   -82,    31,   -82,   -82,   -82,    37,   -82,    11,
      11,   -82,   -82,   -82,   -37,    11,    11,    51,    16,    80,
     -82,    49,    38,    78,   -82,     2,    11,    28,    -7,    -9,
      34,   -82,    89,   -82,   -17,   -82,    39,    11,    11,   -82,
      44,     2,    11,    11,    11,     2,    11,   -82,   -82,   -82,
      -1,    45,    53,    48,    69,   -82,    11,   -82,    -2,    41,
     -82,    62,    91,    80,   -82,    30,    58,   -82,    17,   -82,
     100,   -82,   -82,   -82,     2,    11,    -1,    50,    54,    65,
     -82,    76,   -82,     2,    34,    30,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     4,     0,     0,
       0,     7,     5,    14,     0,     0,     0,     0,     0,    28,
       0,     7,    22,     0,     0,    18,    19,    40,     0,     0,
       0,    35,     0,    27,    29,     0,    34,    13,    14,    25,
       0,     0,     3,     0,    10,    12,    11,     0,     8,     0,
       0,    53,    55,    54,    50,     0,     0,     0,    44,    46,
      48,     0,    38,     0,    26,     0,     0,     0,     0,     0,
       0,    17,     0,     6,     0,    42,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,    30,    33,    15,
       0,    20,     0,     0,     0,    41,     0,    39,     0,     0,
      56,    31,    45,    47,    49,    36,     0,    23,     0,    16,
       0,    43,    52,    51,     0,     0,     0,     0,     0,     0,
      24,     0,    32,     0,     0,    37,     9
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,   -12,    87,   -81,   -67,    71,   -82,   -82,
     -82,   -82,   -82,   -82,   -11,   -82,   -79,   -60,    81,   -82,
      35,   -28,    36,    40,   -44
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,    13,    47,    48,    15,    20,    21,
      22,    40,    41,    69,    31,    32,    33,    34,    35,    36,
      74,    75,    58,    59,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      57,    61,    16,    93,    23,    87,   105,   -38,    27,   107,
       9,    79,    77,    10,    51,    52,    53,    54,    78,    10,
      24,   101,    76,    55,    82,    83,    43,    68,    80,    44,
      45,    46,     3,    95,     4,   120,    96,    19,    88,    28,
     104,    91,    92,    29,   125,    30,    10,    90,   112,    49,
      99,    96,     5,     6,   118,    50,    89,   126,   106,     7,
      56,    17,    18,    19,    44,    45,    46,    12,   111,    11,
      10,   116,    25,    14,    26,    37,    39,    42,    62,    64,
     108,    65,    66,    70,    71,    86,    72,   119,    73,    81,
      84,    85,    94,    50,   100,    97,   -21,   113,   110,   109,
      83,   114,   115,   117,   124,   122,   121,   123,    38,    67,
       0,    63,    98,     0,     0,     0,     0,     0,   102,     0,
       0,     0,     0,   103
};

static const yytype_int8 yycheck[] =
{
      28,    29,    14,    70,    15,    65,    85,     7,     6,    90,
      50,    55,    49,    53,     3,     4,     5,     6,    55,    53,
      54,    81,    50,    12,     8,     9,    27,    39,    56,    30,
      31,    32,     0,    50,    25,   116,    53,    35,    66,    37,
      84,    50,    51,    41,   123,    43,    53,    54,    50,    49,
      78,    53,     6,    49,   114,    55,    67,   124,    86,     6,
      49,    33,    34,    35,    30,    31,    32,     6,    96,    51,
      53,    54,     6,    26,     6,    51,    49,    52,     6,    36,
      92,    51,     7,    54,    51,     7,    55,   115,    51,    38,
      10,    42,     3,    55,    50,    56,    51,    56,    29,    51,
       9,    39,    44,     3,    28,    51,    56,    42,    21,    38,
      -1,    30,    77,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,    25,     6,    49,     6,    60,    50,
      53,    51,     6,    61,    26,    64,    60,    33,    34,    35,
      65,    66,    67,    71,    54,     6,     6,     6,    37,    41,
      43,    71,    72,    73,    74,    75,    76,    51,    61,    49,
      68,    69,    52,    27,    30,    31,    32,    62,    63,    49,
      55,     3,     4,     5,     6,    12,    49,    78,    79,    80,
      81,    78,     6,    75,    36,    51,     7,    64,    60,    70,
      54,    51,    55,    51,    77,    78,    78,    49,    55,    81,
      78,    38,     8,     9,    10,    42,     7,    74,    78,    71,
      54,    50,    51,    63,     3,    50,    53,    56,    77,    78,
      50,    74,    79,    80,    81,    73,    78,    62,    60,    51,
      29,    78,    50,    56,    39,    44,    54,     3,    74,    78,
      62,    56,    51,    42,    28,    73,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    59,    58,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    66,    66,    67,    67,
      68,    69,    69,    70,    70,    70,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    11,     1,     3,     6,     0,     1,     8,
       1,     1,     1,     3,     0,     4,     5,     3,     2,     2,
       3,     3,     0,     3,     5,     0,     3,     1,     0,     1,
       3,     4,     7,     3,     1,     1,     4,     8,     1,     4,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     4,     1,     1,     1,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "pc.y" /* yacc.c:1646  */
    { top_scope = scope_push(top_scope); }
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "pc.y" /* yacc.c:1646  */
    { 
		fprintf(stderr, "\n\nPROGRAM START:\n");
		print_tree((yyvsp[-1].tval), 0);
		fprintf(stderr, "\n\n");
		top_scope = scope_pop(top_scope); 
	}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "pc.y" /* yacc.c:1646  */
    {	
			(yyval.tval) = (yyvsp[0].sval);
		}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "pc.y" /* yacc.c:1646  */
    { 
			(yyval.tval) = (yyvsp[0].sval);
		}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "pc.y" /* yacc.c:1646  */
    {
			if ((tmp = scope_search(top_scope, (char *) (yyvsp[-3].tval))) != NULL) {
				char* msg;
				asprintf(&msg, "\"%s\" is already declared", (char *) (yyvsp[-3].tval));
				semError(msg);
			}
			scope_insert(top_scope, (char *) (yyvsp[-3].tval), VAR, (uintptr_t) (yyvsp[-1].tval));
		}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 146 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = INUM; }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = BOOL; }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = RNUM; }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "pc.y" /* yacc.c:1646  */
    {
			if ( top_scope->return_needed != 0 ){
				semError("Function missing return statement");
			} 
			fprintf(stderr, "\n\nPRINTING TREE:\n");
			print_tree((yyvsp[-3].tval),0);
			print_tree((yyvsp[0].tval),4);
			fprintf(stderr, "\n\n");
			top_scope = scope_pop(top_scope); 
		}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 174 "pc.y" /* yacc.c:1646  */
    {	
			(yyvsp[-4].nval)->effective_type = (uintptr_t) (yyvsp[-1].tval);
			(yyvsp[-4].nval)->parameter_types = (yyvsp[-3].types);
			tmp = scope_insert(top_scope, (char *) (yyvsp[-4].nval)->name, FUNCTION, (uintptr_t) (yyvsp[-1].tval));
			tmp->parameter_types = (yyvsp[-3].types);
			top_scope->return_name = strdup((yyvsp[-4].nval)->name);
			top_scope->return_needed = 1;
			(yyval.tval) = make_func((yyvsp[-4].nval));
		}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "pc.y" /* yacc.c:1646  */
    { 
			(yyvsp[-2].nval)->effective_type = -1;
			(yyvsp[-2].nval)->parameter_types = (yyvsp[-1].types);
			tmp = scope_insert(top_scope, (char *) (yyvsp[-2].nval)->name, PROCEDURE, -1);
			tmp->parameter_types = (yyvsp[-1].types);
			top_scope->return_name = NULL;
			top_scope->return_needed = 0;
			(yyval.tval) = make_proc((yyvsp[-2].nval));
		}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 197 "pc.y" /* yacc.c:1646  */
    {
			procedure = 0;
			if ((tmp = scope_search(top_scope, (yyvsp[0].sval))) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (yyvsp[0].sval));
				semError(msg);
			}
			(yyval.nval) = scope_insert(top_scope, (char *) (yyvsp[0].sval), FUNCTION, (uintptr_t) INTEGER);
			top_scope = scope_push(top_scope);
		}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 208 "pc.y" /* yacc.c:1646  */
    {
			procedure = 1;
			if ((tmp = scope_search(top_scope, (yyvsp[0].sval))) != NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (yyvsp[0].sval));
				semError(msg);
			}
			(yyval.nval) = scope_insert(top_scope, (yyvsp[0].sval), PROCEDURE, -1); // -1 because proc doesn't have ret val	
			top_scope = scope_push(top_scope);
		}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "pc.y" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "pc.y" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[-1].types); }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "pc.y" /* yacc.c:1646  */
    {
			types_t *empty = make_types();
			(yyval.types) = empty; 
		}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 237 "pc.y" /* yacc.c:1646  */
    {
			if ((tmp = scope_search(top_scope, (char *) (yyvsp[-2].tval))) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (char *) (yyvsp[-2].tval));
				semError(msg);
			}
			scope_insert(top_scope, (char *) (yyvsp[-2].tval), VAR, (uintptr_t) (yyvsp[0].tval));
			types_t *parameter_types = make_types();
			insert_type(parameter_types, (uintptr_t) (yyvsp[0].tval));
			(yyval.types) = parameter_types;
		}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "pc.y" /* yacc.c:1646  */
    {
			if ((tmp = scope_search(top_scope, (char *) (yyvsp[-2].tval))) != NULL) { 
				char* msg;
				asprintf(&msg, "Name \"%s\" is already declared", (char *) (yyvsp[-2].tval));
				semError(msg);
			}
			scope_insert(top_scope, (char *) (yyvsp[-2].tval), VAR, (uintptr_t) (yyvsp[0].tval));
			insert_type((yyvsp[-4].types), (uintptr_t) (yyvsp[0].tval));
			(yyval.types) = (yyvsp[-4].types);
		}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 260 "pc.y" /* yacc.c:1646  */
    {
			types_t *empty = make_types();
			(yyval.types) = empty;
		}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 271 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = (yyvsp[-1].tval);
		}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 278 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = (yyvsp[0].tval);
		}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = NULL;
		}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 289 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = (yyvsp[0].tval);
		}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = make_link(LINK, (yyvsp[-2].tval), (yyvsp[0].tval));
		}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = make_if(IF, (yyvsp[-2].tval), (yyvsp[0].tval));
			if ( (yyvsp[-2].tval)->effective_type != BOOL ){
				semError("If expression must evaluate to a boolean");
			}
		}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 307 "pc.y" /* yacc.c:1646  */
    {
			tree_t *tree1 = make_else(THENELSE, (yyvsp[-3].tval), (yyvsp[-1].tval));
			(yyval.tval) = make_if(IF, (yyvsp[-5].tval), tree1);
			if ( (yyvsp[-5].tval)->effective_type != BOOL ){
				semError("If expression must evaluate to a boolean");
			}
		}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 315 "pc.y" /* yacc.c:1646  */
    {
			if ( top_scope->return_name != NULL){
				if ( strcmp(((yyvsp[-2].tval)->attribute.sval)->name, top_scope->return_name)==0 ){
					top_scope->return_needed = 0; //TODO: Handle if this is in a "if" statement
				}
			}
			(yyval.tval) = make_op(ASSIGNOP, ASSIGNOP, (yyvsp[-2].tval), (yyvsp[0].tval));
		}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 324 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = (yyvsp[0].tval);
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 328 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = (yyvsp[0].tval);
		}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 332 "pc.y" /* yacc.c:1646  */
    {
			(yyval.tval) = make_loop(WHILE, (yyvsp[-2].tval), (yyvsp[0].tval));
			if ( (yyvsp[-2].tval)->effective_type != BOOL ){
				semError("While loop expression must evaluate to a boolean");
			}
			fprintf(stderr, "\n\n");
		}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 340 "pc.y" /* yacc.c:1646  */
    {
			tree_t *tree7 = make_inum(1);
			tree_t *tree6 = make_op(ADDOP, ADDOP, (yyvsp[-6].tval), tree7);
			tree_t *tree5 = make_op(ASSIGNOP, ASSIGNOP, (yyvsp[-6].tval), tree6);
			tree_t *tree4 = make_loop(LINKFOR, (yyvsp[0].tval), tree5);	
			tree_t *tree3 = make_op(RELOP, RELOP, (yyvsp[-6].tval), (yyvsp[-2].tval));
			tree_t *tree2 = make_loop(WHILE, tree3, tree4);
			tree_t *tree1 = make_op(ASSIGNOP, ASSIGNOP, (yyvsp[-6].tval), (yyvsp[-4].tval));	
			(yyval.tval) = make_loop(FOR, tree1, tree2);

			if ( (yyvsp[-6].tval)->effective_type != INUM ){
				semError("Indexing variable must be an integer");
			}
			if ( (yyvsp[-4].tval)->effective_type != INUM ){
				semError("Expression must use integers (1st value)");
			}
			if ( (yyvsp[-2].tval)->effective_type != INUM ){
				semError("Expression must use integers (2nd value)");
			}
		
		}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 365 "pc.y" /* yacc.c:1646  */
    {
			if (procedure){ // TODO: change this to be a scope variable
				if ( (tmp = scope_search_all(top_scope, (yyvsp[0].sval))) == NULL ){
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[0].sval));
					semError(msg);
				}
			} else {
				if ( ((tmp = scope_search(top_scope, (yyvsp[0].sval))) == NULL ) ){ 
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[0].sval));
					semError(msg);
				} 	
			}
			(yyval.tval) = make_id(tmp);
		}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 382 "pc.y" /* yacc.c:1646  */
    {
			if (procedure){
				if ((tmp = scope_search_all(top_scope, (yyvsp[-3].sval))) == NULL) {
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[-3].sval));
					semError(msg);
				} else {
					if ( (yyvsp[-1].tval)->effective_type != INUM ){
						semError("Non-integer type for array index");
					}
				}
			} else {
				if ((tmp = scope_search(top_scope, (yyvsp[-3].sval))) == NULL) {
					char* msg;
					asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[-3].sval));
					semError(msg);
				} else {
					if ( (yyvsp[-1].tval)->effective_type != INUM ){
						semError("Non-integer type for array index");
					}
				}
			}
			(yyval.tval) = make_id(tmp);
		}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 410 "pc.y" /* yacc.c:1646  */
    {
			if ((tmp = scope_search(top_scope, (yyvsp[0].sval))) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[0].sval));
				semError(msg);
			}
			(yyval.tval) = make_proc(tmp);
		}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 419 "pc.y" /* yacc.c:1646  */
    {	
			if ( (strcmp((yyvsp[-3].sval), "read") == 0) && (scope_search(top_scope, (yyvsp[-3].sval)) == NULL) ){ //TODO: 1 arg?
				tmp = scope_insert(top_scope, (yyvsp[-3].sval), PROCEDURE, -1); // no return type
				tmp->parameter_types = (yyvsp[-1].types);
				if (tmp->parameter_types->size != 1){
					semError("Function \"read\" only takes one argument");
				}
			}
			if ( (strcmp((yyvsp[-3].sval), "write") == 0) && (scope_search(top_scope, (yyvsp[-3].sval)) == NULL) ){
				tmp = scope_insert(top_scope, (yyvsp[-3].sval), PROCEDURE, -1); // no return type
				tmp->parameter_types = (yyvsp[-1].types);
				if (tmp->parameter_types->size != 1){
					semError("Function \"write\" only takes one argument");
				}
			}
			if ( (tmp = scope_search(top_scope, (yyvsp[-3].sval))) == NULL ){
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[-3].sval));
				semError(msg);
			}
			compare_types(tmp->parameter_types, (yyvsp[-1].types));
			(yyval.tval) = make_proc(tmp);
		}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 449 "pc.y" /* yacc.c:1646  */
    { 	
			(yyval.types) = make_types();
			insert_type((yyval.types), (yyvsp[0].tval)->effective_type);
		}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 454 "pc.y" /* yacc.c:1646  */
    { 
			insert_type((yyval.types), (yyvsp[0].tval)->effective_type);
		}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 461 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 463 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = make_op(RELOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval)); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 468 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 470 "pc.y" /* yacc.c:1646  */
    { 
			(yyval.tval) = make_op(ADDOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval)); 
		}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 477 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[0].tval); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 479 "pc.y" /* yacc.c:1646  */
    { 
			(yyval.tval) = make_op(MULOP, (yyvsp[-1].opval), (yyvsp[-2].tval), (yyvsp[0].tval)); 
		}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 486 "pc.y" /* yacc.c:1646  */
    { 
			if ((tmp = scope_search_all(top_scope, (yyvsp[0].sval))) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[0].sval));
				semError(msg);
			}
			(yyval.tval) = make_id(tmp); 
		}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 495 "pc.y" /* yacc.c:1646  */
    { 
			if ((tmp = scope_search_all(top_scope, (yyvsp[-3].sval))) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[-3].sval));
				semError(msg);
			}
			(yyval.tval) = make_tree(ARRAY_ACCESS, tmp->effective_type, make_id(tmp), (yyvsp[-1].tval)); 
		}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 504 "pc.y" /* yacc.c:1646  */
    { 
			if ((tmp = scope_search_all(top_scope, (yyvsp[-3].sval))) == NULL) {
				char* msg;
				asprintf(&msg, "Name \"%s\" used but not defined\n", (yyvsp[-3].sval));
				semError(msg);
			}
			compare_types(tmp->parameter_types, (yyvsp[-1].types));
			(yyval.tval) = make_func(tmp);
		}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 514 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = make_inum((yyvsp[0].ival)); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 516 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = make_rnum((yyvsp[0].rval)); }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 518 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = make_bool((yyvsp[0].ival)); }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 520 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = (yyvsp[-1].tval); }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 522 "pc.y" /* yacc.c:1646  */
    { (yyval.tval) = make_tree(NOT, BOOL, NULL, (yyvsp[0].tval)); }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1976 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 526 "pc.y" /* yacc.c:1906  */

	
scope_t *top_scope;
node_t *tmp;
int procedure;

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







