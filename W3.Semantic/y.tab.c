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
#line 1 "parser.y"

	void yyerror(char* s);
	int yylex();
	#include "stdio.h"
	#include "stdlib.h"
	#include "ctype.h"
	#include "string.h"
	void insert_type();
	void insert_value();
	void insert_dimensions();
	void insert_parameters();
	void remove_scope (int );
	int check_scope(char*);
	int check_function(char *);
	void insert_SymbolTable_nest(char*, int);
	void insert_SymbolTable_paramscount(char*, int);
	int getSTparamscount(char*);
	int check_duplicate(char*);
	int check_declaration(char*, char *);
	int check_params(char*);
	int duplicate(char *s);
	int check_array(char*);
	void insert_SymbolTable_function(char*);
	char gettype(char*,int);

	struct ErrorTableNode {

		int line_number;
		char *error_message;
		struct ErrorTableNode *next;

	};
	typedef struct ErrorTableNode ErrorTableNode;

	ErrorTableNode *error_table[1];

	extern void print_error_table();
	extern void insert_error_table(int line_number, char *error_message);
	extern void init_error_table();

	int insert_flag = 0;

	extern char current_identifier[20];
	extern char current_type[20];
	extern char current_value[20];
    extern char current_function[20];
	extern char previous_operator[20];
	extern int current_nested_val;
	char currfunctype[100];
	char currfunccall[100];
	extern int params_count;
	int call_params_count;


#line 126 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_DOUBLE = 7,                     /* DOUBLE  */
  YYSYMBOL_LONG = 8,                       /* LONG  */
  YYSYMBOL_SHORT = 9,                      /* SHORT  */
  YYSYMBOL_SIGNED = 10,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 11,                  /* UNSIGNED  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_BREAK = 19,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_GOTO = 21,                      /* GOTO  */
  YYSYMBOL_ENDIF = 22,                     /* ENDIF  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_identifier = 26,                /* identifier  */
  YYSYMBOL_array_identifier = 27,          /* array_identifier  */
  YYSYMBOL_integer_constant = 28,          /* integer_constant  */
  YYSYMBOL_string_constant = 29,           /* string_constant  */
  YYSYMBOL_float_constant = 30,            /* float_constant  */
  YYSYMBOL_character_constant = 31,        /* character_constant  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_MOD_EQUAL = 33,                 /* MOD_EQUAL  */
  YYSYMBOL_MULTIPLY_EQUAL = 34,            /* MULTIPLY_EQUAL  */
  YYSYMBOL_DIVIDE_EQUAL = 35,              /* DIVIDE_EQUAL  */
  YYSYMBOL_ADD_EQUAL = 36,                 /* ADD_EQUAL  */
  YYSYMBOL_SUBTRACT_EQUAL = 37,            /* SUBTRACT_EQUAL  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_OR_OR = 39,                     /* OR_OR  */
  YYSYMBOL_AND_AND = 40,                   /* AND_AND  */
  YYSYMBOL_41_ = 41,                       /* '^'  */
  YYSYMBOL_EQUAL = 42,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 43,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 44,                /* LESS_EQUAL  */
  YYSYMBOL_LESS = 45,                      /* LESS  */
  YYSYMBOL_GREAT_EQUAL = 46,               /* GREAT_EQUAL  */
  YYSYMBOL_GREAT = 47,                     /* GREAT  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '*'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_SIZEOF = 53,                    /* SIZEOF  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_INCREMENT = 55,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 56,                 /* DECREMENT  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* ','  */
  YYSYMBOL_61_ = 61,                       /* '['  */
  YYSYMBOL_62_ = 62,                       /* ']'  */
  YYSYMBOL_63_ = 63,                       /* '('  */
  YYSYMBOL_64_ = 64,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_begin_parse = 66,               /* begin_parse  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_structure_dec = 69,             /* structure_dec  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_structure_content = 71,         /* structure_content  */
  YYSYMBOL_variable_dec = 72,              /* variable_dec  */
  YYSYMBOL_structure_initialize = 73,      /* structure_initialize  */
  YYSYMBOL_variables = 74,                 /* variables  */
  YYSYMBOL_multiple_variables = 75,        /* multiple_variables  */
  YYSYMBOL_identifier_name = 76,           /* identifier_name  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_extended_identifier = 79,       /* extended_identifier  */
  YYSYMBOL_80_4 = 80,                      /* $@4  */
  YYSYMBOL_array_iden = 81,                /* array_iden  */
  YYSYMBOL_array_dims = 82,                /* array_dims  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_initilization = 84,             /* initilization  */
  YYSYMBOL_string_initilization = 85,      /* string_initilization  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_array_initialization = 87,      /* array_initialization  */
  YYSYMBOL_88_7 = 88,                      /* $@7  */
  YYSYMBOL_array_values = 89,              /* array_values  */
  YYSYMBOL_multiple_array_values = 90,     /* multiple_array_values  */
  YYSYMBOL_datatype = 91,                  /* datatype  */
  YYSYMBOL_unsigned_grammar = 92,          /* unsigned_grammar  */
  YYSYMBOL_signed_grammar = 93,            /* signed_grammar  */
  YYSYMBOL_long_grammar = 94,              /* long_grammar  */
  YYSYMBOL_short_grammar = 95,             /* short_grammar  */
  YYSYMBOL_function_dec = 96,              /* function_dec  */
  YYSYMBOL_function_datatype = 97,         /* function_datatype  */
  YYSYMBOL_function_parameters = 98,       /* function_parameters  */
  YYSYMBOL_parameters = 99,                /* parameters  */
  YYSYMBOL_100_8 = 100,                    /* $@8  */
  YYSYMBOL_all_parameter_identifiers = 101, /* all_parameter_identifiers  */
  YYSYMBOL_multiple_parameters = 102,      /* multiple_parameters  */
  YYSYMBOL_parameter_identifier = 103,     /* parameter_identifier  */
  YYSYMBOL_104_9 = 104,                    /* $@9  */
  YYSYMBOL_extended_parameter = 105,       /* extended_parameter  */
  YYSYMBOL_statement = 106,                /* statement  */
  YYSYMBOL_multiple_statement = 107,       /* multiple_statement  */
  YYSYMBOL_108_10 = 108,                   /* $@10  */
  YYSYMBOL_statments = 109,                /* statments  */
  YYSYMBOL_expression_statment = 110,      /* expression_statment  */
  YYSYMBOL_conditional_statements = 111,   /* conditional_statements  */
  YYSYMBOL_112_11 = 112,                   /* $@11  */
  YYSYMBOL_extended_conditional_statements = 113, /* extended_conditional_statements  */
  YYSYMBOL_iterative_statements = 114,     /* iterative_statements  */
  YYSYMBOL_115_12 = 115,                   /* $@12  */
  YYSYMBOL_116_13 = 116,                   /* $@13  */
  YYSYMBOL_117_14 = 117,                   /* $@14  */
  YYSYMBOL_for_initialization = 118,       /* for_initialization  */
  YYSYMBOL_return_statement = 119,         /* return_statement  */
  YYSYMBOL_break_statement = 120,          /* break_statement  */
  YYSYMBOL_expression = 121,               /* expression  */
  YYSYMBOL_simple_expression = 122,        /* simple_expression  */
  YYSYMBOL_and_expression = 123,           /* and_expression  */
  YYSYMBOL_unary_relation_expression = 124, /* unary_relation_expression  */
  YYSYMBOL_regular_expression = 125,       /* regular_expression  */
  YYSYMBOL_relational_operators = 126,     /* relational_operators  */
  YYSYMBOL_sum_expression = 127,           /* sum_expression  */
  YYSYMBOL_sum_operators = 128,            /* sum_operators  */
  YYSYMBOL_term = 129,                     /* term  */
  YYSYMBOL_MULOP = 130,                    /* MULOP  */
  YYSYMBOL_factor = 131,                   /* factor  */
  YYSYMBOL_mutable = 132,                  /* mutable  */
  YYSYMBOL_133_15 = 133,                   /* $@15  */
  YYSYMBOL_immutable = 134,                /* immutable  */
  YYSYMBOL_call = 135,                     /* call  */
  YYSYMBOL_136_16 = 136,                   /* $@16  */
  YYSYMBOL_arguments = 137,                /* arguments  */
  YYSYMBOL_arguments_list = 138,           /* arguments_list  */
  YYSYMBOL_139_17 = 139,                   /* $@17  */
  YYSYMBOL_A = 140,                        /* A  */
  YYSYMBOL_141_18 = 141,                   /* $@18  */
  YYSYMBOL_constant = 142                  /* constant  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      63,    64,    50,    48,    60,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    39,    40,    42,    43,    44,    45,    46,
      47,    53,    54,    55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    95,    96,   100,   101,   102,   103,   106,
     106,   108,   108,   111,   112,   115,   118,   121,   122,   125,
     125,   128,   128,   130,   130,   130,   133,   134,   137,   137,
     138,   141,   142,   143,   146,   146,   149,   149,   152,   155,
     156,   160,   160,   160,   160,   161,   162,   163,   164,   165,
     168,   168,   168,   168,   171,   171,   171,   171,   174,   174,
     177,   177,   180,   183,   186,   189,   189,   189,   192,   195,
     196,   199,   199,   202,   203,   206,   206,   207,   207,   208,
     208,   209,   212,   212,   215,   216,   219,   220,   223,   223,
     226,   227,   230,   230,   231,   231,   232,   232,   235,   236,
     237,   240,   241,   254,   258,   266,   272,   279,   285,   291,
     298,   299,   300,   305,   306,   309,   310,   313,   314,   317,
     318,   321,   322,   323,   324,   325,   326,   329,   330,   333,
     334,   337,   338,   341,   341,   341,   344,   345,   348,   358,
     358,   366,   367,   368,   371,   371,   388,   388,   391,   391,
     394,   394,   395,   398,   399,   400,   401
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "INT", "CHAR",
  "FLOAT", "DOUBLE", "LONG", "SHORT", "SIGNED", "UNSIGNED", "STRUCT",
  "RETURN", "MAIN", "VOID", "WHILE", "FOR", "DO", "BREAK", "CONTINUE",
  "GOTO", "ENDIF", "SWITCH", "CASE", "DEFAULT", "identifier",
  "array_identifier", "integer_constant", "string_constant",
  "float_constant", "character_constant", "ELSE", "MOD_EQUAL",
  "MULTIPLY_EQUAL", "DIVIDE_EQUAL", "ADD_EQUAL", "SUBTRACT_EQUAL", "'='",
  "OR_OR", "AND_AND", "'^'", "EQUAL", "NOT_EQUAL", "LESS_EQUAL", "LESS",
  "GREAT_EQUAL", "GREAT", "'+'", "'-'", "'*'", "'/'", "'%'", "SIZEOF",
  "NOT", "INCREMENT", "DECREMENT", "'{'", "'}'", "';'", "','", "'['",
  "']'", "'('", "')'", "$accept", "begin_parse", "declarations",
  "declaration", "structure_dec", "$@1", "structure_content",
  "variable_dec", "structure_initialize", "variables",
  "multiple_variables", "identifier_name", "$@2", "$@3",
  "extended_identifier", "$@4", "array_iden", "array_dims", "$@5",
  "initilization", "string_initilization", "$@6", "array_initialization",
  "$@7", "array_values", "multiple_array_values", "datatype",
  "unsigned_grammar", "signed_grammar", "long_grammar", "short_grammar",
  "function_dec", "function_datatype", "function_parameters", "parameters",
  "$@8", "all_parameter_identifiers", "multiple_parameters",
  "parameter_identifier", "$@9", "extended_parameter", "statement",
  "multiple_statement", "$@10", "statments", "expression_statment",
  "conditional_statements", "$@11", "extended_conditional_statements",
  "iterative_statements", "$@12", "$@13", "$@14", "for_initialization",
  "return_statement", "break_statement", "expression", "simple_expression",
  "and_expression", "unary_relation_expression", "regular_expression",
  "relational_operators", "sum_expression", "sum_operators", "term",
  "MULOP", "factor", "mutable", "$@15", "immutable", "call", "$@16",
  "arguments", "arguments_list", "$@17", "A", "$@18", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     162,  -107,  -107,  -107,  -107,  -107,    23,    34,    57,    65,
      30,  -107,    58,  -107,   162,  -107,  -107,  -107,    -5,  -107,
     268,  -107,  -107,  -107,  -107,  -107,    23,    34,  -107,  -107,
      23,    34,  -107,    24,  -107,  -107,     8,  -107,    21,    28,
    -107,  -107,    27,  -107,  -107,  -107,  -107,  -107,    41,  -107,
    -107,   -21,   -21,  -107,    24,  -107,    73,   190,   256,  -107,
     -14,  -107,  -107,  -107,  -107,  -107,  -107,    49,    53,    92,
      16,    61,    62,   190,    69,    63,  -107,  -107,  -107,  -107,
    -107,    66,  -107,    66,  -107,    24,  -107,  -107,    70,  -107,
    -107,  -107,  -107,  -107,    71,   104,    91,  -107,    68,    29,
     -40,  -107,    67,  -107,  -107,  -107,    95,   256,    66,  -107,
     111,  -107,   100,   268,  -107,    66,    24,  -107,   105,    66,
     228,   159,  -107,  -107,   115,  -107,  -107,   114,   129,  -107,
      66,    66,  -107,  -107,  -107,  -107,  -107,  -107,     5,  -107,
    -107,     5,  -107,  -107,  -107,     5,    66,    66,    66,    66,
      66,    66,  -107,  -107,   120,  -107,   104,   118,  -107,  -107,
     119,  -107,  -107,   -15,  -107,   -10,  -107,  -107,    66,   123,
     121,    66,    66,  -107,   129,   127,    91,  -107,    29,   -40,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   148,   160,
    -107,  -107,  -107,   -31,  -107,    66,  -107,   126,  -107,   142,
    -107,  -107,   134,  -107,  -107,  -107,  -107,   190,   190,  -107,
       0,   150,  -107,  -107,   154,   180,  -107,    66,  -107,    66,
    -107,   185,   190,  -107,   151,   155,  -107,   163,   164,  -107,
    -107,  -107,   150,   185,  -107,  -107,  -107,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,    41,    42,    43,    44,    59,    61,    57,    53,
       0,    49,     0,     2,     0,     7,     5,    14,     0,     6,
      67,    58,    45,    60,    46,    54,    59,    61,    48,    50,
      59,    61,    47,     9,     1,     3,    19,    21,     0,    18,
      65,    62,     0,    55,    56,    51,    52,    19,     0,    15,
      63,    27,    27,    13,     0,    16,     0,    82,    12,    24,
       0,    20,    23,    22,    17,    71,    66,    70,     0,     0,
       0,     0,     0,    82,     0,   138,   139,   153,   154,   155,
     156,     0,    87,     0,    81,     0,    64,    76,     0,    75,
      77,    78,    79,    80,     0,   112,   114,   116,   118,   120,
     128,   132,   137,   136,   142,   143,     0,    12,     0,    28,
       0,    26,    74,    67,    68,     0,     0,   101,     0,     0,
       0,     0,   103,   144,     0,   117,   137,     0,    82,    86,
       0,     0,   125,   126,   122,   124,   121,   123,     0,   129,
     130,     0,   133,   134,   135,     0,     0,     0,     0,     0,
       0,     0,   110,   111,     0,    11,    25,     0,    34,    30,
       0,    72,    69,     0,   102,     0,   100,    98,     0,     0,
       0,   147,     0,   141,    82,     0,   113,   115,   119,   127,
     131,   109,   107,   108,   105,   106,   104,    10,    33,     0,
      73,    88,    92,     0,    99,     0,   148,     0,   146,     0,
      84,    83,    34,    29,    31,    32,    35,    82,    82,    94,
       0,   152,   145,   140,     0,    91,    93,     0,    96,     0,
     149,     0,    82,    89,     0,     0,   150,    40,     0,    90,
      95,    97,   152,     0,    38,    37,   151,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,   210,  -107,  -107,  -107,   122,     1,  -107,   -29,
    -107,  -107,  -107,  -107,   173,  -107,  -107,  -107,  -107,  -107,
      38,  -107,  -107,  -107,    -6,  -107,     6,  -107,  -107,    -7,
      45,  -107,  -107,  -107,   117,  -107,  -107,  -107,  -107,  -107,
    -107,   -57,  -107,  -107,    54,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   -65,  -106,   101,   -74,
    -107,  -107,   103,  -107,   106,  -107,    97,   -78,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,    13,  -107,  -107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    48,   106,    84,    17,    38,
      55,    39,    51,    52,    61,   108,    62,   111,   157,   203,
     159,   189,   205,   214,   228,   234,    85,    32,    28,    22,
      24,    19,    20,    41,    42,    56,    66,   114,    67,   112,
     161,   174,    87,    88,   175,    89,    90,   207,   223,    91,
     208,   217,   225,   168,    92,    93,    94,    95,    96,    97,
      98,   138,    99,   141,   100,   145,   101,   102,   124,   103,
     104,   171,   197,   198,   211,   220,   232,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,    16,   156,   126,    49,   118,    18,   125,   130,   163,
     142,   143,   144,   165,   109,    16,   121,    59,   127,    43,
      18,    36,    37,    45,   130,    64,    40,    21,   209,   130,
     126,    75,    76,    77,    78,    79,    80,   126,    23,   130,
      60,   126,    75,    76,    77,    78,    79,    80,   110,   191,
      47,    37,   126,   126,   192,   169,    33,   177,    34,   107,
     126,    25,   193,   126,   218,    26,    27,   126,    83,    29,
      81,    50,    44,    30,    31,   117,    46,   139,   140,    83,
      53,   181,   182,   183,   184,   185,   186,    49,    54,   210,
     126,    57,    75,    76,    77,    78,    79,    80,    58,    65,
     146,   147,   148,   149,   150,   151,   196,   199,   107,   113,
     132,   133,   134,   135,   136,   137,   115,   126,   116,    40,
      81,   167,   152,   153,   119,   120,   123,   128,   122,    83,
     129,   131,    68,     2,     3,     4,     5,     6,     7,     8,
       9,    69,    70,   130,    11,    71,    72,    73,    74,   158,
     215,   216,   224,   154,   226,    75,    76,    77,    78,    79,
      80,   160,    -4,     1,   164,   229,     2,     3,     4,     5,
       6,     7,     8,     9,    10,   170,   172,    11,   173,   187,
     188,   190,   194,    81,   195,   201,   202,   -85,    82,   206,
     212,   -36,    83,    68,     2,     3,     4,     5,     6,     7,
       8,     9,    69,    70,   213,    11,    71,    72,    73,    74,
     219,   221,   222,   227,   231,   230,    75,    76,    77,    78,
      79,    80,   235,   233,    35,    63,   204,   237,   200,   155,
     162,   176,     2,     3,     4,     5,     6,     7,     8,     9,
      69,   178,   180,    11,    81,   236,     0,   179,     0,    82,
       0,     0,     0,    83,    75,    76,    77,    78,    79,    80,
       2,     3,     4,     5,     6,     7,     8,     9,    69,     0,
       0,    11,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,    81,    11,     0,     0,     0,   166,     0,     0,
       0,    83
};

static const yytype_int16 yycheck[] =
{
      57,     0,   108,    81,    33,    70,     0,    81,    39,   115,
      50,    51,    52,   119,    28,    14,    73,    38,    83,    26,
      14,    26,    27,    30,    39,    54,    20,     4,    59,    39,
     108,    26,    27,    28,    29,    30,    31,   115,     4,    39,
      61,   119,    26,    27,    28,    29,    30,    31,    62,    64,
      26,    27,   130,   131,    64,   120,    26,   131,     0,    58,
     138,     4,   168,   141,    64,     8,     9,   145,    63,     4,
      54,    63,    27,     8,     9,    59,    31,    48,    49,    63,
      59,   146,   147,   148,   149,   150,   151,   116,    60,   195,
     168,    64,    26,    27,    28,    29,    30,    31,    57,    26,
      33,    34,    35,    36,    37,    38,   171,   172,   107,    60,
      42,    43,    44,    45,    46,    47,    63,   195,    26,   113,
      54,   120,    55,    56,    63,    63,    63,    57,    59,    63,
      59,    40,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    39,    15,    16,    17,    18,    19,    38,
     207,   208,   217,    58,   219,    26,    27,    28,    29,    30,
      31,    61,     0,     1,    59,   222,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    16,    61,    15,    64,    59,
      62,    62,    59,    54,    63,    58,    38,    58,    59,    29,
      64,    57,    63,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    62,    15,    16,    17,    18,    19,
      60,    57,    32,    28,    59,    64,    26,    27,    28,    29,
      30,    31,    58,    60,    14,    52,   188,   233,   174,   107,
     113,   130,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   138,   145,    15,    54,   232,    -1,   141,    -1,    59,
      -1,    -1,    -1,    63,    26,    27,    28,    29,    30,    31,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    54,    15,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    15,    66,    67,    68,    69,    72,    73,    91,    96,
      97,     4,    94,     4,    95,     4,     8,     9,    93,     4,
       8,     9,    92,    26,     0,    67,    26,    27,    74,    76,
      91,    98,    99,    94,    95,    94,    95,    26,    70,    74,
      63,    77,    78,    59,    60,    75,   100,    64,    57,    38,
      61,    79,    81,    79,    74,    26,   101,   103,     3,    12,
      13,    16,    17,    18,    19,    26,    27,    28,    29,    30,
      31,    54,    59,    63,    72,    91,   106,   107,   108,   110,
     111,   114,   119,   120,   121,   122,   123,   124,   125,   127,
     129,   131,   132,   134,   135,   142,    71,    72,    80,    28,
      62,    82,   104,    60,   102,    63,    26,    59,   121,    63,
      63,   106,    59,    63,   133,   124,   132,   121,    57,    59,
      39,    40,    42,    43,    44,    45,    46,    47,   126,    48,
      49,   128,    50,    51,    52,   130,    33,    34,    35,    36,
      37,    38,    55,    56,    58,    71,   122,    83,    38,    85,
      61,   105,    99,   122,    59,   122,    59,    72,   118,   121,
      16,   136,    61,    64,   106,   109,   123,   124,   127,   129,
     131,   121,   121,   121,   121,   121,   121,    59,    62,    86,
      62,    64,    64,   122,    59,    63,   121,   137,   138,   121,
     109,    58,    38,    84,    85,    87,    29,   112,   115,    59,
     122,   139,    64,    62,    88,   106,   106,   116,    64,    60,
     140,    57,    32,   113,   121,   117,   121,    28,    89,   106,
      64,    59,   141,    60,    90,    58,   140,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    68,    70,
      69,    71,    71,    72,    72,    73,    74,    75,    75,    77,
      76,    78,    76,    79,    80,    79,    81,    81,    83,    82,
      82,    84,    84,    84,    86,    85,    88,    87,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    97,    98,   100,    99,    99,   101,   102,
     102,   104,   103,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   108,   107,   109,   109,   110,   110,   112,   111,
     113,   113,   115,   114,   116,   114,   117,   114,   118,   118,
     118,   119,   119,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   132,   133,
     132,   134,   134,   134,   136,   135,   137,   137,   139,   138,
     141,   140,   140,   142,   142,   142,   142
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     0,
       7,     2,     0,     3,     1,     3,     2,     2,     0,     0,
       3,     0,     3,     1,     0,     3,     2,     0,     0,     4,
       2,     1,     1,     0,     0,     3,     0,     5,     2,     2,
       0,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     2,     0,     1,     2,     2,     0,     1,     0,
       1,     0,     2,     3,     3,     0,     3,     0,     2,     2,
       0,     0,     3,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     2,     0,     2,     1,     0,     7,
       2,     0,     0,     6,     0,     8,     0,     8,     1,     2,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     0,     5,     1,     0,     0,     3,
       0,     4,     0,     1,     1,     1,     1
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
  case 9: /* $@1: %empty  */
#line 106 "parser.y"
                                            { insert_type(); }
#line 1597 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 125 "parser.y"
                                     { if(check_function(current_identifier))
						  {yyerror("ERROR: Identifier cannot be same as function name!"); }
						  if(duplicate(current_identifier)){yyerror("Duplicate value!");}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type(); }
#line 1605 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 128 "parser.y"
                                           {if(duplicate(current_identifier)){yyerror("Duplicate value!");}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type();  }
#line 1611 "y.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 130 "parser.y"
                                      {strcpy(previous_operator,"=");}
#line 1617 "y.tab.c"
    break;

  case 28: /* $@5: %empty  */
#line 137 "parser.y"
                                           {insert_dimensions();}
#line 1623 "y.tab.c"
    break;

  case 29: /* array_dims: integer_constant $@5 ']' initilization  */
#line 137 "parser.y"
                                                                                   {if(yyval < 1) {yyerror("Array must have size greater than 1!"); } }
#line 1629 "y.tab.c"
    break;

  case 34: /* $@6: %empty  */
#line 146 "parser.y"
                             {strcpy(previous_operator,"=");}
#line 1635 "y.tab.c"
    break;

  case 35: /* string_initilization: '=' $@6 string_constant  */
#line 146 "parser.y"
                                                                              { insert_value(); }
#line 1641 "y.tab.c"
    break;

  case 36: /* $@7: %empty  */
#line 149 "parser.y"
                             {strcpy(previous_operator,"=");}
#line 1647 "y.tab.c"
    break;

  case 63: /* function_datatype: datatype identifier '('  */
#line 183 "parser.y"
                                                   {strcpy(currfunctype, current_type); check_duplicate(current_identifier); insert_SymbolTable_function(current_identifier);  strcpy(current_function,current_identifier); insert_type();}
#line 1653 "y.tab.c"
    break;

  case 65: /* $@8: %empty  */
#line 189 "parser.y"
                                   { check_params(current_type); }
#line 1659 "y.tab.c"
    break;

  case 66: /* parameters: datatype $@8 all_parameter_identifiers  */
#line 189 "parser.y"
                                                                                             {insert_SymbolTable_paramscount(current_function, params_count);}
#line 1665 "y.tab.c"
    break;

  case 71: /* $@9: %empty  */
#line 199 "parser.y"
                                     {insert_parameters(); insert_type(); insert_SymbolTable_nest(current_identifier,1); params_count++;}
#line 1671 "y.tab.c"
    break;

  case 82: /* $@10: %empty  */
#line 212 "parser.y"
                         {current_nested_val++;}
#line 1677 "y.tab.c"
    break;

  case 83: /* multiple_statement: $@10 '{' statments '}'  */
#line 212 "parser.y"
                                                                   {remove_scope(current_nested_val);current_nested_val--;}
#line 1683 "y.tab.c"
    break;

  case 88: /* $@11: %empty  */
#line 223 "parser.y"
                                                       {if(yyvsp[-1]!=1){yyerror("ERROR: Here, condition must have integer value!");}}
#line 1689 "y.tab.c"
    break;

  case 92: /* $@12: %empty  */
#line 230 "parser.y"
                                                         {if(yyvsp[-1]!=1){yyerror("ERROR: Here, condition must have integer value!");}}
#line 1695 "y.tab.c"
    break;

  case 94: /* $@13: %empty  */
#line 231 "parser.y"
                                                                           {if(yyvsp[-1]!=1){yyerror("Here, condition must have integer value!");}}
#line 1701 "y.tab.c"
    break;

  case 96: /* $@14: %empty  */
#line 232 "parser.y"
                                                                       {if(yyvsp[-1]!=1){yyerror("ERROR: Here, condition must have integer value!");}}
#line 1707 "y.tab.c"
    break;

  case 101: /* return_statement: RETURN ';'  */
#line 240 "parser.y"
                                     {if(strcmp(currfunctype,"void")) {yyerror("ERROR: Cannot have void return for non-void function!"); }}
#line 1713 "y.tab.c"
    break;

  case 102: /* return_statement: RETURN expression ';'  */
#line 241 "parser.y"
                                                { 	if(!strcmp(currfunctype, "void"))
										{
											yyerror("Non-void return for void function!"); ;
										}

										if((currfunctype[0]=='i' || currfunctype[0]=='c') && yyvsp[-1]!=1)
										{
											yyerror("Expression doesn't match return type of function");;
										}

			                     	}
#line 1729 "y.tab.c"
    break;

  case 104: /* expression: mutable '=' expression  */
#line 258 "parser.y"
                                                              {					strcpy(previous_operator,"=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
																	  {
			                                                          yyval=1;
			                                                          }
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch"); }
			                                                       }
#line 1742 "y.tab.c"
    break;

  case 105: /* expression: mutable ADD_EQUAL expression  */
#line 266 "parser.y"
                                                           {					strcpy(previous_operator,"+=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
			                                                          yyval=1;
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch"); }
			                                                       }
#line 1753 "y.tab.c"
    break;

  case 106: /* expression: mutable SUBTRACT_EQUAL expression  */
#line 272 "parser.y"
                                                             {					strcpy(previous_operator,"-=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
			                                                          yyval=1;
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch"); }
			                                                       }
#line 1764 "y.tab.c"
    break;

  case 107: /* expression: mutable MULTIPLY_EQUAL expression  */
#line 279 "parser.y"
                                                            {					strcpy(previous_operator,"*=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
			                                                          yyval=1;
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch"); }
			                                                       }
#line 1775 "y.tab.c"
    break;

  case 108: /* expression: mutable DIVIDE_EQUAL expression  */
#line 285 "parser.y"
                                                                        {				strcpy(previous_operator,"/=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
			                                                          yyval=1;
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch");}
			                                                       }
#line 1786 "y.tab.c"
    break;

  case 109: /* expression: mutable MOD_EQUAL expression  */
#line 291 "parser.y"
                                                                {					strcpy(previous_operator,"%=");
																	  if(yyvsp[-2]==1 && yyvsp[0]==1)
			                                                          yyval=1;
			                                                          else
			                                                          {yyval=-1; yyerror("Type Mismatch"); }
			                                                       }
#line 1797 "y.tab.c"
    break;

  case 110: /* expression: mutable INCREMENT  */
#line 298 "parser.y"
                                                                                                {if(yyvsp[-1] == 1) yyval=1; else yyval=-1;}
#line 1803 "y.tab.c"
    break;

  case 111: /* expression: mutable DECREMENT  */
#line 299 "parser.y"
                                                                                                {if(yyvsp[-1] == 1) yyval=1; else yyval=-1;}
#line 1809 "y.tab.c"
    break;

  case 112: /* expression: simple_expression  */
#line 300 "parser.y"
                                            {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1815 "y.tab.c"
    break;

  case 113: /* simple_expression: simple_expression OR_OR and_expression  */
#line 305 "parser.y"
                                                                 {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1821 "y.tab.c"
    break;

  case 114: /* simple_expression: and_expression  */
#line 306 "parser.y"
                                         {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1827 "y.tab.c"
    break;

  case 115: /* and_expression: and_expression AND_AND unary_relation_expression  */
#line 309 "parser.y"
                                                                           {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1833 "y.tab.c"
    break;

  case 116: /* and_expression: unary_relation_expression  */
#line 310 "parser.y"
                                                     {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1839 "y.tab.c"
    break;

  case 117: /* unary_relation_expression: NOT unary_relation_expression  */
#line 313 "parser.y"
                                                        {if(yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1845 "y.tab.c"
    break;

  case 118: /* unary_relation_expression: regular_expression  */
#line 314 "parser.y"
                                             {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1851 "y.tab.c"
    break;

  case 119: /* regular_expression: regular_expression relational_operators sum_expression  */
#line 317 "parser.y"
                                                                                 {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1857 "y.tab.c"
    break;

  case 120: /* regular_expression: sum_expression  */
#line 318 "parser.y"
                                           {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1863 "y.tab.c"
    break;

  case 121: /* relational_operators: GREAT_EQUAL  */
#line 321 "parser.y"
                                     {strcpy(previous_operator,">=");}
#line 1869 "y.tab.c"
    break;

  case 122: /* relational_operators: LESS_EQUAL  */
#line 322 "parser.y"
                                    {strcpy(previous_operator,"<=");}
#line 1875 "y.tab.c"
    break;

  case 123: /* relational_operators: GREAT  */
#line 323 "parser.y"
                               {strcpy(previous_operator,">");}
#line 1881 "y.tab.c"
    break;

  case 124: /* relational_operators: LESS  */
#line 324 "parser.y"
                              {strcpy(previous_operator,"<");}
#line 1887 "y.tab.c"
    break;

  case 125: /* relational_operators: EQUAL  */
#line 325 "parser.y"
                               {strcpy(previous_operator,"==");}
#line 1893 "y.tab.c"
    break;

  case 126: /* relational_operators: NOT_EQUAL  */
#line 326 "parser.y"
                                   {strcpy(previous_operator,"!=");}
#line 1899 "y.tab.c"
    break;

  case 127: /* sum_expression: sum_expression sum_operators term  */
#line 329 "parser.y"
                                                             {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1905 "y.tab.c"
    break;

  case 128: /* sum_expression: term  */
#line 330 "parser.y"
                               {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1911 "y.tab.c"
    break;

  case 131: /* term: term MULOP factor  */
#line 337 "parser.y"
                                            {if(yyvsp[-2] == 1 && yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1917 "y.tab.c"
    break;

  case 132: /* term: factor  */
#line 338 "parser.y"
                                 {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1923 "y.tab.c"
    break;

  case 136: /* factor: immutable  */
#line 344 "parser.y"
                                    {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1929 "y.tab.c"
    break;

  case 137: /* factor: mutable  */
#line 345 "parser.y"
                                  {if(yyvsp[0] == 1) yyval=1; else yyval=-1;}
#line 1935 "y.tab.c"
    break;

  case 138: /* mutable: identifier  */
#line 348 "parser.y"
                                     {
			              if(!check_scope(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Identifier undeclared");}
			              if(!check_array(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Array Identifier has No Subscript");}
			              if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
			              yyval = 1;
			              else
			              yyval = -1;
			              }
#line 1950 "y.tab.c"
    break;

  case 139: /* $@15: %empty  */
#line 358 "parser.y"
                                           {if(!check_scope(current_identifier)){printf("%s\n",current_identifier);yyerror("Identifier undeclared");}}
#line 1956 "y.tab.c"
    break;

  case 140: /* mutable: array_identifier $@15 '[' expression ']'  */
#line 359 "parser.y"
                                           {if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
			              		yyval = 1;
			              		else
			              		yyval = -1;
			              		}
#line 1966 "y.tab.c"
    break;

  case 141: /* immutable: '(' expression ')'  */
#line 366 "parser.y"
                                             {if(yyvsp[-1]==1) yyval=1; else yyval=-1;}
#line 1972 "y.tab.c"
    break;

  case 143: /* immutable: constant  */
#line 368 "parser.y"
                                   {if(yyvsp[0]==1) yyval=1; else yyval=-1;}
#line 1978 "y.tab.c"
    break;

  case 144: /* $@16: %empty  */
#line 371 "parser.y"
                                        { strcpy(previous_operator,"(");
			             if(!check_declaration(current_identifier, "Function"))
			             { yyerror("Function not declared"); }
			             insert_SymbolTable_function(current_identifier);
						 strcpy(currfunccall,current_identifier);
			             }
#line 1989 "y.tab.c"
    break;

  case 145: /* call: identifier '(' $@16 arguments ')'  */
#line 377 "parser.y"
                                                 { if(strcmp(currfunccall,"printf"))
							{
								if(getSTparamscount(currfunccall)!=call_params_count)
								{
									yyerror("Number of parameters not same as number of arguments during function call!");
							
								}
							}
						 }
#line 2003 "y.tab.c"
    break;

  case 148: /* $@17: %empty  */
#line 391 "parser.y"
                                     { call_params_count++; }
#line 2009 "y.tab.c"
    break;

  case 150: /* $@18: %empty  */
#line 394 "parser.y"
                                         { call_params_count++; }
#line 2015 "y.tab.c"
    break;

  case 153: /* constant: integer_constant  */
#line 398 "parser.y"
                                                {  insert_type(); yyval=1; }
#line 2021 "y.tab.c"
    break;

  case 154: /* constant: string_constant  */
#line 399 "parser.y"
                                                {  insert_type(); yyval=-1;}
#line 2027 "y.tab.c"
    break;

  case 155: /* constant: float_constant  */
#line 400 "parser.y"
                                                {  insert_type(); }
#line 2033 "y.tab.c"
    break;

  case 156: /* constant: character_constant  */
#line 401 "parser.y"
                                            {  insert_type();yyval=1; }
#line 2039 "y.tab.c"
    break;


#line 2043 "y.tab.c"

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

#line 404 "parser.y"


extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insert_SymbolTable_type(char *,char *);
void insert_SymbolTable_value(char *, char *);
void insert_ConstantTable(char *, char *);
void insert_SymbolTable_arraydim(char *, char *);
void insert_SymbolTable_funcparam(char *, char *);
void printSymbolTable();
void printConstantTable();


int main()
{
	yyin = fopen("test2.c", "r");
	init_error_table();
	yyparse();

		printf("%30s SYMBOL TABLE \n", " ");
		printf("%30s %s\n", " ", "------------");
		printSymbolTable();

		printf("\n\n%30s CONSTANT TABLE \n", " ");
		printf("%30s %s\n", " ", "--------------");
		printConstantTable();

		printf("\n\n%30s ERROR TABLE \n", " ");
		printf("%30s %s\n", " ", "--------------");		
		print_error_table();
}

void yyerror(char *s)
{
	insert_error_table(yylineno, s);
}

void insert_type()
{
	insert_SymbolTable_type(current_identifier,current_type);
}

void insert_value()
{
	if(strcmp(previous_operator, "=") == 0)
	{	insert_SymbolTable_value(current_identifier,current_value);
	}
}

void insert_dimensions()
{
    insert_SymbolTable_arraydim(current_identifier, current_value);
}

void insert_parameters()
{
    insert_SymbolTable_funcparam(current_function, current_identifier);
}

int yywrap()
{
	return 1;
}
