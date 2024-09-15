%{
	void yyerror(char* s);
	int yylex();
	#include "stdio.h"
	#include "stdlib.h"
	#include "ctype.h"
	#include "string.h"
	void insert_type();
	void insert_value();
	void insert_dimensions();
	void insert_params();
	int insert_flag = 0;

	extern char current_id[20];
	extern char current_type[20];
	extern char current_value[20];
    extern char current_function[20];
	extern char previous_operator[20];

%}

%name parse	

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT UNION
%token RETURN MAIN
%token VOID
%token WHILE FOR DO 
%token BREAK CONTINUE GOTO
%token ENDIF
%token SWITCH CASE DEFAULT
%expect 2

%token id
%token integer_constant string_constant float_constant character_constant

%nonassoc ELSE

%right MOD_EQUAL
%right MULTIPLY_EQUAL DIVIDE_EQUAL
%right ADD_EQUAL SUBTRACT_EQUAL
%right '='

%left OR_OR
%left AND_AND
%left '^'
%left EQUAL NOT_EQUAL
%left LESS_EQUAL LESS GREAT_EQUAL GREAT
%left '+' '-'
%left '*' '/' '%'

%right SIZEOF
%right NOT
%left INCREMENT DECREMENT 


%start program

%%
program
			: declarations;

declarations
			: declaration declarations 
			|	
			;

declaration
			: var_dec 
			| function_dec
			| struct_dec
			| union_dec ;

struct_dec
			: STRUCT id { insert_type(); } '{' struct_content  '}' ';';

struct_content : var_dec struct_content | ;

union_dec
			: UNION id { insert_type(); } '{' union_content  '}' ';';

union_content : var_dec union_content | ;

var_dec
			: dtype vars ';' 
			| struct_init
			| union_init
			;

struct_init 
			: STRUCT id vars;

union_init 
			: UNION id vars;

vars
			: id_name multiple_vars;

multiple_vars
			: vars ','
			| ;

id_name 
			: id { insert_type(); } extended_id;

extended_id : array_id | '='{strcpy(previous_operator,"=");} expression ; 

array_id
			: '[' array_dims
			| ;

array_dims
			: integer_constant {insert_dimensions();} ']' init
			| ']' string_init;

init
			: string_init
			| array_init
			| ;

string_init
			: '='{strcpy(previous_operator,"=");} string_constant { insert_value(); };

array_init
			: '='{strcpy(previous_operator,"=");} '{' array_values '}';

array_values
			: integer_constant multiple_array_values;

multiple_array_values
			: ',' array_values 
			| ;


dtype 
			: INT | CHAR | FLOAT | DOUBLE 
			| LONG long_grammar 
			| SHORT short_grammar
			| UNSIGNED unsigned_grammar 
			| SIGNED signed_grammar
			| VOID ;

unsigned_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

signed_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

long_grammar 
			: INT | ;

short_grammar 
			: INT | ;

function_dec
			: function_dtype function_params;

function_dtype
			: dtype id '('  {strcpy(current_function,current_id); insert_type();};

function_params
			: params ')' statement;

params 
			: dtype all_parameter_ids | ;

all_parameter_ids 
			: parameter_id multiple_params;

multiple_params
			: ',' params 
			| ;

parameter_id 
			: id { insert_params(); insert_type(); } extended_parameter;

extended_parameter
			: '[' ']'
			| ;

statement 
			: expression_statement | multiple_statement 
			| conditional_statements | loop_statements 
			| return_statement | break_statement 
			| var_dec;

multiple_statement 
			: '{' statements '}' ;

statements 
			: statement statements
			| ;

expression_statement 
			: expression ';' 
			| ';' ;

conditional_statements 
			: IF '(' simple_expression ')' statement extended_conditional_statements;

extended_conditional_statements
			: ELSE statement
			| ;

loop_statements 
			: WHILE '(' simple_expression ')' statement 
			| FOR '(' for_init simple_expression ';' expression ')' 
			| DO statement WHILE '(' simple_expression ')' ';';

for_init
			: var_dec
			| expression ';'
			| ';' ;

return_statement 
			: RETURN return_suffix;

return_suffix
			: ';' 
			| expression ';' ;

break_statement 
			: BREAK ';' ;

expression 
			: identifier expressions
			| simple_expression ;

expressions
			: '='{strcpy(previous_operator,"=");} expression 
			| ADD_EQUAL{strcpy(previous_operator,"+=");} expression 
			| SUBTRACT_EQUAL{strcpy(previous_operator,"-=");} expression 
			| MULTIPLY_EQUAL{strcpy(previous_operator,"*=");} expression 
			| DIVIDE_EQUAL{strcpy(previous_operator,"/=");} expression 
			| MOD_EQUAL{strcpy(previous_operator,"%=");} expression 
			| INCREMENT 
			| DECREMENT ;

simple_expression 
			: and_expression simple_expression_breakup;

simple_expression_breakup 
			: OR_OR and_expression simple_expression_breakup | ;

and_expression 
			: unary_relation_expression and_expression_breakup;

and_expression_breakup
			: AND_AND unary_relation_expression and_expression_breakup
			| ;

unary_relation_expression 
			: NOT unary_relation_expression 
			| regex ;

regex 
			: sum_expression regex_breakup;

regex_breakup
			: relops sum_expression 
			| ;

relops 
			: GREAT_EQUAL{strcpy(previous_operator,">=");}
			| LESS_EQUAL{strcpy(previous_operator,"<=");}
			| GREAT{strcpy(previous_operator,">");} 
			| LESS{strcpy(previous_operator,"<");}
			| EQUAL{strcpy(previous_operator,"==");}
			| NOT_EQUAL{strcpy(previous_operator,"!=");} ;

sum_expression 
			: sum_expression sum_operators term 
			| term ;

sum_operators 
			: '+' 
			| '-' ;

term
			: term multiply_operators factor 
			| factor ;

multiply_operators 
			: '*' | '/' | '%' ;

factor 
			: function | identifier ;

identifier 
			: id 
			| identifier extended_identifier;

extended_identifier
			: '[' expression ']' 
			| '.' id;

function 
			: '('{strcpy(previous_operator,"(");} expression ')' 
			| function_call | constant;

function_call
			: id '('{strcpy(previous_operator,"(");} args ')';

args 
			: args_list | ;

args_list 
			: expression extended_args;

extended_args
			: ',' expression extended_args 
			| ;

constant 
			: integer_constant 	{ insert_value(); } 
			| string_constant	{ insert_value(); } 
			| float_constant	{ insert_value(); } 
			| character_constant{ insert_value(); };

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insert_SymbolTable_type(char *,char *);
void insert_SymbolTable_value(char *, char *);
void insert_ConstantTable(char *, char *);
void insert_SymbolTable_arraydim(char *, char *);
void insert_SymbolTable_functionparam(char *, char *);
void printSymbolTable();
void printConstantTable();


int main()
{	
	yyparse();
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%30s SYMBOL TABLE \n", " ");
	printf("------------------------------------------------------------------------------------------------\n");
	printSymbolTable();

	printf("------------------------------------------------------------------------------------------------\n");
	
	
	printf("------------------------------------------------------------------------------------------------\n");
	printf("%30s CONSTANT TABLE \n", " ");
	printf("-------------------------------------------------------------------------------------------------\n");
	printConstantTable();
	printf("------------------------------------------------------------------------------------------------\n");


}

void yyerror(char *s)
{
	printf("Line No. : %d %s %s\n",yylineno, s, yytext);
	printf("INVALID PARSE\n");
	
}

void insert_type()
{
	insert_SymbolTable_type(current_id,current_type);
}

void insert_value()
{	
	if(strcmp(previous_operator, "=") == 0)
	{	insert_SymbolTable_value(current_id,current_value);
	}
}	

void insert_dimensions()
{
    insert_SymbolTable_arraydim(current_id, current_value);
}

void insert_params()
{
    insert_SymbolTable_functionparam(current_function, current_id);
}

int yywrap()
{
	return 1;
}