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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 259,                     /* INT  */
    CHAR = 260,                    /* CHAR  */
    FLOAT = 261,                   /* FLOAT  */
    DOUBLE = 262,                  /* DOUBLE  */
    LONG = 263,                    /* LONG  */
    SHORT = 264,                   /* SHORT  */
    SIGNED = 265,                  /* SIGNED  */
    UNSIGNED = 266,                /* UNSIGNED  */
    STRUCT = 267,                  /* STRUCT  */
    RETURN = 268,                  /* RETURN  */
    MAIN = 269,                    /* MAIN  */
    VOID = 270,                    /* VOID  */
    WHILE = 271,                   /* WHILE  */
    FOR = 272,                     /* FOR  */
    DO = 273,                      /* DO  */
    BREAK = 274,                   /* BREAK  */
    CONTINUE = 275,                /* CONTINUE  */
    GOTO = 276,                    /* GOTO  */
    ENDIF = 277,                   /* ENDIF  */
    SWITCH = 278,                  /* SWITCH  */
    CASE = 279,                    /* CASE  */
    DEFAULT = 280,                 /* DEFAULT  */
    identifier = 281,              /* identifier  */
    array_identifier = 282,        /* array_identifier  */
    integer_constant = 283,        /* integer_constant  */
    string_constant = 284,         /* string_constant  */
    float_constant = 285,          /* float_constant  */
    character_constant = 286,      /* character_constant  */
    ELSE = 287,                    /* ELSE  */
    MOD_EQUAL = 288,               /* MOD_EQUAL  */
    MULTIPLY_EQUAL = 289,          /* MULTIPLY_EQUAL  */
    DIVIDE_EQUAL = 290,            /* DIVIDE_EQUAL  */
    ADD_EQUAL = 291,               /* ADD_EQUAL  */
    SUBTRACT_EQUAL = 292,          /* SUBTRACT_EQUAL  */
    OR_OR = 293,                   /* OR_OR  */
    AND_AND = 294,                 /* AND_AND  */
    EQUAL = 295,                   /* EQUAL  */
    NOT_EQUAL = 296,               /* NOT_EQUAL  */
    LESS_EQUAL = 297,              /* LESS_EQUAL  */
    LESS = 298,                    /* LESS  */
    GREAT_EQUAL = 299,             /* GREAT_EQUAL  */
    GREAT = 300,                   /* GREAT  */
    SIZEOF = 301,                  /* SIZEOF  */
    NOT = 302,                     /* NOT  */
    INCREMENT = 303,               /* INCREMENT  */
    DECREMENT = 304                /* DECREMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define INT 259
#define CHAR 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define SHORT 264
#define SIGNED 265
#define UNSIGNED 266
#define STRUCT 267
#define RETURN 268
#define MAIN 269
#define VOID 270
#define WHILE 271
#define FOR 272
#define DO 273
#define BREAK 274
#define CONTINUE 275
#define GOTO 276
#define ENDIF 277
#define SWITCH 278
#define CASE 279
#define DEFAULT 280
#define identifier 281
#define array_identifier 282
#define integer_constant 283
#define string_constant 284
#define float_constant 285
#define character_constant 286
#define ELSE 287
#define MOD_EQUAL 288
#define MULTIPLY_EQUAL 289
#define DIVIDE_EQUAL 290
#define ADD_EQUAL 291
#define SUBTRACT_EQUAL 292
#define OR_OR 293
#define AND_AND 294
#define EQUAL 295
#define NOT_EQUAL 296
#define LESS_EQUAL 297
#define LESS 298
#define GREAT_EQUAL 299
#define GREAT 300
#define SIZEOF 301
#define NOT 302
#define INCREMENT 303
#define DECREMENT 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
