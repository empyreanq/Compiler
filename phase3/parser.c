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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "header.h"
#include "quads.h"
#include "temp.h"
#include "scope_offset.h"

unsigned programVarOffset=0;
unsigned functionLocalOffset=0;
unsigned formalArgOffset=0;
unsigned scopeSpaceCounter=1;

quad* quads = (quad*) 0;
unsigned total=0;
unsigned int currQuad=0;


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
int libflag=0;
char *libflagname;
//if 
int ifprefixflag[100];
int ifprefixcounter=0;
int elseprefixflag[100];
int elseprefixcounter=0;
int returnflag[100];
int returncounter=0;
int scopeforreturn[100];

//loop
int loopcounter=0;


#line 121 "parser.c"

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
  YYSYMBOL_funcname = 71,                  /* funcname  */
  YYSYMBOL_funcprefix = 72,                /* funcprefix  */
  YYSYMBOL_funcargs = 73,                  /* funcargs  */
  YYSYMBOL_funcbody = 74,                  /* funcbody  */
  YYSYMBOL_funcdef = 75,                   /* funcdef  */
  YYSYMBOL_const = 76,                     /* const  */
  YYSYMBOL_final_idlist = 77,              /* final_idlist  */
  YYSYMBOL_idlist = 78,                    /* idlist  */
  YYSYMBOL_ifprefix = 79,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 80,                /* elseprefix  */
  YYSYMBOL_ifstmt = 81,                    /* ifstmt  */
  YYSYMBOL_loopstart = 82,                 /* loopstart  */
  YYSYMBOL_loopend = 83,                   /* loopend  */
  YYSYMBOL_loopstmt = 84,                  /* loopstmt  */
  YYSYMBOL_whilestart = 85,                /* whilestart  */
  YYSYMBOL_whilecond = 86,                 /* whilecond  */
  YYSYMBOL_whilestmt = 87,                 /* whilestmt  */
  YYSYMBOL_88_2 = 88,                      /* $@2  */
  YYSYMBOL_N = 89,                         /* N  */
  YYSYMBOL_M = 90,                         /* M  */
  YYSYMBOL_forprefix = 91,                 /* forprefix  */
  YYSYMBOL_forstmt = 92,                   /* forstmt  */
  YYSYMBOL_93_3 = 93,                      /* $@3  */
  YYSYMBOL_94_4 = 94,                      /* $@4  */
  YYSYMBOL_returnstmt = 95                 /* returnstmt  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

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
       0,   163,   163,   164,   167,   174,   191,   192,   193,   194,
     195,   196,   205,   211,   212,   213,   217,   218,   219,   220,
     221,   222,   223,   232,   241,   250,   259,   268,   277,   283,
     289,   292,   293,   302,   308,   319,   330,   341,   352,   355,
     375,   379,   380,   381,   382,   386,   412,   441,   446,   450,
     455,   462,   465,   470,   475,   486,   495,   496,   499,   508,
     516,   526,   533,   534,   538,   546,   558,   567,   570,   573,
     583,   583,   589,   590,   596,   613,   622,   631,   681,   685,
     686,   687,   688,   689,   693,   699,   707,   708,   711,   717,
     722,   726,   733,   737,   741,   745,   750,   757,   757,   772,
     774,   776,   784,   784,   784,   798,   807
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
  "funcname", "funcprefix", "funcargs", "funcbody", "funcdef", "const",
  "final_idlist", "idlist", "ifprefix", "elseprefix", "ifstmt",
  "loopstart", "loopend", "loopstmt", "whilestart", "whilecond",
  "whilestmt", "$@2", "N", "M", "forprefix", "forstmt", "$@3", "$@4",
  "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     199,   -20,  -173,   -11,    -7,   234,    -1,     5,   304,     3,
    -173,  -173,  -173,    -8,    -8,   304,    12,  -173,   269,     8,
    -173,  -173,  -173,  -173,  -173,    50,   199,  -173,   105,  -173,
    -173,  -173,    74,  -173,     1,  -173,  -173,    19,  -173,  -173,
     199,  -173,    23,  -173,  -173,  -173,  -173,   304,   304,  -173,
    -173,  -173,   334,  -173,  -173,  -173,  -173,    55,   -16,     1,
     -16,  -173,   465,    30,   199,   304,   534,    22,    27,    24,
      29,  -173,  -173,  -173,  -173,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,  -173,  -173,
    -173,   304,   304,   304,    37,    38,  -173,  -173,  -173,   304,
     304,    39,    44,    34,    65,   304,  -173,   304,   488,    49,
    -173,    64,  -173,    66,   154,   380,   304,  -173,    67,  -173,
     567,   555,   579,   579,   -18,   -18,  -173,  -173,  -173,   588,
     588,   588,   588,   534,    70,   402,    72,  -173,    76,   423,
    -173,  -173,    56,    81,  -173,  -173,  -173,   199,   511,  -173,
      85,  -173,  -173,    66,   304,  -173,   304,   534,  -173,  -173,
    -173,   304,  -173,  -173,    59,  -173,  -173,  -173,   199,  -173,
    -173,   304,    86,   444,    87,  -173,  -173,  -173,   357,  -173,
    -173,  -173,  -173,   199,  -173,  -173,  -173,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    95,     0,    73,     0,     0,     0,     0,     0,
      82,    83,    81,     0,     0,     0,     0,    70,    63,     0,
      15,    78,    79,    45,    80,     0,     2,     5,     0,    30,
      16,    38,    40,    48,    41,    42,    13,     0,    14,    44,
       0,     7,     0,     8,    99,     9,    10,     0,    63,    72,
      74,   106,     0,    11,    12,    33,    46,     0,    34,     0,
      36,    32,     0,     0,     0,     0,    61,    62,     0,    68,
       0,    67,    47,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    35,
      37,     0,    63,     0,     0,     0,    54,    56,    57,    63,
       0,     0,    87,     0,    90,     0,    97,    63,     0,     0,
     105,     0,    31,    43,     0,     0,     0,    64,     0,    65,
      28,    29,    26,    27,    17,    18,    19,    20,    21,    23,
      25,    22,    24,    39,     0,     0,     0,    49,     0,     0,
      51,    85,    86,     0,    76,    77,    89,     0,     0,    92,
       0,    88,   100,     0,    63,    71,     0,    60,    66,    58,
      50,    63,    53,    52,     0,    75,    91,    96,     0,    98,
     102,     0,     0,     0,     0,    84,    93,    99,     0,    55,
      69,    59,    94,     0,   101,   103,    99,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,    43,   -25,    -5,  -173,  -173,  -173,     4,  -173,
      21,  -173,  -173,  -173,  -173,   -46,  -173,  -173,  -173,     6,
      18,  -173,  -173,  -173,  -173,  -173,   -12,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -172,  -173,  -173,  -173,  -173,  -173,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    96,    97,    98,    67,    68,    35,    69,    70,    71,
      36,    64,    50,    37,   103,   145,    38,    39,   142,   143,
      40,   147,    41,   168,   182,   169,    42,   106,    43,   149,
     107,   171,    44,    45,   177,   186,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    74,   109,    55,    63,   183,     9,    81,    82,    83,
      61,    62,    47,    66,   187,   104,    92,    58,    60,     4,
      93,    48,    94,    95,    57,     8,     9,    10,    11,    12,
      13,    14,    19,    99,    59,    59,    15,   100,    23,    49,
     101,    53,   108,    66,    16,   111,   134,    54,    18,    56,
      73,   102,    19,   138,    72,   105,    21,    22,    23,    24,
     115,   150,     4,   113,   117,   116,   119,   118,    17,   146,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   136,   137,   140,   133,    66,   135,    74,
     141,   152,    89,    90,    66,   139,    91,   153,   154,   164,
     148,    65,    66,   159,   161,   175,    92,   114,   172,   162,
      93,   157,    94,    95,   165,   174,    75,    76,   170,   179,
     181,   144,   166,     0,   158,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,    88,     0,    66,
       0,   173,     0,     0,     0,     0,    66,     1,   185,     2,
       3,     4,     5,     6,     7,     0,   178,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    17,   155,
      18,     0,     0,     0,    19,     0,    20,     0,    21,    22,
      23,    24,     1,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,    16,     0,    17,     0,    18,     0,     0,     0,    19,
       0,    20,     0,    21,    22,    23,    24,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
      18,     0,     0,     0,    19,     0,    51,     0,    21,    22,
      23,    24,     8,     9,    10,    11,    12,    13,    14,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,    16,     0,    65,     0,    18,     0,     0,     0,    19,
       0,     0,     0,    21,    22,    23,    24,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
      18,     0,     0,     0,    19,    75,    76,     0,    21,    22,
      23,    24,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,   110,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,   184,
      77,    78,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,    75,    76,     0,     0,     0,     0,     0,
       0,   156,    77,    78,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    75,    76,     0,     0,     0,   160,
       0,     0,     0,    77,    78,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    75,    76,     0,     0,     0,
     163,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    75,    76,     0,   180,
       0,     0,     0,     0,     0,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,   112,    75,
      76,     0,     0,     0,     0,     0,     0,     0,    77,    78,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,   151,    75,    76,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,   167,    75,    76,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    77,    78,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       5,    26,    48,     8,    16,   177,    14,    25,    26,    27,
      15,    16,    32,    18,   186,    40,    32,    13,    14,     7,
      36,    32,    38,    39,    32,    13,    14,    15,    16,    17,
      18,    19,    40,    32,    13,    14,    24,    36,    46,    46,
      39,    42,    47,    48,    32,    57,    92,    42,    36,    46,
       0,    32,    40,    99,    46,    32,    44,    45,    46,    47,
      65,   107,     7,    33,    37,    43,    37,    43,    34,     4,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    46,    46,    46,    91,    92,    93,   114,
      46,    42,    18,    19,    99,   100,    22,    33,    32,    43,
     105,    34,   107,    33,    32,    46,    32,    64,   154,    33,
      36,   116,    38,    39,    33,   161,    11,    12,    33,    33,
      33,   103,   147,    -1,   118,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,    -1,    42,    -1,   154,
      -1,   156,    -1,    -1,    -1,    -1,   161,     3,   183,     5,
       6,     7,     8,     9,    10,    -1,   171,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,    45,
      46,    47,     3,    -1,     5,     6,     7,     8,     9,    10,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    40,
      -1,    42,    -1,    44,    45,    46,    47,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    40,    -1,    42,    -1,    44,    45,
      46,    47,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    45,    46,    47,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    40,    11,    12,    -1,    44,    45,
      46,    47,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    11,    12,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    11,    12,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    11,    12,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    23,    24,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    13,    14,
      15,    16,    17,    18,    19,    24,    32,    34,    36,    40,
      42,    44,    45,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    65,    69,    72,    75,    76,
      79,    81,    85,    87,    91,    92,    95,    32,    32,    46,
      71,    42,    53,    42,    42,    53,    46,    32,    57,    59,
      57,    53,    53,    75,    70,    34,    53,    63,    64,    66,
      67,    68,    46,     0,    52,    11,    12,    20,    21,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    42,    18,
      19,    22,    32,    36,    38,    39,    60,    61,    62,    32,
      36,    39,    32,    73,    52,    32,    86,    89,    53,    64,
      42,    75,    33,    33,    51,    53,    43,    37,    43,    37,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    64,    53,    46,    46,    64,    53,
      46,    46,    77,    78,    69,    74,     4,    80,    53,    88,
      64,    33,    42,    33,    32,    35,    41,    53,    68,    33,
      37,    32,    33,    37,    43,    33,    52,    33,    82,    84,
      33,    90,    64,    53,    64,    46,    52,    93,    53,    33,
      35,    33,    83,    89,    42,    52,    94,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      70,    69,    71,    71,    72,    73,    74,    75,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    80,
      81,    81,    82,    83,    84,    85,    86,    88,    87,    89,
      90,    91,    93,    94,    92,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     2,     6,     1,     1,     3,     5,
       3,     1,     1,     0,     3,     3,     3,     1,     1,     5,
       0,     4,     1,     0,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     4,     1,
       2,     4,     0,     0,     3,     1,     3,     0,     4,     0,
       0,     7,     0,     0,     9,     3,     2
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
#line 163 "ph2.y"
                         {printf("\"Grammar\": program | program stmt\n");}
#line 1433 "parser.c"
    break;

  case 3: /* program: %empty  */
#line 164 "ph2.y"
                         {(yyval.stmt_tt)=NULL;printf("\"Grammar\": program | empty\n");}
#line 1439 "parser.c"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 167 "ph2.y"
                              {
				//printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
				(yyval.stmt_tt)->breaklist=mergelist((yyvsp[-1].stmt_tt)->breaklist,(yyvsp[0].stmt_tt)->breaklist);
				(yyval.stmt_tt)->contlist=mergelist((yyvsp[-1].stmt_tt)->contlist,(yyvsp[0].stmt_tt)->contlist);
				//printf("\"Grammar\": stmt_list | stmt stmt_list\n");
				//printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
			}
#line 1451 "parser.c"
    break;

  case 5: /* stmt_list: stmt  */
#line 174 "ph2.y"
                             {
				(yyval.stmt_tt)=(yyvsp[0].stmt_tt);
			}
#line 1459 "parser.c"
    break;

  case 6: /* stmt: expr SEMICOLON  */
#line 191 "ph2.y"
                               {resettemp();(yyval.stmt_tt)=make_stmt();if(libflag==-2)printf("ERROR :::::: Variable with name : %s is a libfunc!!!!!\nfailed at line : %d\n",libflagname,yylineno);libflag=0;printf("\"Grammar\": stmt | expr SEMICOLON\n");}
#line 1465 "parser.c"
    break;

  case 7: /* stmt: ifstmt  */
#line 192 "ph2.y"
                                {resettemp();(yyval.stmt_tt)=make_stmt();printf("\"Grammar\": stmt | ifstmt\n");}
#line 1471 "parser.c"
    break;

  case 8: /* stmt: whilestmt  */
#line 193 "ph2.y"
                                  {resettemp();(yyval.stmt_tt)=make_stmt();printf("\"Grammar\": stmt | whilestmt\n");}
#line 1477 "parser.c"
    break;

  case 9: /* stmt: forstmt  */
#line 194 "ph2.y"
                                 {resettemp();(yyval.stmt_tt)=make_stmt();printf("\"Grammar\": stmt | forstmt\n");}
#line 1483 "parser.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 195 "ph2.y"
                                    {resettemp();(yyval.stmt_tt)=make_stmt(); if(return_in_func == 0){printf("Error, return is not inside function at line %d!\n",yylineno); } printf("\"Grammar\": stmt | returnstmt\n"); }
#line 1489 "parser.c"
    break;

  case 11: /* stmt: BREAK SEMICOLON  */
#line 196 "ph2.y"
                                         {resettemp();if(break_in_loop == 0){printf("Error, break is used but not in loop at line %d!\n",yylineno);}
				(yyval.stmt_tt)=make_stmt();
				(yyval.stmt_tt)->breaklist=newlist(currQuad);
				//printf("%d\n",currQuad);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//printf("%d\n",currQuad);
				//printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
				//printf("\"Grammar\": stmt | BREAK SEMICOLON\n");
			}
#line 1503 "parser.c"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 205 "ph2.y"
                                            {resettemp();if(con_in_loop == 0){printf("Error, continue is used but not in loop at line %d!\n",yylineno);}
				(yyval.stmt_tt)=make_stmt();
				(yyval.stmt_tt)->contlist=newlist(currQuad);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				printf("\"Grammar\": stmt | CONTINUE SEMICOLON\n");
			}
#line 1514 "parser.c"
    break;

  case 13: /* stmt: block  */
#line 211 "ph2.y"
                               {resettemp();(yyval.stmt_tt)=(yyvsp[0].stmt_tt);printf("\"Grammar\": stmt | block\n");}
#line 1520 "parser.c"
    break;

  case 14: /* stmt: funcdef  */
#line 212 "ph2.y"
                                 {resettemp();(yyval.stmt_tt)=make_stmt();printf("\"Grammar\": stmt | funcdef\n");}
#line 1526 "parser.c"
    break;

  case 15: /* stmt: SEMICOLON  */
#line 213 "ph2.y"
                                   {resettemp();(yyval.stmt_tt)=make_stmt();printf("\"Grammar\": stmt | SEMICOLON\n");}
#line 1532 "parser.c"
    break;

  case 16: /* expr: assignexpr  */
#line 217 "ph2.y"
                           {printf("\"Grammar\": expr | assignexpr\n");}
#line 1538 "parser.c"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 218 "ph2.y"
                                         {(yyval.expr)=newexpr(arithexpr_e);(yyval.expr)->sym=newtemp(scope);emit(add,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);printf("\"Grammar\": expr | expr PLUS expr\n");}
#line 1544 "parser.c"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 219 "ph2.y"
                                          {(yyval.expr)=newexpr(arithexpr_e);(yyval.expr)->sym=newtemp(scope);emit(sub,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);printf("\"Grammar\": expr | expr MINUS expr\n");}
#line 1550 "parser.c"
    break;

  case 19: /* expr: expr MULTIPLY expr  */
#line 220 "ph2.y"
                                             {(yyval.expr)=newexpr(arithexpr_e);(yyval.expr)->sym=newtemp(scope);emit(mul,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);printf("\"Grammar\": expr | expr MULTIPLY expr\n");}
#line 1556 "parser.c"
    break;

  case 20: /* expr: expr DIVIDE expr  */
#line 221 "ph2.y"
                                           {(yyval.expr)=newexpr(arithexpr_e);(yyval.expr)->sym=newtemp(scope);emit(divide,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);printf("\"Grammar\": expr | expr DIVIDE expr\n");}
#line 1562 "parser.c"
    break;

  case 21: /* expr: expr MODULO expr  */
#line 222 "ph2.y"
                                           {(yyval.expr)=newexpr(arithexpr_e);(yyval.expr)->sym=newtemp(scope);emit(mod,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);printf("\"Grammar\": expr | expr MODULO expr\n");}
#line 1568 "parser.c"
    break;

  case 22: /* expr: expr GREATER expr  */
#line 223 "ph2.y"
                                            {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_greater,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);	
				printf("\"Grammar\": expr | expr GREATER expr\n");
			}
#line 1582 "parser.c"
    break;

  case 23: /* expr: expr GREATEREQ expr  */
#line 232 "ph2.y"
                                              {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_greatereq,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr GREATEREQ expr\n");
			}
#line 1596 "parser.c"
    break;

  case 24: /* expr: expr LESS expr  */
#line 241 "ph2.y"
                                         {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_less,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr LESS expr\n");
			}
#line 1610 "parser.c"
    break;

  case 25: /* expr: expr LESSEQ expr  */
#line 250 "ph2.y"
                                           {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_lesseq,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr LESSEQ expr\n");
			}
#line 1624 "parser.c"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 259 "ph2.y"
                                          {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_eq,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr EQUAL expr\n");
			}
#line 1638 "parser.c"
    break;

  case 27: /* expr: expr NOTEQUAL expr  */
#line 268 "ph2.y"
                                             {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(if_noteq,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),currQuad+4,yylineno);
				emit(assign,newexpr_constbool(0),NULL,(yyval.expr),0,yylineno);
				emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
				emit(assign,newexpr_constbool(1),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr NOTEQUAL expr\n");
			}
#line 1652 "parser.c"
    break;

  case 28: /* expr: expr AND expr  */
#line 277 "ph2.y"
                                        {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(and,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr AND expr\n");
			}
#line 1663 "parser.c"
    break;

  case 29: /* expr: expr OR expr  */
#line 283 "ph2.y"
                                       {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(or,(yyvsp[-2].expr),(yyvsp[0].expr),(yyval.expr),0,yylineno);
				printf("\"Grammar\": expr | expr OR expr\n");
			}
#line 1674 "parser.c"
    break;

  case 30: /* expr: term  */
#line 289 "ph2.y"
                               {(yyval.expr)=(yyvsp[0].expr);printf("\"Grammar\": expr | term\n");}
#line 1680 "parser.c"
    break;

  case 31: /* term: LEFT_PAR expr RIGHT_PAR  */
#line 292 "ph2.y"
                                        {(yyval.expr)=(yyvsp[-1].expr);printf("\"Grammar\": term | LEFT_PAR expr RIGHT_PAR\n");}
#line 1686 "parser.c"
    break;

  case 32: /* term: MINUS expr  */
#line 293 "ph2.y"
                                                 {
				printf("\"Grammar\": term | MINUS expr %prec UMINUS\n");
					check_arith((yyvsp[0].expr));
					(yyval.expr)=newexpr(arithexpr_e);
					(yyval.expr)->sym=newtemp(scope);
					emit(uminus,(yyvsp[0].expr),NULL,(yyval.expr),0,yylineno);
			}
#line 1698 "parser.c"
    break;

  case 33: /* term: NOT expr  */
#line 302 "ph2.y"
                                  {
				(yyval.expr)=newexpr(boolexpr_e);
				(yyval.expr)->sym=newtemp(scope);
				emit(not,(yyvsp[0].expr),NULL,(yyval.expr),0,yylineno);
				printf("\"Grammar\": term | NOT expr\n");
			}
#line 1709 "parser.c"
    break;

  case 34: /* term: PLUSPLUS lvalue  */
#line 308 "ph2.y"
                                         {
				check_arith((yyvsp[0].expr));
				if((yyvsp[0].expr)->type==tableitem_e){}
				else{
					emit(add,(yyvsp[0].expr),exprNumConst(1),(yyvsp[0].expr),0,yylineno);
					(yyval.expr)=newexpr(arithexpr_e);
					(yyval.expr)->sym=newtemp(scope);
					emit(assign,(yyvsp[0].expr),NULL,(yyval.expr),0,yylineno);
				}
				printf("\"Grammar\": term | PLUSPLUS lvalue\n");
			}
#line 1725 "parser.c"
    break;

  case 35: /* term: lvalue PLUSPLUS  */
#line 319 "ph2.y"
                                         {
				check_arith((yyvsp[-1].expr));
				(yyval.expr)=newexpr(var_e);
				(yyval.expr)->sym=newtemp(scope);
				if((yyval.expr)->type==tableitem_e){}
				else{
					emit(assign,(yyvsp[-1].expr),NULL,(yyval.expr),0,yylineno);
					emit(add,(yyvsp[-1].expr),exprNumConst(1),(yyvsp[-1].expr),0,yylineno);
				}
				printf("\"Grammar\": term | lvalue PLUSPLUS\n");
			}
#line 1741 "parser.c"
    break;

  case 36: /* term: MINMIN lvalue  */
#line 330 "ph2.y"
                                       {
				check_arith((yyvsp[0].expr));
				if((yyvsp[0].expr)->type==tableitem_e){}
				else{
					emit(sub,(yyvsp[0].expr),exprNumConst(1),(yyvsp[0].expr),0,yylineno);
					(yyval.expr)=newexpr(arithexpr_e);
					(yyval.expr)->sym=newtemp(scope);
					emit(assign,(yyvsp[0].expr),NULL,(yyval.expr),0,yylineno);
				}
				printf("\"Grammar\": term | MINMIN lvalue\n");
			}
#line 1757 "parser.c"
    break;

  case 37: /* term: lvalue MINMIN  */
#line 341 "ph2.y"
                                       {
				check_arith((yyvsp[-1].expr));
				(yyval.expr)=newexpr(var_e);
				(yyval.expr)->sym=newtemp(scope);
				if((yyval.expr)->type==tableitem_e){}
				else{
					emit(assign,(yyvsp[-1].expr),NULL,(yyval.expr),0,yylineno);
					emit(sub,(yyvsp[-1].expr),exprNumConst(1),(yyvsp[-1].expr),0,yylineno);
				}
				printf("\"Grammar\": term | lvalue MINMIN\n");
			}
#line 1773 "parser.c"
    break;

  case 38: /* term: primary  */
#line 352 "ph2.y"
                                 {(yyval.expr)=(yyvsp[0].expr);printf("\"Grammar\": term | primary \n");}
#line 1779 "parser.c"
    break;

  case 39: /* assignexpr: lvalue ASSIGN expr  */
#line 355 "ph2.y"
                               {
				//isws elenxos gia an eine sunartiseis 		DIFFF
				if((yyvsp[-2].expr)->type == tableitem_e){
					emit(tablesetelem,(yyvsp[-2].expr)->index,(yyvsp[0].expr),(yyvsp[-2].expr),0,yylineno);
					(yyval.expr)=emit_iftableitem((yyvsp[-2].expr),scope,yylineno);
					(yyval.expr)->type=assignexpr_e;
				}else{
					emit(assign,(yyvsp[0].expr),NULL,(yyvsp[-2].expr),0,yylineno);
					(yyval.expr)=lvalue_expr(newtemp(scope));
					(yyval.expr)->type=assignexpr_e; // $$=lvalue_expr(newtemp(scope)); h auto den kserw DIFFF
					//$$->sym=newtemp(scope);
					emit(assign,(yyvsp[-2].expr),NULL,(yyval.expr),0,yylineno);
				}
				/*emit(assign,$3,NULL,$1,0,yylineno);
				$$=lvalue_expr(newtemp(scope));				AUTO EIXAME PRIN PROS8ESW TA TABLE DIFFFF!!!!
				$$->type=assignexpr_e;
				emit(assign,$1,NULL,$$,0,yylineno);*/
				printf("\"Grammar\": assignexpr | lvalue ASSIGN expr\n");}
#line 1802 "parser.c"
    break;

  case 40: /* primary: lvalue  */
#line 375 "ph2.y"
                       {
				(yyval.expr)=emit_iftableitem((yyvsp[0].expr),scope,yylineno);
				printf("\"Grammar\": primary | lvalue\n");
			}
#line 1811 "parser.c"
    break;

  case 41: /* primary: call  */
#line 379 "ph2.y"
                              {printf("\"Grammar\": primary | call\n");}
#line 1817 "parser.c"
    break;

  case 42: /* primary: objectdef  */
#line 380 "ph2.y"
                                   {printf("\"Grammar\": primary | objectdef\n");}
#line 1823 "parser.c"
    break;

  case 43: /* primary: LEFT_PAR funcdef RIGHT_PAR  */
#line 381 "ph2.y"
                                                    {(yyval.expr)=newexpr(programfunc_e);(yyval.expr)=(yyvsp[-1].expr);printf("\"Grammar\": primary | LEFT_PAR funcdef RIGHT_PAR\n");}
#line 1829 "parser.c"
    break;

  case 44: /* primary: const  */
#line 382 "ph2.y"
                               {printf("\"Grammar\": primary | const \n");}
#line 1835 "parser.c"
    break;

  case 45: /* lvalue: ID  */
#line 386 "ph2.y"
                   {
				//printf("$1=%s\n",$1);
				printf("\"Grammar\": lvalue | ID\n");
				struct Entry* x=lookUp((yyvsp[0].strVal));
				if(x==NULL){
					(yyval.expr)=lvalue_expr(checkedInsertion(scope,(yyvsp[0].strVal),yylineno,(scope==0)?0:1,functionvar));
					inccurroffset();
				}
				else {
					(yyval.expr)=lvalue_expr(x);
					inccurroffset();
				}
				/*
				}// prepei na bei periptwsh gia na uparxei to symbol wste na epistrefume ekeino. h na to dinume sthn lvalue_expre
				if(scope==0){
					libflag=checkedInsertion(scope,$<strVal>1,yylineno,0,functionvar);
				}
				else {
					libflag=checkedInsertion(scope,$<strVal>1,yylineno,1,functionvar);
				}
				if(libflag==-1){
						printf("failed at line : %d\n",yylineno);}
					else if(libflag==-2)
						libflagname=$<strVal>1;*/
			}
#line 1865 "parser.c"
    break;

  case 46: /* lvalue: LOCAL ID  */
#line 412 "ph2.y"
                                  {
				printf("\"Grammar\": lvalue | LOCAL ID\n");
				struct Entry* x=lookUp((yyvsp[0].strVal));
				if(x==NULL){
					(yyval.expr)=lvalue_expr(checkedInsertion(scope,(yyvsp[0].strVal),yylineno,(scope==0)?0:5,functionvar));
					inccurroffset();
				}
				else {
					(yyval.expr)=lvalue_expr(x);
					inccurroffset();
				}
				/*printf("\"Grammar\": lvalue | LOCAL ID\n");
				if(lookUpScope($<strVal>1,scope)==NULL){
					checkedInsertion(scope,$<strVal>1,yylineno,0,functionvar);
					inccurroffset();
				}
				if(scope==0){
					if(checkedInsertion(scope,$<strVal>2,yylineno,0,functionvar)==-1){
						printf("failed at line : %d\n",yylineno);
					}
				}else{
					libflag=checkedInsertion(scope,$<strVal>2,yylineno,5,functionvar);
					if(libflag==-1){
						printf("failed at line : %d\n",yylineno);
					}else if(libflag==-2)
						libflagname=$<strVal>2;
				}
			*/}
#line 1898 "parser.c"
    break;

  case 47: /* lvalue: D_SCOPE ID  */
#line 441 "ph2.y"
                                    {
				printf("\"Grammar\": lvalue | D_SCOPE\n");
				(yyval.expr)=lvalue_expr(checkD_Scope((yyvsp[0].strVal))); // isws xreiastei inccurroffset++!!!
			}
#line 1907 "parser.c"
    break;

  case 48: /* lvalue: member  */
#line 446 "ph2.y"
                                {(yyval.expr)=(yyvsp[0].expr);
				printf("\"Grammar\": lvalue | MEMBER\n");}
#line 1914 "parser.c"
    break;

  case 49: /* member: lvalue DOT ID  */
#line 450 "ph2.y"
                              {
				(yyval.expr)=member_item((yyvsp[-2].expr),(yyvsp[0].strVal),scope,yylineno);	
				(yyval.expr)->type=tableitem_e;
				printf("\"Grammar\": member | lvalue DOT ID\n");
			}
#line 1924 "parser.c"
    break;

  case 50: /* member: lvalue LEFT_SQ expr RIGHT_SQ  */
#line 455 "ph2.y"
                                                      {
				(yyvsp[-3].expr)=emit_iftableitem((yyvsp[-3].expr),scope,yylineno);
				(yyval.expr)=newexpr(tableitem_e);
				(yyval.expr)->sym=(yyvsp[-3].expr)->sym;
				(yyval.expr)->index=(yyvsp[-1].expr);
				printf("\"Grammar\": member | lvalue LEFT_SQ\n");
			}
#line 1936 "parser.c"
    break;

  case 51: /* member: call DOT ID  */
#line 462 "ph2.y"
                                     {
				printf("\"Grammar\": member | call DOT ID\n");
			}
#line 1944 "parser.c"
    break;

  case 52: /* member: call LEFT_SQ expr RIGHT_SQ  */
#line 465 "ph2.y"
                                                    {
				printf("\"Grammar\": member | call LEFT_SQ expr RIGHT_SQ\n");
			}
#line 1952 "parser.c"
    break;

  case 53: /* call: call LEFT_PAR elist RIGHT_PAR  */
#line 470 "ph2.y"
                                              {
				printf("\"Grammar\": call | call LEFT_PAR elist RIGHT_PAR\n");
				(yyval.expr)=make_call((yyvsp[-3].expr),(yyvsp[-1].expr),scope,yylineno);	
				
			}
#line 1962 "parser.c"
    break;

  case 54: /* call: lvalue callsuffix  */
#line 475 "ph2.y"
                                           {
				printf("\"Grammar\": call | lvalue callsuffix\n");
				(yyvsp[-1].expr)=emit_iftableitem((yyvsp[-1].expr),scope,yylineno);
				if((yyvsp[0].callee).method){
					expr *t=(yyvsp[-1].expr);
					(yyvsp[-1].expr)=emit_iftableitem(member_item(t,(yyvsp[0].callee).name,scope,yylineno),scope,yylineno);
					(yyvsp[0].callee).elist->next=t;
				}	
				(yyval.expr)=make_call((yyvsp[-1].expr),(yyvsp[0].callee).elist,scope,yylineno);
				
			}
#line 1978 "parser.c"
    break;

  case 55: /* call: LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR  */
#line 486 "ph2.y"
                                                                             {
				printf("\"Grammar\": call | LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR\n");
				expr *func = newexpr(programfunc_e);
				func->sym=(yyvsp[-4].expr)->sym;
				(yyval.expr)=make_call(func,(yyvsp[-1].expr),scope,yylineno);	
				
			}
#line 1990 "parser.c"
    break;

  case 56: /* callsuffix: normcall  */
#line 495 "ph2.y"
                         {(yyval.callee)=(yyvsp[0].callee);printf("\"Grammar\": callsuffix | normcall\n");}
#line 1996 "parser.c"
    break;

  case 57: /* callsuffix: methodcall  */
#line 496 "ph2.y"
                                    {(yyval.callee)=(yyvsp[0].callee);printf("\"Grammar\": callsuffix | methodcall\n");}
#line 2002 "parser.c"
    break;

  case 58: /* normcall: LEFT_PAR elist RIGHT_PAR  */
#line 499 "ph2.y"
                                         {
				printf("\"Grammar\": normcall | LEFT_PAR elist RIGHT_PAR\n");
				(yyval.callee).elist=(yyvsp[-1].expr);
				(yyval.callee).method=0;
				(yyval.callee).name=NULL;

			}
#line 2014 "parser.c"
    break;

  case 59: /* methodcall: DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR  */
#line 508 "ph2.y"
                                                       {
				printf("\"Grammar\": methodcall | DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR\n");
				(yyval.callee).elist=(yyvsp[-1].expr);
				(yyval.callee).method=1;
				(yyval.callee).name=(yyvsp[-3].strVal);
			}
#line 2025 "parser.c"
    break;

  case 60: /* expression: expression COMMA expr  */
#line 516 "ph2.y"
                                     {
				assert((yyvsp[-2].expr)!=NULL && (yyvsp[0].expr)!=NULL);	
				struct expr* t = (yyvsp[-2].expr);
				while(t->next){
					t=t->next;
				}
				t->next=(yyvsp[0].expr);
				(yyval.expr)=(yyvsp[-2].expr);
				//$3->next=$1;$$=$3;
				printf("\"Grammar\": expression | expression COMMA expr\n");}
#line 2040 "parser.c"
    break;

  case 61: /* expression: expr  */
#line 526 "ph2.y"
                             {				
				if((yyvsp[0].expr)){(yyval.expr)=(yyvsp[0].expr);}
				printf("\"Grammar\": expression | expr\n");}
#line 2048 "parser.c"
    break;

  case 62: /* elist: expression  */
#line 533 "ph2.y"
                           {printf("\"Grammar\": elist | expr\n");}
#line 2054 "parser.c"
    break;

  case 63: /* elist: %empty  */
#line 534 "ph2.y"
                                     {(yyval.expr)=NULL;printf("\"Grammar\": elist | empty\n");}
#line 2060 "parser.c"
    break;

  case 64: /* objectdef: LEFT_SQ elist RIGHT_SQ  */
#line 538 "ph2.y"
                                       {
				struct expr* t=newexpr(newtable_e);
				t->sym=newtemp(scope);
				emit(tablecreate,NULL,NULL,t,0,yylineno); // isws adi gia 0 thelei currQuad DIFF
				for(int x=0;(yyvsp[-1].expr);(yyvsp[-1].expr)=(yyvsp[-1].expr)->next){emit(tablesetelem,exprNumConst(x++),(yyvsp[-1].expr),t,0,yylineno);}// isws adi gia 0 thelei currQuad DIFF
				(yyval.expr)=t;
				printf("\"Grammar\": objectdef | LEFT_SQ elist RIGHT_SQ\n");
			}
#line 2073 "parser.c"
    break;

  case 65: /* objectdef: LEFT_SQ indexed RIGHT_SQ  */
#line 546 "ph2.y"
                                                  {
				struct expr* t=newexpr(newtable_e);
				t->sym=newtemp(scope);
				emit(tablecreate,NULL,NULL,t,0,yylineno);
				for(int x=0;(yyvsp[-1].expr);(yyvsp[-1].expr)=(yyvsp[-1].expr)->next){emit(tablesetelem,(yyvsp[-1].expr),t->index,t,0,yylineno);}// isws adi gia 0 thelei currQuad DIFF
				(yyval.expr)=t;
				printf("\"Grammar\": objectdef | LEFT_SQ indexed RIGHT_SQ\n");
			}
#line 2086 "parser.c"
    break;

  case 66: /* indexed_list: indexed_list COMMA indexedelem  */
#line 558 "ph2.y"
                                              {
					assert((yyvsp[-2].expr)!=NULL && (yyvsp[0].expr)!=NULL);
					struct expr* t = (yyvsp[-2].expr);
					while(t->next){
						t=t->next;
					}
					t->next=(yyvsp[0].expr);
					(yyval.expr)=(yyvsp[-2].expr);
				}
#line 2100 "parser.c"
    break;

  case 67: /* indexed_list: indexedelem  */
#line 567 "ph2.y"
                                            {(yyval.expr)=(yyvsp[0].expr);}
#line 2106 "parser.c"
    break;

  case 68: /* indexed: indexed_list  */
#line 570 "ph2.y"
                                    {printf("\"Grammar\": indexed | indexedelem\n");}
#line 2112 "parser.c"
    break;

  case 69: /* indexedelem: LEFT_BR expr SCOPE expr RIGHT_BR  */
#line 573 "ph2.y"
                                                 {
					(yyval.expr)=(yyvsp[-3].expr);
					(yyval.expr)->index=(yyvsp[-1].expr);
					printf("\"Grammar\": indexedelem | LEFT_BR expr SCOPE expr RIGHT_BR\n");}
#line 2121 "parser.c"
    break;

  case 70: /* $@1: %empty  */
#line 583 "ph2.y"
                 {scope++;}
#line 2127 "parser.c"
    break;

  case 71: /* block: LEFT_BR $@1 stmt_list RIGHT_BR  */
#line 583 "ph2.y"
                                               {
				(yyval.stmt_tt)=(yyvsp[-1].stmt_tt);
				hideScope(scope);scope--; 
				printf("\"Grammar\": block | LEFT_BR program RIGHT_BR\n");}
#line 2136 "parser.c"
    break;

  case 72: /* funcname: ID  */
#line 589 "ph2.y"
                  {(yyval.strVal)=(yyvsp[0].strVal);printf("\"Grammar\": funcame | ID\n");}
#line 2142 "parser.c"
    break;

  case 73: /* funcname: %empty  */
#line 590 "ph2.y"
                         {printf("\"Grammar\": funcame | empty\n");aa=malloc(sizeof(int)+4);
				snprintf(aa,sizeof(int)+4,"_f%d",funcounter++);
				(yyval.strVal)=aa;
			}
#line 2151 "parser.c"
    break;

  case 74: /* funcprefix: FUNCTION funcname  */
#line 596 "ph2.y"
                                 {
				printf("\"Grammar\": funcprefix | FUNCTION funcname\n");
				functionvar=1;
				struct Entry* x=checkedInsertion(scope,(yyvsp[0].strVal),yylineno,3,functionvar);
				if(x==NULL){
					printf("failed at line : %d - Exiting the program.\n",yylineno);YYABORT;
				}else {
					(yyval.expr)=lvalue_expr(x);
					//$$.iaddress=currquad;
					emit(funcstart,(yyval.expr),NULL,NULL,0,yylineno);
					//push(scopeoffsetstack,currscopeoffset());
					enterscopespace();
					resetformalargoffset();
				}
			}
#line 2171 "parser.c"
    break;

  case 75: /* funcargs: LEFT_PAR idlist RIGHT_PAR  */
#line 613 "ph2.y"
                                         {
				printf("\"Grammar\": funcargs | LEFT_PAR idlist RIGHT_PAR\n");
				enterscopespace();
				printf("hey\n");
				resetfunctionlocalsoffset();
				return_in_func++;
			}
#line 2183 "parser.c"
    break;

  case 76: /* funcbody: block  */
#line 622 "ph2.y"
                     {
				printf("\"Grammar\": funcbody | block\n");
				(yyval.unsign)=currscopeoffset();
				exitscopespace();
				return_in_func--;
				functionvar=0;
			}
#line 2195 "parser.c"
    break;

  case 77: /* funcdef: funcprefix funcargs funcbody  */
#line 631 "ph2.y"
                                            {
									printf("\"Grammar\": funcdef | FUNCTION ID LEFT_PAR idlist RIGHT_PAR block\n");
				exitscopespace();
				//$1.totalLocals=$3;
				//int offset=pop_and_top(scopeoffsetStack);
				//restorecurrscopeoffset(offset);
				(yyval.expr)=(yyvsp[-2].expr);
				emit(funcend,(yyvsp[-2].expr),NULL,NULL,0,yylineno);
				printf("scopeinfuncdef=%d\n",scope);
				for(int ii=0;ii<returncounter;ii++){
					if(scopeforreturn[ii]==(scope+1))
					{patchlabel(returnflag[ii],currQuad);returnflag[ii]=0;scopeforreturn[ii]=0;printf("scopeinfuncdef=%d\n",scope);}
				}
				/*if(returnflag[returncounter]!=0){
					patchlabel(returnflag[returncounter],currQuad);
					returnflag[returncounter]=0;
					returncounter--;
				}*/
			}
#line 2219 "parser.c"
    break;

  case 78: /* const: INTEGER_C  */
#line 681 "ph2.y"
                                  {
					(yyval.expr)=exprNumConst((yyvsp[0].intVal));
					printf("\"Grammar\": const | INTEGER_C\n");
				}
#line 2228 "parser.c"
    break;

  case 79: /* const: REAL_C  */
#line 685 "ph2.y"
                                        {(yyval.expr)=exprNumConst((yyvsp[0].fltVal));printf("\"Grammar\": const | REAL_C\n");}
#line 2234 "parser.c"
    break;

  case 80: /* const: STRING  */
#line 686 "ph2.y"
                                        {(yyval.expr)=newexpr_conststring((yyvsp[0].strVal));printf("\"Grammar\": const | STRING\n");}
#line 2240 "parser.c"
    break;

  case 81: /* const: NIL  */
#line 687 "ph2.y"
                                     {(yyval.expr)=newexpr(nil_e);printf("\"Grammar\": const | NIL\n");}
#line 2246 "parser.c"
    break;

  case 82: /* const: TRUE  */
#line 688 "ph2.y"
                                      {(yyval.expr)=newexpr_constbool(1);printf("\"Grammar\": const | TRUE\n");}
#line 2252 "parser.c"
    break;

  case 83: /* const: FALSE  */
#line 689 "ph2.y"
                                       {(yyval.expr)=newexpr_constbool(0);printf("\"Grammar\": const | FALSE\n");}
#line 2258 "parser.c"
    break;

  case 84: /* final_idlist: final_idlist COMMA ID  */
#line 693 "ph2.y"
                                     {
					printf("\"Grammar\": final_idlist | final_idlist COMMA ID\n"); 
					if(checkedInsertion(scope,(yyvsp[0].strVal),yylineno,2,functionvar)==NULL){
						printf("failed at line : %d\n",yylineno);
					}
				}
#line 2269 "parser.c"
    break;

  case 85: /* final_idlist: ID  */
#line 699 "ph2.y"
                                   {
					printf("\"Grammar\": final_idlist | ID\n");
					if(checkedInsertion(scope,(yyvsp[0].strVal),yylineno,2,functionvar)==NULL){
						printf("failed at line : %d\n",yylineno);
					}
				}
#line 2280 "parser.c"
    break;

  case 86: /* idlist: final_idlist  */
#line 707 "ph2.y"
                                    {printf("\"Grammar\": idlist | ID\n");}
#line 2286 "parser.c"
    break;

  case 88: /* ifprefix: IF LEFT_PAR expr RIGHT_PAR  */
#line 711 "ph2.y"
                                                  { 
					emit(if_eq,(yyvsp[-1].expr),newexpr_constbool(1),NULL,currQuad+3,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					ifprefixflag[ifprefixcounter++]=currQuad-1;
				}
#line 2296 "parser.c"
    break;

  case 89: /* elseprefix: ELSE  */
#line 717 "ph2.y"
                            {
					emit(jump,NULL,NULL,NULL,0,yylineno);
					elseprefixflag[elseprefixcounter++]=currQuad-1;
				}
#line 2305 "parser.c"
    break;

  case 90: /* ifstmt: ifprefix stmt  */
#line 722 "ph2.y"
                                     {	
					patchlabel(ifprefixflag[--ifprefixcounter],currQuad+1);
					printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt\n");}
#line 2313 "parser.c"
    break;

  case 91: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 726 "ph2.y"
                                                              {
					patchlabel(ifprefixflag[--ifprefixcounter],elseprefixflag[elseprefixcounter-1]+2);
					patchlabel(elseprefixflag[--elseprefixcounter],currQuad+1);
					printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt\n");
				}
#line 2323 "parser.c"
    break;

  case 92: /* loopstart: %empty  */
#line 733 "ph2.y"
                                 {++loopcounter;
				printf("\"Grammar\": loopstart | loopstart\n");
				}
#line 2331 "parser.c"
    break;

  case 93: /* loopend: %empty  */
#line 737 "ph2.y"
                                 {--loopcounter;
				printf("\"Grammar\": loopend | loopend\n");
				}
#line 2339 "parser.c"
    break;

  case 94: /* loopstmt: loopstart stmt loopend  */
#line 741 "ph2.y"
                                              {(yyval.stmt_tt)=(yyvsp[-1].stmt_tt);
				printf("\"Grammar\": loopstmt | loopstmt\n");
				}
#line 2347 "parser.c"
    break;

  case 95: /* whilestart: WHILE  */
#line 745 "ph2.y"
                             {(yyval.unsign)=currQuad+1;
				printf("currQUAD:::::::%d\n",currQuad);
				printf("\"Grammar\": whilestart | whilestart\n");
				}
#line 2356 "parser.c"
    break;

  case 96: /* whilecond: LEFT_PAR expr RIGHT_PAR  */
#line 750 "ph2.y"
                                               {
					emit(if_eq,(yyvsp[-1].expr),newexpr_constbool(1),NULL,currQuad+3,yylineno);
					(yyval.unsign)=currQuad;
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": whilecond | whilecond\n");
				}
#line 2367 "parser.c"
    break;

  case 97: /* $@2: %empty  */
#line 757 "ph2.y"
                                            {break_in_loop++; con_in_loop++; }
#line 2373 "parser.c"
    break;

  case 98: /* whilestmt: whilestart whilecond $@2 loopstmt  */
#line 757 "ph2.y"
                                                                                       {
					if(con_in_loop > 0){con_in_loop--;}if(break_in_loop > 0){ break_in_loop--;}
					emit(jump,NULL,NULL,NULL,(yyvsp[-3].unsign),yylineno);
					patchlabel((yyvsp[-2].unsign),currQuad+1);
					printf("!!!!!!!!!!!!!11edw to kalo to patch:::::::%d int\n",currQuad);
					//$$=$4;
					patchlist((yyvsp[0].stmt_tt)->breaklist,currQuad+1);
					patchlist((yyvsp[0].stmt_tt)->contlist,(yyvsp[-3].unsign));
					printf("\"Grammar\": whilestmt | whilestart whilecond loopstmt\n");
				}
#line 2388 "parser.c"
    break;

  case 99: /* N: %empty  */
#line 772 "ph2.y"
                        {(yyval.unsign)=currQuad;emit(jump,NULL,NULL,NULL,0,yylineno);}
#line 2394 "parser.c"
    break;

  case 100: /* M: %empty  */
#line 774 "ph2.y"
                        {(yyval.unsign)=currQuad+1;}
#line 2400 "parser.c"
    break;

  case 101: /* forprefix: FOR LEFT_PAR elist SEMICOLON M expr SEMICOLON  */
#line 777 "ph2.y"
                        {
				(yyval.forprefixx)=make_prefix();
				(yyval.forprefixx)->test=(yyvsp[-2].unsign);
				(yyval.forprefixx)->enter=currQuad;
				emit(if_eq,(yyvsp[-1].expr),newexpr_constbool(1),NULL,0,yylineno);
			}
#line 2411 "parser.c"
    break;

  case 102: /* $@3: %empty  */
#line 784 "ph2.y"
                                           {break_in_loop++; con_in_loop++; }
#line 2417 "parser.c"
    break;

  case 103: /* $@4: %empty  */
#line 784 "ph2.y"
                                                                                    {
				if(break_in_loop > 0){ break_in_loop--;}if(con_in_loop > 0){con_in_loop--;}
				printf("\"Grammar\": forstmt | FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist LEFT_PAR stmt\n");
			}
#line 2426 "parser.c"
    break;

  case 104: /* forstmt: forprefix N elist RIGHT_PAR $@3 N stmt $@4 N  */
#line 787 "ph2.y"
                            {
				patchlabel((yyvsp[-8].forprefixx)->enter,(yyvsp[-3].unsign)+2);
				patchlabel((yyvsp[-7].unsign),currQuad+1);
				patchlabel((yyvsp[-3].unsign),(yyvsp[-8].forprefixx)->test);
				patchlabel((yyvsp[0].unsign),(yyvsp[-7].unsign)+2);

				patchlist((yyvsp[-2].stmt_tt)->breaklist,currQuad+1);
				patchlist((yyvsp[-2].stmt_tt)->contlist,(yyvsp[-7].unsign)+2);
			}
#line 2440 "parser.c"
    break;

  case 105: /* returnstmt: RETURN expr SEMICOLON  */
#line 798 "ph2.y"
                                       {
					
					emit(ret,NULL,NULL,(yyvsp[-1].expr),0,yylineno);
					returnflag[returncounter]=currQuad;
					scopeforreturn[returncounter++]=scope;
					printf("scopeinreturn=%d\n",scope);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": returnstmt | RETURN expr SEMICOLON\n");
				}
#line 2454 "parser.c"
    break;

  case 106: /* returnstmt: RETURN SEMICOLON  */
#line 807 "ph2.y"
                                                  {
					
					emit(ret,NULL,NULL,NULL,0,yylineno);
					returnflag[returncounter]=currQuad;
					scopeforreturn[returncounter++]=scope;printf("scopeinreturn=%d\n",scope);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": returnstmt | RETURN SEMICOLON\n");
				}
#line 2467 "parser.c"
    break;


#line 2471 "parser.c"

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

#line 820 "ph2.y"



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
	printQuads();
	return 0;
}




