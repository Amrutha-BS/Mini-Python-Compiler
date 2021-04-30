/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "pythonCompiler.y"

    #include<stdio.h>
    #include<string.h>  
	
	int yylineno;

	int yylex();
	void yyerror(char *s);

	char temp[100];
	char temp_no[10]="0";
	//int temp_no=0;
	
	struct ICG
	{
		char op[10];
		char op1[10];
		char op2[10];
		char res[10];
	}ICG[100];
	int ICG_no=0;

	struct sym_tab
	{
		char name[10];
		char type[10];
		char val[10];
	}sym_tab[100];
	int sym_no=0;

	char stk[100][10];
	int top=0;

	char labl[100][10];
	int lab=0;
	
	char label[10]="L";
	char label_no[10]="0";
	
	FILE *fptr;

	void disp_quad();
	void code_assign();
	void code_temp();
	void for1();
	void for2();
	void print();
	void create_quad(char *op, char *op1, char *op2, char *res);
	void create_symtab(char *name, char *type, char *value);
	int searchsymbol(char *var);
	void disp_symtab();
	void ifblock();
	void elseblock();
	void block_exit();
	void loop_incr();
    void slice_str(const char * str, char * buffer, size_t start, size_t end);
	

/* Line 371 of yacc.c  */
#line 127 "pythonCompiler.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "pythonCompiler.tab.h".  */
#ifndef YY_YY_PYTHONCOMPILER_TAB_H_INCLUDED
# define YY_YY_PYTHONCOMPILER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FOR = 258,
     WHILE = 259,
     DQT = 260,
     IF = 261,
     IN = 262,
     RANGE = 263,
     ELIF = 264,
     ELSE = 265,
     PRINT = 266,
     TAB = 267,
     NUM = 268,
     ID = 269,
     OR = 270,
     AND = 271,
     GT = 272,
     LT = 273,
     NE = 274,
     EQ = 275,
     GE = 276,
     LE = 277
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 73 "pythonCompiler.y"

    int ival;           
    double dval;
    char str[10];


/* Line 387 of yacc.c  */
#line 199 "pythonCompiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PYTHONCOMPILER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 227 "pythonCompiler.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,    17,    30,    28,    33,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
      20,    15,    21,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      18,    19,    22,    23,    24,    25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    17,    22,
      23,    28,    29,    34,    35,    40,    41,    46,    47,    52,
      53,    58,    59,    64,    65,    70,    71,    72,    78,    79,
      80,    86,    87,    88,    94,    95,    96,   102,   103,   104,
     110,   111,   112,   118,   119,   120,   126,   127,   128,   134,
     135,   136,   142,   143,   144,   150,   151,   152,   158,   159,
     160,   166,   168,   170,   175,   182,   188,   189,   190,   203,
     205,   209,   211,   213,   214,   224,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    -1,    36,    35,    -1,    71,    35,    -1,
      77,    35,    -1,    72,    35,    -1,    -1,    14,    37,    15,
      38,    -1,    -1,    14,    39,    28,    38,    -1,    -1,    14,
      40,    29,    38,    -1,    -1,    14,    41,    30,    38,    -1,
      -1,    14,    42,    31,    38,    -1,    -1,    13,    43,    28,
      38,    -1,    -1,    13,    44,    29,    38,    -1,    -1,    13,
      45,    30,    38,    -1,    -1,    13,    46,    31,    38,    -1,
      -1,    -1,    14,    47,    27,    48,    38,    -1,    -1,    -1,
      14,    49,    26,    50,    38,    -1,    -1,    -1,    14,    51,
      24,    52,    38,    -1,    -1,    -1,    14,    53,    22,    54,
      38,    -1,    -1,    -1,    14,    55,    23,    56,    38,    -1,
      -1,    -1,    14,    57,    25,    58,    38,    -1,    -1,    -1,
      13,    59,    27,    60,    38,    -1,    -1,    -1,    13,    61,
      26,    62,    38,    -1,    -1,    -1,    13,    63,    24,    64,
      38,    -1,    -1,    -1,    13,    65,    22,    66,    38,    -1,
      -1,    -1,    13,    67,    23,    68,    38,    -1,    -1,    -1,
      13,    69,    25,    70,    38,    -1,    13,    -1,    14,    -1,
      11,    16,    38,    17,    -1,    11,    16,     5,    38,     5,
      17,    -1,    12,    11,    16,    38,    17,    -1,    -1,    -1,
       3,    14,    73,     7,     8,    16,    75,    17,    32,    12,
      76,    74,    -1,    38,    -1,    38,    33,    38,    -1,    71,
      -1,    36,    -1,    -1,     6,    16,    38,    17,    78,    32,
      12,    76,    79,    -1,    -1,    10,    32,    12,    80,    76,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    81,    82,    83,    84,    88,    88,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   109,   110,   110,
     110,   111,   112,   114,   115,   116,   119,   119,   119,   122,
     123,   125,   126,   128,   128,   131,   131
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FOR", "WHILE", "DQT", "IF", "IN",
  "RANGE", "ELIF", "ELSE", "PRINT", "TAB", "NUM", "ID", "'='", "'('",
  "')'", "OR", "AND", "'<'", "'>'", "GT", "LT", "NE", "EQ", "GE", "LE",
  "'+'", "'-'", "'*'", "'/'", "':'", "','", "$accept", "start",
  "Assignment", "$@1", "expr", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25",
  "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "PrintFunc", "ForStmt", "$@34", "$@35", "args", "blockStmt", "IfStmt",
  "$@36", "ElseStmt", "$@37", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    61,    40,    41,   270,   271,
      60,    62,   272,   273,   274,   275,   276,   277,    43,    45,
      42,    47,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    35,    37,    36,    39,
      38,    40,    38,    41,    38,    42,    38,    43,    38,    44,
      38,    45,    38,    46,    38,    47,    48,    38,    49,    50,
      38,    51,    52,    38,    53,    54,    38,    55,    56,    38,
      57,    58,    38,    59,    60,    38,    61,    62,    38,    63,
      64,    38,    65,    66,    38,    67,    68,    38,    69,    70,
      38,    38,    38,    71,    71,    71,    73,    74,    72,    75,
      75,    76,    76,    78,    77,    80,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     1,     1,     4,     6,     5,     0,     0,    12,     1,
       3,     1,     1,     0,     9,     0,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     7,     0,     2,     2,     2,
       2,    66,     0,     0,     0,     0,     1,     3,     4,     6,
       5,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,    63,     0,     8,     0,     0,     0,     0,     0,
      44,    47,    50,    53,    56,    59,     0,     0,     0,     0,
      26,    29,    32,    35,    38,    41,     0,     0,    65,     0,
      18,    20,    22,    24,     0,     0,     0,     0,     0,     0,
      10,    12,    14,    16,     0,     0,     0,     0,     0,     0,
       0,    64,    69,     0,    45,    48,    51,    54,    57,    60,
      27,    30,    33,    36,    39,    42,     0,     0,     0,    72,
      71,     0,    70,     0,     0,    74,     0,     0,    67,    75,
      68,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    15,    24,    40,    41,    42,    43,    30,
      31,    32,    33,    44,    94,    45,    95,    46,    96,    47,
      97,    48,    98,    49,    99,    34,    84,    35,    85,    36,
      86,    37,    87,    38,    88,    39,    89,     8,     9,    21,
     130,   103,   121,    10,    76,   125,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int8 yypact[] =
{
      14,   -10,     3,     5,    11,  -125,    23,    14,    14,    14,
      14,  -125,    -4,    34,     8,    12,  -125,  -125,  -125,  -125,
    -125,    33,     7,    65,    24,    -4,    25,    -4,    -4,    49,
      30,    31,    29,    32,    35,    38,    37,    43,    44,    45,
      40,    48,    39,    47,    52,    54,    73,    76,    77,    74,
    -125,    96,  -125,    85,  -125,    87,    -4,    -4,    -4,    -4,
    -125,  -125,  -125,  -125,  -125,  -125,    -4,    -4,    -4,    -4,
    -125,  -125,  -125,  -125,  -125,  -125,    75,    88,  -125,    -4,
    -125,  -125,  -125,  -125,    -4,    -4,    -4,    -4,    -4,    -4,
    -125,  -125,  -125,  -125,    -4,    -4,    -4,    -4,    -4,    -4,
      94,  -125,    78,    91,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    -6,    -4,    80,  -125,
    -125,    99,  -125,    98,    81,  -125,    -6,   102,  -125,  -125,
    -125,    -6,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,    42,  -115,  -125,   -13,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -113,  -125,  -125,
    -125,  -125,  -124,  -125,  -125,  -125,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      26,   119,   128,   120,    11,     3,     4,   132,     5,    22,
      23,   119,    51,   120,    53,    54,   119,     1,   120,    12,
       2,    13,    14,    16,    27,     3,     4,    28,     5,   -52,
     -55,   -49,   -58,   -46,   -43,   -17,   -19,   -21,   -23,    25,
      29,    50,    52,    80,    81,    82,    83,    22,    23,    17,
      18,    19,    20,    90,    91,    92,    93,    55,    56,    58,
      57,    62,    60,    59,    61,    63,   102,    64,    66,    68,
      65,   104,   105,   106,   107,   108,   109,    67,    69,    70,
      71,   110,   111,   112,   113,   114,   115,   -34,   -37,   -31,
     -40,   -28,   -25,    -9,   -11,   -13,   -15,    72,    73,    75,
      74,    77,    78,    79,   122,   101,   116,   100,   118,   124,
     126,   117,   123,   127,   129
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      13,   116,   126,   116,    14,    11,    12,   131,    14,    13,
      14,   126,    25,   126,    27,    28,   131,     3,   131,    16,
       6,    16,    11,     0,    16,    11,    12,    15,    14,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     5,
       7,    17,    17,    56,    57,    58,    59,    13,    14,     7,
       8,     9,    10,    66,    67,    68,    69,     8,    28,    30,
      29,    24,    27,    31,    26,    22,    79,    23,    28,    30,
      25,    84,    85,    86,    87,    88,    89,    29,    31,    27,
      26,    94,    95,    96,    97,    98,    99,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    24,    22,    25,
      23,     5,    17,    16,   117,    17,    12,    32,    17,    10,
      12,    33,    32,    32,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    11,    12,    14,    35,    36,    71,    72,
      77,    14,    16,    16,    11,    37,     0,    35,    35,    35,
      35,    73,    13,    14,    38,     5,    38,    16,    15,     7,
      43,    44,    45,    46,    59,    61,    63,    65,    67,    69,
      39,    40,    41,    42,    47,    49,    51,    53,    55,    57,
      17,    38,    17,    38,    38,     8,    28,    29,    30,    31,
      27,    26,    24,    22,    23,    25,    28,    29,    30,    31,
      27,    26,    24,    22,    23,    25,    78,     5,    17,    16,
      38,    38,    38,    38,    60,    62,    64,    66,    68,    70,
      38,    38,    38,    38,    48,    50,    52,    54,    56,    58,
      32,    17,    38,    75,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    12,    33,    17,    36,
      71,    76,    38,    32,    10,    79,    12,    32,    76,    12,
      74,    80,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
/* Line 1792 of yacc.c  */
#line 88 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 88 "pythonCompiler.y"
    { code_assign(); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 91 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 91 "pythonCompiler.y"
    { strcpy(stk[++top],"+"); code_temp();}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 92 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 92 "pythonCompiler.y"
    { strcpy(stk[++top],"-"); code_temp();}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 93 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 93 "pythonCompiler.y"
    { strcpy(stk[++top],"*"); code_temp();}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 94 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 94 "pythonCompiler.y"
    { strcpy(stk[++top],"/"); code_temp();}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 95 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 95 "pythonCompiler.y"
    { strcpy(stk[++top],"+"); code_temp();}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 96 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 96 "pythonCompiler.y"
    { strcpy(stk[++top],"-"); code_temp();}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 97 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 97 "pythonCompiler.y"
    { strcpy(stk[++top],"*"); code_temp();}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 98 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 98 "pythonCompiler.y"
    { strcpy(stk[++top],"/"); code_temp();}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 99 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 99 "pythonCompiler.y"
    {strcpy(stk[++top],"<="); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 100 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 100 "pythonCompiler.y"
    {strcpy(stk[++top],">="); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 101 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 101 "pythonCompiler.y"
    {strcpy(stk[++top],"!="); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 102 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 102 "pythonCompiler.y"
    {strcpy(stk[++top],">"); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 103 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 103 "pythonCompiler.y"
    {strcpy(stk[++top],"<"); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 104 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 104 "pythonCompiler.y"
    {strcpy(stk[++top],"=="); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 105 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 105 "pythonCompiler.y"
    {strcpy(stk[++top],"<="); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 106 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 106 "pythonCompiler.y"
    {strcpy(stk[++top],">="); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 107 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 107 "pythonCompiler.y"
    {strcpy(stk[++top],"!="); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 108 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 108 "pythonCompiler.y"
    {strcpy(stk[++top],">"); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 109 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 109 "pythonCompiler.y"
    {strcpy(stk[++top],"<"); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 110 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 110 "pythonCompiler.y"
    {strcpy(stk[++top],"=="); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 111 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 112 "pythonCompiler.y"
    { strcpy(stk[++top],(yyvsp[(1) - (1)].str)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 114 "pythonCompiler.y"
    {print();}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 115 "pythonCompiler.y"
    {print();}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 116 "pythonCompiler.y"
    {print();}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 119 "pythonCompiler.y"
    {  strcpy(stk[++top],(yyvsp[(2) - (2)].str)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 119 "pythonCompiler.y"
    {loop_incr();}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 119 "pythonCompiler.y"
    {block_exit();}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 122 "pythonCompiler.y"
    {for1();}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 123 "pythonCompiler.y"
    {for2();}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 128 "pythonCompiler.y"
    {ifblock();}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 128 "pythonCompiler.y"
    {block_exit();}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 131 "pythonCompiler.y"
    {elseblock();}
    break;


/* Line 1792 of yacc.c  */
#line 1865 "pythonCompiler.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 134 "pythonCompiler.y"


#include "lex.yy.c"
#include<ctype.h>

int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	fptr = fopen("out0.txt","w");
	printf("\n ********* INTERMEDIATE CODE GENERATION *********\n");
	yyparse();
	printf("\n ********* QUADRUPLES *********\n\n");
	disp_quad();
	printf("\n ********* SYMBOL TABLE *********");
	disp_symtab();
	fclose(yyin);
	fclose(fptr);
	return 0;
}
char toks[7][10]={"for","print","if","else","while","range","in"};
void slice_str(const char * str, char * buffer, size_t start, size_t end)
{
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}
void yyerror(char *s) {
        
	printf("\nError!! %s in line no. %d %s\n", s , yylineno, yytext);
        const size_t len = strlen(yytext);
        char buffer[len + 1];

        for ( size_t start = 0; start < len; ++start ) {
            for ( int end = len - 1; end >= (int) start; --end ) {
               slice_str(yytext, buffer, start, end);
               //printf("%s\n", buffer);
	       for(int j=0;j<7;j++)
	       {
	         if(strcmp(buffer,toks[j])==0)
		 {
		    printf("Error recovery successful!!");
		    printf("\n correct word: %s\n",toks[j]);
		   }
	       }
           }
       }

}  

int yywrap(void) {
        return 1;
}

void disp_quad()
{
	printf("Operator Operand-1 Operand-2 Result\n");
	for(int i=0; i<ICG_no; i++)
	{
		printf("  %s     \t %s \t %s \t %s \n", ICG[i].op,ICG[i].op1,ICG[i].op2, ICG[i].res);
	}
}

void loop_incr()
{
	printf("\n%s = %s + 1 \n", stk[top],stk[top]);
	fprintf(fptr,"\n%s = %s + 1 \n", stk[top],stk[top]);
	create_quad("+", stk[top] , "1" , stk[top] );
	printf("\ngoto %s\n", labl[lab]);
	fprintf(fptr,"\ngoto %s\n", labl[lab]);
}

void ifblock()
{
	//printf("In ifblock");
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s %s %s \n",temp,stk[top-2],stk[top-1],stk[top]);
	fprintf(fptr,"\n%s = %s %s %s \n",temp,stk[top-2],stk[top-1],stk[top]);
	create_quad(stk[top-1], stk[top-2] , stk[top] , temp);

	top-=3;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;	

	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] , " " , temp);

	//top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	
	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);
	strcpy(labl[++lab],label);
	
	//printf("done");
	
}

void elseblock()
{
	//printf("In else block");
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\ngoto %s\n", label);
	fprintf(fptr,"\ngoto %s\n", label);
	strcpy(labl[++lab],label);
	printf("\n%s : \n\n", labl[--lab]);
	fprintf(fptr,"\n%s : \n\n", labl[--lab]);
	//lab-=1;
}

void block_exit()
{
	printf("\n%s : \n\n", label);
	fprintf(fptr,"\n%s : \n\n", label);
	lab-=2;
}

void code_assign()
{
	if(strcmp(stk[top],"ERROR")==0);
	else
	{
		printf("\n%s = %s\n",stk[top-1],stk[top]);
		fprintf(fptr,"\n%s = %s\n",stk[top-1],stk[top]);
		create_quad("=", stk[top] , " " , stk[top-1]);

		int ss1,ss2,a=-1,b=-1,c=9999;
		float d=9999.9;
		char val[10];

		b=atoi(stk[top]);

		if(b==0)
		{
			ss1=searchsymbol(stk[top]);
			if(ss1==-1){
				printf("\nError: %s is Undefined variable \n",stk[top]);
			}
			else{ 
				create_symtab(stk[top-1], sym_tab[ss1].type , sym_tab[ss1].val);
			}
		}
		else
			create_symtab(stk[top-1], "INT" , stk[top]);
	}
	top-=2;
} 

void code_temp()
{
	strcpy(temp,"t");
	strcat(temp,temp_no);
	
	int ss1,ss2,a=-1,b=-1,c=9999,z1,z2;
	double d=9999.9;
	char val[10];
	
	printf("\n%s = %s %s %s\n",temp,stk[top-2],stk[top],stk[top-1]);
	fprintf(fptr,"\n%s = %s %s %s\n",temp,stk[top-2],stk[top],stk[top-1]);
	create_quad(stk[top], stk[top-2] , stk[top-1] , temp);

	z1=atoi(stk[top-1]);
	if (z1!=0){
		b=z1;
	}
	else{
		ss2=searchsymbol(stk[top-1]);

		if(ss2==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-1]);
		else{
			b=atoi(sym_tab[ss2].val);
		}	
	}
	
	
	z2=atoi(stk[top-2]);
	if (z2!=0){
		a=z2;
	}
	else
	{
		ss1=searchsymbol(stk[top-2]);

		if(ss1==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-2]);
		else {
			a=atoi(sym_tab[ss1].val);
		}
	}
	

	char sym_plus[5]="+";
	char sym_min[5]="-";
	char sym_mul[5]="*";
	char sym_div[5]="/";

	if((strcmp(stk[top],sym_plus)==0) && a!=-1 && b!=-1)
	{
		c=a+b;	
	}
	if(strcmp(stk[top],sym_min)==0 && a!=-1 && b!=-1)
	{
		c=a-b;	
	}
	if(strcmp(stk[top],sym_mul)==0 && a!=-1 && b!=-1)
	{
		
		d=a*b;	
	}
	if(strcmp(stk[top],sym_div)==0 && a!=-1 && b!=-1)
	{
		if (b!=0)
			d=a/b;	
		else
			printf("\n Error: Division by zero\n");
	}
	
	if(c!=9999)
	{
		sprintf(val,"%d",c);
		create_symtab(temp, "INT" , val);
	}

	if(c==9999 && d!=9999.9)
	{
		sprintf(val,"%lf",d);
		create_symtab(temp, "FLOAT" , val);
	}

	if(c==9999 && d==9999.9);
	
	top-=3;
	strcpy(stk[++top],temp);
	temp_no[0]++;
} 

void for1()
{
	printf("\n%s = 0\n",stk[top-1]);
	fprintf(fptr,"\n%s = 0\n",stk[top-1]);
	create_quad("=", "0" , " " , stk[top-1]);

	create_symtab(stk[top-1], "INT" , "0");
	
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	strcpy(labl[++lab],label);

	printf("\n%s :\n",label);
	fprintf(fptr,"\n%s :\n",label);

	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s < %s \n",temp,stk[top-1],stk[top]);
	fprintf(fptr,"\n%s = %s < %s \n",temp,stk[top-1],stk[top]);
	create_quad("<", stk[top-1] , stk[top] , temp);

	top-=1;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;	

	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] , " " , temp);

	top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);

	strcpy(labl[++lab],label);
	lab-=1;
} 

void for2()
{
	printf("\n%s = %s\n",stk[top-2],stk[top-1]);
	fprintf(fptr,"\n%s = %s\n",stk[top-2],stk[top-1]);
	create_quad("=", stk[top-1] , " " , stk[top-2]);

	int ss1,ss2,a=-1,b=-1,c=9999;
	float d=9999.9;
	char val[10];

	b=atoi(stk[top-1]);

	if(b==-1)
	{
		ss1=searchsymbol(stk[top-1]);
		if(ss1==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-2]);
		else{ 
			create_symtab(stk[top-2], sym_tab[ss1].type , sym_tab[ss1].val);
		}
	}
	else
		create_symtab(stk[top-2], "INT" , stk[top-1]);

	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	strcpy(labl[++lab],label);

	printf("\n%s :\n",label);
	fprintf(fptr,"\n%s :\n",label);

	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s < %s \n",temp,stk[top-2],stk[top]);
	fprintf(fptr,"\n%s = %s < %s \n",temp,stk[top-2],stk[top]);
	create_quad("<", stk[top-2] ,stk[top] , temp);

	top-=2;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] ," " , temp);

	top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);

	strcpy(labl[++lab],label);
	lab-=1;
} 

void print()
{
	printf("\nPRINT %s \n", stk[top]);
	fprintf(fptr,"\nPRINT %s \n", stk[top]);
	//printf("\n%s = %s + 1 \n", stk[top],stk[top]);
	create_quad("PRINT", " " , " " , stk[top] );
	//create_quad("+", stk[top] , "1" , stk[top] );
	top-=1;
	//printf("\ngoto %s \n", labl[lab-1]);
	//printf("\n%s : \n\n", labl[lab]);
	//lab-=2;
} 

void create_quad(char *op, char *op1, char *op2, char *res)
{
	strcpy(ICG[ICG_no].op, op);
	strcpy(ICG[ICG_no].op1, op1);
	strcpy(ICG[ICG_no].op2, op2);
	strcpy(ICG[ICG_no].res, res);
	ICG_no++;
} 

void create_symtab(char *name, char *type, char *value)
{
	strcpy(sym_tab[sym_no].name, name);
	strcpy(sym_tab[sym_no].type, type);
	strcpy(sym_tab[sym_no].val, value);
	sym_no++;
} 

int searchsymbol(char *var)
{
	int o=-1;
	for (int i=0; i<sym_no; i++)
	{
		if(strcmp(sym_tab[i].name,var)==0)
			o = i;
	}
	return o;
} 

void disp_symtab()
{
	printf("\n\nNAME   TYPE   VALUE\n");
	for(int i=0; i<sym_no; i++)
	{
		printf("  %s \t %s \t %s \n", sym_tab[i].name,sym_tab[i].type,sym_tab[i].val);
 	}
}


