/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    FUNCTION = 262,                /* FUNCTION  */
    RETURN = 263,                  /* RETURN  */
    BREAK = 264,                   /* BREAK  */
    CONTINUE = 265,                /* CONTINUE  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    NOT = 268,                     /* NOT  */
    LOCAL = 269,                   /* LOCAL  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    NIL = 272,                     /* NIL  */
    PLUSPLUS = 273,                /* PLUSPLUS  */
    MINMIN = 274,                  /* MINMIN  */
    EQUAL = 275,                   /* EQUAL  */
    NOTEQUAL = 276,                /* NOTEQUAL  */
    ASSIGN = 277,                  /* ASSIGN  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    MULTIPLY = 280,                /* MULTIPLY  */
    DIVIDE = 281,                  /* DIVIDE  */
    MODULO = 282,                  /* MODULO  */
    GREATEREQ = 283,               /* GREATEREQ  */
    LESSEQ = 284,                  /* LESSEQ  */
    GREATER = 285,                 /* GREATER  */
    LESS = 286,                    /* LESS  */
    LEFT_PAR = 287,                /* LEFT_PAR  */
    RIGHT_PAR = 288,               /* RIGHT_PAR  */
    LEFT_BR = 289,                 /* LEFT_BR  */
    RIGHT_BR = 290,                /* RIGHT_BR  */
    LEFT_SQ = 291,                 /* LEFT_SQ  */
    RIGHT_SQ = 292,                /* RIGHT_SQ  */
    DOUBLE_DOT = 293,              /* DOUBLE_DOT  */
    DOT = 294,                     /* DOT  */
    D_SCOPE = 295,                 /* D_SCOPE  */
    SCOPE = 296,                   /* SCOPE  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COMMA = 298,                   /* COMMA  */
    INTEGER_C = 299,               /* INTEGER_C  */
    REAL_C = 300,                  /* REAL_C  */
    ID = 301,                      /* ID  */
    STRING = 302,                  /* STRING  */
    UMINUS = 303                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define AND 266
#define OR 267
#define NOT 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define PLUSPLUS 273
#define MINMIN 274
#define EQUAL 275
#define NOTEQUAL 276
#define ASSIGN 277
#define PLUS 278
#define MINUS 279
#define MULTIPLY 280
#define DIVIDE 281
#define MODULO 282
#define GREATEREQ 283
#define LESSEQ 284
#define GREATER 285
#define LESS 286
#define LEFT_PAR 287
#define RIGHT_PAR 288
#define LEFT_BR 289
#define RIGHT_BR 290
#define LEFT_SQ 291
#define RIGHT_SQ 292
#define DOUBLE_DOT 293
#define DOT 294
#define D_SCOPE 295
#define SCOPE 296
#define SEMICOLON 297
#define COMMA 298
#define INTEGER_C 299
#define REAL_C 300
#define ID 301
#define STRING 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "ph2.y"
 
	int intVal; 
	char* strVal; 
	float fltVal;
	struct Entry* exprNode;
	

#line 171 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
