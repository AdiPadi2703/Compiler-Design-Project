#ifndef YY_PARSE_h_included
#define YY_PARSE_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_PARSE_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_PARSE_COMPATIBILITY 1
 #else
  #define  YY_PARSE_COMPATIBILITY 0
 #endif
#endif

#if YY_PARSE_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_PARSE_LTYPE
   #define YY_PARSE_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_PARSE_STYPE
   #define YY_PARSE_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_PARSE_DEBUG
   #define  YY_PARSE_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_PARSE_USE_GOTO
  #define YY_PARSE_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_PARSE_USE_GOTO
 #define YY_PARSE_USE_GOTO 0
#endif

#ifndef YY_PARSE_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_PARSE_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#ifndef YY_USE_CLASS
# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
#endif

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_PARSE_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_PARSE_DEBUG */
#endif

#ifndef YY_PARSE_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_PARSE_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_PARSE_LSP_NEEDED
 #ifndef YY_PARSE_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_PARSE_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_PARSE_STYPE
 #define YY_PARSE_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_PARSE_PARSE
 #define YY_PARSE_PARSE yyparse
#endif

#ifndef YY_PARSE_LEX
 #define YY_PARSE_LEX yylex
#endif

#ifndef YY_PARSE_LVAL
 #define YY_PARSE_LVAL yylval
#endif

#ifndef YY_PARSE_LLOC
 #define YY_PARSE_LLOC yylloc
#endif

#ifndef YY_PARSE_CHAR
 #define YY_PARSE_CHAR yychar
#endif

#ifndef YY_PARSE_NERRS
 #define YY_PARSE_NERRS yynerrs
#endif

#ifndef YY_PARSE_DEBUG_FLAG
 #define YY_PARSE_DEBUG_FLAG yydebug
#endif

#ifndef YY_PARSE_ERROR
 #define YY_PARSE_ERROR yyerror
#endif

#ifndef YY_PARSE_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_PARSE_PARSE_PARAM
    #ifndef YY_PARSE_PARSE_PARAM_DEF
     #define YY_PARSE_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_PARSE_PARSE_PARAM
  #define YY_PARSE_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_PARSE_PURE
  #ifndef yylval
   extern YY_PARSE_STYPE YY_PARSE_LVAL;
  #else
   #if yylval != YY_PARSE_LVAL
    extern YY_PARSE_STYPE YY_PARSE_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	IF	258
#define	INT	259
#define	CHAR	260
#define	FLOAT	261
#define	DOUBLE	262
#define	LONG	263
#define	SHORT	264
#define	SIGNED	265
#define	UNSIGNED	266
#define	STRUCT	267
#define	RETURN	268
#define	MAIN	269
#define	VOID	270
#define	WHILE	271
#define	FOR	272
#define	DO	273
#define	BREAK	274
#define	CONTINUE	275
#define	GOTO	276
#define	ENDIF	277
#define	SWITCH	278
#define	CASE	279
#define	DEFAULT	280
#define	identifier	281
#define	array_identifier	282
#define	integer_constant	283
#define	string_constant	284
#define	float_constant	285
#define	character_constant	286
#define	ELSE	287
#define	MOD_EQUAL	288
#define	MULTIPLY_EQUAL	289
#define	DIVIDE_EQUAL	290
#define	ADD_EQUAL	291
#define	SUBTRACT_EQUAL	292
#define	OR_OR	293
#define	AND_AND	294
#define	EQUAL	295
#define	NOT_EQUAL	296
#define	LESS_EQUAL	297
#define	LESS	298
#define	GREAT_EQUAL	299
#define	GREAT	300
#define	SIZEOF	301
#define	NOT	302
#define	INCREMENT	303
#define	DECREMENT	304


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_PARSE_CLASS
  #define YY_PARSE_CLASS PARSE
 #endif

 #ifndef YY_PARSE_INHERIT
  #define YY_PARSE_INHERIT
 #endif

 #ifndef YY_PARSE_MEMBERS
  #define YY_PARSE_MEMBERS 
 #endif

 #ifndef YY_PARSE_LEX_BODY
  #define YY_PARSE_LEX_BODY  
 #endif

 #ifndef YY_PARSE_ERROR_BODY
  #define YY_PARSE_ERROR_BODY  
 #endif

 #ifndef YY_PARSE_CONSTRUCTOR_PARAM
  #define YY_PARSE_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_PARSE_USE_CONST_TOKEN
  #define YY_PARSE_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_PARSE_USE_CONST_TOKEN != 0
  #ifndef YY_PARSE_ENUM_TOKEN
   #define YY_PARSE_ENUM_TOKEN yy_PARSE_enum_token
  #endif
 #endif

class YY_PARSE_CLASS YY_PARSE_INHERIT
{
public: 
 #if YY_PARSE_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int IF;
static const int INT;
static const int CHAR;
static const int FLOAT;
static const int DOUBLE;
static const int LONG;
static const int SHORT;
static const int SIGNED;
static const int UNSIGNED;
static const int STRUCT;
static const int RETURN;
static const int MAIN;
static const int VOID;
static const int WHILE;
static const int FOR;
static const int DO;
static const int BREAK;
static const int CONTINUE;
static const int GOTO;
static const int ENDIF;
static const int SWITCH;
static const int CASE;
static const int DEFAULT;
static const int identifier;
static const int array_identifier;
static const int integer_constant;
static const int string_constant;
static const int float_constant;
static const int character_constant;
static const int ELSE;
static const int MOD_EQUAL;
static const int MULTIPLY_EQUAL;
static const int DIVIDE_EQUAL;
static const int ADD_EQUAL;
static const int SUBTRACT_EQUAL;
static const int OR_OR;
static const int AND_AND;
static const int EQUAL;
static const int NOT_EQUAL;
static const int LESS_EQUAL;
static const int LESS;
static const int GREAT_EQUAL;
static const int GREAT;
static const int SIZEOF;
static const int NOT;
static const int INCREMENT;
static const int DECREMENT;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_PARSE_ENUM_TOKEN { YY_PARSE_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,IF=258
	,INT=259
	,CHAR=260
	,FLOAT=261
	,DOUBLE=262
	,LONG=263
	,SHORT=264
	,SIGNED=265
	,UNSIGNED=266
	,STRUCT=267
	,RETURN=268
	,MAIN=269
	,VOID=270
	,WHILE=271
	,FOR=272
	,DO=273
	,BREAK=274
	,CONTINUE=275
	,GOTO=276
	,ENDIF=277
	,SWITCH=278
	,CASE=279
	,DEFAULT=280
	,identifier=281
	,array_identifier=282
	,integer_constant=283
	,string_constant=284
	,float_constant=285
	,character_constant=286
	,ELSE=287
	,MOD_EQUAL=288
	,MULTIPLY_EQUAL=289
	,DIVIDE_EQUAL=290
	,ADD_EQUAL=291
	,SUBTRACT_EQUAL=292
	,OR_OR=293
	,AND_AND=294
	,EQUAL=295
	,NOT_EQUAL=296
	,LESS_EQUAL=297
	,LESS=298
	,GREAT_EQUAL=299
	,GREAT=300
	,SIZEOF=301
	,NOT=302
	,INCREMENT=303
	,DECREMENT=304


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_PARSE_PARSE(YY_PARSE_PARSE_PARAM);
 virtual void YY_PARSE_ERROR(char *msg) YY_PARSE_ERROR_BODY;
 #ifdef YY_PARSE_PURE
  #ifdef YY_PARSE_LSP_NEEDED
   virtual int  YY_PARSE_LEX(YY_PARSE_STYPE *YY_PARSE_LVAL,YY_PARSE_LTYPE *YY_PARSE_LLOC) YY_PARSE_LEX_BODY;
  #else
   virtual int  YY_PARSE_LEX(YY_PARSE_STYPE *YY_PARSE_LVAL) YY_PARSE_LEX_BODY;
  #endif
 #else
  virtual int YY_PARSE_LEX() YY_PARSE_LEX_BODY;
  YY_PARSE_STYPE YY_PARSE_LVAL;
  #ifdef YY_PARSE_LSP_NEEDED
   YY_PARSE_LTYPE YY_PARSE_LLOC;
  #endif
  int YY_PARSE_NERRS;
  int YY_PARSE_CHAR;
 #endif
 #if YY_PARSE_DEBUG != 0
  public:
   int YY_PARSE_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_PARSE_CLASS(YY_PARSE_CONSTRUCTOR_PARAM);
public:
 YY_PARSE_MEMBERS 
};
/* other declare folow */
#endif


#if YY_PARSE_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_PARSE_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_PARSE_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_PARSE_DEBUG 
   #define YYDEBUG YY_PARSE_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
