%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%token AUTO CONST BREAK GOTO CONTINUE SWITCH CASE DO DEFAULT 
%token REGISTER STATIC WHILE VOLATILE EXTERN SHORT UNSIGNED SIGNED INT CHAR 
%token FLOAT VOID BOOL MAIN FOR RETURN SIZEOF STRUCT UNION TYPEDEF IF ELSE
%token INCLUDE DEFINE HEADERPATH IDENTIFIER 
%token UNMATCHEDSTRING OPENCURLY CLOSEDCURLY OPENPAREN CLOSEDPAREN OPENREC CLOSEDREC
%token INT_LIT CHAR_LIT FLOAT_LIT BOOL_LIT
%token COMMA SEMICOLON
%token SINGLELINECOMMENT MULTILINECOMMENT UNMATCHEDCOMMENT UNMATCHEDCOMMENTCLOSED
%token UNARY BINARY QTERTIARY CTERTIARY

%%

program: headers main '(' ')' '{' body return '}'
;

headers: headers headers
| INCLUDE
;

main: datatype ID
;

datatype: INT 
| FLOAT 
| CHAR
| VOID
;

body: FOR '(' statement ';' condition ';' statement ')' '{' body '}'
| IF '(' condition ')' '{' body '}' else
| statement ';' 
| body body
| PRINTFF '(' STR ')' ';'
| SCANFF '(' STR ',' '&' ID ')' ';'
;

else: ELSE '{' body '}'
|
;

condition: value relop value 
| TRUE 
| FALSE
;

statement: datatype ID init 
| ID '=' expression 
| ID relop expression
| ID UNARY 
| UNARY ID
;

init: '=' value 
|
;

expression: expression arithmetic expression
| value
;

arithmetic: ADD 
| SUBTRACT 
| MULTIPLY
| DIVIDE
;

relop: LT
| GT
| LE
| GE
| EQ
| NE
;

value: NUMBER
| FLOAT_NUM
| CHARACTER
| ID
;

return: RETURN value ';' 
|
;

%%

int main() {
    yyparse();
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}