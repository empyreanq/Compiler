/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "ph2.y"

#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int yylex(void);
int yyerror(char* yaccProvidedMessage); /*kaleitai apo yacc gia na apokalipsei error*/


extern int yylineno;
extern char* yytext;
extern FILE* yyin;
int scope=0;
int funcounter=0;
char *aa;
int return_in_func=0;
int break_in_loop=0;
int con_in_loop=0;
int functionvar=0;

#line 96 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_LOCAL = 14,                     /* LOCAL  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_NIL = 17,                       /* NIL  */
  YYSYMBOL_PLUSPLUS = 18,                  /* PLUSPLUS  */
  YYSYMBOL_MINMIN = 19,                    /* MINMIN  */
  YYSYMBOL_EQUAL = 20,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 21,                  /* NOTEQUAL  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 25,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 26,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 27,                    /* MODULO  */
  YYSYMBOL_GREATEREQ = 28,                 /* GREATEREQ  */
  YYSYMBOL_LESSEQ = 29,                    /* LESSEQ  */
  YYSYMBOL_GREATER = 30,                   /* GREATER  */
  YYSYMBOL_LESS = 31,                      /* LESS  */
  YYSYMBOL_LEFT_PAR = 32,                  /* LEFT_PAR  */
  YYSYMBOL_RIGHT_PAR = 33,                 /* RIGHT_PAR  */
  YYSYMBOL_LEFT_BR = 34,                   /* LEFT_BR  */
  YYSYMBOL_RIGHT_BR = 35,                  /* RIGHT_BR  */
  YYSYMBOL_LEFT_SQ = 36,                   /* LEFT_SQ  */
  YYSYMBOL_RIGHT_SQ = 37,                  /* RIGHT_SQ  */
  YYSYMBOL_DOUBLE_DOT = 38,                /* DOUBLE_DOT  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_D_SCOPE = 40,                   /* D_SCOPE  */
  YYSYMBOL_SCOPE = 41,                     /* SCOPE  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_INTEGER_C = 44,                 /* INTEGER_C  */
  YYSYMBOL_REAL_C = 45,                    /* REAL_C  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_UMINUS = 48,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_stmt_list = 51,                 /* stmt_list  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_assignexpr = 55,                /* assignexpr  */
  YYSYMBOL_primary = 56,                   /* primary  */
  YYSYMBOL_lvalue = 57,                    /* lvalue  */
  YYSYMBOL_member = 58,                    /* member  */
  YYSYMBOL_call = 59,                      /* call  */
  YYSYMBOL_callsuffix = 60,                /* callsuffix  */
  YYSYMBOL_normcall = 61,                  /* normcall  */
  YYSYMBOL_methodcall = 62,                /* methodcall  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_elist = 64,                     /* elist  */
  YYSYMBOL_objectdef = 65,                 /* objectdef  */
  YYSYMBOL_indexed_list = 66,              /* indexed_list  */
  YYSYMBOL_indexed = 67,                   /* indexed  */
  YYSYMBOL_indexedelem = 68,               /* indexedelem  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_funcdef = 71,                   /* funcdef  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_const = 76,                     /* const  */
  YYSYMBOL_final_idlist = 77,              /* final_idlist  */
  YYSYMBOL_idlist = 78,                    /* idlist  */
  YYSYMBOL_ifstmt = 79,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 80,                 /* whilestmt  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_forstmt = 82,                   /* forstmt  */
  YYSYMBOL_83_7 = 83,                      /* $@7  */
  YYSYMBOL_returnstmt = 84                 /* returnstmt  */
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   555

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   130,   131,   134,   135,   136,   137,   138,
     139,   141,   143,   144,   145,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     166,   167,   170,   171,   172,   173,   174,   175,   178,   181,
     182,   183,   184,   185,   190,   194,   195,   196,   199,   200,
     201,   202,   205,   206,   207,   210,   211,   214,   217,   220,
     221,   226,   227,   231,   232,   237,   238,   241,   244,   251,
     251,   257,   257,   257,   258,   258,   258,   262,   263,   264,
     265,   266,   267,   270,   272,   275,   276,   280,   281,   284,
     284,   287,   287,   291,   292
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "OR", "NOT",
  "LOCAL", "TRUE", "FALSE", "NIL", "PLUSPLUS", "MINMIN", "EQUAL",
  "NOTEQUAL", "ASSIGN", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO",
  "GREATEREQ", "LESSEQ", "GREATER", "LESS", "LEFT_PAR", "RIGHT_PAR",
  "LEFT_BR", "RIGHT_BR", "LEFT_SQ", "RIGHT_SQ", "DOUBLE_DOT", "DOT",
  "D_SCOPE", "SCOPE", "SEMICOLON", "COMMA", "INTEGER_C", "REAL_C", "ID",
  "STRING", "UMINUS", "$accept", "program", "stmt_list", "stmt", "expr",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "expression", "elist",
  "objectdef", "indexed_list", "indexed", "indexedelem", "block", "$@1",
  "funcdef", "$@2", "$@3", "$@4", "$@5", "const", "final_idlist", "idlist",
  "ifstmt", "whilestmt", "$@6", "forstmt", "$@7", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   -28,   -26,   -23,   -29,    97,   -12,     9,   217,   -27,
    -150,  -150,  -150,    90,    90,   217,    18,  -150,   182,     7,
    -150,  -150,  -150,  -150,  -150,    22,  -150,   147,   247,  -150,
    -150,  -150,   185,  -150,   -16,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,   217,   217,   217,  -150,    23,  -150,   270,
    -150,  -150,  -150,  -150,    49,   -24,   -16,   -24,  -150,   401,
      26,   147,   217,   470,    17,    24,    37,    29,  -150,  -150,
    -150,  -150,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,  -150,  -150,  -150,   217,   217,
     217,    36,    40,  -150,  -150,  -150,   217,   217,    41,   424,
     447,    39,    56,    43,  -150,    57,  -150,    61,    59,   316,
     217,  -150,    62,  -150,   503,   491,   515,   515,     1,     1,
    -150,  -150,  -150,   524,   524,   524,   524,   470,    64,   338,
      63,  -150,    65,   359,  -150,   147,  -150,   217,    43,  -150,
      58,    67,    61,   217,  -150,   217,   470,  -150,  -150,  -150,
     217,  -150,  -150,    98,   147,   293,    70,    71,  -150,    74,
     380,    75,   147,  -150,   217,  -150,  -150,    84,  -150,  -150,
    -150,  -150,    76,    84,  -150,  -150,  -150,   147,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,    74,     0,     0,     0,     0,     0,
      81,    82,    80,     0,     0,     0,     0,    69,    62,     0,
      14,    77,    78,    44,    79,     0,     2,     4,     0,    29,
      15,    37,    39,    47,    40,    41,    12,    13,    43,     6,
       7,     8,     9,     0,     0,    62,    71,     0,    94,     0,
      10,    11,    32,    45,     0,    33,     0,    35,    31,     0,
       0,     4,     0,    60,    61,     0,    67,     0,    66,    46,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,    34,    36,     0,    62,
       0,     0,     0,    53,    55,    56,    62,     0,     0,     0,
       0,     0,     0,    86,    93,     0,    30,    42,     0,     0,
       0,    63,     0,    64,    27,    28,    25,    26,    16,    17,
      18,    19,    20,    22,    24,    21,    23,    38,     0,     0,
       0,    48,     0,     0,    50,     0,    89,     0,    86,    84,
      85,     0,     0,    62,    70,     0,    59,    65,    57,    49,
      62,    52,    51,    88,     0,     0,     0,     0,    75,     0,
       0,     0,     0,    90,    62,    72,    83,     0,    54,    68,
      58,    87,     0,     0,    76,    91,    73,     0,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   -20,  -133,    -5,  -150,  -150,  -150,    33,  -150,
      35,  -150,  -150,  -150,  -150,   -44,  -150,  -150,  -150,    11,
    -149,  -150,   -11,  -150,  -150,  -150,  -150,  -150,  -150,   -19,
    -150,  -150,  -150,  -150,  -150,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    93,    94,    95,    64,    65,    35,    66,    67,    68,
      36,    61,    37,   102,   173,    47,   167,    38,   140,   141,
      39,    40,   154,    41,   177,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,   101,   153,    52,    43,    60,    44,    71,    89,    45,
      58,    59,    90,    63,    91,    92,    96,    46,   174,    53,
      97,   163,    70,    98,   176,     4,    78,    79,    80,   171,
      50,     8,     9,    10,    11,    12,    13,    14,    99,   100,
      63,   108,    15,   105,   178,   128,    55,    57,    56,    56,
      16,    51,   132,    69,    18,   103,     4,   109,    19,   107,
     110,   111,    21,    22,    23,    24,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     112,   137,   130,   127,    63,   129,   131,   134,   138,   139,
     142,    63,   133,   143,   144,   150,    62,   148,   151,   159,
     158,   157,   162,   165,     9,   146,   161,   168,   170,   175,
       8,     9,    10,    11,    12,    13,    14,   166,    17,   156,
     172,    15,    54,   147,     0,     0,     0,     0,     0,    16,
      19,     0,   155,    18,     0,     0,    23,    19,    63,    48,
     160,    21,    22,    23,    24,    63,     0,     0,     0,     0,
       1,     0,     2,     3,     4,     5,     6,     7,     0,    63,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,    17,     0,    18,     0,     0,     0,    19,     0,    20,
       0,    21,    22,    23,    24,     8,     9,    10,    11,    12,
      13,    14,     0,    86,    87,     0,    15,    88,     0,     0,
       0,     0,     0,     0,    16,     0,    62,    89,    18,     0,
       0,    90,    19,    91,    92,     0,    21,    22,    23,    24,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,    18,     0,     0,     0,    19,    72,    73,
       0,    21,    22,    23,    24,     0,     0,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,    85,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,    72,    73,     0,     0,     0,     0,
       0,     0,   104,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,   164,    74,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    72,
      73,     0,     0,     0,     0,     0,     0,   145,    74,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      72,    73,     0,     0,     0,   149,     0,     0,     0,    74,
      75,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    72,    73,     0,     0,     0,   152,     0,     0,     0,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    72,    73,     0,   169,     0,     0,     0,     0,
       0,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,   106,    72,    73,     0,     0,     0,
       0,     0,     0,     0,    74,    75,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,   135,    72,    73,
       0,     0,     0,     0,     0,     0,     0,    74,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
     136,    72,    73,     0,     0,     0,     0,     0,     0,     0,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    72,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       5,    45,   135,     8,    32,    16,    32,    27,    32,    32,
      15,    16,    36,    18,    38,    39,    32,    46,   167,    46,
      36,   154,     0,    39,   173,     7,    25,    26,    27,   162,
      42,    13,    14,    15,    16,    17,    18,    19,    43,    44,
      45,    61,    24,    54,   177,    89,    13,    14,    13,    14,
      32,    42,    96,    46,    36,    32,     7,    62,    40,    33,
      43,    37,    44,    45,    46,    47,    37,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      43,    42,    46,    88,    89,    90,    46,    46,    32,    46,
      33,    96,    97,    32,    35,    32,    34,    33,    33,   143,
      33,    43,     4,    33,    14,   110,   150,    33,    33,    33,
      13,    14,    15,    16,    17,    18,    19,    46,    34,   138,
     164,    24,    32,   112,    -1,    -1,    -1,    -1,    -1,    32,
      40,    -1,   137,    36,    -1,    -1,    46,    40,   143,    42,
     145,    44,    45,    46,    47,   150,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,   164,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    40,    -1,    42,
      -1,    44,    45,    46,    47,    13,    14,    15,    16,    17,
      18,    19,    -1,    18,    19,    -1,    24,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    32,    36,    -1,
      -1,    36,    40,    38,    39,    -1,    44,    45,    46,    47,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    11,    12,
      -1,    44,    45,    46,    47,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    41,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      11,    12,    -1,    -1,    -1,    37,    -1,    -1,    -1,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    11,    12,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    11,    12,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    23,    24,    25,
      26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    13,    14,
      15,    16,    17,    18,    19,    24,    32,    34,    36,    40,
      42,    44,    45,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    65,    69,    71,    76,    79,
      80,    82,    84,    32,    32,    32,    46,    74,    42,    53,
      42,    42,    53,    46,    32,    57,    59,    57,    53,    53,
      71,    70,    34,    53,    63,    64,    66,    67,    68,    46,
       0,    51,    11,    12,    20,    21,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    42,    18,    19,    22,    32,
      36,    38,    39,    60,    61,    62,    32,    36,    39,    53,
      53,    64,    72,    32,    42,    71,    33,    33,    51,    53,
      43,    37,    43,    37,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    64,    53,
      46,    46,    64,    53,    46,    33,    33,    42,    32,    46,
      77,    78,    33,    32,    35,    41,    53,    68,    33,    37,
      32,    33,    37,    52,    81,    53,    78,    43,    33,    64,
      53,    64,     4,    52,    42,    33,    46,    75,    33,    35,
      33,    52,    64,    73,    69,    33,    69,    83,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    70,
      69,    72,    73,    71,    74,    75,    71,    76,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    81,
      80,    83,    82,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     2,     6,     1,     1,     3,     5,     3,
       1,     1,     0,     3,     3,     3,     1,     1,     5,     0,
       4,     0,     0,     8,     0,     0,     7,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     7,     5,     0,
       6,     0,    10,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
  case 2: /* program: stmt_list  */
#line 127 "ph2.y"
                          {printf("\"Grammar\": program | program stmt\n");}
#line 1374 "parser.c"
    break;

  case 5: /* stmt: expr SEMICOLON  */
#line 134 "ph2.y"
                                {printf("\"Grammar\": stmt | expr SEMICOLON\n");}
#line 1380 "parser.c"
    break;

  case 6: /* stmt: ifstmt  */
#line 135 "ph2.y"
                                {printf("\"Grammar\": stmt | ifstmt\n");}
#line 1386 "parser.c"
    break;

  case 7: /* stmt: whilestmt  */
#line 136 "ph2.y"
                                   {printf("\"Grammar\": stmt | whilestmt\n");}
#line 1392 "parser.c"
    break;

  case 8: /* stmt: forstmt  */
#line 137 "ph2.y"
                                 {printf("\"Grammar\": stmt | forstmt\n");}
#line 1398 "parser.c"
    break;

  case 9: /* stmt: returnstmt  */
#line 138 "ph2.y"
                                    { if(return_in_func == 0){printf("Error, return is not inside function at line %d!\n",yylineno); } printf("\"Grammar\": stmt | returnstmt\n"); }
#line 1404 "parser.c"
    break;

  case 10: /* stmt: BREAK SEMICOLON  */
#line 139 "ph2.y"
                                         {if(break_in_loop == 0){printf("Error, break is used but not in loop at line %d!\n",yylineno);}
			printf("\"Grammar\": stmt | BREAK SEMICOLON\n");}
#line 1411 "parser.c"
    break;

  case 11: /* stmt: CONTINUE SEMICOLON  */
#line 141 "ph2.y"
                                            {if(con_in_loop == 0){printf("Error, continue is used but not in loop at line %d!\n",yylineno);}
			printf("\"Grammar\": stmt | CONTINUE SEMICOLON\n");}
#line 1418 "parser.c"
    break;

  case 12: /* stmt: block  */
#line 143 "ph2.y"
                               {printf("\"Grammar\": stmt | block\n");}
#line 1424 "parser.c"
    break;

  case 13: /* stmt: funcdef  */
#line 144 "ph2.y"
                                 {printf("\"Grammar\": stmt | funcdef\n");}
#line 1430 "parser.c"
    break;

  case 14: /* stmt: SEMICOLON  */
#line 145 "ph2.y"
                                   {printf("\"Grammar\": stmt | SEMICOLON\n");}
#line 1436 "parser.c"
    break;

  case 15: /* expr: assignexpr  */
#line 149 "ph2.y"
                            {printf("\"Grammar\": expr | assignexpr\n");}
#line 1442 "parser.c"
    break;

  case 16: /* expr: expr PLUS expr  */
#line 150 "ph2.y"
                                         {printf("\"Grammar\": expr | expr PLUS expr\n");}
#line 1448 "parser.c"
    break;

  case 17: /* expr: expr MINUS expr  */
#line 151 "ph2.y"
                                          {printf("\"Grammar\": expr | expr MINUS expr\n");}
#line 1454 "parser.c"
    break;

  case 18: /* expr: expr MULTIPLY expr  */
#line 152 "ph2.y"
                                             {printf("\"Grammar\": expr | expr MULTIPLY expr\n");}
#line 1460 "parser.c"
    break;

  case 19: /* expr: expr DIVIDE expr  */
#line 153 "ph2.y"
                                           {printf("\"Grammar\": expr | expr DIVIDE expr\n");}
#line 1466 "parser.c"
    break;

  case 20: /* expr: expr MODULO expr  */
#line 154 "ph2.y"
                                           {printf("\"Grammar\": expr | expr MODULO expr\n");}
#line 1472 "parser.c"
    break;

  case 21: /* expr: expr GREATER expr  */
#line 155 "ph2.y"
                                            {printf("\"Grammar\": expr | expr GREATER expr\n");}
#line 1478 "parser.c"
    break;

  case 22: /* expr: expr GREATEREQ expr  */
#line 156 "ph2.y"
                                              {printf("\"Grammar\": expr | expr GREATEREQ expr\n");}
#line 1484 "parser.c"
    break;

  case 23: /* expr: expr LESS expr  */
#line 157 "ph2.y"
                                         {printf("\"Grammar\": expr | expr LESS expr\n");}
#line 1490 "parser.c"
    break;

  case 24: /* expr: expr LESSEQ expr  */
#line 158 "ph2.y"
                                           {printf("\"Grammar\": expr | expr LESSEQ expr\n");}
#line 1496 "parser.c"
    break;

  case 25: /* expr: expr EQUAL expr  */
#line 159 "ph2.y"
                                          {printf("\"Grammar\": expr | expr EQUAL expr\n");}
#line 1502 "parser.c"
    break;

  case 26: /* expr: expr NOTEQUAL expr  */
#line 160 "ph2.y"
                                             {printf("\"Grammar\": expr | expr NOTEQUAL expr\n");}
#line 1508 "parser.c"
    break;

  case 27: /* expr: expr AND expr  */
#line 161 "ph2.y"
                                        {printf("\"Grammar\": expr | expr AND expr\n");}
#line 1514 "parser.c"
    break;

  case 28: /* expr: expr OR expr  */
#line 162 "ph2.y"
                                       {printf("\"Grammar\": expr | expr OR expr\n");}
#line 1520 "parser.c"
    break;

  case 29: /* expr: term  */
#line 163 "ph2.y"
                               {printf("\"Grammar\": expr | term\n");}
#line 1526 "parser.c"
    break;

  case 30: /* term: LEFT_PAR expr RIGHT_PAR  */
#line 166 "ph2.y"
                                         {printf("\"Grammar\": term | LEFT_PAR expr RIGHT_PAR\n");}
#line 1532 "parser.c"
    break;

  case 31: /* term: MINUS expr  */
#line 167 "ph2.y"
                                                 {printf("\"Grammar\": term | MINUS expr %prec UMINUS\n");}
#line 1538 "parser.c"
    break;

  case 32: /* term: NOT expr  */
#line 170 "ph2.y"
                                  {printf("\"Grammar\": term | NOT expr\n");}
#line 1544 "parser.c"
    break;

  case 33: /* term: PLUSPLUS lvalue  */
#line 171 "ph2.y"
                                         {printf("\"Grammar\": term | PLUSPLUS lvalue\n");}
#line 1550 "parser.c"
    break;

  case 34: /* term: lvalue PLUSPLUS  */
#line 172 "ph2.y"
                                         {printf("\"Grammar\": term | lvalue PLUSPLUS\n");}
#line 1556 "parser.c"
    break;

  case 35: /* term: MINMIN lvalue  */
#line 173 "ph2.y"
                                       {printf("\"Grammar\": term | MINMIN lvalue\n");}
#line 1562 "parser.c"
    break;

  case 36: /* term: lvalue MINMIN  */
#line 174 "ph2.y"
                                       {printf("\"Grammar\": term | lvalue MINMIN\n");}
#line 1568 "parser.c"
    break;

  case 37: /* term: primary  */
#line 175 "ph2.y"
                                 {printf("\"Grammar\": term | primary \n");}
#line 1574 "parser.c"
    break;

  case 38: /* assignexpr: lvalue ASSIGN expr  */
#line 178 "ph2.y"
                                {printf("\"Grammar\": assignexpr | lvalue\n");}
#line 1580 "parser.c"
    break;

  case 39: /* primary: lvalue  */
#line 181 "ph2.y"
                                {printf("\"Grammar\": primary | lvalue\n");}
#line 1586 "parser.c"
    break;

  case 40: /* primary: call  */
#line 182 "ph2.y"
                                      {printf("\"Grammar\": primary | call\n");}
#line 1592 "parser.c"
    break;

  case 41: /* primary: objectdef  */
#line 183 "ph2.y"
                                           {printf("\"Grammar\": primary | objectdef\n");}
#line 1598 "parser.c"
    break;

  case 42: /* primary: LEFT_PAR funcdef RIGHT_PAR  */
#line 184 "ph2.y"
                                                            {printf("\"Grammar\": primary | LEFT_PAR funcdef RIGHT_PAR\n");}
#line 1604 "parser.c"
    break;

  case 43: /* primary: const  */
#line 185 "ph2.y"
                                       {printf("\"Grammar\": primary | const \n");}
#line 1610 "parser.c"
    break;

  case 44: /* lvalue: ID  */
#line 190 "ph2.y"
                            {printf("\"Grammar\": lvalue | ID\n"); 
					if(scope==0)checkedInsertion(scope,(yyvsp[0].strVal),yylineno,0,functionvar);
					else checkedInsertion(scope,(yyvsp[0].strVal),yylineno,1,functionvar); }
#line 1618 "parser.c"
    break;

  case 45: /* lvalue: LOCAL ID  */
#line 194 "ph2.y"
                                          {printf("\"Grammar\": lvalue | LOCAL ID\n");checkedInsertion(scope,(yyvsp[0].strVal),yylineno,1,functionvar);}
#line 1624 "parser.c"
    break;

  case 46: /* lvalue: D_SCOPE ID  */
#line 195 "ph2.y"
                                            {printf("\"Grammar\": lvalue | D_SCOPE\n");checkD_Scope((yyvsp[0].strVal));}
#line 1630 "parser.c"
    break;

  case 47: /* lvalue: member  */
#line 196 "ph2.y"
                                        {printf("\"Grammar\": lvalue | MEMBER\n");}
#line 1636 "parser.c"
    break;

  case 48: /* member: lvalue DOT ID  */
#line 199 "ph2.y"
                                       {printf("\"Grammar\": member | lvalue DOT ID\n");}
#line 1642 "parser.c"
    break;

  case 49: /* member: lvalue LEFT_SQ expr RIGHT_SQ  */
#line 200 "ph2.y"
                                                              {printf("\"Grammar\": member | lvalue LEFT_SQ\n");}
#line 1648 "parser.c"
    break;

  case 50: /* member: call DOT ID  */
#line 201 "ph2.y"
                                             {printf("\"Grammar\": member | call DOT ID\n");}
#line 1654 "parser.c"
    break;

  case 51: /* member: call LEFT_SQ expr RIGHT_SQ  */
#line 202 "ph2.y"
                                                            {printf("\"Grammar\": member | call LEFT_SQ expr RIGHT_SQ\n");}
#line 1660 "parser.c"
    break;

  case 52: /* call: call LEFT_PAR elist RIGHT_PAR  */
#line 205 "ph2.y"
                                                       {printf("\"Grammar\": call | call LEFT_PAR elist RIGHT_PAR\n");}
#line 1666 "parser.c"
    break;

  case 53: /* call: lvalue callsuffix  */
#line 206 "ph2.y"
                                                   {printf("\"Grammar\": call | lvalue callsuffix\n");}
#line 1672 "parser.c"
    break;

  case 54: /* call: LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR  */
#line 207 "ph2.y"
                                                                                     {printf("\"Grammar\": call | LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR\n");}
#line 1678 "parser.c"
    break;

  case 55: /* callsuffix: normcall  */
#line 210 "ph2.y"
                                  {printf("\"Grammar\": callsuffix | normcall\n");}
#line 1684 "parser.c"
    break;

  case 56: /* callsuffix: methodcall  */
#line 211 "ph2.y"
                                            {printf("\"Grammar\": callsuffix | methodcall\n");}
#line 1690 "parser.c"
    break;

  case 57: /* normcall: LEFT_PAR elist RIGHT_PAR  */
#line 214 "ph2.y"
                                                  {printf("\"Grammar\": normcall | LEFT_PAR elist RIGHT_PAR\n");}
#line 1696 "parser.c"
    break;

  case 58: /* methodcall: DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR  */
#line 217 "ph2.y"
                                                                {printf("\"Grammar\": methodcall | DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR\n");}
#line 1702 "parser.c"
    break;

  case 61: /* elist: expression  */
#line 226 "ph2.y"
                                    {printf("\"Grammar\": elist | expr\n");}
#line 1708 "parser.c"
    break;

  case 63: /* objectdef: LEFT_SQ elist RIGHT_SQ  */
#line 231 "ph2.y"
                                                {printf("\"Grammar\": objectdef | LEFT_SQ elist RIGHT_SQ\n");}
#line 1714 "parser.c"
    break;

  case 64: /* objectdef: LEFT_SQ indexed RIGHT_SQ  */
#line 232 "ph2.y"
                                                          {printf("\"Grammar\": objectdef | LEFT_SQ indexed RIGHT_SQ\n");}
#line 1720 "parser.c"
    break;

  case 67: /* indexed: indexed_list  */
#line 241 "ph2.y"
                                    {printf("\"Grammar\": indexed | indexedelem\n");}
#line 1726 "parser.c"
    break;

  case 68: /* indexedelem: LEFT_BR expr SCOPE expr RIGHT_BR  */
#line 244 "ph2.y"
                                                          {printf("\"Grammar\": indexedelem | LEFT_BR expr SCOPE expr RIGHT_BR\n");}
#line 1732 "parser.c"
    break;

  case 69: /* $@1: %empty  */
#line 251 "ph2.y"
                                 {scope++;}
#line 1738 "parser.c"
    break;

  case 70: /* block: LEFT_BR $@1 stmt_list RIGHT_BR  */
#line 251 "ph2.y"
                                                               {hideScope(scope);scope--; 
				if(return_in_func > 0){ return_in_func--;} 
				if(break_in_loop > 0){ break_in_loop--;} if(con_in_loop > 0){con_in_loop--;}
				printf("\"Grammar\": block | LEFT_BR program RIGHT_BR\n");}
#line 1747 "parser.c"
    break;

  case 71: /* $@2: %empty  */
#line 257 "ph2.y"
                                    {functionvar=1;checkedInsertion(scope,(yyvsp[0].strVal),yylineno,3,functionvar);}
#line 1753 "parser.c"
    break;

  case 72: /* $@3: %empty  */
#line 257 "ph2.y"
                                                                                                                                         {return_in_func++;}
#line 1759 "parser.c"
    break;

  case 73: /* funcdef: FUNCTION ID $@2 LEFT_PAR idlist RIGHT_PAR $@3 block  */
#line 257 "ph2.y"
                                                                                                                                                                   {printf("\"Grammar\": funcdef | FUNCTION ID LEFT_PAR idlist RIGHT_PAR block\n");functionvar=0;}
#line 1765 "parser.c"
    break;

  case 74: /* $@4: %empty  */
#line 258 "ph2.y"
                                          {functionvar=1;aa=malloc(sizeof(int)+4);snprintf(aa,sizeof(int)+4,"$%d",funcounter++);checkedInsertion(scope,aa,yylineno,3,functionvar);}
#line 1771 "parser.c"
    break;

  case 75: /* $@5: %empty  */
#line 258 "ph2.y"
                                                                                                                                                                                                              {return_in_func++;}
#line 1777 "parser.c"
    break;

  case 76: /* funcdef: FUNCTION $@4 LEFT_PAR idlist RIGHT_PAR $@5 block  */
#line 258 "ph2.y"
                                                                                                                                                                                                                                        {printf("\"Grammar\": funcdef | FUNCTION LEFT_PAR idlist RIGHT_PAR block\n");functionvar=0;}
#line 1783 "parser.c"
    break;

  case 77: /* const: INTEGER_C  */
#line 262 "ph2.y"
                                   {printf("\"Grammar\": const | INTEGER_C\n");}
#line 1789 "parser.c"
    break;

  case 78: /* const: REAL_C  */
#line 263 "ph2.y"
                                        {printf("\"Grammar\": const | REAL_C\n");}
#line 1795 "parser.c"
    break;

  case 79: /* const: STRING  */
#line 264 "ph2.y"
                                        {printf("\"Grammar\": const | STRING\n");}
#line 1801 "parser.c"
    break;

  case 80: /* const: NIL  */
#line 265 "ph2.y"
                                     {printf("\"Grammar\": const | NIL\n");}
#line 1807 "parser.c"
    break;

  case 81: /* const: TRUE  */
#line 266 "ph2.y"
                                      {printf("\"Grammar\": const | TRUE\n");}
#line 1813 "parser.c"
    break;

  case 82: /* const: FALSE  */
#line 267 "ph2.y"
                                       {printf("\"Grammar\": const | FALSE\n");}
#line 1819 "parser.c"
    break;

  case 83: /* final_idlist: final_idlist COMMA ID  */
#line 270 "ph2.y"
                                     {printf("\"Grammar\": final_idlist | final_idlist COMMA ID\n"); 
				checkedInsertion(scope,(yyvsp[0].strVal),yylineno,2,functionvar);}
#line 1826 "parser.c"
    break;

  case 84: /* final_idlist: ID  */
#line 272 "ph2.y"
                                   {printf("\"Grammar\": final_idlist | ID\n");checkedInsertion(scope,(yyvsp[0].strVal),yylineno,2,functionvar);}
#line 1832 "parser.c"
    break;

  case 85: /* idlist: final_idlist  */
#line 275 "ph2.y"
                                    {printf("\"Grammar\": idlist | ID\n");}
#line 1838 "parser.c"
    break;

  case 87: /* ifstmt: IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt  */
#line 280 "ph2.y"
                                                                  {printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt\n");}
#line 1844 "parser.c"
    break;

  case 88: /* ifstmt: IF LEFT_PAR expr RIGHT_PAR stmt  */
#line 281 "ph2.y"
                                                                {printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt\n");}
#line 1850 "parser.c"
    break;

  case 89: /* $@6: %empty  */
#line 284 "ph2.y"
                                                      {break_in_loop++; con_in_loop++; }
#line 1856 "parser.c"
    break;

  case 90: /* whilestmt: WHILE LEFT_PAR expr RIGHT_PAR $@6 stmt  */
#line 284 "ph2.y"
                                                                                             {printf("\"Grammar\": whilestmt | WHILE LEFT_PAR expr RIGHT_PAR stmt\n");}
#line 1862 "parser.c"
    break;

  case 91: /* $@7: %empty  */
#line 287 "ph2.y"
                                                                                    {break_in_loop++; con_in_loop++; }
#line 1868 "parser.c"
    break;

  case 92: /* forstmt: FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist RIGHT_PAR $@7 stmt  */
#line 287 "ph2.y"
                                                                                                                           {printf("\"Grammar\": forstmt | FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist LEFT_PAR stmt\n");}
#line 1874 "parser.c"
    break;

  case 93: /* returnstmt: RETURN expr SEMICOLON  */
#line 291 "ph2.y"
                                       {printf("\"Grammar\": returnstmt | RETURN expr SEMICOLON\n");}
#line 1880 "parser.c"
    break;

  case 94: /* returnstmt: RETURN SEMICOLON  */
#line 292 "ph2.y"
                                                  {printf("\"Grammar\": returnstmt | RETURN SEMICOLON\n");}
#line 1886 "parser.c"
    break;


#line 1890 "parser.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 298 "ph2.y"



/*conclusion*/

int yyerror(char* yaccProvidedMessage){  /*tin parexoume emeis ston yacc*/

	fprintf(stderr,"%s: at line %d, before token %s\n",yaccProvidedMessage,yylineno,yytext);
	fprintf(stderr,"INPUT NOT VALID\n");

}

int main(int argc, char **argv) {

	
	if(argc >1){
		if(!(yyin = fopen(argv[1],"r"))){
			fprintf(stderr,"Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}
	else
	{
		yyin=stdin;
	}
	libfunctions();
	yyparse(); /*parexetai apo yacc*/
	printRes();
	return 0;
}




