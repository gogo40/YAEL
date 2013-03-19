/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 7 "parser.y"


#include "yael.h"

FILE* plog;
FILE* pout;

static char buffer[256];
string __path;

int nerrors, nlines;

map<string,bool> isvect;
map<string,vect> vect_l;

map<string,bool> isfunction;
map<string,function> function_l; 

map<string,int>  func_narg;
map<string,int>  func_id;
map<string,bool> is_bultin_func;

map<string, double> var;
map<string, bool> isvar;

map<string, bool> isclass;
map<string, bool> isobj;
map<string, sclass> yaelClass;
map<string, sobj> yaelObj;

inline
double eval(Tokens* in){
	return eval(&var, &isvar, &isclass, &isobj, &yaelClass, &yaelObj, &vect_l, &isvect, in);
}

inline
double interp(iTokens* in){
	return interp(&var, &isvar, &isclass, &isobj, &yaelClass, &yaelObj,&vect_l,&isvect, in);
}

void build_o(build_obj* in){
	string out;
	out=*in->obj_;
	if(in->isv){
		sprintf(buffer,"%.0lf",eval(in->i));
		out= out +"[" +buffer + "]";
	}
	
	isobj[out]=true;
	yaelObj[out].pai=*in->class_;
	yaelObj[out].x=eval(in->x);
	yaelObj[out].y=eval(in->y);
	yaelObj[out].z=eval(in->z);
}

void build_o(build_obj* in,
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* yaelClass,
map<string, sobj>* yaelObj,
map<string,vect>* vect_l,
map<string,bool>* isvect){
	string out;
	out=*in->obj_;
	if(in->isv){
		sprintf(buffer,"%.0lf",eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->i));
		out= out +"[" +buffer + "]";
	}
	
	(*isobj)[out]=true;
	(*yaelObj)[out].pai=*in->class_;
	 

	(*yaelObj)[out].x=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->x);
	(*yaelObj)[out].y=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->y);
	(*yaelObj)[out].z=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->z);
}

typedef vector<string> vs;
typedef vector<int> vi;

typedef pair<vs*,vi*> func_arg;



/* Line 268 of yacc.c  */
#line 159 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ECHO_ = 258,
     ECHOS = 259,
     PRINT = 260,
     PRINTS = 261,
     EXEC = 262,
     END_ = 263,
     RETURN = 264,
     EXPR = 265,
     BUILD_OBJ = 266,
     FUNCTION = 267,
     FUNCTION_CALL = 268,
     DO = 269,
     FOR = 270,
     IF = 271,
     ELSE = 272,
     WHILE = 273,
     END_WHILE = 274,
     END_FOR = 275,
     STRING = 276,
     READ = 277,
     REAL = 278,
     VECTOR = 279,
     VECTOR_ID = 280,
     VECTOR_ID_POS = 281,
     VECTOR_ID_ATTR = 282,
     VECTOR_POS = 283,
     VAR = 284,
     NUM = 285,
     ID = 286,
     CLASS_ID = 287,
     OBJ_ID = 288,
     BUILT_IN_FUNC = 289,
     NEG = 290,
     CLASS = 291,
     USE = 292,
     DIFF = 293,
     EQ = 294,
     LEQ = 295,
     GEQ = 296,
     OR = 297,
     AND = 298,
     NOT = 299,
     INC = 300,
     DEC = 301,
     BREAK = 302,
     CONTINUE = 303,
     POW_ATR = 304,
     MOD_ATR = 305,
     DIV_ATR = 306,
     MUL_ATR = 307,
     SUB_ATR = 308,
     ADD_ATR = 309,
     PRE_DEC = 310,
     POS_DEC = 311,
     PRE_INC = 312,
     POS_INC = 313,
     LE = 314,
     LN = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 94 "parser.y"

	double val;
	string* str;
	sfields* sf;
	Matrix* valM;
	Vector* valV;
	Tokens* tk;
	iTokens* itk;
	vs* vS;
	vi* vI;
	func_arg* fa;
	build_obj* bobj;



/* Line 293 of yacc.c  */
#line 271 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 283 "parser.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1788

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  317

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    66,     2,     2,
      73,    74,    64,    63,    75,    62,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    70,
      50,    51,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,     2,     2,     2,     2,
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
      45,    46,    47,    48,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    12,    15,    19,    25,    30,    39,
      49,    51,    56,    61,    64,    67,    68,    74,    82,    84,
      88,   103,   117,   134,   150,   154,   158,   162,   164,   168,
     170,   174,   176,   179,   181,   184,   188,   191,   195,   198,
     202,   206,   211,   215,   220,   224,   229,   233,   238,   242,
     247,   250,   254,   256,   259,   261,   264,   266,   269,   271,
     274,   281,   289,   293,   295,   305,   317,   318,   320,   328,
     336,   348,   358,   371,   375,   377,   379,   384,   389,   391,
     393,   395,   397,   401,   405,   409,   413,   417,   420,   424,
     428,   432,   436,   440,   444,   448,   452,   456,   460,   464,
     467,   470,   473,   476,   479,   483,   487,   491,   495,   499,
     503,   508,   513,   517,   518
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      80,     0,    -1,    80,    82,    70,    -1,    80,    37,    31,
      70,    -1,    82,    70,    -1,    37,    31,    70,    -1,    80,
       7,    71,    90,    72,    -1,     7,    71,    90,    72,    -1,
      12,    31,    73,    81,    74,    71,    90,    72,    -1,    80,
      12,    31,    73,    81,    74,    71,    90,    72,    -1,     1,
      -1,    81,    75,    23,    31,    -1,    81,    75,    24,    31,
      -1,    23,    31,    -1,    24,    31,    -1,    -1,    36,    31,
      71,    84,    72,    -1,    36,    31,    76,    83,    71,    84,
      72,    -1,    32,    -1,    83,    75,    32,    -1,    84,    31,
      73,    30,    75,    30,    75,    30,    75,    30,    74,    51,
      85,    70,    -1,    31,    73,    30,    75,    30,    75,    30,
      75,    30,    74,    51,    85,    70,    -1,    84,    31,    73,
      30,    75,    30,    75,    30,    75,    30,    75,    30,    74,
      51,    85,    70,    -1,    31,    73,    30,    75,    30,    75,
      30,    75,    30,    75,    30,    74,    51,    85,    70,    -1,
      77,    86,    78,    -1,    77,    88,    78,    -1,    86,    70,
      87,    -1,    87,    -1,    87,    75,    99,    -1,    99,    -1,
      88,    70,    89,    -1,    89,    -1,    89,    30,    -1,    30,
      -1,    47,    70,    -1,    90,    47,    70,    -1,    48,    70,
      -1,    90,    48,    70,    -1,    99,    70,    -1,    90,    99,
      70,    -1,     9,    99,    70,    -1,    90,     9,    99,    70,
      -1,     3,    21,    70,    -1,    90,     3,    21,    70,    -1,
       3,    99,    70,    -1,    90,     3,    99,    70,    -1,     5,
      21,    70,    -1,    90,     5,    21,    70,    -1,     5,    99,
      70,    -1,    90,     5,    99,    70,    -1,    97,    70,    -1,
      90,    97,    70,    -1,    96,    -1,    90,    96,    -1,    95,
      -1,    90,    95,    -1,    93,    -1,    90,    93,    -1,    92,
      -1,    90,    92,    -1,    24,    31,    73,    91,    74,    70,
      -1,    90,    24,    31,    73,    91,    74,    70,    -1,    91,
      75,    30,    -1,    30,    -1,    14,    71,    90,    72,    18,
      73,    99,    74,    70,    -1,    15,    73,    94,    70,    94,
      70,    94,    74,    71,    90,    72,    -1,    -1,    99,    -1,
      18,    73,    99,    74,    71,    90,    72,    -1,    16,    73,
      99,    74,    71,    90,    72,    -1,    16,    73,    99,    74,
      71,    90,    72,    17,    71,    90,    72,    -1,    32,    31,
      73,    99,    75,    99,    75,    99,    74,    -1,    32,    31,
      77,    99,    78,    73,    99,    75,    99,    75,    99,    74,
      -1,    98,    75,    99,    -1,    99,    -1,    25,    -1,    25,
      77,    98,    78,    -1,    31,    77,    98,    78,    -1,    22,
      -1,    29,    -1,    31,    -1,    30,    -1,    99,    63,    99,
      -1,    99,    62,    99,    -1,    99,    64,    99,    -1,    99,
      65,    99,    -1,    99,    66,    99,    -1,    62,    99,    -1,
      99,    69,    99,    -1,    73,    99,    74,    -1,    99,    51,
      99,    -1,    99,    57,    99,    -1,    99,    56,    99,    -1,
      99,    55,    99,    -1,    99,    54,    99,    -1,    99,    53,
      99,    -1,    99,    52,    99,    -1,    99,    43,    99,    -1,
      99,    42,    99,    -1,    44,    99,    -1,    45,    99,    -1,
      99,    45,    -1,    46,    99,    -1,    99,    46,    -1,    99,
      40,    99,    -1,    99,    41,    99,    -1,    99,    39,    99,
      -1,    99,    50,    99,    -1,    99,    49,    99,    -1,    99,
      38,    99,    -1,    34,    73,   100,    74,    -1,    31,    73,
     100,    74,    -1,    99,    75,   100,    -1,    -1,    99,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   204,   204,   205,   217,   218,   229,   231,   234,   252,
     270,   274,   281,   288,   295,   302,   309,   317,   357,   364,
     376,   383,   390,   397,   410,   412,   420,   422,   427,   429,
     437,   439,   444,   446,   454,   457,   460,   463,   466,   469,
     472,   475,   478,   481,   484,   487,   490,   493,   496,   499,
     502,   505,   508,   511,   514,   517,   520,   523,   526,   529,
     532,   535,   540,   543,   551,   568,   587,   588,   596,   615,
     628,   649,   652,   660,   663,   668,   671,   674,   677,   680,
     683,   686,   689,   692,   695,   698,   701,   704,   707,   710,
     713,   716,   719,   722,   725,   728,   731,   734,   737,   740,
     743,   746,   749,   752,   755,   758,   761,   764,   767,   770,
     773,   776,   781,   784,   786
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ECHO_", "ECHOS", "PRINT", "PRINTS",
  "EXEC", "END_", "RETURN", "EXPR", "BUILD_OBJ", "FUNCTION",
  "FUNCTION_CALL", "DO", "FOR", "IF", "ELSE", "WHILE", "END_WHILE",
  "END_FOR", "STRING", "READ", "REAL", "VECTOR", "VECTOR_ID",
  "VECTOR_ID_POS", "VECTOR_ID_ATTR", "VECTOR_POS", "VAR", "NUM", "ID",
  "CLASS_ID", "OBJ_ID", "BUILT_IN_FUNC", "NEG", "CLASS", "USE", "DIFF",
  "EQ", "LEQ", "GEQ", "OR", "AND", "NOT", "INC", "DEC", "BREAK",
  "CONTINUE", "'>'", "'<'", "'='", "POW_ATR", "MOD_ATR", "DIV_ATR",
  "MUL_ATR", "SUB_ATR", "ADD_ATR", "PRE_DEC", "POS_DEC", "PRE_INC",
  "POS_INC", "'-'", "'+'", "'*'", "'/'", "'%'", "LE", "LN", "'^'", "';'",
  "'{'", "'}'", "'('", "')'", "','", "':'", "'['", "']'", "$accept",
  "init", "list_name_args", "class_def", "class_father", "class_fields",
  "value", "matrix_expr", "list_expr", "matrix_num", "list_num",
  "cmd_interp", "dim_list", "do_while_cond", "for_cond", "for_exp",
  "while_cond", "if_else_cond", "build_yael_obj", "l_exp", "exp",
  "list_arg", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    62,
      60,    61,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,    45,    43,    42,    47,    37,   314,   315,    94,
      59,   123,   125,    40,    41,    44,    58,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    93,    94,    94,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     2,     3,     5,     4,     8,     9,
       1,     4,     4,     2,     2,     0,     5,     7,     1,     3,
      14,    13,    16,    15,     3,     3,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     3,     2,     3,     2,     3,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       6,     7,     3,     1,     9,    11,     0,     1,     7,     7,
      11,     9,    12,     3,     1,     1,     4,     4,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       4,     4,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,    78,     0,    75,    79,    81,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    56,    54,    52,     0,     0,    15,     0,     0,
       5,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,   113,     0,     0,   113,
      99,   100,   102,    34,    36,    87,     0,     0,     0,     0,
       0,     0,     0,     7,    59,    57,    55,    53,     0,     0,
      50,     0,     0,     0,     0,     0,     0,   101,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
      18,     0,     0,    15,     3,    42,    44,    46,    48,    40,
       0,     0,    67,     0,     0,     0,     0,    74,   114,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,    35,    37,    51,    39,   109,   106,   104,   105,    98,
      97,   108,   107,    90,    96,    95,    94,    93,    92,    91,
      83,    82,    84,    85,    86,    88,    13,    14,     0,     0,
       0,     0,    16,     0,     0,     6,     0,     0,    66,     0,
       0,    63,     0,     0,    76,   113,   111,    77,     0,     0,
     110,    43,    45,    47,    49,    41,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,    73,   112,     0,     0,     0,     0,    11,    12,     0,
       0,    17,     0,     0,    66,     0,     0,    60,    62,     0,
       0,     0,     8,     0,     0,     0,     0,     0,    69,    68,
       0,     0,    61,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    70,     0,     0,     0,
       0,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,    27,     0,    31,    29,    21,     0,     0,
       0,     0,    24,     0,     0,    25,    32,     0,    20,     0,
      26,    28,    33,    30,    23,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,   117,     7,   121,   119,   287,   292,   293,   294,
     295,    40,   192,    41,    42,   131,    43,    44,    45,   136,
      46,   139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -287
static const yytype_int16 yypact[] =
{
      26,  -287,   -66,   -12,    19,    27,    29,   -40,   769,    23,
      -7,    32,  -287,    40,    89,    91,    62,  -287,   106,   216,
     851,    63,    60,    65,    66,  -287,   115,    70,  -287,  -287,
      -5,   118,    81,   851,   851,   851,    85,    86,   851,   851,
     301,  -287,  -287,  -287,  -287,    87,  1337,    33,   127,   128,
    -287,   769,    90,    92,  -287,    94,  1370,    95,  1403,  1436,
     769,   851,   851,   851,    93,   851,   851,   851,    24,   851,
    1665,    79,    79,  -287,  -287,    98,  1115,   799,   825,   851,
     138,   101,   102,  -287,  -287,  -287,  -287,  -287,   103,  1469,
    -287,   851,   851,   851,   851,   851,   851,  -287,  -287,   851,
     851,   851,   851,   851,   851,   851,   851,   851,   851,   851,
     851,   851,   851,   851,  -287,   143,   145,     5,   105,   -20,
    -287,    28,   353,    33,  -287,  -287,  -287,  -287,  -287,  -287,
     405,   111,  1601,  1152,  1189,   129,   -47,  1601,   925,   109,
     -38,   851,   851,   110,  -287,   116,  1502,   117,  1535,  1568,
     112,  -287,  -287,  -287,  -287,  1697,  1697,  1697,  1697,  1633,
    1665,  1697,  1697,  1719,  1719,  1719,  1719,  1719,  1719,  1719,
     -56,   -56,     1,     1,    98,    98,  -287,  -287,   119,    82,
     159,   121,  -287,   127,   163,  -287,    35,   173,   851,   125,
     126,  -287,    39,   851,  -287,   851,  -287,  -287,   963,   891,
    -287,  -287,  -287,  -287,  -287,  -287,   129,   769,   167,   168,
     131,   170,   -17,  -287,   130,   136,   132,   769,   769,   133,
     180,  1601,  -287,   851,   139,    42,   457,  -287,  -287,   189,
     149,  -287,   769,   851,   851,   509,   561,  -287,  -287,  1001,
     851,   156,  -287,   153,   199,   613,  1226,   157,   219,  -287,
     851,  1039,  -287,   203,   176,  -287,   188,   172,   192,  1263,
     851,   184,   234,  -287,   769,   769,  -287,  1077,   235,   196,
     665,   717,   851,    44,   242,  -287,  -287,  1300,   222,   244,
      51,  -287,   198,   205,   226,   250,   877,   211,   231,   198,
     212,   -24,   -46,   213,   -36,   257,  1601,  -287,   198,   220,
     240,   851,  -287,   851,   262,  -287,  -287,   225,  -287,   198,
     213,  1601,  -287,   257,  -287,   227,  -287
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -287,  -287,   175,   290,  -287,   122,  -286,  -287,    -2,  -287,
      -4,   -25,   107,   -22,   -15,  -181,    -1,    31,    58,   241,
     -18,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -34
static const yytype_int16 yytable[] =
{
      56,    58,    59,   299,   143,     8,   -33,   216,   110,   111,
     112,   181,   307,   113,   181,    70,    71,    72,    84,     9,
      75,    76,    89,   315,   301,    85,   122,     1,   193,    12,
      17,   194,   302,     2,   304,   130,    13,   193,     3,    86,
     197,    14,   305,   132,   133,   134,   -33,   137,   138,   137,
      10,   138,   182,   247,   -33,   231,   115,   116,    11,   146,
     148,   149,     4,     5,    48,     4,    15,   112,    66,    49,
     113,    87,    67,   155,   156,   157,   158,   159,   160,   178,
     179,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    47,   141,    88,   183,
      84,   142,    50,   184,    89,   208,   209,    85,    84,   214,
     179,    51,    89,   219,   220,    85,   241,   220,   278,   279,
      52,    86,    53,   198,   199,   284,   285,    55,    25,    86,
     222,    27,    54,    61,    60,    28,    29,    30,    62,    63,
      32,   108,   109,   110,   111,   112,    64,    65,   113,    68,
      33,    34,    35,    87,    69,    73,    74,    90,   118,   191,
     120,    87,   124,   123,   125,   127,   135,   113,    38,   150,
     132,   151,   152,   153,   176,   221,   177,   138,   180,    39,
      88,   188,   226,   196,   200,   206,   201,   203,    88,   210,
     207,   215,   235,   236,   211,   213,   217,   218,   227,   228,
     230,   232,   234,   237,    84,   239,   229,   245,    89,   233,
     238,    85,   240,    84,    84,   246,   132,    89,    89,   243,
      85,    85,   251,    84,   244,    86,   252,    89,   253,   254,
      85,   257,   259,   261,    86,    86,   258,    57,    25,   270,
     271,    27,   267,   264,    86,    28,    29,    30,    84,    84,
      32,   262,    89,    89,   277,    85,    85,    87,   263,   268,
      33,    34,    35,   265,   269,   273,    87,    87,   296,    86,
      86,   274,   280,   282,   283,   286,    87,   289,    38,   288,
     290,   297,   298,   296,    88,   311,   300,   306,   303,    39,
     308,   309,   312,    88,    88,   314,    16,   316,   186,   310,
     313,    87,    87,    88,    77,   212,    78,     0,   140,     0,
      79,     0,     0,   225,     0,    21,    22,    23,     0,    24,
       0,     0,     0,    25,     0,    80,    27,     0,    88,    88,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    81,    82,
       0,     0,     0,     0,     0,     0,    77,     0,    78,     0,
       0,     0,    79,    38,     0,     0,     0,    21,    22,    23,
       0,    24,     0,    83,    39,    25,     0,    80,    27,     0,
       0,     0,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      81,    82,     0,     0,     0,     0,     0,     0,    77,     0,
      78,     0,     0,     0,    79,    38,     0,     0,     0,    21,
      22,    23,     0,    24,     0,   185,    39,    25,     0,    80,
      27,     0,     0,     0,    28,    29,    30,    31,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    81,    82,     0,     0,     0,     0,     0,     0,
      77,     0,    78,     0,     0,     0,    79,    38,     0,     0,
       0,    21,    22,    23,     0,    24,     0,   187,    39,    25,
       0,    80,    27,     0,     0,     0,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    81,    82,     0,     0,     0,     0,
       0,     0,    77,     0,    78,     0,     0,     0,    79,    38,
       0,     0,     0,    21,    22,    23,     0,    24,     0,   242,
      39,    25,     0,    80,    27,     0,     0,     0,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    81,    82,     0,     0,
       0,     0,     0,     0,    77,     0,    78,     0,     0,     0,
      79,    38,     0,     0,     0,    21,    22,    23,     0,    24,
       0,   248,    39,    25,     0,    80,    27,     0,     0,     0,
      28,    29,    30,    31,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    81,    82,
       0,     0,     0,     0,     0,     0,    77,     0,    78,     0,
       0,     0,    79,    38,     0,     0,     0,    21,    22,    23,
       0,    24,     0,   249,    39,    25,     0,    80,    27,     0,
       0,     0,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      81,    82,     0,     0,     0,     0,     0,     0,    77,     0,
      78,     0,     0,     0,    79,    38,     0,     0,     0,    21,
      22,    23,     0,    24,     0,   255,    39,    25,     0,    80,
      27,     0,     0,     0,    28,    29,    30,    31,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    81,    82,     0,     0,     0,     0,     0,     0,
      77,     0,    78,     0,     0,     0,    79,    38,     0,     0,
       0,    21,    22,    23,     0,    24,     0,   275,    39,    25,
       0,    80,    27,     0,     0,     0,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    81,    82,     0,     0,     0,     0,
       0,     0,    18,     0,    19,     0,     0,     0,    20,    38,
       0,     0,     0,    21,    22,    23,     0,    24,     0,   276,
      39,    25,     0,    26,    27,     0,     0,     0,    28,    29,
      30,    31,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,    36,    37,     0,     0,
     145,    25,     0,     0,    27,     0,     0,     0,    28,    29,
      30,    38,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    33,    34,    35,   147,    25,     0,     0,
      27,     0,     0,     0,    28,    29,    30,     0,     0,    32,
       0,    38,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    35,    39,    25,     0,     0,    27,     0,     0,     0,
      28,    29,    30,     0,     0,    32,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    33,    34,    35,    39,    25,
       0,     0,    27,     0,     0,     0,    28,   291,    30,     0,
       0,    32,     0,    38,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    39,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,     0,    97,    98,     0,    38,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
      39,     0,     0,   108,   109,   110,   111,   112,     0,     0,
     113,     0,     0,    91,    92,    93,    94,    95,    96,   224,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,     0,     0,   113,     0,     0,     0,     0,     0,
     195,    91,    92,    93,    94,    95,    96,     0,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
       0,     0,   113,     0,     0,     0,     0,     0,   223,    91,
      92,    93,    94,    95,    96,     0,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,     0,     0,
     113,     0,     0,     0,     0,     0,   250,    91,    92,    93,
      94,    95,    96,     0,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,     0,     0,   113,     0,
       0,     0,     0,     0,   260,    91,    92,    93,    94,    95,
      96,     0,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,     0,     0,   113,     0,     0,     0,
       0,     0,   272,    91,    92,    93,    94,    95,    96,     0,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,     0,     0,   113,     0,     0,     0,     0,   144,
      91,    92,    93,    94,    95,    96,     0,    97,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,     0,
       0,   113,     0,     0,     0,     0,   189,    91,    92,    93,
      94,    95,    96,     0,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,     0,     0,   113,     0,
       0,     0,     0,   190,    91,    92,    93,    94,    95,    96,
       0,    97,    98,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,     0,     0,   113,     0,     0,     0,     0,
     256,    91,    92,    93,    94,    95,    96,     0,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
       0,     0,   113,     0,     0,     0,     0,   266,    91,    92,
      93,    94,    95,    96,     0,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,     0,     0,   113,
       0,     0,     0,     0,   281,    91,    92,    93,    94,    95,
      96,     0,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,     0,     0,   113,   114,    91,    92,
      93,    94,    95,    96,     0,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,     0,     0,   113,
     126,    91,    92,    93,    94,    95,    96,     0,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
       0,     0,   113,   128,    91,    92,    93,    94,    95,    96,
       0,    97,    98,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,     0,     0,   113,   129,    91,    92,    93,
      94,    95,    96,     0,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,     0,     0,   113,   154,
      91,    92,    93,    94,    95,    96,     0,    97,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,     0,
       0,   113,   202,    91,    92,    93,    94,    95,    96,     0,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,     0,     0,   113,   204,    91,    92,    93,    94,
      95,    96,     0,    97,    98,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,     0,     0,   113,   205,    91,
      92,    93,    94,    95,    96,     0,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,     0,     0,
     113,    91,    92,    93,    94,     0,    96,     0,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
       0,     0,   113,    91,    92,    93,    94,     0,     0,     0,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,     0,     0,   113,   -34,   -34,   -34,   -34,     0,
       0,     0,    97,    98,     0,     0,   -34,   -34,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,    97,    98,   113,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,     0,     0,   113
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-287))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-34))

static const yytype_int16 yycheck[] =
{
      18,    19,    20,   289,    69,    71,    30,   188,    64,    65,
      66,    31,   298,    69,    31,    33,    34,    35,    40,    31,
      38,    39,    40,   309,    70,    40,    51,     1,    75,     0,
      70,    78,    78,     7,    70,    60,     7,    75,    12,    40,
      78,    12,    78,    61,    62,    63,    70,    65,    66,    67,
      31,    69,    72,   234,    78,    72,    23,    24,    31,    77,
      78,    79,    36,    37,    71,    36,    37,    66,    73,    76,
      69,    40,    77,    91,    92,    93,    94,    95,    96,    74,
      75,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    73,    73,    40,    71,
     122,    77,    70,    75,   122,    23,    24,   122,   130,    74,
      75,    71,   130,    74,    75,   130,    74,    75,    74,    75,
      31,   122,    31,   141,   142,    74,    75,    21,    22,   130,
     195,    25,    70,    73,    71,    29,    30,    31,    73,    73,
      34,    62,    63,    64,    65,    66,    31,    77,    69,    31,
      44,    45,    46,   122,    73,    70,    70,    70,    31,    30,
      32,   130,    70,    73,    70,    70,    73,    69,    62,    31,
     188,    70,    70,    70,    31,   193,    31,   195,    73,    73,
     122,    70,   207,    74,    74,    73,    70,    70,   130,    30,
      71,    18,   217,   218,    73,    32,    71,    71,    31,    31,
      30,    71,    70,    70,   226,   223,    75,   232,   226,    73,
      30,   226,    73,   235,   236,   233,   234,   235,   236,    30,
     235,   236,   240,   245,    75,   226,    70,   245,    75,    30,
     245,    74,   250,    30,   235,   236,    17,    21,    22,   264,
     265,    25,   260,    71,   245,    29,    30,    31,   270,   271,
      34,    75,   270,   271,   272,   270,   271,   226,    70,    75,
      44,    45,    46,    71,    30,    30,   235,   236,   286,   270,
     271,    75,    30,    51,    30,    77,   245,    51,    62,    74,
      30,    70,    51,   301,   226,   303,    74,    30,    75,    73,
      70,    51,    30,   235,   236,    70,     6,    70,   123,   301,
     304,   270,   271,   245,     3,   183,     5,    -1,    67,    -1,
       9,    -1,    -1,   206,    -1,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    25,    -1,   270,   271,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,     9,    62,    -1,    -1,    -1,    14,    15,    16,
      -1,    18,    -1,    72,    73,    22,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,     9,    62,    -1,    -1,    -1,    14,
      15,    16,    -1,    18,    -1,    72,    73,    22,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,    -1,    -1,     9,    62,    -1,    -1,
      -1,    14,    15,    16,    -1,    18,    -1,    72,    73,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,    -1,    -1,    -1,     9,    62,
      -1,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    72,
      73,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,    -1,    -1,    -1,
       9,    62,    -1,    -1,    -1,    14,    15,    16,    -1,    18,
      -1,    72,    73,    22,    -1,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,     9,    62,    -1,    -1,    -1,    14,    15,    16,
      -1,    18,    -1,    72,    73,    22,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,     9,    62,    -1,    -1,    -1,    14,
      15,    16,    -1,    18,    -1,    72,    73,    22,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,    -1,    -1,     9,    62,    -1,    -1,
      -1,    14,    15,    16,    -1,    18,    -1,    72,    73,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,    -1,    -1,    -1,     9,    62,
      -1,    -1,    -1,    14,    15,    16,    -1,    18,    -1,    72,
      73,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,    62,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    44,    45,    46,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    73,    22,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    73,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    73,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    -1,    62,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      73,    -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      69,    -1,    -1,    38,    39,    40,    41,    42,    43,    78,
      45,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      75,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    69,    -1,    -1,    -1,    -1,    74,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    74,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      74,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    74,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    74,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    69,    70,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,    69,
      70,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    69,    70,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    69,    70,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    -1,    -1,    69,    70,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      69,    38,    39,    40,    41,    -1,    43,    -1,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    38,    39,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    69,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    45,    46,    69,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    12,    36,    37,    80,    82,    71,    31,
      31,    31,     0,     7,    12,    37,    82,    70,     3,     5,
       9,    14,    15,    16,    18,    22,    24,    25,    29,    30,
      31,    32,    34,    44,    45,    46,    47,    48,    62,    73,
      90,    92,    93,    95,    96,    97,    99,    73,    71,    76,
      70,    71,    31,    31,    70,    21,    99,    21,    99,    99,
      71,    73,    73,    73,    31,    77,    73,    77,    31,    73,
      99,    99,    99,    70,    70,    99,    99,     3,     5,     9,
      24,    47,    48,    72,    92,    93,    95,    96,    97,    99,
      70,    38,    39,    40,    41,    42,    43,    45,    46,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    62,    63,
      64,    65,    66,    69,    70,    23,    24,    81,    31,    84,
      32,    83,    90,    73,    70,    70,    70,    70,    70,    70,
      90,    94,    99,    99,    99,    73,    98,    99,    99,   100,
      98,    73,    77,   100,    74,    21,    99,    21,    99,    99,
      31,    70,    70,    70,    70,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    31,    31,    74,    75,
      73,    31,    72,    71,    75,    72,    81,    72,    70,    74,
      74,    30,    91,    75,    78,    75,    74,    78,    99,    99,
      74,    70,    70,    70,    70,    70,    73,    71,    23,    24,
      30,    73,    84,    32,    74,    18,    94,    71,    71,    74,
      75,    99,   100,    75,    78,    91,    90,    31,    31,    75,
      30,    72,    71,    73,    70,    90,    90,    70,    30,    99,
      73,    74,    72,    30,    75,    90,    99,    94,    72,    72,
      75,    99,    70,    75,    30,    72,    74,    74,    17,    99,
      75,    30,    75,    70,    71,    71,    74,    99,    75,    30,
      90,    90,    75,    30,    75,    72,    72,    99,    74,    75,
      30,    74,    51,    30,    74,    75,    77,    85,    74,    51,
      30,    30,    86,    87,    88,    89,    99,    70,    51,    85,
      74,    70,    78,    75,    70,    78,    30,    85,    70,    51,
      87,    99,    30,    89,    70,    85,    70
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  *++yyvsp = yylval;

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
        case 3:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    { 
	if(nerrors==0){
		printf("Usando: %s\n",(yyvsp[(3) - (4)].str)->c_str()); 
		fprintf(plog,"Usando: %s\n",(yyvsp[(3) - (4)].str)->c_str()); 

		//printf("size= %d\n",yaelClass.size());
		loadFile((*(yyvsp[(3) - (4)].str)+".mo").c_str(),yaelClass,isclass,yaelObj,isobj,__path);
		//printf("size= %d\n",yaelClass.size());
		delete (yyvsp[(3) - (4)].str); 
	}
}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    { 
	if(nerrors==0){
		printf("Usando: %s\n",(yyvsp[(2) - (3)].str)->c_str());
		fprintf(plog,"Usando: %s\n",(yyvsp[(2) - (3)].str)->c_str());	
		//printf("size= %d\n",yaelClass.size());
		loadFile((*(yyvsp[(2) - (3)].str)+".mo").c_str(),yaelClass,isclass,yaelObj,isobj,__path); 
		//printf("size= %d\n",yaelClass.size());
		delete (yyvsp[(2) - (3)].str); 
	}
}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    {  if(nerrors==0){ interp((yyvsp[(4) - (5)].itk)); } vect_l.clear(); isvect.clear(); isvar.clear(); var.clear(); delete (yyvsp[(4) - (5)].itk);  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 232 "parser.y"
    {  if(nerrors==0){ interp((yyvsp[(3) - (4)].itk)); } vect_l.clear(); isvect.clear(); isvar.clear(); var.clear(); delete (yyvsp[(3) - (4)].itk);  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    {
	function* f;
		
	f=&function_l[*(yyvsp[(2) - (8)].str)];
	f->rt=0;
	f->narg=(yyvsp[(4) - (8)].fa)->first->size();
	f->args_name=(yyvsp[(4) - (8)].fa)->first;
	f->args_t=(yyvsp[(4) - (8)].fa)->second;
	f->var=var;
	f->vect_l=vect_l;
	f->f=(yyvsp[(7) - (8)].itk);
	isfunction[*(yyvsp[(2) - (8)].str)]=true;
		
	delete (yyvsp[(2) - (8)].str); delete (yyvsp[(4) - (8)].fa);
	var.clear(); isvar.clear(); vect_l.clear(); isvect.clear();
}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    {
	function* f;

	f=&function_l[*(yyvsp[(3) - (9)].str)];
	f->rt=0;
	f->narg=(yyvsp[(5) - (9)].fa)->first->size();
	f->args_name=(yyvsp[(5) - (9)].fa)->first;
	f->args_t=(yyvsp[(5) - (9)].fa)->second;
	f->var=var;
	f->vect_l=vect_l;
	f->f=(yyvsp[(8) - (9)].itk);
	isfunction[*(yyvsp[(3) - (9)].str)]=true;

	delete (yyvsp[(3) - (9)].str); delete (yyvsp[(5) - (9)].fa);
	var.clear(); isvar.clear(); vect_l.clear(); isvect.clear();
}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    { }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    {
	(yyval.fa)=(yyvsp[(1) - (4)].fa); 
	(yyval.fa)->first->push_back(*(yyvsp[(4) - (4)].str)); delete (yyvsp[(4) - (4)].str);
	(yyval.fa)->second->push_back(0);
}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    {
	(yyval.fa)=(yyvsp[(1) - (4)].fa); 
	(yyval.fa)->first->push_back(*(yyvsp[(4) - (4)].str)); delete (yyvsp[(4) - (4)].str);
	(yyval.fa)->second->push_back(1);
}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 289 "parser.y"
    {
	(yyval.fa)=new func_arg(); (yyval.fa)->first=new vs();  (yyval.fa)->second=new vi(); 
	(yyval.fa)->first->push_back(*(yyvsp[(2) - (2)].str)); delete (yyvsp[(2) - (2)].str);
	(yyval.fa)->second->push_back(0);
}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 296 "parser.y"
    {
	(yyval.fa)=new func_arg(); (yyval.fa)->first=new vs();  (yyval.fa)->second=new vi(); 
	(yyval.fa)->first->push_back(*(yyvsp[(2) - (2)].str)); delete (yyvsp[(2) - (2)].str);
	(yyval.fa)->second->push_back(1);
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 302 "parser.y"
    {  (yyval.fa)=new func_arg(); (yyval.fa)->first=new vs();  (yyval.fa)->second=new vi();  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 310 "parser.y"
    { 
	isclass[*(yyvsp[(2) - (5)].str)]=true;
	yaelClass[*(yyvsp[(2) - (5)].str)].add_fields((yyvsp[(4) - (5)].sf)->first,(yyvsp[(4) - (5)].sf)->second);
	delete (yyvsp[(2) - (5)].str);  
	delete (yyvsp[(4) - (5)].sf);
}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 318 "parser.y"
    { 
	isclass[*(yyvsp[(2) - (7)].str)]=true;
	yaelClass[*(yyvsp[(2) - (7)].str)].add_fields((yyvsp[(6) - (7)].sf)->first,(yyvsp[(6) - (7)].sf)->second);
	
	delete (yyvsp[(6) - (7)].sf);
	
	/*Adiciona campos herdados*/
	sclass* p=&yaelClass[*(yyvsp[(2) - (7)].str)];
	for(int i=0;i<(yyvsp[(4) - (7)].vS)->size();i++){
		sclass* c;
		map<string,pair<Matrix*,sf*> >::iterator it;
		
		c=&yaelClass[(*(yyvsp[(4) - (7)].vS))[i]];
		it=c->field.begin();
		
		for(;it!=c->field.end();it++){
			pair<Matrix*,sf*>* it2;
			Matrix* m;
			
			it2=&p->field[it->first];
			(*it2).second=it->second.second;
			m=it->second.first;
			
			if(it2->first==0) it2->first=new Matrix();
			
			for(int k=0;k<m->size();k++){	
				it2->first->push_back((*m)[k]);
			}
		}
	}
	delete (yyvsp[(4) - (7)].vS);
	delete (yyvsp[(2) - (7)].str);  
}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 358 "parser.y"
    {
	(yyval.vS)=new vs();
	(yyval.vS)->push_back(*(yyvsp[(1) - (1)].str));
	delete (yyvsp[(1) - (1)].str);
}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 365 "parser.y"
    {
	(yyval.vS)=(yyvsp[(1) - (3)].vS);
	(yyval.vS)->push_back(*(yyvsp[(3) - (3)].str));
	delete (yyvsp[(3) - (3)].str);
}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 377 "parser.y"
    { 
	(yyvsp[(1) - (14)].sf)->first.push_back(*(yyvsp[(2) - (14)].str)); 
	delete (yyvsp[(2) - (14)].str); 
	(yyvsp[(1) - (14)].sf)->second.push_back(pair<Matrix*,sf*> ((yyvsp[(13) - (14)].valM), new sf((int)((yyvsp[(4) - (14)].val)),(int)((yyvsp[(6) - (14)].val)),(int)((yyvsp[(8) - (14)].val)),(int)((yyvsp[(10) - (14)].val))) ));
	(yyval.sf)=(yyvsp[(1) - (14)].sf);
}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 384 "parser.y"
    { 
	(yyval.sf)=new sfields();
	(yyval.sf)->first.push_back(*(yyvsp[(1) - (13)].str)); 
	delete (yyvsp[(1) - (13)].str); 
	(yyval.sf)->second.push_back(pair<Matrix*,sf*> ((yyvsp[(12) - (13)].valM), new sf((int)((yyvsp[(3) - (13)].val)),(int)((yyvsp[(5) - (13)].val)),(int)((yyvsp[(7) - (13)].val)),(int)((yyvsp[(9) - (13)].val))) )); 
}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 391 "parser.y"
    { 
	(yyvsp[(1) - (16)].sf)->first.push_back(*(yyvsp[(2) - (16)].str)); 
	delete (yyvsp[(2) - (16)].str); 
	(yyvsp[(1) - (16)].sf)->second.push_back(pair<Matrix*,sf*> ((yyvsp[(15) - (16)].valM), new sf((int)((yyvsp[(4) - (16)].val)),(int)((yyvsp[(6) - (16)].val)),(int)((yyvsp[(8) - (16)].val)),(int)((yyvsp[(10) - (16)].val)),(int)(yyvsp[(12) - (16)].val)) ));
	(yyval.sf)=(yyvsp[(1) - (16)].sf);
}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 398 "parser.y"
    { 
	(yyval.sf)=new sfields();
	(yyval.sf)->first.push_back(*(yyvsp[(1) - (15)].str)); 
	delete (yyvsp[(1) - (15)].str); 
	(yyval.sf)->second.push_back(pair<Matrix*,sf*> ((yyvsp[(14) - (15)].valM), new sf((int)((yyvsp[(3) - (15)].val)),(int)((yyvsp[(5) - (15)].val)),(int)((yyvsp[(7) - (15)].val)),(int)((yyvsp[(9) - (15)].val)),(int)((yyvsp[(11) - (15)].val))) )); 
}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 411 "parser.y"
    { (yyval.valM)=(yyvsp[(2) - (3)].valM); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 413 "parser.y"
    {  (yyval.valM)=(yyvsp[(2) - (3)].valM); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 421 "parser.y"
    { (yyvsp[(1) - (3)].valM)->push_back((yyvsp[(3) - (3)].valV)); (yyval.valM)=(yyvsp[(1) - (3)].valM); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 423 "parser.y"
    { (yyval.valM)=new Matrix(); (yyval.valM)->push_back((yyvsp[(1) - (1)].valV));}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 428 "parser.y"
    {(yyvsp[(1) - (3)].valV)->push_back(eval((yyvsp[(3) - (3)].tk))); (yyval.valV)=(yyvsp[(1) - (3)].valV); delete (yyvsp[(3) - (3)].tk);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    { (yyval.valV)=new Vector(); (yyval.valV)->push_back(eval((yyvsp[(1) - (1)].tk))); delete (yyvsp[(1) - (1)].tk); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 438 "parser.y"
    { (yyvsp[(1) - (3)].valM)->push_back((yyvsp[(3) - (3)].valV)); (yyval.valM)=(yyvsp[(1) - (3)].valM); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 440 "parser.y"
    { (yyval.valM)=new Matrix(); (yyval.valM)->push_back((yyvsp[(1) - (1)].valV)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 445 "parser.y"
    {  (yyvsp[(1) - (2)].valV)->push_back((yyvsp[(2) - (2)].val)); (yyval.valV)=(yyvsp[(1) - (2)].valV); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 447 "parser.y"
    {  (yyval.valV)=new Vector(); (yyval.valV)->push_back((yyvsp[(1) - (1)].val)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 455 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(BREAK));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 458 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (3)].itk); (yyval.itk)->push_back(iToken(BREAK)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 461 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(CONTINUE));}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 464 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (3)].itk); (yyval.itk)->push_back(iToken(CONTINUE)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 467 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(EXPR,(yyvsp[(1) - (2)].tk)));}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 470 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (3)].itk); (yyval.itk)->push_back(iToken(EXPR,(yyvsp[(2) - (3)].tk))); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 473 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(RETURN,(yyvsp[(2) - (3)].tk)));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 476 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (4)].itk); (yyval.itk)->push_back(iToken(RETURN,(yyvsp[(3) - (4)].tk))); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 479 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(ECHOS,(yyvsp[(2) - (3)].str))); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 482 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (4)].itk); (yyval.itk)->push_back(iToken(ECHOS,(yyvsp[(3) - (4)].str))); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 485 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(ECHO_,(yyvsp[(2) - (3)].tk))); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 488 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (4)].itk); (yyval.itk)->push_back(iToken(ECHO_,(yyvsp[(3) - (4)].tk))); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 491 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(PRINTS,(yyvsp[(2) - (3)].str))); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 494 "parser.y"
    { 	(yyval.itk)=(yyvsp[(1) - (4)].itk); (yyval.itk)->push_back(iToken(PRINTS,(yyvsp[(3) - (4)].str))); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 497 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(PRINT,(yyvsp[(2) - (3)].tk)));}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 500 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (4)].itk); (yyval.itk)->push_back(iToken(PRINT,(yyvsp[(3) - (4)].tk))); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 503 "parser.y"
    { (yyval.itk)=new iTokens(); (yyval.itk)->push_back(iToken(BUILD_OBJ,(yyvsp[(1) - (2)].bobj))); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 506 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (3)].itk); (yyval.itk)->push_back(iToken(BUILD_OBJ,(yyvsp[(2) - (3)].bobj))); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 509 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (1)].itk); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 512 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (2)].itk); append((yyval.itk),(yyvsp[(2) - (2)].itk)); delete (yyvsp[(2) - (2)].itk); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 515 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (1)].itk); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 518 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (2)].itk); append((yyval.itk),(yyvsp[(2) - (2)].itk)); delete (yyvsp[(2) - (2)].itk); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 521 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (1)].itk); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 524 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (2)].itk); append((yyval.itk),(yyvsp[(2) - (2)].itk)); delete (yyvsp[(2) - (2)].itk); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 527 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (1)].itk); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 530 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (2)].itk); append((yyval.itk),(yyvsp[(2) - (2)].itk)); delete (yyvsp[(2) - (2)].itk); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 533 "parser.y"
    { (yyval.itk)=new iTokens(); isvect[*(yyvsp[(2) - (6)].str)]=true; vect_l[*(yyvsp[(2) - (6)].str)]=vect((yyvsp[(4) - (6)].vI));  delete (yyvsp[(2) - (6)].str); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 536 "parser.y"
    { (yyval.itk)=(yyvsp[(1) - (7)].itk); isvect[*(yyvsp[(3) - (7)].str)]=true; vect_l[*(yyvsp[(3) - (7)].str)]=vect((yyvsp[(5) - (7)].vI));  delete (yyvsp[(3) - (7)].str); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 541 "parser.y"
    { (yyval.vI)=(yyvsp[(1) - (3)].vI); (yyval.vI)->push_back((int)((yyvsp[(3) - (3)].val))); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 544 "parser.y"
    { (yyval.vI)=new vi(); (yyval.vI)->push_back((int)((yyvsp[(1) - (1)].val))); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 552 "parser.y"
    {
	(yyval.itk)=(yyvsp[(3) - (9)].itk);
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=(yyvsp[(7) - (9)].tk);
	while_->false_next=1;
	
	(yyval.itk)->push_back(iToken(WHILE,while_));
	(*(yyval.itk))[(yyval.itk)->size()-1].next=-((int)((yyvsp[(3) - (9)].itk)->size()-1));
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 569 "parser.y"
    {
	(yyval.itk)=new iTokens();
	(yyval.itk)->push_back(iToken(EXPR,(yyvsp[(3) - (11)].tk)));
	(yyvsp[(10) - (11)].itk)->push_back(iToken(EXPR,(yyvsp[(7) - (11)].tk)));
	
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=(yyvsp[(5) - (11)].tk);
	while_->false_next=2+(yyvsp[(10) - (11)].itk)->size();
	(yyval.itk)->push_back(iToken(WHILE,while_));
	(yyvsp[(10) - (11)].itk)->push_back( iToken(END_FOR,-((int)(yyvsp[(10) - (11)].itk)->size() + 1 )) );
	append((yyval.itk),(yyvsp[(10) - (11)].itk));
	
	delete (yyvsp[(10) - (11)].itk);
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 587 "parser.y"
    {(yyval.tk)=new Tokens(); (yyval.tk)->push_back(Token(NUM,1.0));}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 589 "parser.y"
    {(yyval.tk)=(yyvsp[(1) - (1)].tk);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 597 "parser.y"
    {
	(yyval.itk)=new iTokens();
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=(yyvsp[(3) - (7)].tk);
	while_->false_next=2+(yyvsp[(6) - (7)].itk)->size();
	(yyval.itk)->push_back(iToken(WHILE,while_));
	(yyvsp[(6) - (7)].itk)->push_back(iToken(END_WHILE,-((int)(yyvsp[(6) - (7)].itk)->size() + 1 )));
	append((yyval.itk),(yyvsp[(6) - (7)].itk));
	
	delete (yyvsp[(6) - (7)].itk);
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 616 "parser.y"
    { 
	(yyval.itk)=new iTokens(); 
	if_else_ctrl* ifelse=new if_else_ctrl();
	
	ifelse->expr=(yyvsp[(3) - (7)].tk);
	ifelse->false_next=1+(yyvsp[(6) - (7)].itk)->size();
	(yyval.itk)->push_back(iToken(IF,ifelse));
	append((yyval.itk),(yyvsp[(6) - (7)].itk));
	
	delete (yyvsp[(6) - (7)].itk);
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 629 "parser.y"
    { 
	(yyval.itk)=new iTokens(); 
	if_else_ctrl* ifelse=new if_else_ctrl();
	
	ifelse->expr=(yyvsp[(3) - (11)].tk);
	ifelse->false_next=1+(yyvsp[(6) - (11)].itk)->size();
	(yyval.itk)->push_back(iToken(IF,ifelse)); 
	append((yyval.itk),(yyvsp[(6) - (11)].itk));
	
	(*(yyval.itk))[(yyval.itk)->size()-1].next=1+(yyvsp[(10) - (11)].itk)->size();
	append((yyval.itk),(yyvsp[(10) - (11)].itk));
	
	delete (yyvsp[(6) - (11)].itk); delete (yyvsp[(10) - (11)].itk);
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 650 "parser.y"
    { (yyval.bobj)=new build_obj((yyvsp[(1) - (9)].str),(yyvsp[(2) - (9)].str),(yyvsp[(4) - (9)].tk),(yyvsp[(6) - (9)].tk),(yyvsp[(8) - (9)].tk)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 653 "parser.y"
    { (yyval.bobj)=new build_obj((yyvsp[(1) - (12)].str),(yyvsp[(2) - (12)].str),(yyvsp[(7) - (12)].tk),(yyvsp[(9) - (12)].tk),(yyvsp[(11) - (12)].tk),true,(yyvsp[(4) - (12)].tk)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 661 "parser.y"
    {(yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 664 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (1)].tk); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 669 "parser.y"
    { (yyval.tk)=new Tokens(); (yyval.tk)->push_back(Token(VECTOR_ID,(yyvsp[(1) - (1)].str)));}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 672 "parser.y"
    { (yyval.tk)=(yyvsp[(3) - (4)].tk); (yyval.tk)->push_back(Token(VECTOR_ID_POS,new vect_pos((yyvsp[(1) - (4)].str),0))); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 675 "parser.y"
    { (yyval.tk)=(yyvsp[(3) - (4)].tk); (yyval.tk)->push_back(Token(VECTOR_ID_POS,new vect_pos((yyvsp[(1) - (4)].str),0))); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 678 "parser.y"
    { (yyval.tk)=new Tokens(); (yyval.tk)->push_back(Token(READ,0)); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 681 "parser.y"
    { (yyval.tk)=new Tokens(); (yyval.tk)->push_back(Token(VAR,(yyvsp[(1) - (1)].str))); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 684 "parser.y"
    { (yyval.tk)=new Tokens(); (yyval.tk)->push_back(Token(ID,(yyvsp[(1) - (1)].str))); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 687 "parser.y"
    { (yyval.tk) = new Tokens(); (yyval.tk)->push_back(Token(NUM,(yyvsp[(1) - (1)].val)));}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 690 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('+',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 693 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('-',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 696 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('*',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 699 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('/',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 702 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('%',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 705 "parser.y"
    { (yyval.tk) = (yyvsp[(2) - (2)].tk); (yyval.tk)->push_back(Token(NEG,1)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 708 "parser.y"
    { (yyval.tk) = (yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('^',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 711 "parser.y"
    { (yyval.tk) = (yyvsp[(2) - (3)].tk); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 714 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('=',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 717 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(ADD_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 720 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(SUB_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 723 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(MUL_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 726 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(DIV_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 729 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(MOD_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 732 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(POW_ATR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 735 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(AND,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 738 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(OR,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 741 "parser.y"
    { (yyval.tk) = (yyvsp[(2) - (2)].tk); (yyval.tk)->push_back(Token(NOT,1)); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 744 "parser.y"
    { (yyval.tk)=(yyvsp[(2) - (2)].tk); (yyval.tk)->push_back(Token(PRE_INC,1));}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 747 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (2)].tk); (yyval.tk)->push_back(Token(POS_INC,1)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 750 "parser.y"
    { (yyval.tk)=(yyvsp[(2) - (2)].tk); (yyval.tk)->push_back(Token(PRE_DEC,1)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 753 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (2)].tk); (yyval.tk)->push_back(Token(POS_DEC,1)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 756 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(LEQ,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 759 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(GEQ,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 762 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(EQ,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 765 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('<',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 768 "parser.y"
    {  (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token('>',2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 771 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk)); (yyval.tk)->push_back(Token(DIFF,2)); delete (yyvsp[(3) - (3)].tk); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 774 "parser.y"
    { (yyval.tk)=(yyvsp[(3) - (4)].tk); (yyval.tk)->push_back(Token(func_id[*(yyvsp[(1) - (4)].str)],func_narg[*(yyvsp[(1) - (4)].str)])); delete (yyvsp[(1) - (4)].str); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 777 "parser.y"
    { (yyval.tk)=(yyvsp[(3) - (4)].tk); (yyval.tk)->push_back(Token(FUNCTION_CALL,(yyvsp[(1) - (4)].str))); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 782 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (3)].tk); append((yyval.tk),(yyvsp[(3) - (3)].tk));}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 784 "parser.y"
    { (yyval.tk)=new Tokens(); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 787 "parser.y"
    { (yyval.tk)=(yyvsp[(1) - (1)].tk); }
    break;



/* Line 1806 of yacc.c  */
#line 3031 "parser.tab.c"
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 790 "parser.y"


#include "lex.yy.c"

#include "yael_function_list.h"
#include "yael_eval.cpp"
#include "yael_interp.cpp"

char* __yy_file_name;

void
yyerror (char const *s)
{
	fprintf (stderr, "%s:%d: %s\n", __yy_file_name,nlines, s);
	fprintf (plog, "%s:%d: %s\n", __yy_file_name,nlines, s);
	nerrors++;
}

void init(){
	nlines=1; nerrors=0;
	//setOutput("yael_out");
	plog=fopen((__path+"/yael_log").c_str(),"w+");
	pout=fopen((__path+"/yael_out").c_str(),"w+");
}

int main(int argc, char** argv )
{
	++argv, --argc; 
	if(argc<1){
		printf("Formato do comando: %s  <file_in>\n",argv[-1]);
		printf("<file_in> = 1 arquivo de entrada\n");
		return 0;
	}
	srand(time(NULL));
	init_main();
	
	string file_in("");
	
	for(int i=0;i<argc;i++){ if(i>0) file_in+=string(" "); file_in+=argv[i]; }
	
	FILE* f=fopen( file_in.c_str(), "r" );
	if(!f){
		printf("Falha ao abrir:%s %s\n",file_in.c_str(),argv[0]);
		return -1;
	}
	
	__yy_file_name=(char*)malloc((file_in.size()+1)*sizeof(char));
	for(int i=0;i<file_in.size();i++) __yy_file_name[i]=file_in[i];
	__yy_file_name[file_in.size()]=0;
	
	int p, l;
		
	__path="";
	for(l=file_in.size()-1;l>-1&&(file_in[l]!='/'&&file_in[l]!='\\');l--);
	for(int k=0;k<file_in.size()&&k<l;k++) __path+=file_in[k];
	//__path+="/";
	printf("Caminho:%s\n",__path.c_str());
	
	yyin = f;
	init();
	yyparse();
	
	string out("");
		
	if(nerrors==0){
		int len=file_in.size();
		
		for(p=len-1;p>-1 && file_in[p]!='.';p--);
		
		for(int k=0;k<file_in.size()&& k<p;k++) out+=file_in[k];
		out+=".mo";
		
		saveFile(out.c_str(),yaelClass,yaelObj);
		fprintf (stderr,"Script compilado com sucesso!\n");
		fprintf (plog, "Script compilado com sucesso!\n");
	}else{
		fprintf (stderr, "%s: Foram encontrados %d erros sint�ticos\n", __yy_file_name,nerrors);
		fprintf (plog, "%s: Foram encontrados %d erros sint�ticos\n", __yy_file_name,nerrors);
	}

	if(nerrors==0) saveFile(out.c_str(),yaelClass,yaelObj);
	
	fclose(plog);
	fclose(pout);
	return 0;
}


