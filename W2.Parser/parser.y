%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    extern int yylex();
    int yywrap();
%}


%token AUTO CONST BREAK GOTO CONTINUE SWITCH CASE DO DEFAULT 
%token REGISTER STATIC WHILE VOLATILE EXTERN SHORT UNSIGNED SIGNED INT CHAR 
%token FLOAT VOID MAIN FOR RETURN SIZEOF STRUCT UNION IF ELSE
%token INCLUDE DEFINE HEADERPATH IDENTIFIER 
%token UNMATCHEDSTRING OPENCURLY CLOSEDCURLY OPENPAREN CLOSEDPAREN OPENREC CLOSEDREC
%token INT_LIT CHAR_LIT FLOAT_LIT
%token COMMA SEMICOLON
%token SINGLELINECOMMENT MULTILINECOMMENT UNMATCHEDCOMMENT UNMATCHEDCOMMENTCLOSED
%token UNARY BINARY QTERTIARY CTERTIARY ASSIGN MINUS
%token PRINTF SCANF RELOP

%%
// main CFG
program: headers premain main postmain ;
headers: INCLUDE HEADERPATH headers| DEFINE IDENTIFIER headers | ;
premain : structs | unions | members | function | ;
postmain : structs | unions | members | function | ;

//types 
literal : INT_LIT | CHAR_LIT | FLOAT_LIT ; 
type : INT | CHAR | FLOAT ;

//statements
operand : IDENTIFIER | literal;

condition : condition RELOP statements | statements ;
statements : OPENPAREN condition CLOSEDPAREN | expression;


expression : expression BINARY arithmeticStatement | arithmeticStatement;
arithmeticStatement : OPENPAREN expression CLOSEDPAREN | operand | MINUS operand | condition;

// main 
main : INT MAIN OPENPAREN CLOSEDPAREN OPENCURLY body CLOSEDCURLY | 
       VOID MAIN OPENPAREN CLOSEDPAREN OPENCURLY body CLOSEDCURLY |
       INT MAIN OPENPAREN CLOSEDPAREN OPENCURLY body RETURN INT_LIT SEMICOLON CLOSEDCURLY ;

//body
body : ;

//structs and unions
structs : STRUCT IDENTIFIER OPENCURLY members CLOSEDCURLY SEMICOLON ; 
members : variableDec SEMICOLON members | ;
unions : UNION IDENTIFIER OPENCURLY members CLOSEDCURLY SEMICOLON ;

//variable declaration
variableDec : INT IDENTIFIER | CHAR IDENTIFIER | FLOAT IDENTIFIER;

// function declaration
function : INT IDENTIFIER OPENPAREN arguments CLOSEDPAREN OPENCURLY body RETURN INT_LIT SEMICOLON CLOSEDCURLY |
CHAR IDENTIFIER OPENPAREN arguments CLOSEDPAREN OPENCURLY body RETURN CHAR_LIT SEMICOLON CLOSEDCURLY |
FLOAT IDENTIFIER OPENPAREN arguments CLOSEDPAREN OPENCURLY body RETURN FLOAT_LIT SEMICOLON CLOSEDCURLY ;
arguments : variableDec COMMA arguments | variableDec ;


// control statements
controlStatement : openStatement | closedStatement ;
openStatement : IF OPENPAREN condition CLOSEDPAREN closedStatement 
| IF OPENPAREN condition CLOSEDPAREN openStatement 
| IF OPENPAREN condition CLOSEDPAREN closedStatement ELSE openStatement ;
closedStatement : body |IF OPENPAREN condition CLOSEDPAREN closedStatement ELSE closedStatement;
%%

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int main() {
    yyparse();
}