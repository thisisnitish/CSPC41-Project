/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "oldparser.y"

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "lex.yy.c"

void yyerror(const char*);
int yylex();
int yywrap();

void add(char);
void insert_type();
void insert_type_table();
int sym_search(char *);
int search(char *);
void addTo(char i,char *n);

void FOO();
void add_ptr();
void pop();
char temptype(char *,char*);
void type_check(char *,char*);
void printtree(struct node1*);

struct node{ 
	int val;
}x;

struct dataType{
	char * id_name;
	char * data_type;
	char * type;
	int line_no;
	}symbolTable[20];

int ifd=0;						//Label
int eld=20;
char typeStack[10][100];
int typeStack_top = 0;
char type[10];
char count=0;
int nxt=1;						//printed next once
int c=0;						//Temp var count
int q;
extern int countn;
struct node1 { 
	struct node1 *left;
	struct node1 *right;
	char *token;
};
struct node1* mknode(struct node1 *left,struct node1 *right, char *token);

#line 124 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IF = 258,
    ELSE = 259,
    INT = 260,
    FLOAT = 261,
    CHAR = 262,
    VOID = 263,
    INCLUDE = 264,
    RETURN = 265,
    LE = 266,
    GE = 267,
    LT = 268,
    GT = 269,
    EQ = 270,
    NE = 271,
    NUM = 272,
    AND = 273,
    OR = 274,
    TR = 275,
    FL = 276,
    STRLT = 277,
    identifiers = 278,
    printff = 279,
    scanff = 280
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define INT 260
#define FLOAT 261
#define CHAR 262
#define VOID 263
#define INCLUDE 264
#define RETURN 265
#define LE 266
#define GE 267
#define LT 268
#define GT 269
#define EQ 270
#define NE 271
#define NUM 272
#define AND 273
#define OR 274
#define TR 275
#define FL 276
#define STRLT 277
#define identifiers 278
#define printff 279
#define scanff 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "oldparser.y"
 
	struct var_name {
		char name[100];
		struct node1* nd;
	}nam; 
	
	struct gen_code {
		char tr[10];
		char fal[10];
		struct node1* nd;
	} gen; 

#line 239 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

#define YYUNDEFTOK  2
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      32,    33,    28,    26,    36,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    86,    88,    89,    90,    83,   101,   102,
     106,   107,   108,   109,   113,   113,   115,   116,   121,   122,
     127,   127,   129,   129,   135,   136,   135,   139,   140,   140,
     141,   145,   145,   147,   149,   152,   155,   156,   159,   152,
     166,   167,   185,   189,   189,   190,   190,   191,   194,   195,
     194,   202,   206,   208,   208,   208,   208,   210,   223,   223,
     238,   243,   248,   260,   269,   268,   285,   288,   287,   305,
     305,   319,   322,   322,   337,   337,   354,   357,   357,   373,
     376,   376,   377,   377,   378,   378,   382,   382,   382,   382,
     382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "INT", "FLOAT", "CHAR",
  "VOID", "INCLUDE", "RETURN", "LE", "GE", "LT", "GT", "EQ", "NE", "NUM",
  "AND", "OR", "TR", "FL", "STRLT", "identifiers", "printff", "scanff",
  "'+'", "'-'", "'*'", "'/'", "'='", "'^'", "'('", "')'", "'{'", "'}'",
  "','", "';'", "'['", "']'", "'&'", "$accept", "begin", "$@1", "$@2",
  "$@3", "$@4", "$@5", "header", "datatypes", "normalFuncArg", "$@6",
  "terminate", "pointerFuncArg", "$@7", "$@8", "arrayFuncArg", "$@9",
  "$@10", "$@11", "funcReturn", "$@12", "funcCode", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "EL", "$@19", "$@20", "Arg", "logicalCond", "B",
  "$@21", "assign", "$@22", "relationalCond", "$@23", "$@24", "F", "$@25",
  "$@26", "T", "$@27", "Q", "$@28", "$@29", "$@30", "relop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    43,    45,    42,    47,
      61,    94,    40,    41,   123,   125,    44,    59,    91,    93,
      38
};
# endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -63,    58,   109,   -63,   -63,   -63,   -63,   -63,     6,
      55,   -63,    59,   -63,    15,   -63,   -63,    -4,    11,    66,
      74,    -4,    66,   -63,   -63,   -63,   -63,   -10,   -63,   -63,
     -63,    63,    15,    72,   105,    84,   -63,    89,    74,   -63,
      74,    60,   -63,    85,   -63,   -63,    47,   -63,   -63,    76,
      60,   -63,    74,    94,   -63,   106,    95,    97,    66,   120,
      60,   -63,    73,    19,   -63,    98,   110,   111,   -63,    29,
      99,    81,    38,   -63,   -63,    62,   -63,    88,   -63,    61,
      41,   104,   -63,   -63,   -63,    27,   100,   103,   102,   -63,
     107,   -63,   -63,   -63,   -63,    74,    19,    81,    81,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    19,   -63,   -63,
     -63,   -63,   -63,   108,   101,   112,   -63,    19,   -63,   -15,
     -63,   -63,   113,    19,    19,    82,    19,    19,    19,   -63,
     116,   -63,    82,   -63,   -63,   -63,   -63,   -63,   -63,   104,
     115,    60,   114,     2,   -63,   -63,   136,   -63,   -63,   118,
     -63,    60,    25,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,     0,     0,     1,    10,    11,    12,    13,     8,
       0,     2,     0,     3,     0,    20,    22,     0,     0,    19,
      30,     0,    19,     4,    14,    18,    17,    24,    21,    23,
      16,     0,     0,     0,     0,     0,     5,    15,    30,    25,
      30,    47,    27,     0,    29,    35,     0,    43,    45,     0,
       6,    40,    30,     0,    64,     0,     0,     0,    19,    34,
      42,    26,     0,     0,    52,     0,     0,     0,    41,     0,
       0,     0,    84,    61,    60,    82,    80,     0,    56,     0,
      71,    76,    79,    84,    82,     0,     0,     0,     0,    31,
       0,     7,    55,    85,    58,    30,     0,     0,     0,    36,
      86,    87,    88,    89,    90,    67,    69,     0,    72,    74,
      77,    65,    66,     0,     0,     0,    33,     0,    83,     0,
      53,    54,     0,     0,     0,    57,     0,     0,     0,    44,
       0,    32,    59,    81,    37,    68,    70,    73,    75,    78,
       0,    47,     0,     0,    46,    38,    51,    48,    39,     0,
      49,    47,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   142,     3,   121,
     -63,   -19,    65,   -63,   -63,   -36,   -63,   -63,   -63,   -63,
     -63,   -41,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -57,   -63,   -63,   -63,   -62,   -63,   -63,
      -7,   -63,   -63,    18,   -63,   -63,   -63,   -63,   -63,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,    14,    31,    41,    59,     9,    49,    18,
      32,    26,    19,    20,    21,    28,    34,    43,    35,    70,
     115,    60,    53,   122,   141,   146,    56,    57,   148,   149,
     151,    65,    77,    78,   117,    51,    63,    79,   123,   124,
      80,   126,   127,    81,   128,    82,    96,    95,    93,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    85,    42,    30,    44,    45,    10,     5,     6,     7,
       8,   105,   106,    33,    92,     1,    61,    17,   133,    15,
       5,     6,     7,     8,    16,    46,    47,    48,    45,   -28,
       5,     6,     7,     8,   119,    17,    83,   145,    15,    68,
     120,   121,    84,    16,    23,   125,    89,    24,    46,    47,
      48,    76,    90,   105,   106,   132,   -63,   -63,     4,   118,
     153,   135,   136,    45,   111,     5,     6,     7,     8,   108,
     109,   -63,   100,   101,   102,   103,   104,    54,    11,    55,
     -62,   -62,    22,    46,    47,    48,    29,   105,   106,    71,
      72,    13,    94,    73,    74,   -62,    75,    36,    72,    58,
     143,    73,    74,    25,    75,    76,    97,    98,   105,   106,
     152,    38,    27,    76,     5,     6,     7,     8,     1,   137,
     138,    99,    39,    40,    52,    24,    62,    66,    64,    67,
      69,    86,    87,    88,    91,   110,   113,   112,   114,   140,
     147,   130,     3,     0,   116,   129,   139,   134,   142,   131,
       0,   144,   150,    37
};

static const yytype_int16 yycheck[] =
{
      41,    63,    38,    22,    40,     3,     3,     5,     6,     7,
       8,    26,    27,    23,    71,     9,    52,    14,    33,    23,
       5,     6,     7,     8,    28,    23,    24,    25,     3,    39,
       5,     6,     7,     8,    96,    32,    17,    35,    23,    58,
      97,    98,    23,    28,    33,   107,    17,    36,    23,    24,
      25,    32,    23,    26,    27,   117,    18,    19,     0,    95,
      35,   123,   124,     3,    37,     5,     6,     7,     8,    28,
      29,    33,    11,    12,    13,    14,    15,    30,    23,    32,
      18,    19,    17,    23,    24,    25,    21,    26,    27,    16,
      17,    32,    30,    20,    21,    33,    23,    34,    17,    23,
     141,    20,    21,    37,    23,    32,    18,    19,    26,    27,
     151,    39,    38,    32,     5,     6,     7,     8,     9,   126,
     127,    33,    17,    39,    39,    36,    32,    32,    22,    32,
      10,    33,    22,    22,    35,    31,    33,    37,    36,    23,
       4,    40,     0,    -1,    37,    37,   128,    34,    33,    37,
      -1,    37,    34,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    42,    48,     0,     5,     6,     7,     8,    48,
      49,    23,    43,    32,    44,    23,    28,    49,    50,    53,
      54,    55,    53,    33,    36,    37,    52,    38,    56,    53,
      52,    45,    51,    23,    57,    59,    34,    50,    39,    17,
      39,    46,    56,    58,    56,     3,    23,    24,    25,    49,
      62,    76,    39,    63,    30,    32,    67,    68,    23,    47,
      62,    56,    32,    77,    22,    72,    32,    32,    52,    10,
      60,    16,    17,    20,    21,    23,    32,    73,    74,    78,
      81,    84,    86,    17,    23,    78,    33,    22,    22,    17,
      23,    35,    74,    89,    30,    88,    87,    18,    19,    33,
      11,    12,    13,    14,    15,    26,    27,    90,    28,    29,
      31,    37,    37,    33,    36,    61,    37,    75,    56,    78,
      74,    74,    64,    79,    80,    78,    82,    83,    85,    37,
      40,    37,    78,    33,    34,    78,    78,    81,    81,    84,
      23,    65,    33,    62,    37,    35,    66,     4,    69,    70,
      34,    71,    62,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    44,    45,    46,    47,    42,    48,    48,
      49,    49,    49,    49,    51,    50,    50,    50,    52,    52,
      54,    53,    55,    53,    57,    58,    56,    56,    59,    56,
      56,    61,    60,    60,    60,    63,    64,    65,    66,    62,
      62,    62,    62,    67,    62,    68,    62,    62,    70,    71,
      69,    69,    72,    73,    73,    73,    73,    74,    75,    74,
      74,    74,    74,    74,    77,    76,    76,    79,    78,    80,
      78,    78,    82,    81,    83,    81,    81,    85,    84,    84,
      87,    86,    88,    86,    89,    86,    90,    90,    90,    90,
      90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,    15,     2,     1,
       1,     1,     1,     1,     0,     4,     3,     2,     1,     0,
       0,     3,     0,     3,     0,     0,     6,     4,     0,     4,
       0,     0,     4,     3,     0,     0,     0,     0,     0,    12,
       1,     3,     2,     0,     6,     0,     9,     0,     0,     0,
       6,     0,     1,     3,     3,     2,     1,     3,     0,     4,
       1,     1,     1,     1,     0,     5,     5,     0,     4,     0,
       4,     1,     0,     4,     0,     4,     1,     0,     4,     1,
       0,     4,     0,     3,     0,     2,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 85 "oldparser.y"
                                                                                                                                                                                                        { insert_type_table(); }
#line 1527 "y.tab.c"
    break;

  case 3:
#line 86 "oldparser.y"
                                                                                                                                                                                                                { add('t'); }
#line 1533 "y.tab.c"
    break;

  case 4:
#line 88 "oldparser.y"
                                                                                                                                                                                                                { add('t'); }
#line 1539 "y.tab.c"
    break;

  case 5:
#line 89 "oldparser.y"
                                                                                                                                                                                                                        { add('t'); }
#line 1545 "y.tab.c"
    break;

  case 6:
#line 90 "oldparser.y"
                                                                                                                                                                                                                { printf("Label next:\n"); }
#line 1551 "y.tab.c"
    break;

  case 7:
#line 92 "oldparser.y"
                    { 
			(yyval.nam).nd = mknode(NULL,(yyvsp[-3].nam).nd,"start"); 
			printf("#######################################################################################\n");
			printf("\t\t\tSyntax Tree in Inorder traversal\n#######################################################################################\n");
			printtree((yyval.nam).nd);
			printf("\n\n");
			add('t');
		}
#line 1564 "y.tab.c"
    break;

  case 8:
#line 101 "oldparser.y"
                                                                                                                                                                                                        {;}
#line 1570 "y.tab.c"
    break;

  case 9:
#line 102 "oldparser.y"
                                                                                                                                                                                                                        { add('H'); }
#line 1576 "y.tab.c"
    break;

  case 10:
#line 106 "oldparser.y"
                                                                                                                                                                                                                { insert_type(); }
#line 1582 "y.tab.c"
    break;

  case 11:
#line 107 "oldparser.y"
                                                                                                                                                                                                                        { insert_type(); }
#line 1588 "y.tab.c"
    break;

  case 12:
#line 108 "oldparser.y"
                                                                                                                                                                                                                        { insert_type(); }
#line 1594 "y.tab.c"
    break;

  case 13:
#line 109 "oldparser.y"
                                                                                                                                                                                                                        { insert_type(); }
#line 1600 "y.tab.c"
    break;

  case 14:
#line 113 "oldparser.y"
                                                                                                                                                                                        { add('t'); }
#line 1606 "y.tab.c"
    break;

  case 18:
#line 121 "oldparser.y"
                                                                                                                                                                                                                { add('t'); }
#line 1612 "y.tab.c"
    break;

  case 20:
#line 127 "oldparser.y"
                                                                                                                                                                                                { insert_type_table(); }
#line 1618 "y.tab.c"
    break;

  case 21:
#line 128 "oldparser.y"
                                                                                                                                                                                                                {;}
#line 1624 "y.tab.c"
    break;

  case 22:
#line 129 "oldparser.y"
                                                                                                                                                                                                                        { add_ptr(); }
#line 1630 "y.tab.c"
    break;

  case 24:
#line 135 "oldparser.y"
                                                                                                                                                                                                                { add('t'); }
#line 1636 "y.tab.c"
    break;

  case 25:
#line 136 "oldparser.y"
                                                                                                                                                                                                                                { add('n'); }
#line 1642 "y.tab.c"
    break;

  case 28:
#line 140 "oldparser.y"
                                      { add('t'); }
#line 1648 "y.tab.c"
    break;

  case 31:
#line 145 "oldparser.y"
                                                                                                                                                                                                                { add('n'); }
#line 1654 "y.tab.c"
    break;

  case 32:
#line 146 "oldparser.y"
                                                                                                                                                                                                                                { add('t'); printf("Return\t%s\n",(yyvsp[-2].nam).name); }
#line 1660 "y.tab.c"
    break;

  case 33:
#line 148 "oldparser.y"
                                                                                                                                                                                                                        { add('t'); printf("Return\t%s\n",(yyvsp[-1].nam).name);}
#line 1666 "y.tab.c"
    break;

  case 35:
#line 152 "oldparser.y"
                                                                                                                                                                                                                        { add('k'); }
#line 1672 "y.tab.c"
    break;

  case 36:
#line 155 "oldparser.y"
                                                                                                                                                                                                                        { printf("\nLabel\t%s:\n",(yyvsp[-1].gen).tr); }
#line 1678 "y.tab.c"
    break;

  case 37:
#line 156 "oldparser.y"
                                                                                                                                                                                                                        { addTo('{',"Punctuations"); }
#line 1684 "y.tab.c"
    break;

  case 38:
#line 159 "oldparser.y"
                                                                                                                                                                                                                                { 
																													addTo ('}',"Punctuations");
																													pop();
																													printf("goto next\n");
																													printf("\nLabel\t%s:\n",(yyvsp[-6].gen).fal);}
#line 1694 "y.tab.c"
    break;

  case 39:
#line 163 "oldparser.y"
                                                                                                                                                                                                                                                                             {(yyval.nam).nd=mknode((yyvsp[-8].gen).nd,(yyvsp[-3].nam).nd,"IF");
																													strcpy((yyval.nam).name,"IF");
																												}
#line 1702 "y.tab.c"
    break;

  case 40:
#line 166 "oldparser.y"
                                                                                                                                                                                                                        {(yyval.nam).nd=(yyvsp[0].nam).nd;}
#line 1708 "y.tab.c"
    break;

  case 41:
#line 167 "oldparser.y"
                                                          {
				(yyval.nam).nd=mknode(NULL,NULL,"definition"); 
				int i=sym_search((yyvsp[-1].nam).name);
				if(i!=-1)
					{
						if(strcmp((yyvsp[-2].nam).name,"int")==0)
						{
							addTo('i',(yyvsp[-1].nam).name);
						} else if(strcmp((yyvsp[-2].nam).name,"float")==0)
									addTo('f',(yyvsp[-1].nam).name);
							else 
								addTo('c',(yyvsp[-1].nam).name);
					}
					else { 
						printf("Variable already defined, error at line no: %d\n",yylineno);
						exit(0);
					}
				}
#line 1731 "y.tab.c"
    break;

  case 42:
#line 185 "oldparser.y"
                                            {
				(yyval.nam).nd=mknode((yyvsp[-1].nam).nd,(yyvsp[0].nam).nd,"statement");
				strcpy((yyval.nam).name,"STATEMENT");
			}
#line 1740 "y.tab.c"
    break;

  case 43:
#line 189 "oldparser.y"
                                   { add('f');}
#line 1746 "y.tab.c"
    break;

  case 44:
#line 189 "oldparser.y"
                                                                 {(yyval.nam).nd = mknode(NULL,NULL,"printf");}
#line 1752 "y.tab.c"
    break;

  case 45:
#line 190 "oldparser.y"
                                 { add('f');}
#line 1758 "y.tab.c"
    break;

  case 46:
#line 190 "oldparser.y"
                                                                              {(yyval.nam).nd = mknode(NULL,NULL,"scanf");}
#line 1764 "y.tab.c"
    break;

  case 47:
#line 191 "oldparser.y"
                          { (yyval.nam).nd=mknode(NULL,NULL,"EPSILON"); }
#line 1770 "y.tab.c"
    break;

  case 48:
#line 194 "oldparser.y"
                                                                                                                                                                                                        { add('k'); }
#line 1776 "y.tab.c"
    break;

  case 49:
#line 195 "oldparser.y"
                                                                                                                                                                                                                { addTo('{',"Punctuations"); }
#line 1782 "y.tab.c"
    break;

  case 50:
#line 198 "oldparser.y"
                {
			(yyval.nam)=(yyvsp[-1].nam);addTo('}',"Punctuations");
			pop();
			printf("goto next\n");
			printf("\n");}
#line 1792 "y.tab.c"
    break;

  case 51:
#line 202 "oldparser.y"
                                        {printf("goto next\n");
			printf("\n");
		}
#line 1800 "y.tab.c"
    break;

  case 56:
#line 208 "oldparser.y"
                                                             {(yyval.gen).nd=(yyvsp[0].gen).nd;}
#line 1806 "y.tab.c"
    break;

  case 57:
#line 210 "oldparser.y"
                                            {
				(yyval.gen).nd=mknode((yyvsp[-2].nam).nd,(yyvsp[0].nam).nd,(yyvsp[-1].nam).name);
				int i=search((yyvsp[-2].nam).name);
				int j=search((yyvsp[0].nam).name);
				if(i!=0 && j!=0) {
					printf("if %s %s %s goto L%d else goto L%d\n",(yyvsp[-2].nam).name,(yyvsp[-1].nam).name,(yyvsp[0].nam).name,ifd,eld);
					sprintf((yyval.gen).tr,"L%d",ifd);
					sprintf((yyval.gen).fal,"L%d",eld);ifd++;eld++;}   
				else {
					printf(" Variable not declared at line no: %d\n", yylineno);
					exit(0);
					}
				}
#line 1824 "y.tab.c"
    break;

  case 58:
#line 223 "oldparser.y"
                                        { add('o'); }
#line 1830 "y.tab.c"
    break;

  case 59:
#line 224 "oldparser.y"
                                               { 
						int i=search((yyvsp[-3].nam).name);
 						int j=search((yyvsp[0].nam).name);
 						if(i!=0&&j!=0)
						{
						printf("if %s!=0 goto L%d else goto L%d\n",(yyvsp[-3].nam).name,ifd,eld);
						sprintf((yyval.gen).tr,"L%d",ifd);
						sprintf((yyval.gen).fal,"L%d",eld);ifd++;eld++;} 
						else
							{
								printf(" Variable not declared at line no: %d\n", yylineno);
								exit(0);
							}
					}
#line 1849 "y.tab.c"
    break;

  case 60:
#line 238 "oldparser.y"
                           { 
				printf("if False  goto L%d\n",eld);
				sprintf((yyval.gen).tr,"L%d",ifd);
				sprintf((yyval.gen).fal,"L%d",eld);ifd++;eld++;
				}
#line 1859 "y.tab.c"
    break;

  case 61:
#line 243 "oldparser.y"
                           {
				printf("if True  goto L%d\n",ifd);
				sprintf((yyval.gen).tr,"L%d",ifd);
				sprintf((yyval.gen).fal,"L%d",eld);ifd++;eld++;
				}
#line 1869 "y.tab.c"
    break;

  case 62:
#line 248 "oldparser.y"
                                     { 
					int i=search((yyvsp[0].nam).name);
					if(i!=0)
					{
						printf("if %s!=0  goto L%d else goto L%d\n",(yyvsp[0].nam).name,ifd,eld);
						sprintf((yyval.gen).tr,"L%d",ifd);
						sprintf((yyval.gen).fal,"L%d",eld);ifd++;eld++;}    
					else {
						printf(" Variable not declared at line no: %d\n", yylineno);
					exit(0);
					} 
				}
#line 1886 "y.tab.c"
    break;

  case 63:
#line 260 "oldparser.y"
                              {
					add('n');
					printf("if %s!=0  goto L%d else goto L%d\n",(yyvsp[0].nam).name,ifd,eld);
					sprintf((yyval.gen).tr,"L%d",ifd);
					sprintf((yyval.gen).fal,"L%d",eld);
					ifd++;eld++;
				}
#line 1898 "y.tab.c"
    break;

  case 64:
#line 269 "oldparser.y"
                                            { add('o'); }
#line 1904 "y.tab.c"
    break;

  case 65:
#line 270 "oldparser.y"
                                                           {
						(yyvsp[-4].nam).nd = mknode(NULL,NULL,(yyvsp[-4].nam).name);
						(yyval.nam).nd=mknode((yyvsp[-4].nam).nd,(yyvsp[-1].nam).nd,"=");
						strcpy((yyval.nam).name,"=");add('t');
						int i=search((yyvsp[-4].nam).name);
						int j=search((yyvsp[-1].nam).name);
						if(i!=0&&j!=0) 
						{
							type_check((yyvsp[-4].nam).name,(yyvsp[-1].nam).name);
							printf("= \t %s\t %s \n",(yyvsp[-1].nam).name,(yyvsp[-4].nam).name);} 
							else {
								printf("Variable not declared at line no: %d\n", yylineno);
								exit(0);
							}
						}
#line 1924 "y.tab.c"
    break;

  case 66:
#line 285 "oldparser.y"
                                                              {add('t');}
#line 1930 "y.tab.c"
    break;

  case 67:
#line 288 "oldparser.y"
                    { add('o'); }
#line 1936 "y.tab.c"
    break;

  case 68:
#line 289 "oldparser.y"
                               { 
				(yyval.nam).nd=mknode((yyvsp[-3].nam).nd,(yyvsp[0].nam).nd,"+");
				strcpy((yyval.nam).name,"+");
				int i=search((yyvsp[-3].nam).name);
				int j=search((yyvsp[0].nam).name);
				sprintf((yyval.nam).name,"t%d",c);
				c++;
				addTo(temptype((yyvsp[-3].nam).name,(yyvsp[0].nam).name),(yyval.nam).name);
				if(i!=0 && j!=0) {
					printf("%s\t%s\t%s\t%s\n","+",(yyvsp[-3].nam).name,(yyvsp[0].nam).name,(yyval.nam).name);
				}
				else {
					printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
					}
			}
#line 1956 "y.tab.c"
    break;

  case 69:
#line 305 "oldparser.y"
                             {add('o');}
#line 1962 "y.tab.c"
    break;

  case 70:
#line 305 "oldparser.y"
                                                        { 
			(yyval.nam).nd=mknode((yyvsp[-3].nam).nd,(yyvsp[0].nam).nd,"-");
			strcpy((yyval.nam).name,"-");
			int i=search((yyvsp[-3].nam).name);
			int j=search((yyvsp[0].nam).name);
			sprintf((yyval.nam).name,"t%d",c);c++;
			addTo(temptype((yyvsp[-3].nam).name,(yyvsp[0].nam).name),(yyval.nam).name);
			if(i!=0 && j!=0) {
				printf("%s\t%s\t%s\t%s\n","-",(yyvsp[-3].nam).name,(yyvsp[0].nam).name,(yyval.nam).name);
			} 
			else {
				printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
			}
		}
#line 1981 "y.tab.c"
    break;

  case 71:
#line 319 "oldparser.y"
            { (yyval.nam).nd=(yyvsp[0].nam).nd; }
#line 1987 "y.tab.c"
    break;

  case 72:
#line 322 "oldparser.y"
               { add('o'); }
#line 1993 "y.tab.c"
    break;

  case 73:
#line 322 "oldparser.y"
                               {
			(yyval.nam).nd=mknode((yyvsp[-3].nam).nd,(yyvsp[0].nam).nd,"*");
			strcpy((yyval.nam).name,"*");
			int i=search((yyvsp[-3].nam).name);
			int j=search((yyvsp[0].nam).name);
			sprintf((yyval.nam).name,"t%d",c);c++;
			addTo(temptype((yyvsp[-3].nam).name,(yyvsp[0].nam).name),(yyval.nam).name);
			if(i!=0 && j!=0) {
				printf("%s\t%s\t%s\t%s\n","*",(yyvsp[-3].nam).name,(yyvsp[0].nam).name,(yyval.nam).name);
			}
			else {
				printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
				}
			}
#line 2012 "y.tab.c"
    break;

  case 74:
#line 337 "oldparser.y"
                { add('o');}
#line 2018 "y.tab.c"
    break;

  case 75:
#line 337 "oldparser.y"
                               { (yyval.nam).nd=mknode((yyvsp[-3].nam).nd,(yyvsp[0].nam).nd,"/");
	strcpy((yyval.nam).name,"/"); 
	int i=search((yyvsp[-3].nam).name);
	int j=search((yyvsp[0].nam).name);
	sprintf((yyval.nam).name,"%d",c);
	strcat((yyval.nam).name,"t");c++;
	addTo(temptype((yyvsp[-3].nam).name,(yyvsp[0].nam).name),(yyval.nam).name);
	if(i!=0 && j!=0) 
	{
		printf("%s\t%s\t%s\t%s\n","/",(yyvsp[-3].nam).name,(yyvsp[0].nam).name,(yyval.nam).name);
	}
	 else {
		 printf(" Variable not declared at line no: %d\n", yylineno);
	 exit(0);
	 }
	}
#line 2039 "y.tab.c"
    break;

  case 76:
#line 354 "oldparser.y"
            {(yyval.nam).nd=(yyvsp[0].nam).nd;}
#line 2045 "y.tab.c"
    break;

  case 77:
#line 357 "oldparser.y"
              { add('o'); }
#line 2051 "y.tab.c"
    break;

  case 78:
#line 357 "oldparser.y"
                              { 
		(yyval.nam).nd=mknode((yyvsp[-3].nam).nd,(yyvsp[0].nam).nd,"^");
		strcpy((yyval.nam).name,"^");
		int i=search((yyvsp[-3].nam).name);
		int j=search((yyvsp[0].nam).name);
		sprintf((yyval.nam).name,"%d",c);
		strcat((yyval.nam).name,"t");c++;
		addTo(temptype((yyvsp[-3].nam).name,(yyvsp[0].nam).name),(yyval.nam).name);
		if(i!=0 && j!=0) {
			printf("%s\t%s\t%s\t%s\n","^",(yyvsp[-3].nam).name,(yyvsp[0].nam).name,(yyval.nam).name);} 
		else {
			printf(" Variable not declared at line no: %d\n", yylineno);
			exit(0);
			}
		}
#line 2071 "y.tab.c"
    break;

  case 79:
#line 373 "oldparser.y"
            {(yyval.nam).nd=(yyvsp[0].nam).nd;}
#line 2077 "y.tab.c"
    break;

  case 80:
#line 376 "oldparser.y"
        {add('t');}
#line 2083 "y.tab.c"
    break;

  case 81:
#line 376 "oldparser.y"
                                       {add('t'); (yyval.nam)=(yyvsp[-1].nam);}
#line 2089 "y.tab.c"
    break;

  case 82:
#line 377 "oldparser.y"
                      {insert_type_table();}
#line 2095 "y.tab.c"
    break;

  case 83:
#line 377 "oldparser.y"
                                                          {(yyval.nam).nd=mknode(NULL,NULL,(yyvsp[-2].nam).name);strcpy((yyval.nam).name,(yyvsp[-2].nam).name);}
#line 2101 "y.tab.c"
    break;

  case 84:
#line 378 "oldparser.y"
             {add('n');}
#line 2107 "y.tab.c"
    break;

  case 85:
#line 378 "oldparser.y"
                        {(yyval.nam).nd=mknode(NULL,NULL,(yyvsp[-1].nam).name);
		strcpy((yyval.nam).name,(yyvsp[-1].nam).name);}
#line 2114 "y.tab.c"
    break;

  case 86:
#line 382 "oldparser.y"
           {add('r');}
#line 2120 "y.tab.c"
    break;

  case 87:
#line 382 "oldparser.y"
                            {add('r');}
#line 2126 "y.tab.c"
    break;

  case 88:
#line 382 "oldparser.y"
                                            {add('r');}
#line 2132 "y.tab.c"
    break;

  case 89:
#line 382 "oldparser.y"
                                                             {add('r');}
#line 2138 "y.tab.c"
    break;

  case 90:
#line 382 "oldparser.y"
                                                                             {add('r');}
#line 2144 "y.tab.c"
    break;


#line 2148 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 384 "oldparser.y"


int main()
{
	extern int yylineno;
	x.val=10;
	printf("#######################################################################################\n");
	printf("\t\t\tIntermediate code\n");
	printf("#######################################################################################\n");
	yyparse();
	
	printf("\nParsing is Successful\n");	
	printf("#######################################################################################\n");
	printf("\t\t\tSymbol table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t type  \t identify \t line number\n");
	printf("_______________________________________________________________________________________\n");
	int i=0;	
	for(i=0;i<count;i++){
		printf("%s\t%s\t%s\t%d\t\n",symbolTable[i].id_name,symbolTable[i].data_type,symbolTable[i].type,symbolTable[i].line_no);
		
	}
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	return 0;
}


void yyerror(const char* s){
	printf("Not accepted\n");
	exit(0);
}


//insert the type into symboltable
void insert_type(){
	strcpy(type,yytext);
	q=search(type);
	if(q==0){
		symbolTable[count].id_name=strdup(yytext);
		symbolTable[count].data_type=strdup("N/A");
		symbolTable[count].line_no = countn;
		symbolTable[count].type=strdup("KEYWORD\t");
		count++;
	}
}


struct node1* mknode(struct node1 *left, struct node1 *right, char *token)
{
  struct node1 *newnode = (struct node1 *)malloc(sizeof(struct node1));
  char *newstr = (char *)malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}


void pop()
{
	int i;
	//printf("count %d\n",count);
	int temp=count-1;
	for(i=temp;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,"{")!=0)
		{
			//printf("$$\n");
			count=count-1;;
		}
		else
		{
			count=count-1;
			break;
		}
	}	
	
}

//add declaration of data to symboltable
void addTo(char i,char *n)
{
	if(i=='i')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="int";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='f')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="float";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='c')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="char";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='{')
	{
			symbolTable[count].id_name=strdup("{");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
	else if(i=='}')
	{
			symbolTable[count].id_name=strdup("}");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
}


char temptype(char* one,char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if((strcmp(onetype,"float")==0) || (strcmp(twotype,"float")==0))
		return 'f';
	else
		return 'i';
}


void insert_type_table(){
		q=search(yytext);
		if(q==0){
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("IDENTIFIER");
			count++;
		}
	
	
}


void type_check(char* one, char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if(strcmp(onetype,twotype)>0){ printf("type error at lineno %d\n",yylineno);exit(0);}
}

//ADD the recent parsed string into symboltable
void add(char c)
{
	q=search(yytext);
	if(q==0){
		if(c=='H')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c=='t')
		{	
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Punctuation");
			count++;
		}
		else if(c=='o')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Operator");
			count++;
		}
		else if(c=='r')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Rel Op\t");
			count++;
		}
		else if(c=='k')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("KEYWORD\t");
			count++;
		}
		else if(c=='n')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("int");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("NUMBER\t");
			count++;
		}
		else if(c=='f')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("FUNCTION\t");
			count++;
		}
	}
}


int  sym_search(char *type)
{
	int i;
	for(i=count -1 ;i>=0&&(strcmp(symbolTable[i].id_name,"{")!=0);i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	}
	return 0;
}


//Search in the Symbol table whether the parsed String is present in Symbol table already
int  search(char *type) {
	int i;
	for(i=count -1 ;i>=0;i--){
		if(strcmp(symbolTable[i].id_name,type)==0){
			return -1;
			break;
		}
	}
	return 0;
}


void add_ptr(){
	strcat(type,"*");
}


//print the abstract syntax tree
void printtree(struct node1* tree){
  	int i;
  	if (tree->left){
		printtree(tree->left);
	}
 	printf(" %s , ", tree->token);
  	if (tree->right){
		printtree(tree->right);
	}
}
