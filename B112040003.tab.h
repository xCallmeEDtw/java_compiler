/* A Bison parser, made by GNU Bison 3.8.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_B112040003_TAB_H_INCLUDED
# define YY_YY_B112040003_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    Identifier = 258,              /* Identifier  */
    COMMENT = 259,                 /* COMMENT  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    BREAK = 261,                   /* BREAK  */
    BYTE = 262,                    /* BYTE  */
    CASE = 263,                    /* CASE  */
    CHAR = 264,                    /* CHAR  */
    CATCH = 265,                   /* CATCH  */
    CLASS = 266,                   /* CLASS  */
    CONST = 267,                   /* CONST  */
    CONTINUE = 268,                /* CONTINUE  */
    DEFAULT = 269,                 /* DEFAULT  */
    DO = 270,                      /* DO  */
    DOUBLE = 271,                  /* DOUBLE  */
    ELSE = 272,                    /* ELSE  */
    EXTENDS = 273,                 /* EXTENDS  */
    FALSE2 = 274,                  /* FALSE2  */
    FINAL = 275,                   /* FINAL  */
    FINALLY = 276,                 /* FINALLY  */
    FLOAT = 277,                   /* FLOAT  */
    FOR = 278,                     /* FOR  */
    IF = 279,                      /* IF  */
    IMPLEMENTS = 280,              /* IMPLEMENTS  */
    INT = 281,                     /* INT  */
    LONG = 282,                    /* LONG  */
    MAIN = 283,                    /* MAIN  */
    NEW = 284,                     /* NEW  */
    PRINT = 285,                   /* PRINT  */
    PRIVATE = 286,                 /* PRIVATE  */
    PROTECTED = 287,               /* PROTECTED  */
    PUBLIC = 288,                  /* PUBLIC  */
    RETURN = 289,                  /* RETURN  */
    SHORT = 290,                   /* SHORT  */
    STATIC = 291,                  /* STATIC  */
    STRING = 292,                  /* STRING  */
    SWITCH = 293,                  /* SWITCH  */
    THIS = 294,                    /* THIS  */
    TRUE2 = 295,                   /* TRUE2  */
    TRY = 296,                     /* TRY  */
    VOID = 297,                    /* VOID  */
    WHILE = 298,                   /* WHILE  */
    READ = 299,                    /* READ  */
    INTEGER = 300,                 /* INTEGER  */
    REAL = 301,                    /* REAL  */
    ID = 302,                      /* ID  */
    PPLUS = 303,                   /* PPLUS  */
    MMINUS = 304,                  /* MMINUS  */
    SEQUAL = 305,                  /* SEQUAL  */
    BEQUAL = 306,                  /* BEQUAL  */
    EQUAL = 307,                   /* EQUAL  */
    NEQUAL = 308,                  /* NEQUAL  */
    AND = 309,                     /* AND  */
    OR = 310,                      /* OR  */
    EMPTYLINE = 311                /* EMPTYLINE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "B112040003.y"

	char* s;
	char c;
	float d;
	int i;

#line 127 "B112040003.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_B112040003_TAB_H_INCLUDED  */
