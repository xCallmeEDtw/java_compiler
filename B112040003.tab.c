/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "B112040003.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LINE_LEN 1024
#define returnDollarLEN 200
#define IDLISTSIZE 200
#define IDLEN 200
#define STACKSIZE 500

extern int eol_numbers[MAX_LINES];
extern int line_numbers[MAX_LINES];
extern char *lines[MAX_LINES];
extern FILE *yyin;
extern total_lines;
extern count_newlines(const char *str);
extern printerror;

int countchar;
int printerror =0;
int yyparse();
int line_number1 = 0;
int errlineno = 0 ;
int counts =0;
struct st_func{
	int size;
	char scope_name[IDLEN];
	char idlist[IDLISTSIZE][IDLEN];
};
typedef struct st_func ST;

struct mystack{
	int size;
	ST list[STACKSIZE];
}table;
typedef struct mystack STACK;

void into_scope(char str[]);
void add_id(char str[]);
void out_scope();
void print_current();
int check_sameid(char str[]);
int check_exist(char str[]);
void int_to_3char(int value, char out[3]);
int remove_spaces(char* str);

int sem_def;
void yyerror(const char *str);

static int lineno = 1;

void print_lineno(char str[], int addsemi);
void substr(char str[], int begin, int end);

void func_name(char in[], char out[]);





#line 133 "B112040003.tab.c"

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

#include "B112040003.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Identifier = 3,                 /* Identifier  */
  YYSYMBOL_COMMENT = 4,                    /* COMMENT  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_BREAK = 6,                      /* BREAK  */
  YYSYMBOL_BYTE = 7,                       /* BYTE  */
  YYSYMBOL_CASE = 8,                       /* CASE  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_CATCH = 10,                     /* CATCH  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_EXTENDS = 18,                   /* EXTENDS  */
  YYSYMBOL_FALSE2 = 19,                    /* FALSE2  */
  YYSYMBOL_FINAL = 20,                     /* FINAL  */
  YYSYMBOL_FINALLY = 21,                   /* FINALLY  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_IMPLEMENTS = 25,                /* IMPLEMENTS  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_LONG = 27,                      /* LONG  */
  YYSYMBOL_MAIN = 28,                      /* MAIN  */
  YYSYMBOL_NEW = 29,                       /* NEW  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_PRIVATE = 31,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 32,                 /* PROTECTED  */
  YYSYMBOL_PUBLIC = 33,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_STATIC = 36,                    /* STATIC  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_SWITCH = 38,                    /* SWITCH  */
  YYSYMBOL_THIS = 39,                      /* THIS  */
  YYSYMBOL_TRUE2 = 40,                     /* TRUE2  */
  YYSYMBOL_TRY = 41,                       /* TRY  */
  YYSYMBOL_VOID = 42,                      /* VOID  */
  YYSYMBOL_WHILE = 43,                     /* WHILE  */
  YYSYMBOL_READ = 44,                      /* READ  */
  YYSYMBOL_INTEGER = 45,                   /* INTEGER  */
  YYSYMBOL_REAL = 46,                      /* REAL  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_PPLUS = 48,                     /* PPLUS  */
  YYSYMBOL_MMINUS = 49,                    /* MMINUS  */
  YYSYMBOL_SEQUAL = 50,                    /* SEQUAL  */
  YYSYMBOL_BEQUAL = 51,                    /* BEQUAL  */
  YYSYMBOL_EQUAL = 52,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 53,                    /* NEQUAL  */
  YYSYMBOL_AND = 54,                       /* AND  */
  YYSYMBOL_OR = 55,                        /* OR  */
  YYSYMBOL_EMPTYLINE = 56,                 /* EMPTYLINE  */
  YYSYMBOL_57_ = 57,                       /* ';'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ','  */
  YYSYMBOL_62_ = 62,                       /* '['  */
  YYSYMBOL_63_ = 63,                       /* ']'  */
  YYSYMBOL_64_ = 64,                       /* '*'  */
  YYSYMBOL_65_ = 65,                       /* '<'  */
  YYSYMBOL_66_ = 66,                       /* '>'  */
  YYSYMBOL_67_ = 67,                       /* '/'  */
  YYSYMBOL_68_ = 68,                       /* '.'  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_71_ = 71,                       /* '%'  */
  YYSYMBOL_72_ = 72,                       /* '!'  */
  YYSYMBOL_73_ = 73,                       /* '{'  */
  YYSYMBOL_74_ = 74,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_printnumber = 76,               /* printnumber  */
  YYSYMBOL_declaration = 77,               /* declaration  */
  YYSYMBOL_class_declr = 78,               /* class_declr  */
  YYSYMBOL_new_obj = 79,                   /* new_obj  */
  YYSYMBOL_class_body = 80,                /* class_body  */
  YYSYMBOL_method_declr = 81,              /* method_declr  */
  YYSYMBOL_method_declr_parem = 82,        /* method_declr_parem  */
  YYSYMBOL_method_modifier = 83,           /* method_modifier  */
  YYSYMBOL_assign = 84,                    /* assign  */
  YYSYMBOL_arrinit = 85,                   /* arrinit  */
  YYSYMBOL_arrinit_expr = 86,              /* arrinit_expr  */
  YYSYMBOL_conditional = 87,               /* conditional  */
  YYSYMBOL_boolean_expr = 88,              /* boolean_expr  */
  YYSYMBOL_infixop = 89,                   /* infixop  */
  YYSYMBOL_loop = 90,                      /* loop  */
  YYSYMBOL_for_parem = 91,                 /* for_parem  */
  YYSYMBOL_forinitop = 92,                 /* forinitop  */
  YYSYMBOL_forupdate = 93,                 /* forupdate  */
  YYSYMBOL_type = 94,                      /* type  */
  YYSYMBOL_simple = 95,                    /* simple  */
  YYSYMBOL_name = 96,                      /* name  */
  YYSYMBOL_identifier_list = 97,           /* identifier_list  */
  YYSYMBOL_identifier_list_char = 98,      /* identifier_list_char  */
  YYSYMBOL_expr = 99,                      /* expr  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_factor = 101,                   /* factor  */
  YYSYMBOL_prefixOp = 102,                 /* prefixOp  */
  YYSYMBOL_postfixOp = 103,                /* postfixOp  */
  YYSYMBOL_const_expr = 104,               /* const_expr  */
  YYSYMBOL_compound = 105,                 /* compound  */
  YYSYMBOL_function = 106,                 /* function  */
  YYSYMBOL_main_func = 107,                /* main_func  */
  YYSYMBOL_func_parem = 108,               /* func_parem  */
  YYSYMBOL_func_return = 109,              /* func_return  */
  YYSYMBOL_leftcurly = 110,                /* leftcurly  */
  YYSYMBOL_rightcurly = 111                /* rightcurly  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1883

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  409

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    71,     2,     2,
      59,    60,    64,    69,    61,    70,    68,    67,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      65,    58,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,    74,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    93,    97,   102,   106,   119,   123,   127,
     130,   140,   152,   157,   161,   165,   168,   171,   174,   178,
     182,   186,   190,   194,   201,   202,   210,   219,   228,   237,
     246,   256,   266,   276,   286,   294,   302,   308,   316,   325,
     331,   335,   339,   344,   345,   346,   348,   353,   362,   370,
     378,   382,   390,   398,   406,   418,   419,   424,   428,   432,
     436,   440,   444,   448,   452,   456,   462,   463,   467,   469,
     470,   471,   472,   473,   474,   476,   480,   484,   488,   492,
     496,   500,   504,   509,   513,   517,   521,   525,   529,   533,
     537,   541,   545,   546,   547,   551,   556,   557,   561,   565,
     570,   570,   570,   570,   570,   570,   572,   578,   582,   587,
     593,   599,   603,   605,   606,   610,   616,   623,   628,   641,
     649,   657,   666,   667,   704,   710,   718,   726,   735,   736,
     742,   743,   747,   751,   755,   759,   763,   767,   771,   775,
     780,   785,   789,   791,   792,   796,   802,   807,   815,   823,
     830,   831,   832,   836,   839,   842,   852,   860,   868,   876,
     884,   888,   893,   902,   913,   917,   922,   926,   930,   931,
     932,   936,   937,   941,   945,   949,   953,   957,   961,   966,
     967,   973,   977,   983,   987,   992,   993,   998,  1002,  1006,
    1008,  1013
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "Identifier",
  "COMMENT", "BOOLEAN", "BREAK", "BYTE", "CASE", "CHAR", "CATCH", "CLASS",
  "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "EXTENDS",
  "FALSE2", "FINAL", "FINALLY", "FLOAT", "FOR", "IF", "IMPLEMENTS", "INT",
  "LONG", "MAIN", "NEW", "PRINT", "PRIVATE", "PROTECTED", "PUBLIC",
  "RETURN", "SHORT", "STATIC", "STRING", "SWITCH", "THIS", "TRUE2", "TRY",
  "VOID", "WHILE", "READ", "INTEGER", "REAL", "ID", "PPLUS", "MMINUS",
  "SEQUAL", "BEQUAL", "EQUAL", "NEQUAL", "AND", "OR", "EMPTYLINE", "';'",
  "'='", "'('", "')'", "','", "'['", "']'", "'*'", "'<'", "'>'", "'/'",
  "'.'", "'+'", "'-'", "'%'", "'!'", "'{'", "'}'", "$accept",
  "printnumber", "declaration", "class_declr", "new_obj", "class_body",
  "method_declr", "method_declr_parem", "method_modifier", "assign",
  "arrinit", "arrinit_expr", "conditional", "boolean_expr", "infixop",
  "loop", "for_parem", "forinitop", "forupdate", "type", "simple", "name",
  "identifier_list", "identifier_list_char", "expr", "term", "factor",
  "prefixOp", "postfixOp", "const_expr", "compound", "function",
  "main_func", "func_parem", "func_return", "leftcurly", "rightcurly", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-311)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-200)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -311,  1417,  -311,    -2,  -311,  -311,   -12,   -34,  -311,    39,
    -311,    50,    81,  -311,   107,   120,  -311,  -311,  -311,    39,
      -8,  -311,   132,   137,  -311,  -311,   492,    16,   159,  -311,
    -311,   353,   116,   238,   161,    95,  -311,  -311,  -311,    39,
    -311,   156,  -311,     4,  -311,   604,  1790,    51,    93,  -311,
    -311,  -311,  -311,  -311,    77,   -35,   170,   158,  -311,   150,
    -311,  -311,    13,  1758,  1705,   167,   353,    13,  1360,   161,
     186,  -311,  -311,    59,   203,   353,  -311,  -311,  -311,  -311,
     106,   -33,   230,  -311,  -311,  -311,  -311,   126,  -311,  -311,
     209,  -311,   200,   281,   201,  -311,   210,   214,   353,   286,
     161,   217,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  1742,
    -311,  -311,  1742,  1761,  1776,   353,   229,   246,  1742,  1742,
    1742,  -311,    48,    17,   216,   232,   249,   245,    48,  -311,
    1474,   143,  -311,   124,   188,   241,   248,   253,    85,   252,
    1813,   150,   317,  -311,  1652,   255,   260,   265,   297,   264,
      65,   278,   285,  -311,   533,  -311,   290,   284,  -311,   430,
      13,   292,    13,  -311,  -311,   533,  -311,   381,   291,  -311,
    -311,    74,  -311,  -311,   289,  -311,   289,  -311,   533,  -311,
    -311,  -311,  -311,  -311,    77,  -311,   299,   305,    48,  -311,
     306,   339,  -311,   542,   324,  1671,  1531,   298,   612,  1012,
    1078,   678,   422,  -311,   744,   318,  1588,   331,   321,   267,
     328,   244,   476,  1689,   207,  1652,  1588,   334,  -311,  1588,
     325,  1652,   336,   341,  -311,  -311,  -311,   932,   150,   108,
     344,   349,  -311,    13,  -311,   353,  -311,   347,   150,  -311,
     379,    39,  -311,  -311,   150,  -311,  1813,   810,  -311,  -311,
    -311,  -311,   942,   352,  1144,  -311,  1588,  -311,  -311,  -311,
    -311,  -311,   298,   355,   244,   182,   368,   372,  -311,  -311,
     267,    56,  -311,  -311,  1588,   267,   364,   409,  1588,   298,
    -311,   298,   380,  -311,  1588,  -311,   373,   -27,   374,  1588,
    -311,  -311,  1210,    25,   119,  -311,  -311,   150,   353,    39,
     371,  1588,  -311,  -311,  -311,  1276,  -311,   298,   876,   378,
    -311,  -311,  -311,  -311,  -311,   298,  -311,   267,  1622,   298,
    -311,  -311,   390,   298,   384,  -311,  1210,    43,   298,   298,
    -311,  -311,  1210,    39,   393,   353,   298,   467,   395,   396,
     298,  -311,  1342,  -311,  -311,   413,  -311,  -311,  -311,  -311,
    1588,   423,   399,  -311,  -311,   298,  -311,  -311,  1210,  -311,
    -311,   298,  -311,  -311,    39,   298,  -311,   353,   415,   401,
    -311,  -311,   405,   298,  1622,   150,  -311,   298,  -311,  -311,
    -311,  -311,  -311,   403,  -311,   421,  -311,  -311,  -311,  1588,
    1588,  -311,  -311,   407,   298,   298,   428,  -311,  -311,   411,
     410,   433,   427,   441,   435,   456,   440,   457,  -311
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,     1,   152,     2,   110,   111,     0,    75,     0,
     113,     0,     0,   112,     0,     0,    53,    54,    55,     0,
     161,   115,     0,     0,   174,   175,   123,     0,     0,    10,
     122,     0,     0,     0,     0,     0,     5,    19,     4,     0,
       7,     0,     9,     0,     6,   158,     0,   140,   153,   163,
     164,   160,   165,    11,    16,     0,     0,   138,    15,     0,
     111,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   173,     0,     0,     0,   166,   167,   152,   161,
     123,   158,     0,   168,   170,   169,   171,   123,   159,     3,
       0,     8,     0,   128,   132,    13,     0,     0,     0,     0,
       0,     0,   149,   150,    83,    84,    79,    80,   121,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,   135,     0,     0,    59,     0,   200,
       0,   128,    18,     0,     0,   102,     0,     0,     0,     0,
      76,     0,     0,    17,     0,     0,     0,     0,     0,     0,
     123,     0,     0,   124,   151,   162,     0,     0,    14,     0,
       0,   129,     0,   119,   120,    56,   191,   195,     0,   157,
     116,   123,   143,   144,   147,   141,   148,   142,    77,   145,
     146,   154,   155,   156,     0,   137,     0,     0,     0,    60,
      57,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,   103,   100,
       0,     0,     0,     0,   128,     0,     0,     0,    87,     0,
       0,     0,     0,     0,   125,   126,   127,     0,     0,     0,
       0,     0,   131,     0,   133,     0,   192,    58,     0,   136,
       0,     0,    35,    27,     0,   198,    76,     0,    33,   201,
      20,    29,     0,     0,     0,   183,     0,   185,    24,    27,
      30,   184,     0,     0,     0,     0,     0,     0,    97,   106,
      98,     0,   104,    89,     0,    99,     0,    67,     0,     0,
     117,     0,     0,    85,     0,   118,     0,     0,     0,     0,
      45,    46,     0,     0,    49,   130,   196,     0,     0,     0,
       0,     0,    28,    27,   190,     0,   182,     0,     0,     0,
     105,   109,   107,   108,    94,     0,    95,    96,     0,     0,
     193,    88,     0,     0,     0,    48,     0,     0,     0,     0,
      42,    44,     0,     0,    51,     0,     0,    65,     0,     0,
       0,   177,     0,    32,    27,     0,    90,    93,    73,    69,
       0,    68,     0,    86,    21,     0,    43,    47,     0,   194,
      38,     0,    40,    50,     0,     0,    64,     0,     0,     0,
     188,   187,     0,     0,     0,     0,    39,     0,    41,    36,
      52,    63,    66,     0,    62,     0,    70,    74,    71,     0,
       0,    37,    61,     0,     0,     0,     0,    72,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,    28,  -311,  -311,  -177,   510,  -218,  -311,   -43,
      -3,  -310,     0,   -23,  -311,   513,  -311,  -205,  -253,    14,
      -1,   -26,   -55,   -91,     3,   620,  -311,  -311,  -191,   256,
     105,   444,   525,   294,  -311,   -45,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,   253,    36,    37,   197,   198,   230,    39,   161,
      94,   336,   199,    41,   115,   200,   136,   137,   268,   138,
     254,    45,    95,    58,   202,    47,    48,    49,    50,    51,
     203,    52,   204,   168,   205,   256,   250
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    40,   101,    57,    46,    81,   272,   132,    88,   288,
     125,   124,   143,    59,   130,    43,   242,   314,   269,   248,
    -114,   251,   316,    62,   258,   365,    99,   260,   126,    35,
     325,   185,    92,    67,    82,    54,   100,   192,    81,  -114,
      81,   139,    81,   147,     5,   146,   129,   151,    60,    81,
      55,    93,    56,    90,  -114,   -78,  -114,   382,   -78,   310,
     131,    10,   186,    76,   347,    13,    55,   140,    56,   142,
     302,   140,    81,    81,   169,    55,    61,    56,   154,   269,
     187,    21,   331,    81,   269,   206,    81,    81,    81,    81,
     208,   135,    81,    81,    81,   184,   216,   239,   129,   219,
     357,   165,   167,    70,   149,   232,   150,   234,    81,    63,
      55,   210,    56,     5,    98,   363,   129,    60,   178,    57,
     116,   117,    71,    72,   121,    57,   269,    73,   225,   201,
      10,   343,   214,    74,    13,    98,    73,   140,   122,   123,
      64,   124,    74,   218,    43,    61,   380,    55,   206,    56,
      21,   206,    89,   206,    71,    72,   206,   118,   196,   206,
     119,    24,    25,    83,   120,   290,    65,   274,    73,    81,
     278,    70,   245,   231,    74,    75,   284,    98,   295,    66,
     333,   129,    98,   289,   292,    57,   207,    81,    73,     3,
     276,    68,   201,   298,    74,   201,    69,   201,   246,   301,
     201,    98,   206,   201,   160,   123,    77,    43,    87,    81,
      43,   273,    43,    91,   277,    43,   140,   127,    43,   128,
     283,   196,   311,   129,   196,    79,   196,   141,   208,   196,
      71,    72,   196,    24,    25,    80,    27,    28,   167,   135,
      98,   231,   326,   291,   148,   209,   201,    31,   332,     5,
     153,   334,   335,     6,   158,   300,   156,    32,    33,   157,
      34,    43,   162,   206,     9,    98,    10,   163,   160,   123,
      13,   164,    81,   350,   170,   196,   179,   188,   102,   103,
      19,    61,   358,    24,    25,    85,    21,    78,    84,    86,
     155,   271,   135,   180,   109,   189,   190,   112,   243,   113,
     114,   337,   211,   191,   255,   257,   259,   201,   212,    81,
     213,   262,   215,   338,   265,   266,   267,   349,   348,   220,
     221,   279,    43,    79,   281,   222,   223,   224,   158,   389,
     390,    24,    25,    80,    27,    28,   196,    99,   337,    98,
     159,    81,   160,   123,   228,    31,   166,   231,   226,   227,
     308,   236,   303,   233,    78,    32,    33,   304,    34,   306,
    -174,   307,   237,   238,   240,   102,   103,   320,   241,   321,
     337,   244,   249,   388,   387,   261,   263,   217,   231,   315,
     330,   109,   264,   319,   112,   270,   113,   114,   286,   323,
      79,   280,   282,   285,   328,   342,   294,   329,    24,    25,
      80,    27,    28,   346,   293,   297,   340,   351,   299,   305,
     341,   353,    31,   344,   356,   312,   359,   360,   309,   313,
     362,   317,    32,    33,   366,    34,   318,   322,   370,   102,
     103,   355,   324,   339,   327,     5,   345,   361,   352,    60,
     374,   369,   235,   376,   354,   109,   378,   371,   112,   379,
     113,   114,    10,   381,   364,   373,    13,   368,   372,   375,
     383,   386,   385,   377,   384,   391,   392,    61,   393,   396,
     102,   103,    21,   399,   400,   401,   -91,    78,   402,   108,
     -91,   -91,   397,   398,   403,   -91,   109,   -91,   404,   112,
     229,   113,   114,   -91,   394,   395,   -91,   405,   -91,   -91,
     -91,   406,   -91,   407,   -91,   408,    15,   -91,   -91,   -91,
     -91,    38,   -91,    79,    42,   102,   103,   152,   -91,   -91,
      23,    24,    25,    80,    27,    28,    53,     0,   367,   296,
       0,   109,   -91,    30,   112,    31,   113,   114,     0,    70,
      71,    72,     0,   193,     0,    32,    33,     5,    34,   129,
     -91,     6,     0,   194,    73,     0,     0,     0,     0,     8,
      74,    75,     9,     0,    10,    11,    12,     0,    13,     0,
      14,     0,    15,    16,    17,    18,   195,     0,    19,    20,
       0,   102,   103,     0,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,     0,   109,     0,    30,
     112,    31,   113,   114,     0,     0,  -152,     0,     0,  -152,
       0,    32,    33,   193,    34,   129,   -34,     5,     0,     0,
       0,     6,     0,   194,     0,     0,     0,     0,     0,     8,
       0,     0,     9,     0,    10,    11,    12,     0,    13,     0,
      14,     0,    15,    16,    17,    18,   195,     0,    19,    20,
       0,     0,    96,    97,    21,    22,    23,    24,    25,    26,
      27,    28,    98,    99,     0,     0,     0,     0,     0,    30,
       0,    31,     0,   100,     0,     0,     0,     0,     0,   193,
       0,    32,    33,     5,    34,   129,   -25,     6,     0,   194,
       0,     0,     0,     0,     0,     8,     0,     0,     9,     0,
      10,    11,    12,     0,    13,     0,    14,     0,    15,    16,
      17,    18,   195,     0,    19,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,     0,   172,
       0,     0,   173,   175,   177,    30,     0,    31,   181,   182,
     183,     0,     0,     0,     0,   193,     0,    32,    33,     5,
      34,   129,   -23,     6,     0,   194,     0,     0,     0,     0,
       0,     8,     0,     0,     9,     0,    10,    11,    12,     0,
      13,     0,    14,     0,    15,    16,    17,    18,   195,     0,
      19,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    31,     0,     0,     0,     0,     0,     0,
       0,   193,     0,    32,    33,     5,    34,   129,   -26,     6,
       0,   194,     0,     0,     0,     0,     0,     8,     0,     0,
       9,     0,    10,    11,    12,     0,    13,     0,    14,     0,
      15,    16,    17,    18,   195,     0,    19,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,     0,   193,     0,    32,
      33,     5,    34,   129,   -22,     6,     0,   194,     0,     0,
       0,     0,     0,     8,     0,     0,     9,     0,    10,    11,
      12,     0,    13,     0,    14,     0,    15,    16,    17,    18,
     195,     0,    19,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,     0,     5,     0,     0,
       0,    60,     0,   252,     0,    32,    33,     5,    34,   129,
     -31,     6,     0,   194,    10,     0,     0,     0,    13,     8,
       0,     0,     9,     0,    10,    11,    12,     0,    13,    61,
       0,     0,    15,     0,    21,     0,   195,     0,    19,    20,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,   287,     0,     0,     0,     0,     0,     0,    30,
       0,    31,     0,     0,     0,     0,  -152,     0,     0,  -152,
       0,    32,    33,   252,    34,   129,  -189,     5,     0,     0,
       0,     6,     0,   194,     0,     0,     0,     0,     0,     8,
       0,     0,     9,     0,    10,    11,    12,     0,    13,     0,
       0,     0,    15,     0,     0,     0,   195,     0,    19,    20,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    31,     0,     0,     0,     0,     0,     0,     0,   252,
       0,    32,    33,     5,    34,   129,  -179,     6,     0,   194,
       0,     0,     0,     0,     0,     8,     0,     0,     9,     0,
      10,    11,    12,     0,    13,     0,     0,     0,    15,     0,
       0,     0,   195,     0,    19,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    31,     0,     0,
       0,     0,     0,     0,     0,   252,     0,    32,    33,     5,
      34,   129,  -181,     6,     0,   194,     0,     0,     0,     0,
       0,     8,     0,     0,     9,     0,    10,    11,    12,     0,
      13,     0,     0,     0,    15,     0,     0,     0,   195,     0,
      19,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    30,     0,    31,     0,     0,     0,     0,     0,     0,
       0,   252,     0,    32,    33,     5,    34,   129,  -178,     6,
       0,   194,     0,     0,     0,     0,     0,     8,     0,     0,
       9,     0,    10,    11,    12,     0,    13,     0,     0,     0,
      15,     0,     0,     0,   195,     0,    19,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,     0,   252,     0,    32,
      33,     5,    34,   129,   249,     6,     0,   194,     0,     0,
       0,     0,     0,     8,     0,     0,     9,     0,    10,    11,
      12,     0,    13,     0,     0,     0,    15,     0,     0,     0,
     195,     0,    19,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,     0,     0,     0,     0,
       0,     0,     0,   252,     0,    32,    33,     5,    34,   129,
    -176,     6,     0,   194,     0,     0,     0,     0,     0,     8,
       0,     3,     9,     0,    10,    11,    12,     0,    13,     0,
       0,     0,    15,     0,     0,     0,   195,     0,    19,    20,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,     0,     0,     0,     0,     0,    79,     0,    30,
       0,    31,     0,     0,     0,    24,    25,    80,    27,    28,
       0,    32,    33,     0,    34,   129,  -186,     2,     3,    31,
     144,     4,     5,     0,   145,     0,     6,     0,     7,    32,
      33,     0,    34,     0,     8,     0,     0,     9,     0,    10,
      11,    12,     0,    13,     0,    14,     0,    15,    16,    17,
      18,     0,     0,    19,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,    29,    30,   193,    31,     0,     0,     5,
       0,     0,     0,     6,     0,   194,    32,    33,     0,    34,
       0,     8,     0,     0,     9,     0,    10,    11,    12,     0,
      13,     0,    14,     0,    15,    16,    17,    18,   195,     0,
      19,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
       0,    30,   193,    31,     0,     0,     5,     0,     0,     0,
       6,     0,   194,    32,    33,     0,    34,   129,     8,     0,
       0,     9,     0,    10,    11,    12,     0,    13,     0,    14,
       0,    15,    16,    17,    18,   195,     0,    19,    20,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,   247,   252,
      31,     0,     0,     5,     0,     0,     0,     6,     0,   194,
      32,    33,     0,    34,   129,     8,     0,     0,     9,     0,
      10,    11,    12,     0,    13,     0,     0,     0,    15,     0,
       0,     0,   195,    78,    19,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     8,
       0,     0,     0,     0,     0,    30,    12,    31,     0,     0,
       0,     0,    15,    78,     0,     0,     0,    32,    33,    79,
      34,   129,     0,     0,     0,     0,    23,    24,    25,    80,
      27,    28,     3,     0,     0,     0,     0,     0,     0,    30,
       0,    31,    15,     0,     0,     0,     0,     0,     0,    79,
       3,    32,    33,     0,    34,   129,    23,    24,    25,    80,
      27,    28,     0,     0,     0,     0,     3,     0,    79,    30,
       0,    31,     0,     0,     0,     0,    24,    25,    80,    27,
      28,    32,    33,     0,    34,   129,    79,     0,  -199,     0,
      31,     0,     0,     0,    24,    25,    80,    27,    28,     0,
      32,    33,    79,    34,     0,     0,   275,     0,    31,     0,
      24,    25,    80,    27,    28,     0,     0,     0,    32,    33,
       0,    34,     0,     5,    31,     0,     0,     6,     0,     0,
       0,     0,     0,     0,    32,    33,     0,    34,     9,    79,
      10,     0,     0,     0,    13,     0,     0,    24,    25,   171,
      27,    28,     0,     0,    19,    61,     0,     0,    79,     0,
      21,    31,     0,     0,     0,   133,   174,    25,   171,    27,
      28,    32,    33,    79,    34,   134,     0,     0,     0,     0,
      31,   176,    25,   171,    27,    28,     0,     0,     0,     0,
      32,    33,     0,    34,     0,    31,     0,     0,   102,   103,
     104,   105,   106,   107,     0,    32,    33,   108,    34,     0,
       0,     0,     0,     0,   109,   110,   111,   112,     0,   113,
     114,   102,   103,   104,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,     0,   113,   114
};

static const yytype_int16 yycheck[] =
{
       1,     1,    45,     6,     1,    31,   211,    62,    34,   227,
      45,    54,    67,    47,    59,     1,   193,   270,   209,   196,
      28,   198,   275,     9,   201,   335,    59,   204,    63,     1,
      57,   122,    28,    19,    31,    47,    69,   128,    64,    47,
      66,    64,    68,    69,     5,    68,    73,    73,     9,    75,
      62,    47,    64,    39,    62,    57,    64,   367,    60,   264,
      47,    22,    45,    47,   317,    26,    62,    64,    64,    66,
     247,    68,    98,    99,   100,    62,    37,    64,    75,   270,
      63,    42,    57,   109,   275,   130,   112,   113,   114,   115,
     133,    63,   118,   119,   120,    47,   141,   188,    73,   144,
      57,    98,    99,    47,    45,   160,    47,   162,   134,    59,
      62,   134,    64,     5,    58,   333,    73,     9,   115,   122,
      69,    70,    48,    49,    47,   128,   317,    62,    63,   130,
      22,   308,    47,    68,    26,    58,    62,   134,    61,    62,
      59,   184,    68,   144,   130,    37,   364,    62,   193,    64,
      42,   196,    57,   198,    48,    49,   201,    64,   130,   204,
      67,    45,    46,    47,    71,    57,    59,   212,    62,   195,
     215,    47,   195,   159,    68,    69,   221,    58,   233,    59,
      61,    73,    58,   228,   229,   188,    62,   213,    62,     1,
     213,    59,   193,   238,    68,   196,    59,   198,   195,   244,
     201,    58,   247,   204,    61,    62,    47,   193,    47,   235,
     196,   212,   198,    57,   215,   201,   213,    47,   204,    61,
     221,   193,   265,    73,   196,    37,   198,    60,   271,   201,
      48,    49,   204,    45,    46,    47,    48,    49,   235,   211,
      58,   227,   287,   229,    58,    57,   247,    59,   293,     5,
      47,   294,   297,     9,    47,   241,    47,    69,    70,    59,
      72,   247,    61,   308,    20,    58,    22,    57,    61,    62,
      26,    57,   298,   318,    57,   247,    47,    61,    48,    49,
      36,    37,   327,    45,    46,    47,    42,     1,    32,    33,
      60,    47,   264,    47,    64,    63,    47,    67,   193,    69,
      70,   298,    61,    58,   199,   200,   201,   308,    60,   335,
      57,   206,    60,   299,    47,    48,    49,   318,   318,    64,
      60,   216,   308,    37,   219,    60,    29,    63,    47,   374,
     375,    45,    46,    47,    48,    49,   308,    59,   335,    58,
      59,   367,    61,    62,    60,    59,    60,   333,    63,    59,
     262,    60,   247,    61,     1,    69,    70,   252,    72,   254,
      71,   256,    63,    58,    58,    48,    49,   279,    29,   281,
     367,    47,    74,   374,   374,    57,    45,    60,   364,   274,
     292,    64,    61,   278,    67,    57,    69,    70,    47,   284,
      37,    57,    67,    57,   289,   307,    47,   292,    45,    46,
      47,    48,    49,   315,    60,    58,   301,   319,    29,    57,
     305,   323,    59,   308,   326,    47,   328,   329,    63,    47,
     332,    57,    69,    70,   336,    72,    17,    47,   340,    48,
      49,   326,    59,    62,    60,     5,    58,   332,    48,     9,
      17,    45,    61,   355,    60,    64,   358,   342,    67,   361,
      69,    70,    22,   365,    61,   350,    26,    62,    45,    60,
      45,   373,    57,   358,    63,   377,    63,    37,    47,    62,
      48,    49,    42,    45,    63,    65,     0,     1,    45,    57,
       4,     5,   394,   395,    57,     9,    64,    11,    47,    67,
      60,    69,    70,    17,   389,   390,    20,    62,    22,    23,
      24,    45,    26,    63,    28,    48,    30,    31,    32,    33,
      34,     1,    36,    37,     1,    48,    49,    73,    42,    43,
      44,    45,    46,    47,    48,    49,     1,    -1,    61,   235,
      -1,    64,    56,    57,    67,    59,    69,    70,    -1,    47,
      48,    49,    -1,     1,    -1,    69,    70,     5,    72,    73,
      74,     9,    -1,    11,    62,    -1,    -1,    -1,    -1,    17,
      68,    69,    20,    -1,    22,    23,    24,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    -1,    36,    37,
      -1,    48,    49,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    64,    -1,    57,
      67,    59,    69,    70,    -1,    -1,    64,    -1,    -1,    67,
      -1,    69,    70,     1,    72,    73,    74,     5,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,    26,    -1,
      28,    -1,    30,    31,    32,    33,    34,    -1,    36,    37,
      -1,    -1,    48,    49,    42,    43,    44,    45,    46,    47,
      48,    49,    58,    59,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    69,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    69,    70,     5,    72,    73,    74,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    26,    -1,    28,    -1,    30,    31,
      32,    33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,   109,
      -1,    -1,   112,   113,   114,    57,    -1,    59,   118,   119,
     120,    -1,    -1,    -1,    -1,     1,    -1,    69,    70,     5,
      72,    73,    74,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    69,    70,     5,    72,    73,    74,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    -1,    26,    -1,    28,    -1,
      30,    31,    32,    33,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    69,
      70,     5,    72,    73,    74,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    26,    -1,    28,    -1,    30,    31,    32,    33,
      34,    -1,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,     5,    -1,    -1,
      -1,     9,    -1,     1,    -1,    69,    70,     5,    72,    73,
      74,     9,    -1,    11,    22,    -1,    -1,    -1,    26,    17,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,    26,    37,
      -1,    -1,    30,    -1,    42,    -1,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    60,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,
      -1,    69,    70,     1,    72,    73,    74,     5,    -1,    -1,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    69,    70,     5,    72,    73,    74,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    69,    70,     5,
      72,    73,    74,     9,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    69,    70,     5,    72,    73,    74,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    69,
      70,     5,    72,    73,    74,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    -1,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    69,    70,     5,    72,    73,
      74,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,     1,    20,    -1,    22,    23,    24,    -1,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    37,    -1,    57,
      -1,    59,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    69,    70,    -1,    72,    73,    74,     0,     1,    59,
      60,     4,     5,    -1,    64,    -1,     9,    -1,    11,    69,
      70,    -1,    72,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    -1,    26,    -1,    28,    -1,    30,    31,    32,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,     1,    59,    -1,    -1,     5,
      -1,    -1,    -1,     9,    -1,    11,    69,    70,    -1,    72,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    -1,    30,    31,    32,    33,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,     1,    59,    -1,    -1,     5,    -1,    -1,    -1,
       9,    -1,    11,    69,    70,    -1,    72,    73,    17,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      -1,    30,    31,    32,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,     1,
      59,    -1,    -1,     5,    -1,    -1,    -1,     9,    -1,    11,
      69,    70,    -1,    72,    73,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,     1,    36,    37,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    57,    24,    59,    -1,    -1,
      -1,    -1,    30,     1,    -1,    -1,    -1,    69,    70,    37,
      72,    73,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,     1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
       1,    69,    70,    -1,    72,    73,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,     1,    -1,    37,    57,
      -1,    59,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    69,    70,    -1,    72,    73,    37,    -1,    57,    -1,
      59,    -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      69,    70,    37,    72,    -1,    -1,    57,    -1,    59,    -1,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    69,    70,
      -1,    72,    -1,     5,    59,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    72,    20,    37,
      22,    -1,    -1,    -1,    26,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    36,    37,    -1,    -1,    37,    -1,
      42,    59,    -1,    -1,    -1,    47,    45,    46,    47,    48,
      49,    69,    70,    37,    72,    57,    -1,    -1,    -1,    -1,
      59,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      69,    70,    -1,    72,    -1,    59,    -1,    -1,    48,    49,
      50,    51,    52,    53,    -1,    69,    70,    57,    72,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    -1,    69,
      70,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    -1,    69,    70
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    76,     0,     1,     4,     5,     9,    11,    17,    20,
      22,    23,    24,    26,    28,    30,    31,    32,    33,    36,
      37,    42,    43,    44,    45,    46,    47,    48,    49,    56,
      57,    59,    69,    70,    72,    77,    78,    79,    81,    83,
      87,    88,    90,    94,    95,    96,    99,   100,   101,   102,
     103,   104,   106,   107,    47,    62,    64,    85,    98,    47,
       9,    37,    94,    59,    59,    59,    59,    94,    59,    59,
      47,    48,    49,    62,    68,    69,    47,    47,     1,    37,
      47,    96,    99,    47,   104,    47,   104,    47,    96,    57,
      94,    57,    28,    47,    85,    97,    48,    49,    58,    59,
      69,    84,    48,    49,    50,    51,    52,    53,    57,    64,
      65,    66,    67,    69,    70,    89,    69,    70,    64,    67,
      71,    47,    61,    62,    84,    45,    63,    47,    61,    73,
     110,    47,    97,    47,    57,    77,    91,    92,    94,    88,
      99,    60,    99,    97,    60,    64,    88,    96,    58,    45,
      47,    96,   106,    47,    99,    60,    47,    59,    47,    59,
      61,    84,    61,    57,    57,    99,    60,    99,   108,    96,
      57,    47,   100,   100,    45,   100,    45,   100,    99,    47,
      47,   100,   100,   100,    47,    98,    45,    63,    61,    63,
      47,    58,    98,     1,    11,    34,    77,    80,    81,    87,
      90,    95,    99,   105,   107,   109,   110,    62,    84,    57,
      88,    61,    60,    57,    47,    60,   110,    60,    95,   110,
      64,    60,    60,    29,    63,    63,    63,    59,    60,    60,
      82,    94,    97,    61,    97,    61,    60,    63,    58,    98,
      58,    29,    80,   105,    47,    88,    99,    57,    80,    74,
     111,    80,     1,    77,    95,   105,   110,   105,    80,   105,
      80,    57,   105,    45,    61,    47,    48,    49,    93,   103,
      57,    47,    92,    95,   110,    57,    88,    95,   110,   105,
      57,   105,    67,    95,   110,    57,    47,    60,    82,   110,
      57,    94,   110,    60,    47,    97,   108,    58,   110,    29,
      94,   110,    80,   105,   105,    57,   105,   105,   111,    63,
      92,    84,    47,    47,    93,   105,    93,    57,    17,   105,
     111,   111,    47,   105,    59,    57,   110,    60,   105,   105,
     111,    57,   110,    61,    84,   110,    86,    99,    94,    62,
     105,   105,   111,    80,   105,    58,   111,    93,    87,    95,
     110,   111,    48,   111,    60,   105,   111,    57,   110,   111,
     111,   105,   111,    82,    61,    86,   111,    61,    62,    45,
     111,   105,    45,   105,    17,    60,   111,   105,   111,   111,
      82,   111,    86,    45,    63,    57,   111,    87,    95,   110,
     110,   111,    63,    47,   105,   105,    62,   111,   111,    45,
      63,    65,    45,    57,    47,    62,    45,    63,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      78,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     110,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     2,     2,     3,     2,
       2,     2,     0,     2,     3,     2,     2,     3,     3,     1,
       5,     7,     2,     1,     2,     1,     1,     1,     3,     2,
       2,     3,     4,     2,     1,     2,     8,     9,     7,     8,
       7,     8,     6,     7,     6,     5,     5,     7,     6,     2,
       4,     3,     5,     1,     1,     1,     2,     3,     4,     2,
       3,     9,     8,     8,     7,     1,     3,     5,     7,     7,
       9,     9,    11,     7,     9,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     4,     6,     5,
       7,     4,    11,     5,     4,     4,     4,     3,     3,     3,
       2,    19,     1,     2,     3,     4,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     5,     5,     3,
       3,     2,     1,     1,     3,     4,     4,     4,     1,     2,
       4,     3,     1,     3,     2,     2,     4,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     1,     3,     3,     3,     3,     1,     2,
       1,     1,     3,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     2,     3,     1,     1,
       3,     1,     2,     2,     2,     2,     3,     4,     5,     1,
       2,     3,     4,     6,     7,     1,     3,     2,     2,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* printnumber: printnumber COMMENT  */
#line 79 "B112040003.y"
                                              {  printf("LINE %d: \n",lineno++);  }
#line 1800 "B112040003.tab.c"
    break;

  case 3: /* printnumber: printnumber declaration ';'  */
#line 80 "B112040003.y"
                                             { print_lineno((yyvsp[-1].s),1);  }
#line 1806 "B112040003.tab.c"
    break;

  case 4: /* printnumber: printnumber method_declr  */
#line 81 "B112040003.y"
                                                   { print_lineno((yyvsp[0].s),0);  }
#line 1812 "B112040003.tab.c"
    break;

  case 5: /* printnumber: printnumber class_declr  */
#line 82 "B112040003.y"
                                                      { print_lineno((yyvsp[0].s),0);  }
#line 1818 "B112040003.tab.c"
    break;

  case 6: /* printnumber: printnumber simple  */
#line 83 "B112040003.y"
                                                 { print_lineno((yyvsp[0].s),0);  }
#line 1824 "B112040003.tab.c"
    break;

  case 7: /* printnumber: printnumber conditional  */
#line 84 "B112040003.y"
                                                      { print_lineno((yyvsp[0].s),0); }
#line 1830 "B112040003.tab.c"
    break;

  case 8: /* printnumber: printnumber boolean_expr ';'  */
#line 85 "B112040003.y"
                                                           { print_lineno((yyvsp[-1].s),1);  }
#line 1836 "B112040003.tab.c"
    break;

  case 9: /* printnumber: printnumber loop  */
#line 86 "B112040003.y"
                                               { print_lineno((yyvsp[0].s),0);  }
#line 1842 "B112040003.tab.c"
    break;

  case 10: /* printnumber: printnumber EMPTYLINE  */
#line 87 "B112040003.y"
                                                    { printf("LINE %d: \n",lineno++); }
#line 1848 "B112040003.tab.c"
    break;

  case 11: /* printnumber: printnumber main_func  */
#line 88 "B112040003.y"
                                                    { print_lineno((yyvsp[0].s),0); }
#line 1854 "B112040003.tab.c"
    break;

  case 12: /* printnumber: %empty  */
#line 89 "B112040003.y"
                              { /*empty*/ }
#line 1860 "B112040003.tab.c"
    break;

  case 13: /* declaration: type identifier_list  */
#line 93 "B112040003.y"
                                       {
				(yyval.s) = (char*)malloc(sizeof(char)*3*returnDollarLEN);				
				sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 1869 "B112040003.tab.c"
    break;

  case 14: /* declaration: type ID ID  */
#line 97 "B112040003.y"
                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*3*returnDollarLEN);
					 sprintf((yyval.s),">@Linexxxx, char: ** , a syntax error at '%s' \n%s %s %s;",(yyvsp[0].s),(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));

				}
#line 1879 "B112040003.tab.c"
    break;

  case 15: /* declaration: CHAR identifier_list_char  */
#line 102 "B112040003.y"
                                                   {
				(yyval.s) = (char*)malloc(sizeof(char)*3*returnDollarLEN);				
				sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 1888 "B112040003.tab.c"
    break;

  case 16: /* declaration: CHAR ID  */
#line 106 "B112040003.y"
                                 {
				    (yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);		
					if(check_sameid((yyvsp[0].s))){
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),">@**** '%s' in the next line is a duplicated identifier in the current scope.***\n%s %s",(yyvsp[0].s),(yyvsp[-1].s),(yyvsp[0].s));
					}
					else{ 
 						add_id((yyvsp[0].s));
 						sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
 					}				
			}
#line 1904 "B112040003.tab.c"
    break;

  case 17: /* declaration: STATIC type identifier_list  */
#line 119 "B112040003.y"
                                                      {
				(yyval.s) = (char*)malloc(sizeof(char)*3*returnDollarLEN);	
				sprintf((yyval.s),"static %s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 1913 "B112040003.tab.c"
    break;

  case 18: /* declaration: FINAL type identifier_list  */
#line 123 "B112040003.y"
                                                     {
				(yyval.s) = (char*)malloc(sizeof(char)*3*returnDollarLEN);	
				sprintf((yyval.s),"final %s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 1922 "B112040003.tab.c"
    break;

  case 19: /* declaration: new_obj  */
#line 127 "B112040003.y"
                                  { (yyval.s) = (yyvsp[0].s); }
#line 1928 "B112040003.tab.c"
    break;

  case 20: /* class_declr: CLASS ID leftcurly class_body rightcurly  */
#line 130 "B112040003.y"
                                                          {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s %s \n{\n>'%s' is a duplicate identifier\n%s\n}",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-3].s),(yyvsp[-1].s));
				else{ 
					add_id((yyvsp[-3].s));
					sprintf((yyval.s),"%s %s {\n%s\n}",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-1].s));
				}
			}
#line 1941 "B112040003.tab.c"
    break;

  case 21: /* new_obj: ID ID '=' NEW ID '(' ')'  */
#line 140 "B112040003.y"
                                           {
				if(strcmp((yyvsp[-6].s),(yyvsp[-2].s))!=0) fprintf(stderr,">'%s' typed do not match with newed type '%s'\n",(yyvsp[-6].s),(yyvsp[-2].s));
				(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);	
				/* check if class difined */
				if(check_sameid((yyvsp[-5].s))) sprintf((yyval.s),"%s %s = new %s()\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-2].s),(yyvsp[-5].s));
				else{
					add_id((yyvsp[-5].s));
					sprintf((yyval.s),"%s %s = new %s ( )",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-2].s));
				}
			}
#line 1956 "B112040003.tab.c"
    break;

  case 22: /* class_body: declaration ';'  */
#line 152 "B112040003.y"
                                  {
				(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);	
				sprintf((yyval.s),"%s ;",(yyvsp[-1].s));
			}
#line 1965 "B112040003.tab.c"
    break;

  case 23: /* class_body: simple  */
#line 157 "B112040003.y"
                                {
				(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);	
				sprintf((yyval.s),"%s ;",(yyvsp[0].s));
			}
#line 1974 "B112040003.tab.c"
    break;

  case 24: /* class_body: simple class_body  */
#line 161 "B112040003.y"
                                            {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"%s\n %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 1983 "B112040003.tab.c"
    break;

  case 25: /* class_body: method_declr  */
#line 165 "B112040003.y"
                                       {
				(yyval.s) = (yyvsp[0].s);
			}
#line 1991 "B112040003.tab.c"
    break;

  case 26: /* class_body: main_func  */
#line 168 "B112040003.y"
                                    {
				(yyval.s) = (yyvsp[0].s);
			}
#line 1999 "B112040003.tab.c"
    break;

  case 27: /* class_body: compound  */
#line 171 "B112040003.y"
                                   {
				(yyval.s) = (yyvsp[0].s);
			}
#line 2007 "B112040003.tab.c"
    break;

  case 28: /* class_body: declaration ';' class_body  */
#line 174 "B112040003.y"
                                                     {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"%s ;\n%s",(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2016 "B112040003.tab.c"
    break;

  case 29: /* class_body: method_declr class_body  */
#line 178 "B112040003.y"
                                                  {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"%s\n%s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2025 "B112040003.tab.c"
    break;

  case 30: /* class_body: main_func class_body  */
#line 182 "B112040003.y"
                                               {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"%s\n%s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2034 "B112040003.tab.c"
    break;

  case 31: /* class_body: leftcurly compound rightcurly  */
#line 186 "B112040003.y"
                                                        {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"{\n%s\n}",(yyvsp[-1].s));
			}
#line 2043 "B112040003.tab.c"
    break;

  case 32: /* class_body: leftcurly compound rightcurly class_body  */
#line 190 "B112040003.y"
                                                                   {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf((yyval.s),"{\n%s\n}\n%s",(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2052 "B112040003.tab.c"
    break;

  case 33: /* class_body: declaration class_body  */
#line 194 "B112040003.y"
                                       {
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				printerror = 1;	
				sprintf((yyval.s),"%s \n>@Linexxxx, char: 17, statement without semicolon\n%s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2062 "B112040003.tab.c"
    break;

  case 34: /* class_body: error  */
#line 201 "B112040003.y"
                                { /* error recovery */ (yyval.s) = "ERROR HERE 1"; }
#line 2068 "B112040003.tab.c"
    break;

  case 35: /* class_body: error class_body  */
#line 202 "B112040003.y"
                                           {
					/* error recovery */ 
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					printf("%d\n",errlineno++);
					sprintf((yyval.s),"ERROR HERE 2 \n%s",(yyvsp[0].s));
			}
#line 2079 "B112040003.tab.c"
    break;

  case 36: /* method_declr: type ID '(' method_declr_parem ')' leftcurly compound rightcurly  */
#line 210 "B112040003.y"
                                                                               { /*function*/
				/* ps compound is things inside function(){ HERE } */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-6].s))) sprintf((yyval.s),"%s %s(%s){\n>'%s' is a duplicate identifier\n%s\n}",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-6].s),(yyvsp[-1].s));
				else{
					add_id((yyvsp[-6].s));
					sprintf((yyval.s),"%s %s(%s){\n%s\n}",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s));
				}
			}
#line 2093 "B112040003.tab.c"
    break;

  case 37: /* method_declr: method_modifier type ID '(' method_declr_parem ')' leftcurly compound rightcurly  */
#line 219 "B112040003.y"
                                                                                                           { /*function*/
				/* ps compound is things inside function(){ HERE } */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-6].s))) sprintf((yyval.s),"%s %s %s(%s){\n>'%s' is a duplicate identifier\n%s\n}",(yyvsp[-8].s),(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-6].s),(yyvsp[-1].s));
				else{
					add_id((yyvsp[-6].s));
					sprintf((yyval.s),"%s %s %s(%s){\n%s\n}",(yyvsp[-8].s),(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s));
				}
			}
#line 2107 "B112040003.tab.c"
    break;

  case 38: /* method_declr: type ID '(' ')' leftcurly compound rightcurly  */
#line 228 "B112040003.y"
                                                                         { /*function*/
				/* ps compound is things inside function(){ HERE } */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-5].s))) sem_def = 1;
				else{
					add_id((yyvsp[-5].s));
					sprintf((yyval.s),"%s %s ( ) {\n%s\n}",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-1].s));
				}
			}
#line 2121 "B112040003.tab.c"
    break;

  case 39: /* method_declr: method_modifier type ID '(' ')' leftcurly compound rightcurly  */
#line 237 "B112040003.y"
                                                                                        { /*function*/
				/* ps compound is things inside function(){ HERE } */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-5].s))) sprintf((yyval.s),"%s %s %s(){\n>'%s' is a duplicate identifier\n%s\n}",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-5].s),(yyvsp[-1].s));
				else{ 
					sprintf((yyval.s),"%s %s %s ( ) {\n%s\n}",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-1].s));
 					add_id((yyvsp[-5].s));
 				}
			}
#line 2135 "B112040003.tab.c"
    break;

  case 40: /* method_declr: type ID '(' method_declr_parem ')' leftcurly rightcurly  */
#line 246 "B112040003.y"
                                                                                  { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-5].s))) sprintf((yyval.s),"%s %s(%s){ }\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s),(yyvsp[-5].s));
				else{ 
					sprintf((yyval.s),"%s %s ( %s ) { }",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
 					add_id((yyvsp[-5].s));
 				}
			}
#line 2150 "B112040003.tab.c"
    break;

  case 41: /* method_declr: method_modifier type ID '(' method_declr_parem ')' leftcurly rightcurly  */
#line 256 "B112040003.y"
                                                                                                  { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-5].s))) sprintf((yyval.s),"%s %s %s(%s){ }\n>'%s' is a duplicate identifier",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s),(yyvsp[-5].s));
				else{ 
					sprintf((yyval.s),"%s %s %s ( %s ) { }",(yyvsp[-7].s),(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
 					add_id((yyvsp[-5].s));
 				}
			}
#line 2165 "B112040003.tab.c"
    break;

  case 42: /* method_declr: type ID '(' ')' leftcurly rightcurly  */
#line 266 "B112040003.y"
                                                                { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-4].s))) sprintf((yyval.s),"%s %s(){ }\n>'%s' is a duplicate identifier",(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-4].s));
				else{ 
					sprintf((yyval.s),"%s %s ( ) { }",(yyvsp[-5].s),(yyvsp[-4].s));
					add_id((yyvsp[-4].s));
				}
			}
#line 2180 "B112040003.tab.c"
    break;

  case 43: /* method_declr: method_modifier type ID '(' ')' leftcurly rightcurly  */
#line 276 "B112040003.y"
                                                                               { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-4].s))) sprintf((yyval.s),"%s %s %s(){ }\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-4].s));
				else{ 
					sprintf((yyval.s),"%s %s %s ( ) { }",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-4].s));
 					add_id((yyvsp[-4].s));
 				}
			}
#line 2195 "B112040003.tab.c"
    break;

  case 44: /* method_declr: type ID '(' method_declr_parem ')' ';'  */
#line 286 "B112040003.y"
                                                                 { /* function declaration */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-4].s))) sprintf((yyval.s),"%s %s(%s) ;\n>'%s' is a duplicate identifier",(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-2].s));
				else{ 
					sprintf((yyval.s),"%s %s ( %s ) ;",(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-2].s));
					add_id((yyvsp[-4].s));
				}
			}
#line 2208 "B112040003.tab.c"
    break;

  case 45: /* method_declr: type ID '(' ')' ';'  */
#line 294 "B112040003.y"
                                              { /* function declaration */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s %s() ;\n>'%s' is a duplicate identifier",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-3].s));
				else{ 
					sprintf((yyval.s),"%s %s ( ) ;",(yyvsp[-4].s),(yyvsp[-3].s));
 					add_id((yyvsp[-3].s));
 				}
			}
#line 2221 "B112040003.tab.c"
    break;

  case 46: /* method_declr: type ID '(' ')' type  */
#line 302 "B112040003.y"
                                              { /* function declaration */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
                sprintf((yyval.s),"%s %s ( ) ;\n>'%s' is a no semicolon",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-3].s));

			}
#line 2231 "B112040003.tab.c"
    break;

  case 47: /* method_declr: method_modifier type ID '(' method_declr_parem ')' ';'  */
#line 308 "B112040003.y"
                                                                                 { /* function declaration */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-4].s))) sprintf((yyval.s),"%s %s %s(%s) ;\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[-4].s));
				else{ 
					sprintf((yyval.s),"%s %s %s ( %s ) ;",(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-2].s));
 					add_id((yyvsp[-4].s));
 				}
			}
#line 2244 "B112040003.tab.c"
    break;

  case 48: /* method_declr: method_modifier type ID '(' ')' ';'  */
#line 316 "B112040003.y"
                                                              { /* function declaration */
				(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s %s %s() ;\n>'%s' is a duplicate identifier",(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-3].s));
				else{ 
					sprintf((yyval.s),"%s %s %s ( ) ;",(yyvsp[-5].s),(yyvsp[-4].s),(yyvsp[-3].s));
 					add_id((yyvsp[-3].s));
 				}
			}
#line 2257 "B112040003.tab.c"
    break;

  case 49: /* method_declr_parem: type ID  */
#line 325 "B112040003.y"
                             {
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
					}
#line 2266 "B112040003.tab.c"
    break;

  case 50: /* method_declr_parem: type ID ',' method_declr_parem  */
#line 331 "B112040003.y"
                                                                         {
						(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
						sprintf((yyval.s),"%s %s , %s",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s));
					}
#line 2275 "B112040003.tab.c"
    break;

  case 51: /* method_declr_parem: type ID assign  */
#line 335 "B112040003.y"
                                                        {
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),"%s %s %s",(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
					}
#line 2284 "B112040003.tab.c"
    break;

  case 52: /* method_declr_parem: type ID assign ',' method_declr_parem  */
#line 339 "B112040003.y"
                                                                                {
						(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
						sprintf((yyval.s),"%s %s %s , %s",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s));
					}
#line 2293 "B112040003.tab.c"
    break;

  case 53: /* method_modifier: PRIVATE  */
#line 344 "B112040003.y"
                          { (yyval.s) = (yyvsp[0].s); }
#line 2299 "B112040003.tab.c"
    break;

  case 54: /* method_modifier: PROTECTED  */
#line 345 "B112040003.y"
                                            { (yyval.s) = (yyvsp[0].s); }
#line 2305 "B112040003.tab.c"
    break;

  case 55: /* method_modifier: PUBLIC  */
#line 346 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 2311 "B112040003.tab.c"
    break;

  case 56: /* assign: '=' expr  */
#line 348 "B112040003.y"
                                   { 
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"= %s",(yyvsp[0].s));
				}
#line 2320 "B112040003.tab.c"
    break;

  case 57: /* arrinit: '[' ']' ID  */
#line 353 "B112040003.y"
                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[0].s))) sprintf((yyval.s),"[] %s\n>'%s' is a duplicate identifier",(yyvsp[0].s),(yyvsp[0].s));
					else{ 
						sprintf((yyval.s),"[ ] %s",(yyvsp[0].s));
 						add_id((yyvsp[0].s));

 					}
				}
#line 2334 "B112040003.tab.c"
    break;

  case 58: /* arrinit: ID '[' INTEGER ']'  */
#line 362 "B112040003.y"
                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);		
					if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s[%d]\n>'%s' is a duplicate identifier",(yyvsp[-3].s),(yyvsp[-1].i),(yyvsp[-3].s));
					else{ 
						sprintf((yyval.s),"%s [ %d ]",(yyvsp[-3].s),(yyvsp[-1].i));
 						add_id((yyvsp[-3].s));
 					}
				}
#line 2347 "B112040003.tab.c"
    break;

  case 59: /* arrinit: '*' ID  */
#line 370 "B112040003.y"
                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[0].s))) sprintf((yyval.s),"* %s\n>'%s' is a duplicate identifier",(yyvsp[0].s),(yyvsp[0].s));
					else{ 
						sprintf((yyval.s),"* %s",(yyvsp[0].s));
 						add_id((yyvsp[0].s));
 					}
				}
#line 2360 "B112040003.tab.c"
    break;

  case 60: /* arrinit: '[' INTEGER ']'  */
#line 378 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"[%d]",(yyvsp[-1].i));
				}
#line 2369 "B112040003.tab.c"
    break;

  case 61: /* arrinit: '[' ']' ID '=' NEW type '[' INTEGER ']'  */
#line 382 "B112040003.y"
                                                                          {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-6].s))) sprintf((yyval.s),"[] %s = new %s[%d]\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].i),(yyvsp[-6].s));
					else{ 
						sprintf((yyval.s),"[ ] %s = new %s [ %d ]",(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].i));
 						add_id((yyvsp[-6].s));
 					}
				}
#line 2382 "B112040003.tab.c"
    break;

  case 62: /* arrinit: '*' ID '=' NEW type '[' INTEGER ']'  */
#line 390 "B112040003.y"
                                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-6].s))) sprintf((yyval.s),"*%s = new %s[%d]\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].i),(yyvsp[-6].s));
					else{ 
						sprintf((yyval.s),"*%s = new %s [ %d ]",(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].i));
 						add_id((yyvsp[-6].s));
 					}
				}
#line 2395 "B112040003.tab.c"
    break;

  case 63: /* arrinit: ID '[' INTEGER ']' '=' leftcurly arrinit_expr rightcurly  */
#line 398 "B112040003.y"
                                                                                            {
					(yyval.s) = (char*)malloc(sizeof(char)*8*returnDollarLEN);	
					if(check_sameid((yyvsp[-7].s))) sprintf((yyval.s),"%s[%d] = {%s}\n>'%s' is a duplicate identifier",(yyvsp[-7].s),(yyvsp[-5].i),(yyvsp[-1].s),(yyvsp[-7].s));
					else{ 
						sprintf((yyval.s),"%s [ %d ] = { %s }",(yyvsp[-7].s),(yyvsp[-5].i),(yyvsp[-1].s));
						add_id((yyvsp[-7].s));
					}
				}
#line 2408 "B112040003.tab.c"
    break;

  case 64: /* arrinit: ID '[' ']' '=' leftcurly arrinit_expr rightcurly  */
#line 406 "B112040003.y"
                                                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*8*returnDollarLEN);	
					if(check_sameid((yyvsp[-6].s))) sprintf((yyval.s),"%s[] = {%s}\n>'%s' is a duplicate identifier",(yyvsp[-6].s),(yyvsp[-1].s),(yyvsp[-6].s));
					else{ 
						sprintf((yyval.s),"%s [ ] = { %s }",(yyvsp[-6].s),(yyvsp[-1].s));
						 add_id((yyvsp[-6].s));
					}
				}
#line 2421 "B112040003.tab.c"
    break;

  case 65: /* arrinit_expr: expr  */
#line 418 "B112040003.y"
                       { (yyval.s) = (yyvsp[0].s); }
#line 2427 "B112040003.tab.c"
    break;

  case 66: /* arrinit_expr: expr ',' arrinit_expr  */
#line 419 "B112040003.y"
                                                        {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 2436 "B112040003.tab.c"
    break;

  case 67: /* conditional: IF '(' boolean_expr ')' simple  */
#line 424 "B112040003.y"
                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) %s",(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[0].s)); 
				}
#line 2445 "B112040003.tab.c"
    break;

  case 68: /* conditional: IF '(' boolean_expr ')' leftcurly compound rightcurly  */
#line 428 "B112040003.y"
                                                                                        {
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s));
				}
#line 2454 "B112040003.tab.c"
    break;

  case 69: /* conditional: IF '(' boolean_expr ')' simple ELSE simple  */
#line 432 "B112040003.y"
                                                                             {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) %s\n%s %s",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 2463 "B112040003.tab.c"
    break;

  case 70: /* conditional: IF '(' boolean_expr ')' simple ELSE leftcurly compound rightcurly  */
#line 436 "B112040003.y"
                                                                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) %s\n%s {\n%s\n}",(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-1].s));
				}
#line 2472 "B112040003.tab.c"
    break;

  case 71: /* conditional: IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE simple  */
#line 440 "B112040003.y"
                                                                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}\n%s %s",(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 2481 "B112040003.tab.c"
    break;

  case 72: /* conditional: IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE leftcurly compound rightcurly  */
#line 444 "B112040003.y"
                                                                                                                           {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}\n%s {\n%s\n}",(yyvsp[-10].s),(yyvsp[-8].s),(yyvsp[-5].s),(yyvsp[-3].s),(yyvsp[-1].s));
				}
#line 2490 "B112040003.tab.c"
    break;

  case 73: /* conditional: IF '(' boolean_expr ')' simple ELSE conditional  */
#line 448 "B112040003.y"
                                                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) %s\n%s %s",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 2499 "B112040003.tab.c"
    break;

  case 74: /* conditional: IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE conditional  */
#line 452 "B112040003.y"
                                                                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}\n%s %s",(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-3].s),(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 2508 "B112040003.tab.c"
    break;

  case 75: /* conditional: ELSE  */
#line 456 "B112040003.y"
                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*30*returnDollarLEN);
					sprintf((yyval.s),">@******Else Without If at linexxx, char %d******\n%s",strlen((yyvsp[0].s)),(yyvsp[0].s));
				}
#line 2517 "B112040003.tab.c"
    break;

  case 76: /* boolean_expr: expr  */
#line 462 "B112040003.y"
                       { (yyval.s) = (yyvsp[0].s);}
#line 2523 "B112040003.tab.c"
    break;

  case 77: /* boolean_expr: expr infixop expr  */
#line 463 "B112040003.y"
                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"%s %s %s",(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 2532 "B112040003.tab.c"
    break;

  case 78: /* boolean_expr: error  */
#line 467 "B112040003.y"
                                        { /* error recovery */ (yyval.s) = "ERROR HERE 3"; }
#line 2538 "B112040003.tab.c"
    break;

  case 79: /* infixop: EQUAL  */
#line 469 "B112040003.y"
                                { (yyval.s) = (yyvsp[0].s); }
#line 2544 "B112040003.tab.c"
    break;

  case 80: /* infixop: NEQUAL  */
#line 470 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 2550 "B112040003.tab.c"
    break;

  case 81: /* infixop: '<'  */
#line 471 "B112040003.y"
                                      { (yyval.s) = "<"; }
#line 2556 "B112040003.tab.c"
    break;

  case 82: /* infixop: '>'  */
#line 472 "B112040003.y"
                                      { (yyval.s) = ">"; }
#line 2562 "B112040003.tab.c"
    break;

  case 83: /* infixop: SEQUAL  */
#line 473 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 2568 "B112040003.tab.c"
    break;

  case 84: /* infixop: BEQUAL  */
#line 474 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 2574 "B112040003.tab.c"
    break;

  case 85: /* loop: WHILE '(' boolean_expr ')' simple  */
#line 476 "B112040003.y"
                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s ) %s",(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2583 "B112040003.tab.c"
    break;

  case 86: /* loop: WHILE '(' boolean_expr ')' leftcurly compound rightcurly  */
#line 480 "B112040003.y"
                                                                                   {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s));
			}
#line 2592 "B112040003.tab.c"
    break;

  case 87: /* loop: WHILE '(' ')' simple  */
#line 484 "B112040003.y"
                                               {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ( ) %s ;",(yyvsp[-3].s),(yyvsp[0].s));
			}
#line 2601 "B112040003.tab.c"
    break;

  case 88: /* loop: WHILE '(' ')' leftcurly compound rightcurly  */
#line 488 "B112040003.y"
                                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf((yyval.s),"%s ( ) {\n%s\n}",(yyvsp[-5].s),(yyvsp[-1].s));
			}
#line 2610 "B112040003.tab.c"
    break;

  case 89: /* loop: FOR '(' for_parem ')' simple  */
#line 492 "B112040003.y"
                                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s )\n%s ",(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2619 "B112040003.tab.c"
    break;

  case 90: /* loop: FOR '(' for_parem ')' leftcurly compound rightcurly  */
#line 496 "B112040003.y"
                                                                              {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s ) {\n%s\n}",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s));
			}
#line 2628 "B112040003.tab.c"
    break;

  case 91: /* loop: FOR '(' for_parem ')'  */
#line 500 "B112040003.y"
                                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s ) \n",(yyvsp[-3].s),(yyvsp[-1].s));
			}
#line 2637 "B112040003.tab.c"
    break;

  case 92: /* loop: WHILE '(' '*' '*' '/' ID PPLUS ')' leftcurly compound rightcurly  */
#line 504 "B112040003.y"
                                                                                {
			        (yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);						
                    sprintf((yyval.s),">@******Invalid Boolean Expression at line***,char** ******\n%s ( * * / %s ++ ) {\n%s\n}",(yyvsp[-10].s),(yyvsp[-5].s),(yyvsp[-1].s));
			}
#line 2646 "B112040003.tab.c"
    break;

  case 93: /* for_parem: forinitop ';' boolean_expr ';' forupdate  */
#line 509 "B112040003.y"
                                                           {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ; %s ; %s",(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2655 "B112040003.tab.c"
    break;

  case 94: /* for_parem: ';' boolean_expr ';' forupdate  */
#line 513 "B112040003.y"
                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s)," ; %s ; %s",(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2664 "B112040003.tab.c"
    break;

  case 95: /* for_parem: forinitop ';' ';' forupdate  */
#line 517 "B112040003.y"
                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ; ; %s",(yyvsp[-3].s),(yyvsp[0].s));
			}
#line 2673 "B112040003.tab.c"
    break;

  case 96: /* for_parem: forinitop ';' boolean_expr ';'  */
#line 521 "B112040003.y"
                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s ; %s ;",(yyvsp[-3].s),(yyvsp[-1].s));
			}
#line 2682 "B112040003.tab.c"
    break;

  case 97: /* for_parem: ';' ';' forupdate  */
#line 525 "B112040003.y"
                                            {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s)," ; ; %s ",(yyvsp[0].s));
			}
#line 2691 "B112040003.tab.c"
    break;

  case 98: /* for_parem: ';' boolean_expr ';'  */
#line 529 "B112040003.y"
                                               {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s)," ; %s ; ",(yyvsp[-1].s));
			}
#line 2700 "B112040003.tab.c"
    break;

  case 99: /* for_parem: forinitop ';' ';'  */
#line 533 "B112040003.y"
                                            {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s)," %s ; ;",(yyvsp[-2].s));
			}
#line 2709 "B112040003.tab.c"
    break;

  case 100: /* for_parem: ';' ';'  */
#line 537 "B112040003.y"
                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s)," ; ; ");
			}
#line 2718 "B112040003.tab.c"
    break;

  case 101: /* for_parem: ID '[' INTEGER ']' '=' INTEGER ';' ID '[' INTEGER ']' '<' INTEGER ';' ID '[' INTEGER ']' PPLUS  */
#line 542 "B112040003.y"
                        {  (yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf((yyval.s),"%s [ %d ] = %d ; %s [ %d ] < %d ; %s [ %d ] ++ ",(yyvsp[-18].s),(yyvsp[-16].i),(yyvsp[-13].i),(yyvsp[-11].s),(yyvsp[-9].i),(yyvsp[-6].i),(yyvsp[-4].s),(yyvsp[-2].i));}
#line 2725 "B112040003.tab.c"
    break;

  case 102: /* forinitop: declaration  */
#line 545 "B112040003.y"
                              { (yyval.s) = (yyvsp[0].s); }
#line 2731 "B112040003.tab.c"
    break;

  case 103: /* forinitop: ID assign  */
#line 546 "B112040003.y"
                                    { (yyval.s) = (yyvsp[-1].s); }
#line 2737 "B112040003.tab.c"
    break;

  case 104: /* forinitop: declaration ',' forinitop  */
#line 547 "B112040003.y"
                                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2746 "B112040003.tab.c"
    break;

  case 105: /* forinitop: ID assign ',' forinitop  */
#line 551 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf((yyval.s),"%s %s , %s",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s));
			}
#line 2755 "B112040003.tab.c"
    break;

  case 106: /* forupdate: postfixOp  */
#line 556 "B112040003.y"
                            { (yyval.s) = (yyvsp[0].s); }
#line 2761 "B112040003.tab.c"
    break;

  case 107: /* forupdate: PPLUS ID  */
#line 557 "B112040003.y"
                                   {
				(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
				sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2770 "B112040003.tab.c"
    break;

  case 108: /* forupdate: MMINUS ID  */
#line 561 "B112040003.y"
                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2779 "B112040003.tab.c"
    break;

  case 109: /* forupdate: ID assign  */
#line 565 "B112040003.y"
                                    {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
			}
#line 2788 "B112040003.tab.c"
    break;

  case 110: /* type: BOOLEAN  */
#line 570 "B112040003.y"
                          {(yyval.s) = (yyvsp[0].s);}
#line 2794 "B112040003.tab.c"
    break;

  case 111: /* type: CHAR  */
#line 570 "B112040003.y"
                                            {(yyval.s) = (yyvsp[0].s);}
#line 2800 "B112040003.tab.c"
    break;

  case 112: /* type: INT  */
#line 570 "B112040003.y"
                                                             {(yyval.s) = (yyvsp[0].s); }
#line 2806 "B112040003.tab.c"
    break;

  case 113: /* type: FLOAT  */
#line 570 "B112040003.y"
                                                                                 {(yyval.s) = (yyvsp[0].s);}
#line 2812 "B112040003.tab.c"
    break;

  case 114: /* type: STRING  */
#line 570 "B112040003.y"
                                                                                                     {(yyval.s) = (yyvsp[0].s);}
#line 2818 "B112040003.tab.c"
    break;

  case 115: /* type: VOID  */
#line 570 "B112040003.y"
                                                                                                                       { (yyval.s) = (yyvsp[0].s); }
#line 2824 "B112040003.tab.c"
    break;

  case 116: /* simple: name assign ';'  */
#line 572 "B112040003.y"
                                          {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s %s ;",$1,$2);
					else sprintf($$,"%s %s ;\n>'%s' id did not exist1",$1,$2,$1);*/
					sprintf((yyval.s),"%s %s ;",(yyvsp[-2].s),(yyvsp[-1].s));
				}
#line 2835 "B112040003.tab.c"
    break;

  case 117: /* simple: PRINT '(' expr ')' ';'  */
#line 578 "B112040003.y"
                                                         { 
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf((yyval.s),"%s ( %s ) ;",(yyvsp[-4].s),(yyvsp[-2].s));
				}
#line 2844 "B112040003.tab.c"
    break;

  case 118: /* simple: READ '(' name ')' ';'  */
#line 582 "B112040003.y"
                                                        { 
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[-2].s))) sprintf((yyval.s),"%s(%s) ;",(yyvsp[-4].s),(yyvsp[-2].s));
					else sprintf((yyval.s),"%s ( %s ) ;>'%s' id did not exist2",(yyvsp[-4].s),(yyvsp[-2].s),(yyvsp[-2].s));
				}
#line 2854 "B112040003.tab.c"
    break;

  case 119: /* simple: name PPLUS ';'  */
#line 587 "B112040003.y"
                                                 {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s%s ;",$1,$2);
					else sprintf($$,"%s%s ;>'%s' id did not exist3",$1,$2,$1);*/
					sprintf((yyval.s),"%s %s ;",(yyvsp[-2].s),(yyvsp[-1].s));
				}
#line 2865 "B112040003.tab.c"
    break;

  case 120: /* simple: name MMINUS ';'  */
#line 593 "B112040003.y"
                                                  { 
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s%s ;",$1,$2);
					else sprintf($$,"%s%s ;>'%s' id did not exist4",$1,$2,$1);*/
					sprintf((yyval.s),"%s %s ;",(yyvsp[-2].s),(yyvsp[-1].s));
				}
#line 2876 "B112040003.tab.c"
    break;

  case 121: /* simple: expr ';'  */
#line 599 "B112040003.y"
                                           { 
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s ;",(yyvsp[-1].s));
				}
#line 2885 "B112040003.tab.c"
    break;

  case 122: /* simple: ';'  */
#line 603 "B112040003.y"
                                      { (yyval.s) = ";"; }
#line 2891 "B112040003.tab.c"
    break;

  case 123: /* name: ID  */
#line 605 "B112040003.y"
                             { (yyval.s) = (yyvsp[0].s); }
#line 2897 "B112040003.tab.c"
    break;

  case 124: /* name: ID '.' ID  */
#line 606 "B112040003.y"
                                            { 
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s.%s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 2906 "B112040003.tab.c"
    break;

  case 125: /* name: ID '[' INTEGER ']'  */
#line 610 "B112040003.y"
                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[-3].s))) sprintf((yyval.s),"%s[%d]",(yyvsp[-3].s),(yyvsp[-1].i));
					else sprintf((yyval.s),"%s[%d]\n>'%s' id did not exist5",(yyvsp[-3].s),(yyvsp[-1].i),(yyvsp[-3].s));
					
				}
#line 2917 "B112040003.tab.c"
    break;

  case 126: /* name: ID '[' ID ']'  */
#line 616 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[-3].s))) sprintf((yyval.s),"%s[%s]",(yyvsp[-3].s),(yyvsp[-1].s));
					else sprintf((yyval.s),"%s[%s]\n>'%s' id did not exist6",(yyvsp[-3].s),(yyvsp[-1].s),(yyvsp[-3].s));
					/*$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s [ %s ]",$1,$3);*/
				}
#line 2929 "B112040003.tab.c"
    break;

  case 127: /* name: ID '[' function ']'  */
#line 623 "B112040003.y"
                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s [ %s ]",(yyvsp[-3].s),(yyvsp[-1].s));
				}
#line 2938 "B112040003.tab.c"
    break;

  case 128: /* identifier_list: ID  */
#line 628 "B112040003.y"
                     {	
					if(check_sameid((yyvsp[0].s))){
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),"%s ;\n>'%s' is a duplicate identifier.",(yyvsp[0].s),(yyvsp[0].s));
					}
					else{ 
 						add_id((yyvsp[0].s));
 						(yyval.s) = (yyvsp[0].s);
 					}
					
				}
#line 2954 "B112040003.tab.c"
    break;

  case 129: /* identifier_list: ID assign  */
#line 641 "B112040003.y"
                                            {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-1].s))) sprintf((yyval.s),"%s %s\n>'%s' is a duplicate identifier2",(yyvsp[-1].s),(yyvsp[0].s),(yyvsp[-1].s));
					else{ 
						add_id((yyvsp[-1].s));
						sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
					}
				}
#line 2967 "B112040003.tab.c"
    break;

  case 130: /* identifier_list: ID assign ',' identifier_list  */
#line 649 "B112040003.y"
                                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s %s, %s\n>'%s' is a duplicate identifier3",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s),(yyvsp[-3].s));
					else{ 
						sprintf((yyval.s),"%s %s, %s",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s));
 						add_id((yyvsp[-3].s));
 					}
				}
#line 2980 "B112040003.tab.c"
    break;

  case 131: /* identifier_list: ID ',' identifier_list  */
#line 657 "B112040003.y"
                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-2].s))) sprintf((yyval.s),"%s, %s\n>'%s' is a duplicate identifier4",(yyvsp[-2].s),(yyvsp[0].s),(yyvsp[-2].s));
					else{ 
						sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
 						add_id((yyvsp[-2].s));
 					}
				}
#line 2993 "B112040003.tab.c"
    break;

  case 132: /* identifier_list: arrinit  */
#line 666 "B112040003.y"
                                          { (yyval.s) = (yyvsp[0].s); }
#line 2999 "B112040003.tab.c"
    break;

  case 133: /* identifier_list: arrinit ',' identifier_list  */
#line 667 "B112040003.y"
                                                              {
					(yyval.s) = (char*)malloc(sizeof(char)*8*returnDollarLEN);
					sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3008 "B112040003.tab.c"
    break;

  case 134: /* identifier_list_char: ID ID  */
#line 704 "B112040003.y"
                             {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					 sprintf((yyval.s),"%s %s\n>'%s' is no comma ",(yyvsp[-1].s),(yyvsp[0].s),(yyvsp[-1].s));

				}
#line 3018 "B112040003.tab.c"
    break;

  case 135: /* identifier_list_char: ID assign  */
#line 710 "B112040003.y"
                                            {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-1].s))) sprintf((yyval.s),"%s %s\n>'%s' is a duplicate identifier2",(yyvsp[-1].s),(yyvsp[0].s),(yyvsp[-1].s));
					else{ 
						add_id((yyvsp[-1].s));
						sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
					}
				}
#line 3031 "B112040003.tab.c"
    break;

  case 136: /* identifier_list_char: ID assign ',' identifier_list_char  */
#line 718 "B112040003.y"
                                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-3].s))) sprintf((yyval.s),"%s %s, %s\n>'%s' is a duplicate identifier3",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s),(yyvsp[-3].s));
					else{ 
						sprintf((yyval.s),"%s %s , %s",(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[0].s));
 						add_id((yyvsp[-3].s));
 					}
				}
#line 3044 "B112040003.tab.c"
    break;

  case 137: /* identifier_list_char: ID ',' identifier_list_char  */
#line 726 "B112040003.y"
                                                              {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid((yyvsp[-2].s))) sprintf((yyval.s),"%s, %s\n>'%s' is a duplicate identifier4",(yyvsp[-2].s),(yyvsp[0].s),(yyvsp[-2].s));
					else{ 
						sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
 						add_id((yyvsp[-2].s));
 					}
				}
#line 3057 "B112040003.tab.c"
    break;

  case 138: /* identifier_list_char: arrinit  */
#line 735 "B112040003.y"
                                          { (yyval.s) = (yyvsp[0].s); }
#line 3063 "B112040003.tab.c"
    break;

  case 139: /* identifier_list_char: arrinit ',' identifier_list_char  */
#line 736 "B112040003.y"
                                                                   {
					(yyval.s) = (char*)malloc(sizeof(char)*8*returnDollarLEN);
					sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3072 "B112040003.tab.c"
    break;

  case 140: /* expr: term  */
#line 742 "B112040003.y"
                               { (yyval.s) = (yyvsp[0].s);}
#line 3078 "B112040003.tab.c"
    break;

  case 141: /* expr: expr '+' term  */
#line 743 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3087 "B112040003.tab.c"
    break;

  case 142: /* expr: expr '-' term  */
#line 747 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s - %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3096 "B112040003.tab.c"
    break;

  case 143: /* expr: expr '*' term  */
#line 751 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s - %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3105 "B112040003.tab.c"
    break;

  case 144: /* expr: expr '/' term  */
#line 755 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s - %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3114 "B112040003.tab.c"
    break;

  case 145: /* expr: term '+' ID  */
#line 759 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s ",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3123 "B112040003.tab.c"
    break;

  case 146: /* expr: term '-' ID  */
#line 763 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s ",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3132 "B112040003.tab.c"
    break;

  case 147: /* expr: expr '+' INTEGER  */
#line 767 "B112040003.y"
                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s ",(yyvsp[-2].s),(yyvsp[0].i));
				}
#line 3141 "B112040003.tab.c"
    break;

  case 148: /* expr: expr '-' INTEGER  */
#line 771 "B112040003.y"
                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s ",(yyvsp[-2].s),(yyvsp[0].i));
				}
#line 3150 "B112040003.tab.c"
    break;

  case 149: /* expr: expr PPLUS  */
#line 775 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s --",(yyvsp[-1].s));
				}
#line 3159 "B112040003.tab.c"
    break;

  case 150: /* expr: expr MMINUS  */
#line 780 "B112040003.y"
                                                 {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s --",(yyvsp[-1].s));
				}
#line 3168 "B112040003.tab.c"
    break;

  case 151: /* expr: ID '+' expr  */
#line 785 "B112040003.y"
                                               {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s + %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3177 "B112040003.tab.c"
    break;

  case 152: /* expr: error  */
#line 789 "B112040003.y"
                                        { /* error recovery */ (yyval.s) = "ERROR HERE 4"; }
#line 3183 "B112040003.tab.c"
    break;

  case 153: /* term: factor  */
#line 791 "B112040003.y"
                                 { (yyval.s) = (yyvsp[0].s); }
#line 3189 "B112040003.tab.c"
    break;

  case 154: /* term: factor '*' term  */
#line 792 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s * %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3198 "B112040003.tab.c"
    break;

  case 155: /* term: factor '/' term  */
#line 796 "B112040003.y"
                                                  {
					/*zero divisor*/
					if((yyvsp[0].s)[0]=='0') fprintf(stderr,">zero divisor\n");
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s / %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3209 "B112040003.tab.c"
    break;

  case 156: /* term: factor '%' term  */
#line 802 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s \% %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3218 "B112040003.tab.c"
    break;

  case 157: /* factor: name '+' name  */
#line 807 "B112040003.y"
                                          {
	                
					if(check_exist((yyvsp[-2].s))) (yyval.s) = (yyvsp[-2].s);
					else{					
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					 sprintf((yyval.s),"%s + %s",(yyvsp[-2].s),(yyvsp[0].s)); 
					}
                }
#line 3231 "B112040003.tab.c"
    break;

  case 158: /* factor: name  */
#line 815 "B112040003.y"
                       {
					add_id((yyvsp[0].s));
					if(check_exist((yyvsp[0].s))) (yyval.s) = (yyvsp[0].s);
					else{
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),"%s\n>'%s' id did not exist5",(yyvsp[0].s),(yyvsp[0].s));
					}
				}
#line 3244 "B112040003.tab.c"
    break;

  case 159: /* factor: '!' name  */
#line 823 "B112040003.y"
                                           {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[0].s))) sprintf((yyval.s),"!%s",(yyvsp[0].s));
					else{
						sprintf((yyval.s),"!%s\n>'%s' id did not exist6",(yyvsp[0].s),(yyvsp[0].s));
					}
				}
#line 3256 "B112040003.tab.c"
    break;

  case 160: /* factor: const_expr  */
#line 830 "B112040003.y"
                                             { (yyval.s) = (yyvsp[0].s);}
#line 3262 "B112040003.tab.c"
    break;

  case 161: /* factor: STRING  */
#line 831 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 3268 "B112040003.tab.c"
    break;

  case 162: /* factor: '(' expr ')'  */
#line 832 "B112040003.y"
                                               {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"( %s )",(yyvsp[-1].s));
				}
#line 3277 "B112040003.tab.c"
    break;

  case 163: /* factor: prefixOp  */
#line 836 "B112040003.y"
                                           {
					(yyval.s) = (yyvsp[0].s);
				}
#line 3285 "B112040003.tab.c"
    break;

  case 164: /* factor: postfixOp  */
#line 839 "B112040003.y"
                                            {
					(yyval.s) = (yyvsp[0].s);;
				}
#line 3293 "B112040003.tab.c"
    break;

  case 165: /* factor: function  */
#line 842 "B112040003.y"
                                           {
					char fname[strlen((yyvsp[0].s))];
					func_name((yyvsp[0].s),fname);
					if(check_exist(fname)) (yyval.s) = (yyvsp[0].s);
					else{
						(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf((yyval.s),"%s\n>'%s' id did not exist7",(yyvsp[0].s),fname);
					}
				}
#line 3307 "B112040003.tab.c"
    break;

  case 166: /* prefixOp: PPLUS ID  */
#line 852 "B112040003.y"
                                   {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"++ %s",(yyvsp[0].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support ++ operator\n");*/
				}
#line 3320 "B112040003.tab.c"
    break;

  case 167: /* prefixOp: MMINUS ID  */
#line 860 "B112040003.y"
                                            {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"-- %s",(yyvsp[0].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
#line 3333 "B112040003.tab.c"
    break;

  case 168: /* prefixOp: '+' ID  */
#line 868 "B112040003.y"
                                         {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"+ %s",(yyvsp[0].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
#line 3346 "B112040003.tab.c"
    break;

  case 169: /* prefixOp: '-' ID  */
#line 876 "B112040003.y"
                                         {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"- %s",(yyvsp[0].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
#line 3359 "B112040003.tab.c"
    break;

  case 170: /* prefixOp: '+' const_expr  */
#line 884 "B112040003.y"
                                                 {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"- %s",(yyvsp[0].s));
				}
#line 3368 "B112040003.tab.c"
    break;

  case 171: /* prefixOp: '-' const_expr  */
#line 888 "B112040003.y"
                                                 {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"- %s",(yyvsp[0].s));
				}
#line 3377 "B112040003.tab.c"
    break;

  case 172: /* postfixOp: ID PPLUS  */
#line 893 "B112040003.y"
                                   {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[-1].s))) sprintf((yyval.s),"%s++",(yyvsp[-1].s));
					else sprintf((yyval.s),"%s ++\n>'%s' id did not exist8",(yyvsp[-1].s),(yyvsp[-1].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support ++ operator\n");*/
				}
#line 3391 "B112040003.tab.c"
    break;

  case 173: /* postfixOp: ID MMINUS  */
#line 902 "B112040003.y"
                                            {
					/* need implement ID = function or variable */
					/* if ID is variable */
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist((yyvsp[-1].s))) sprintf((yyval.s),"%s--",(yyvsp[-1].s));
					else sprintf((yyval.s),"%s --\n>'%s' id did not exist9",(yyvsp[-1].s),(yyvsp[-1].s));
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
#line 3405 "B112040003.tab.c"
    break;

  case 174: /* const_expr: INTEGER  */
#line 913 "B112040003.y"
                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"%d",(yyvsp[0].i)); 
				}
#line 3414 "B112040003.tab.c"
    break;

  case 175: /* const_expr: REAL  */
#line 917 "B112040003.y"
                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf((yyval.s),"%g",(yyvsp[0].d));
				}
#line 3423 "B112040003.tab.c"
    break;

  case 176: /* compound: declaration ';'  */
#line 922 "B112040003.y"
                                          {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"%s ;",(yyvsp[-1].s));
				}
#line 3432 "B112040003.tab.c"
    break;

  case 177: /* compound: declaration ';' compound  */
#line 926 "B112040003.y"
                                                       {
				   (yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				   sprintf((yyval.s),"%s ;\n%s",(yyvsp[-2].s),(yyvsp[0].s));
			    }
#line 3441 "B112040003.tab.c"
    break;

  case 178: /* compound: simple  */
#line 930 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 3447 "B112040003.tab.c"
    break;

  case 179: /* compound: conditional  */
#line 931 "B112040003.y"
                                              { (yyval.s) = (yyvsp[0].s); }
#line 3453 "B112040003.tab.c"
    break;

  case 180: /* compound: declaration ';' compound  */
#line 932 "B112040003.y"
                                                           {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"%s\n%s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3462 "B112040003.tab.c"
    break;

  case 181: /* compound: loop  */
#line 936 "B112040003.y"
                                       { (yyval.s) = (yyvsp[0].s); }
#line 3468 "B112040003.tab.c"
    break;

  case 182: /* compound: simple compound  */
#line 937 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf((yyval.s),"%s\n%s",(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 3477 "B112040003.tab.c"
    break;

  case 183: /* compound: conditional compound  */
#line 941 "B112040003.y"
                                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf((yyval.s),"%s\n%s",(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 3486 "B112040003.tab.c"
    break;

  case 184: /* compound: func_return ';'  */
#line 945 "B112040003.y"
                                                  {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s ;",(yyvsp[-1].s));
				}
#line 3495 "B112040003.tab.c"
    break;

  case 185: /* compound: loop compound  */
#line 949 "B112040003.y"
                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf((yyval.s),"%s\n%s",(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 3504 "B112040003.tab.c"
    break;

  case 186: /* compound: leftcurly compound rightcurly  */
#line 953 "B112040003.y"
                                                                {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf((yyval.s),"{\n%s\n}",(yyvsp[-1].s));
				}
#line 3513 "B112040003.tab.c"
    break;

  case 187: /* compound: leftcurly compound rightcurly compound  */
#line 957 "B112040003.y"
                                                                         {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf((yyval.s),"{\n%s\n}\n%s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3522 "B112040003.tab.c"
    break;

  case 188: /* compound: CLASS ID leftcurly compound rightcurly  */
#line 961 "B112040003.y"
                                                                          { 
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf((yyval.s),"%s %s {\n%s\n}",(yyvsp[-4].s),(yyvsp[-3].s),(yyvsp[-1].s));
				}
#line 3531 "B112040003.tab.c"
    break;

  case 189: /* compound: error  */
#line 966 "B112040003.y"
                                        { /* error recovery */ (yyval.s) = "ERROR HERE 5"; }
#line 3537 "B112040003.tab.c"
    break;

  case 190: /* compound: error compound  */
#line 967 "B112040003.y"
                                                 {
					/* error recovery */ 
					(yyval.s) = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf((yyval.s),"ERROR HERE 6\n%s",(yyvsp[0].s));
				}
#line 3547 "B112040003.tab.c"
    break;

  case 191: /* function: name '(' ')'  */
#line 973 "B112040003.y"
                                       {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf((yyval.s),"%s()",(yyvsp[-2].s));
				}
#line 3556 "B112040003.tab.c"
    break;

  case 192: /* function: name '(' func_parem ')'  */
#line 977 "B112040003.y"
                                                          {
					(yyval.s) = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf((yyval.s),"%s(%s)",(yyvsp[-3].s),(yyvsp[-1].s));
				}
#line 3565 "B112040003.tab.c"
    break;

  case 193: /* main_func: MAIN '(' ')' leftcurly compound rightcurly  */
#line 983 "B112040003.y"
                                                                     {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"main ( ) \n{\n%s\n}",(yyvsp[-1].s));
				}
#line 3574 "B112040003.tab.c"
    break;

  case 194: /* main_func: type MAIN '(' ')' leftcurly compound rightcurly  */
#line 987 "B112040003.y"
                                                                                   {
					(yyval.s) = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf((yyval.s),"%s main ( ) {\n%s\n}",(yyvsp[-6].s),(yyvsp[-1].s));
				}
#line 3583 "B112040003.tab.c"
    break;

  case 195: /* func_parem: expr  */
#line 992 "B112040003.y"
                               { (yyval.s) = (yyvsp[0].s); }
#line 3589 "B112040003.tab.c"
    break;

  case 196: /* func_parem: expr ',' func_parem  */
#line 993 "B112040003.y"
                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s , %s",(yyvsp[-2].s),(yyvsp[0].s));
				}
#line 3598 "B112040003.tab.c"
    break;

  case 197: /* func_return: RETURN expr  */
#line 998 "B112040003.y"
                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 3607 "B112040003.tab.c"
    break;

  case 198: /* func_return: RETURN boolean_expr  */
#line 1002 "B112040003.y"
                                                      {
					(yyval.s) = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf((yyval.s),"%s %s",(yyvsp[-1].s),(yyvsp[0].s));
				}
#line 3616 "B112040003.tab.c"
    break;

  case 199: /* func_return: RETURN  */
#line 1006 "B112040003.y"
                                         { (yyval.s) = (yyvsp[0].s); }
#line 3622 "B112040003.tab.c"
    break;

  case 200: /* leftcurly: '{'  */
#line 1008 "B112040003.y"
                              {
					into_scope("scope");
					(yyval.c) = '{';
				}
#line 3631 "B112040003.tab.c"
    break;

  case 201: /* rightcurly: '}'  */
#line 1013 "B112040003.y"
                              {
					/*print_current();*/
					out_scope();				
					(yyval.c) = '}';
				}
#line 3641 "B112040003.tab.c"
    break;


#line 3645 "B112040003.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1019 "B112040003.y"


void into_scope(char str[]){
	table.size++;
	table.list[table.size-1].size=0;
	strcpy(table.list[table.size-1].scope_name,str);
}

void add_id(char str[]){
	table.list[table.size-1].size++;
	strcpy(table.list[table.size-1].idlist[table.list[table.size-1].size-1],str);
}

void out_scope(){
	table.list[table.size-1].size = 0;
	table.size--;
}

void print_current(){
	int cur_size = table.list[table.size-1].size, i;
	printf("scope: %s\nid list size: %d\n",table.list[table.size-1].scope_name,cur_size);
	for(i=0;i<cur_size;++i){
		printf("%s\n",table.list[table.size-1].idlist[i]);
	}
}

int check_sameid(char str[]){
	int cur_size = table.list[table.size-1].size, i;	
	for(i=0;i<cur_size;++i){
		if(strcmp(table.list[table.size-1].idlist[i],str)==0) return 1;
	}
	return 0;
}

int check_exist(char str[]){
	int i,j;
	for(j=table.size-1;j>=0;--j){
		for(i=0;i<table.list[j].size;++i){
			if(strcmp(table.list[j].idlist[i],str)==0) return 1;
		}
	}
	return 0;
}

void yyerror(const char *str){
	fprintf(stderr,">%s\n",str);
}

void print_lineno(char str[], int addsemi){
    
	int errorno;
    line_number1++;

	int lineflag=0;
	int afterflag =0;
	counts=0;

	while (line_numbers[line_number1]!=0){
		counts = count_newlines(lines[line_number1]);
		lineflag=1;
		/*printf("%d\n",counts);*/
	    printf("\nline %3d: ",lineno++);
		char *str = lines[line_number1];
		if (counts >1){
  		    //lineno = lineno + counts ;
		    while (*str) {
		      if ( *str == '\n') 
		    	{printf("\nline %3d: ",lineno++);
				 line_number1++;}
		      else 
		          printf("%c",*str);		      
		      str++;  
			}
			printf("\n");
		}
		else 
		    printf("%s\n",lines[line_number1]);   
	    
	line_number1++;		
	}
    printf("line %3d: ",lineno++);
	//if (lineflag ==1 ) {lineflag=0; line_number1--; lineno--; }
    
	

	/*printf("strlen %d",strlen(str));*/
	/*if(addsemi){
		printf("%s ;\n",str);
		return;
	}*/
	int i,k=0;
	
	for(i=0;i<strlen(str);++i){

		
		if(str[i]=='\n' && (i+1) < strlen(str) && str[i+1]!='>'){
		   line_number1++;

           lineflag=0;
		   while (line_numbers[line_number1]!=0){
			   lineflag++;
			   counts = count_newlines(lines[line_number1]);
			   if (lineflag >1 ) 
			      printf("line %3d: ",lineno++);
			   else
	              printf("\nline %3d: ",lineno++);
			   printf("%s",lines[line_number1]);
		       line_number1++;
			}
			if  (lineflag >=1 ) {
				lineflag=0;
			    if (line_numbers[line_number1-1] !=2 )  printf ("\n");
				printf("line %3d: ",lineno++);
				}
			else 
			    printf("\nline %3d: ",lineno++);
			

		}

		else if (str[i+1] =='>'){
		   line_number1++;	    
           afterflag =1;
		   while (line_numbers[line_number1]!=0 && printerror == 0 ){
			   lineflag++;
			   counts = count_newlines(lines[line_number1]);
			   if (lineflag >1 ) {
			      printf("line %3d: ",lineno++);
				  printf("%s\n",lines[line_number1]);
			      }
			   else{
	              printf("\nline %3d: ",lineno++);
			      printf("%s",lines[line_number1]);
			     }
			    
		       line_number1++;
			}

            line_number1--;

			if  (lineflag >=1 ) {
				lineflag=0;
			    if (line_numbers[line_number1-1] !=2 )  printf ("\n");
				}
			else 
			{
			    printf("\n");
			}
			

		}
		else {
			  if (str[i] =='{' && eol_numbers[line_number1] ==0){
				 printf("\nline %3d: ",lineno++);
		         line_number1++;
			     printf("%c",str[i]);
			  }
			  else	{
			    if (str[i] =='>' && str[i+1] =='@'){
                     i++;
					 i++;
				    if ( str[i] =='L' && str[i+1] =='i' && str[i+2] =='n'  && str[i+3] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						countchar = 12;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);
						str[i+4]=' ' ; 
					    str[i+5]=resultchar[0] ;
					    str[i+6]=resultchar[1] ;
						str[i+7]=resultchar[2] ;
						int_to_3char(countchar , resultchar);
						str[i+16]=resultchar[1] ;
						str[i+17]=resultchar[2] ;

					}
				   	if ( str[i+25] =='l' && str[i+26] =='i' && str[i+27] =='n'  && str[i+28] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);

					    str[i+29]=resultchar[0] ;
					    str[i+30]=resultchar[1] ;
						str[i+31]=resultchar[2] ;

					}
					if ( str[i+36] =='l' && str[i+37] =='i' && str[i+38] =='n'  && str[i+39] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						countchar = 9;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);
					    str[i+40]=resultchar[0] ;
					    str[i+41]=resultchar[1] ;
						str[i+42]=resultchar[2] ;
						int_to_3char(countchar, resultchar);
						str[i+48]=resultchar[1] ;
						str[i+49]=resultchar[2] ;

					}		
				}
                if (afterflag ==1 && str[i] ==';') afterflag =0;
				else 
		        printf("%c",str[i]);
			  }	
	    }
	}
	printf("\n");
}


void func_name(char in[], char out[]){
	int i;
	for(i=0;i<strlen(in);++i){
		if ( in[i] != '(' ) out[i] = in[i];
		else{ out[i]='\0'; break; }
	}
}

void print_with_line_numbers(FILE *fp) {
    char line[1024];
    int lineno = 1;
    while (fgets(line, sizeof(line), fp)) {
        printf("line %4d: %s", lineno++, line);
    }
    rewind(fp); // Reset file pointer for parsing
}

void int_to_3char(int value, char out[3]) {
    char temp[4]; // temp buffer to hold up to 3 digits + null terminator
    snprintf(temp, sizeof(temp), "%d", value);

    int len = strlen(temp);
    int pad = 3 - len;

    for (int i = 0; i < pad; i++) {
        out[i] = ' ';
    }
    for (int i = 0; i < len; i++) {
        out[pad + i] = temp[i];
    }
}

int remove_spaces(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the string
    return j;      // Return new length
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Cannot open file");
        return 1;
    }	

    //print_with_line_numbers(f);
    yyin = f;
	table.size = 0;
	into_scope("global");
    yyparse();

	while (lineno < total_lines){
        if (lines[lineno] != NULL && strlen(lines[lineno])!=0 ){
	  	    counts = count_newlines(lines[lineno]);
		    char *str = lines[lineno];
		    if (counts >= 1 && line_numbers[lineno]==1 ){  	
				printf("LINE %3d:",lineno);	
				lineno++;    
		        while (*str) {
		          if ( *str == '\n') {
		    	    printf("\nLINE %3d:",lineno);
				    lineno++;
					}
		           else 
		             printf("%c",*str);		      
		          str++;				    
			    }
			    printf("\n");
		    }
		   else 
		      printf("LINE %3d:%s",lineno,lines[lineno]); 
			    	
		}

       
	  lineno++;
    }
	
	//printf ("Total:%d  Current:%d \n",total_lines,lineno);
    fclose(f);
    return 0;
}
