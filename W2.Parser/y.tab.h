#ifndef YY_parse_h_included
#define YY_parse_h_included
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
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
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

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
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

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	AUTO	258
#define	CONST	259
#define	BREAK	260
#define	GOTO	261
#define	CONTINUE	262
#define	SWITCH	263
#define	CASE	264
#define	DO	265
#define	DEFAULT	266
#define	REGISTER	267
#define	STATIC	268
#define	WHILE	269
#define	VOLATILE	270
#define	EXTERN	271
#define	SHORT	272
#define	UNSIGNED	273
#define	SIGNED	274
#define	INT	275
#define	CHAR	276
#define	FLOAT	277
#define	VOID	278
#define	MAIN	279
#define	FOR	280
#define	RETURN	281
#define	SIZEOF	282
#define	STRUCT	283
#define	UNION	284
#define	IF	285
#define	ELSE	286
#define	INCLUDE	287
#define	DEFINE	288
#define	HEADERPATH	289
#define	IDENTIFIER	290
#define	UNMATCHEDSTRING	291
#define	OPENCURLY	292
#define	CLOSEDCURLY	293
#define	OPENPAREN	294
#define	CLOSEDPAREN	295
#define	OPENREC	296
#define	CLOSEDREC	297
#define	INT_LIT	298
#define	CHAR_LIT	299
#define	FLOAT_LIT	300
#define	COMMA	301
#define	SEMICOLON	302
#define	SINGLELINECOMMENT	303
#define	MULTILINECOMMENT	304
#define	UNMATCHEDCOMMENT	305
#define	UNMATCHEDCOMMENTCLOSED	306
#define	UNARY	307
#define	BINARY	308
#define	QTERTIARY	309
#define	CTERTIARY	310
#define	ASSIGN	311
#define	MINUS	312
#define	PRINTF	313
#define	SCANF	314
#define	RELOP	315


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int AUTO;
static const int CONST;
static const int BREAK;
static const int GOTO;
static const int CONTINUE;
static const int SWITCH;
static const int CASE;
static const int DO;
static const int DEFAULT;
static const int REGISTER;
static const int STATIC;
static const int WHILE;
static const int VOLATILE;
static const int EXTERN;
static const int SHORT;
static const int UNSIGNED;
static const int SIGNED;
static const int INT;
static const int CHAR;
static const int FLOAT;
static const int VOID;
static const int MAIN;
static const int FOR;
static const int RETURN;
static const int SIZEOF;
static const int STRUCT;
static const int UNION;
static const int IF;
static const int ELSE;
static const int INCLUDE;
static const int DEFINE;
static const int HEADERPATH;
static const int IDENTIFIER;
static const int UNMATCHEDSTRING;
static const int OPENCURLY;
static const int CLOSEDCURLY;
static const int OPENPAREN;
static const int CLOSEDPAREN;
static const int OPENREC;
static const int CLOSEDREC;
static const int INT_LIT;
static const int CHAR_LIT;
static const int FLOAT_LIT;
static const int COMMA;
static const int SEMICOLON;
static const int SINGLELINECOMMENT;
static const int MULTILINECOMMENT;
static const int UNMATCHEDCOMMENT;
static const int UNMATCHEDCOMMENTCLOSED;
static const int UNARY;
static const int BINARY;
static const int QTERTIARY;
static const int CTERTIARY;
static const int ASSIGN;
static const int MINUS;
static const int PRINTF;
static const int SCANF;
static const int RELOP;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,AUTO=258
	,CONST=259
	,BREAK=260
	,GOTO=261
	,CONTINUE=262
	,SWITCH=263
	,CASE=264
	,DO=265
	,DEFAULT=266
	,REGISTER=267
	,STATIC=268
	,WHILE=269
	,VOLATILE=270
	,EXTERN=271
	,SHORT=272
	,UNSIGNED=273
	,SIGNED=274
	,INT=275
	,CHAR=276
	,FLOAT=277
	,VOID=278
	,MAIN=279
	,FOR=280
	,RETURN=281
	,SIZEOF=282
	,STRUCT=283
	,UNION=284
	,IF=285
	,ELSE=286
	,INCLUDE=287
	,DEFINE=288
	,HEADERPATH=289
	,IDENTIFIER=290
	,UNMATCHEDSTRING=291
	,OPENCURLY=292
	,CLOSEDCURLY=293
	,OPENPAREN=294
	,CLOSEDPAREN=295
	,OPENREC=296
	,CLOSEDREC=297
	,INT_LIT=298
	,CHAR_LIT=299
	,FLOAT_LIT=300
	,COMMA=301
	,SEMICOLON=302
	,SINGLELINECOMMENT=303
	,MULTILINECOMMENT=304
	,UNMATCHEDCOMMENT=305
	,UNMATCHEDCOMMENTCLOSED=306
	,UNARY=307
	,BINARY=308
	,QTERTIARY=309
	,CTERTIARY=310
	,ASSIGN=311
	,MINUS=312
	,PRINTF=313
	,SCANF=314
	,RELOP=315


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
