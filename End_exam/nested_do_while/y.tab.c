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
#line 1 "do_while.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include "symbol.c"
	int g_addr = 100;
int i=1,lnum1=0,label1[20],ltop1;
int stack[100],index1=0,end[100],arr[10],gl1,gl2,ct,c,b,fl,top=0,label[20],lnum=0,ltop=0;
char st1[100][10];
char i_[2]="0";
char temp[2]="t";
char null[2]=" ";
void yyerror(char *s);
int printline();
void open1()
{
	stack[index1]=i;
	i++;
	index1++;
	return;
}
void close1()
{
	index1--;
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
void if1()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;	
	
}
void if2()
{
	lnum++;
	printf("goto L%d\n",lnum);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=lnum;
}
void if3()
{
	printf("L%d:\n",label[ltop--]);
}
void w1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void w2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
}
void w3()
{
	int y=label[ltop--];
	printf("goto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}
void dw1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void dw2()
{
 	printf("if %s goto L%d\n",st1[top--],label[ltop--]);
}
void f1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void f2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
	lnum++;
	printf("goto L%d\n",lnum);
	label[++ltop]=lnum;
	lnum++;
	printf("L%d:\n",lnum);	
	label[++ltop]=lnum;
}
void f3()
{
	printf("goto L%d\n",label[ltop-3]);
	printf("L%d:\n",label[ltop-1]);
}
void f4()
{
	printf("goto L%d\n",label[ltop]);
	printf("L%d:\n",label[ltop-2]);
	ltop-=4;
}
void push(char *a)
{
	strcpy(st1[++top],a);
}
void array1()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s * 4\n",temp,st1[top]);
	strcpy(st1[top],temp);
	i_[0]++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;	
}
void codegen()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);
	top-=2;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_umin()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = -%s\n",temp,st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_assign()
{
	printf("%s = %s\n",st1[top-2],st1[top]);
	top-=2;
}



#line 225 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    ID = 261,
    NUM = 262,
    REAL = 263,
    LE = 264,
    GE = 265,
    EQ = 266,
    NEQ = 267,
    AND = 268,
    OR = 269,
    WHILE = 270,
    IF = 271,
    RETURN = 272,
    PREPROC = 273,
    STRING = 274,
    PRINT = 275,
    FUNCTION = 276,
    DO = 277,
    ARRAY = 278,
    ELSE = 279,
    STRUCT = 280,
    STRUCT_VAR = 281,
    FOR = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define ID 261
#define NUM 262
#define REAL 263
#define LE 264
#define GE 265
#define EQ 266
#define NEQ 267
#define AND 268
#define OR 269
#define WHILE 270
#define IF 271
#define RETURN 272
#define PREPROC 273
#define STRING 274
#define PRINT 275
#define FUNCTION 276
#define DO 277
#define ARRAY 278
#define ELSE 279
#define STRUCT 280
#define STRUCT_VAR 281
#define FOR 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 169 "do_while.y" /* yacc.c:355  */

		int ival;
		char *str;
	

#line 324 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 341 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      36,    37,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   176,   177,   178,   181,   202,   203,   204,
     207,   210,   211,   214,   215,   216,   217,   218,   219,   220,
     226,   227,   228,   229,   232,   232,   232,   235,   235,   235,
     235,   238,   238,   238,   241,   242,   245,   245,   245,   248,
     249,   250,   251,   252,   253,   256,   256,   256,   256,   273,
     277,   278,   282,   285,   286,   289,   289,   289,   289,   320,
     332,   337,   338,   342,   346,   349,   349,   352,   352,   353,
     353,   354,   355,   355,   355,   356,   356,   356,   357,   357,
     357,   358,   358,   358,   359,   359,   359,   360,   360,   360,
     361,   361,   361,   362,   362,   362,   363,   363,   363,   364,
     366,   366,   367,   367,   368,   370,   371,   371,   372,   373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "ID", "NUM",
  "REAL", "LE", "GE", "EQ", "NEQ", "AND", "OR", "WHILE", "IF", "RETURN",
  "PREPROC", "STRING", "PRINT", "FUNCTION", "DO", "ARRAY", "ELSE",
  "STRUCT", "STRUCT_VAR", "FOR", "'<'", "'>'", "'='", "UMINUS", "'+'",
  "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "','", "'['",
  "']'", "$accept", "start", "Function", "Type", "CompoundStmt",
  "StmtList", "stmt", "dowhile", "$@1", "$@2", "for", "$@3", "$@4", "$@5",
  "if", "$@6", "$@7", "else", "while", "$@8", "$@9", "assignment",
  "assignment1", "$@10", "$@11", "$@12", "consttype", "Declaration",
  "$@13", "$@14", "$@15", "array", "$@16", "E", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36", "T",
  "$@37", "$@38", "F", "$@39", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      61,   283,    43,    45,    42,    47,    40,    41,   123,   125,
      59,    44,    91,    93
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -97

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     141,   -80,   -80,   -80,   -80,   -34,   -80,   -80,   141,     7,
      25,   141,    21,    -3,    -9,   141,   161,   161,    28,   -80,
      -2,   -80,   -80,    -8,   -80,   161,   -80,    12,   -80,     4,
     -80,    34,   157,    14,   164,    77,   -80,    46,    23,   -80,
     128,    97,   101,    16,   100,   116,   -80,   -80,    10,   -80,
      23,   -80,   -80,    71,    88,   -80,   131,   134,   -80,   -80,
     119,   164,   164,   135,   164,    23,   136,   167,   169,   166,
     168,   170,   171,   153,   155,   156,    62,    55,   -80,   -80,
     -80,   -80,   -80,   -80,   113,   -80,   -80,   -80,   -80,   -80,
      71,    23,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    62,    62,    62,    62,   114,   -80,
     151,     3,   152,   -80,   154,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   149,    17,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    88,    88,   -80,   -80,   158,
     160,    23,   -80,   159,   172,   101,    23,   -80,   -80,    71,
      71,    71,    71,    71,    71,    71,    71,    71,   162,    23,
      57,   -80,   163,   177,    71,   -80,    69,   -80,   165,   173,
     174,   -80,   101,   -80,    23,    23,   101,   -80,    78,    71,
     -80,   179,   -80,   175,   101,   -80,   176,    23,   -80,   -80,
      71,   180,   101,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,     7,     8,     9,    45,    53,    54,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     3,
       0,     1,     2,    55,    59,     0,     4,    51,    49,     0,
      46,     0,     0,     0,     0,     0,    50,     0,     0,    63,
       0,     0,     0,    43,     0,    44,    56,    61,   108,   106,
       0,   109,    99,    47,    71,   104,    55,     0,    12,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    69,
      48,   100,   102,    62,     0,    39,    40,    41,    60,    42,
      57,     0,    73,    76,    79,    82,    85,    88,    91,    94,
      97,   108,   107,   105,     0,     0,     0,     0,    45,    36,
       0,     0,     0,    24,     0,    10,    21,    23,    11,    17,
      18,    14,    16,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    70,   101,   103,     0,
       0,     0,    20,     0,     0,     0,     0,    58,    66,    74,
      77,    80,    83,    86,    89,    92,    95,    98,     0,     0,
       0,    19,     0,     0,    27,    15,     0,    31,     0,     0,
       0,    37,     0,    22,     0,     0,     0,    32,     0,    28,
      38,    35,    25,     0,     0,    33,     0,     0,    34,    26,
      29,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,    56,   -80,   -30,   -79,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,    11,    83,   -80,   -80,   -80,     1,   -29,   -80,   -80,
     -80,   -80,   -80,   -50,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    27,   -80,   -80,   -62,   -80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    59,    84,   118,   119,   145,   186,
     120,   170,   183,   191,   121,   172,   181,   185,   122,   140,
     176,    44,    13,    18,    38,    80,    51,    15,    35,    65,
     124,    52,    66,    53,   104,   105,    67,   126,    68,   127,
      69,   128,    70,   129,    71,   130,    72,   131,    73,   132,
      74,   133,    75,   134,    54,   106,   107,    55,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    14,    40,    41,    31,   117,   -51,    16,    17,    14,
       6,     7,    14,    20,   102,    90,    14,    14,    14,   -72,
     -75,   -78,   -81,   -84,   -87,    21,    14,    23,    33,    48,
       6,     7,    25,    14,    34,    45,    32,    24,   -90,   -93,
     -96,   125,   -45,   142,   137,   138,    60,    37,    61,    78,
      79,    42,   -65,    16,    40,   123,    49,    62,    30,    50,
     148,    85,    45,    45,    19,    45,   163,    22,   101,     6,
       7,    26,    86,    87,    39,    89,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    14,    47,    78,    79,    78,
      79,   160,   103,   177,   167,    49,   164,   180,    50,    28,
      29,    78,    79,    78,    79,   188,   171,    46,    36,   166,
      78,    79,   143,   193,     1,   182,     2,     3,     4,   108,
       6,     7,    81,    82,   178,   179,     6,     7,   109,   110,
     111,   135,   136,   112,    56,   113,    57,   190,     9,    58,
     114,    -5,     1,    63,     2,     3,     4,     5,     6,     7,
     139,    58,   115,   116,   -51,    16,    17,    64,     1,     8,
       2,     3,     4,     5,     6,     7,     9,    27,     6,     7,
      43,     6,     7,    34,    83,    88,    92,    94,    91,    93,
      95,    98,     9,    96,    99,    97,   100,   141,   144,   147,
     146,   162,   169,     0,     0,   158,   159,     0,     0,   161,
     168,     0,   165,   184,     0,   173,     0,     0,     0,   174,
       0,     0,     0,     0,   175,   187,   189,   192
};

static const yytype_int16 yycheck[] =
{
      50,     0,    32,    32,     6,    84,    40,    41,    42,     8,
       7,     8,    11,     6,    76,    65,    15,    16,    17,     9,
      10,    11,    12,    13,    14,     0,    25,     6,    36,     6,
       7,     8,    41,    32,    42,    34,    38,    40,    28,    29,
      30,    91,    30,    40,   106,   107,    30,    43,    32,    32,
      33,    37,    42,    41,    84,    84,    33,    41,    30,    36,
      43,    60,    61,    62,     8,    64,   145,    11,     6,     7,
       8,    15,    61,    62,    40,    64,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    84,    40,    32,    33,    32,
      33,   141,    37,   172,    37,    33,   146,   176,    36,    16,
      17,    32,    33,    32,    33,   184,    37,    30,    25,   159,
      32,    33,   111,   192,     1,    37,     3,     4,     5,     6,
       7,     8,    34,    35,   174,   175,     7,     8,    15,    16,
      17,   104,   105,    20,     6,    22,    39,   187,    25,    38,
      27,     0,     1,    43,     3,     4,     5,     6,     7,     8,
      36,    38,    39,    40,    40,    41,    42,    41,     1,    18,
       3,     4,     5,     6,     7,     8,    25,     6,     7,     8,
       6,     7,     8,    42,    40,    40,     9,    11,    42,    10,
      12,    28,    25,    13,    29,    14,    30,    36,    36,    40,
      36,    19,    15,    -1,    -1,    37,    36,    -1,    -1,    40,
      37,    -1,    40,    24,    -1,    40,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    40,    40,    40,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    18,    25,
      45,    46,    47,    66,    70,    71,    41,    42,    67,    45,
       6,     0,    45,     6,    40,    41,    45,     6,    66,    66,
      30,     6,    38,    36,    42,    72,    66,    43,    68,    40,
      47,    71,    37,     6,    65,    70,    30,    40,     6,    33,
      36,    70,    75,    77,    98,   101,     6,    39,    38,    48,
      30,    32,    41,    43,    41,    73,    76,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   102,    77,    32,    33,
      69,    34,    35,    40,    49,    70,    65,    65,    40,    65,
      77,    42,     9,    10,    11,    12,    13,    14,    28,    29,
      30,     6,   101,    37,    78,    79,    99,   100,     6,    15,
      16,    17,    20,    22,    27,    39,    40,    48,    50,    51,
      54,    58,    62,    71,    74,    77,    81,    83,    85,    87,
      89,    91,    93,    95,    97,    98,    98,   101,   101,    36,
      63,    36,    40,    70,    36,    52,    36,    40,    43,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    37,    36,
      77,    40,    19,    48,    77,    40,    77,    37,    37,    15,
      55,    37,    59,    40,    36,    40,    64,    48,    77,    77,
      48,    60,    37,    56,    24,    61,    53,    40,    48,    40,
      77,    57,    37,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    46,    47,    47,    47,
      48,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    52,    53,    51,    55,    56,    57,
      54,    59,    60,    58,    61,    61,    63,    64,    62,    65,
      65,    65,    65,    65,    65,    67,    68,    69,    66,    66,
      66,    66,    66,    70,    70,    72,    73,    74,    71,    71,
      71,    71,    71,    71,    71,    76,    75,    78,    77,    79,
      77,    77,    80,    81,    77,    82,    83,    77,    84,    85,
      77,    86,    87,    77,    88,    89,    77,    90,    91,    77,
      92,    93,    77,    94,    95,    77,    96,    97,    77,    77,
      99,    98,   100,    98,    98,   101,   102,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     1,     1,     1,
       3,     2,     0,     1,     1,     4,     1,     1,     1,     3,
       2,     1,     5,     1,     0,     0,     9,     0,     0,     0,
      12,     0,     0,     8,     2,     0,     0,     0,     7,     3,
       3,     3,     3,     1,     1,     0,     0,     0,     6,     3,
       3,     1,     1,     1,     1,     0,     0,     0,     8,     2,
       6,     5,     6,     4,     1,     0,     5,     0,     4,     0,
       4,     1,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     1,
       0,     4,     0,     4,     1,     3,     0,     3,     1,     1
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
        case 6:
#line 181 "do_while.y" /* yacc.c:1646  */
    {
	if(strcmp((yyvsp[-3].str),"main")!=0)
	{
		printf("goto F%d\n",lnum1);
	}
	if ((yyvsp[-4].ival)!=returntype_func(ct))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush"))) 
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline()); 
	else 
	{ 
		insert((yyvsp[-3].str),FUNCTION,g_addr); 
		insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr); 
		g_addr+=4;
	}
	}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 220 "do_while.y" /* yacc.c:1646  */
    {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) 
						storereturn(ct,FLOAT); 
					else 
						storereturn(ct,INT); ct++;
					}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "do_while.y" /* yacc.c:1646  */
    {storereturn(ct,VOID); ct++;}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "do_while.y" /* yacc.c:1646  */
    {dw1();}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 232 "do_while.y" /* yacc.c:1646  */
    {dw2();}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 235 "do_while.y" /* yacc.c:1646  */
    {f1();}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 235 "do_while.y" /* yacc.c:1646  */
    {f2();}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 235 "do_while.y" /* yacc.c:1646  */
    {f3();}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "do_while.y" /* yacc.c:1646  */
    {f4();}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 238 "do_while.y" /* yacc.c:1646  */
    {if1();}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 238 "do_while.y" /* yacc.c:1646  */
    {if2();}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 241 "do_while.y" /* yacc.c:1646  */
    {if3();}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 245 "do_while.y" /* yacc.c:1646  */
    {w1();}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "do_while.y" /* yacc.c:1646  */
    {w2();}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 245 "do_while.y" /* yacc.c:1646  */
    {w3();}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 256 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 256 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"=");}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "do_while.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 257 "do_while.y" /* yacc.c:1646  */
    {
		int sct=returnscope((yyvsp[-5].str),stack[index1-1]); 
		int type=returntype((yyvsp[-5].str),sct); 
		if((!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && type==258 && fl==0) 
			printf("\nError : Type Mismatch : Line %d\n",printline()); 
		if(!lookup((yyvsp[-5].str))) 
		{ 
			int currscope=stack[index1-1]; 
			int scope=returnscope((yyvsp[-5].str),currscope); 
			if((scope<=currscope && end[scope]==0) && !(scope==0)) 
			{
				check_scope_update((yyvsp[-5].str),(yyvsp[-1].str),currscope);
			}
		} 
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "do_while.y" /* yacc.c:1646  */
    {
					if(lookup((yyvsp[-2].str))) 
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
				}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 278 "do_while.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[0].str))) 
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 289 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 289 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"=");}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "do_while.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 290 "do_while.y" /* yacc.c:1646  */
    {
		if( (!(strspn((yyvsp[-2].str),"0123456789")==strlen((yyvsp[-2].str)))) && (yyvsp[-7].ival)==258 && (fl==0)) 
		{
			printf("\nError : Type Mismatch : Line %d\n",printline());
			fl=1;
		} 
		if(!lookup((yyvsp[-6].str))) 
		{
			int currscope=stack[index1-1]; 
			int previous_scope=returnscope((yyvsp[-6].str),currscope); 
			if(currscope==previous_scope) 
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-6].str),printline()); 
			else 
			{
				insert_dup((yyvsp[-6].str),(yyvsp[-7].ival),g_addr,currscope);
				check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
				int sg=returnscope((yyvsp[-6].str),stack[index1-1]); 
				g_addr+=4;
			}
		} 
		else 
		{ 
			int scope=stack[index1-1];  
			insert((yyvsp[-6].str),(yyvsp[-7].ival),g_addr); 
			insertscope((yyvsp[-6].str),scope); 
			check_scope_update((yyvsp[-6].str),(yyvsp[-2].str),stack[index1-1]);
			g_addr+=4;
		}
	}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 320 "do_while.y" /* yacc.c:1646  */
    {
				if(!lookup((yyvsp[-1].str))) 
				{ 
					int currscope=stack[index1-1]; 
					int scope=returnscope((yyvsp[-1].str),currscope); 
					if(!(scope<=currscope && end[scope]==0) || scope==0) 
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				} 
				else 
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline()); 
				}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 332 "do_while.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),ARRAY,g_addr); 
						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr); 
						g_addr+=4; 
					}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 338 "do_while.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),STRUCT,g_addr); 
						g_addr+=4; 
						}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 342 "do_while.y" /* yacc.c:1646  */
    {
				insert((yyvsp[-1].str),STRUCT_VAR,g_addr); 
				g_addr+=4;
				}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 349 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 352 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"+");}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 352 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 353 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"-");}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 353 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 355 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 355 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"<=");}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 355 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 356 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 356 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],">=");}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 356 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 357 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 357 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"==");}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 357 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 358 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 358 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"!=");}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 358 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 359 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 359 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"&&");}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 359 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 360 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 360 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"||");}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 360 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 361 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 361 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"<");}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 361 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 362 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 362 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],">");}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 362 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 363 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 363 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"||");}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 363 "do_while.y" /* yacc.c:1646  */
    {codegen_assign();}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 364 "do_while.y" /* yacc.c:1646  */
    {array1();}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 366 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"*");}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 366 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 367 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"/");}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 367 "do_while.y" /* yacc.c:1646  */
    {codegen();}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 370 "do_while.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[-1].str);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 371 "do_while.y" /* yacc.c:1646  */
    {strcpy(st1[++top],"-");}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 371 "do_while.y" /* yacc.c:1646  */
    {codegen_umin();}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 372 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));fl=1;}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 373 "do_while.y" /* yacc.c:1646  */
    {push((yyvsp[0].str));}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2078 "y.tab.c" /* yacc.c:1646  */
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
#line 376 "do_while.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>


int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	yyparse();
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

void yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}
int printline()
{
	return yylineno;
}
