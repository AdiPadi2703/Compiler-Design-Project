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

	extern int flag;
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

%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO
%token BREAK CONTINUE GOTO
%token ENDIF
%token SWITCH CASE DEFAULT
%expect 2

%token identifier array_identifier
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


%start begin_parse
%name PARSE

%%
begin_parse
			: declarations;

declarations
			: declaration declarations
			|
			;

declaration
			: variable_dec
			| function_dec
			| structure_dec;

structure_dec
			: STRUCT identifier { insert_type(); } '{' structure_content  '}' ';';

structure_content : variable_dec structure_content | ;

variable_dec
			: datatype variables ';'
			| structure_initialize;

structure_initialize
			: STRUCT identifier variables;

variables
			: identifier_name multiple_variables;

multiple_variables
			: ',' variables
			| ;

identifier_name
			: identifier { if(check_function(current_identifier))
						  {yyerror("ERROR: Identifier cannot be same as function name!\n"); exit(8);}
						  if(duplicate(current_identifier)){yyerror("Duplicate value!\n");exit(0);}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type(); } extended_identifier
			| array_identifier {if(duplicate(current_identifier)){yyerror("Duplicate value!\n");exit(0);}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type();  } extended_identifier;

extended_identifier : array_iden | '='{strcpy(previous_operator,"=");} simple_expression ;

array_iden
			: '[' array_dims
			| ;

array_dims
			: integer_constant {insert_dimensions();} ']' initilization{if($$ < 1) {yyerror("Array must have size greater than 1!\n"); exit(0);} }
			| ']' string_initilization;

initilization
			: string_initilization
			| array_initialization
			| ;

string_initilization
			: '='{strcpy(previous_operator,"=");} string_constant { insert_value(); };

array_initialization
			: '='{strcpy(previous_operator,"=");} '{' array_values '}';

array_values
			: integer_constant multiple_array_values;

multiple_array_values
			: ',' array_values
			| ;


datatype
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
			: function_datatype function_parameters;

function_datatype
			: datatype identifier '('  {strcpy(currfunctype, current_type); check_duplicate(current_identifier); insert_SymbolTable_function(current_identifier);  strcpy(current_function,current_identifier); insert_type();};

function_parameters
			: parameters ')' statement;

parameters
			: datatype { check_params(current_type); } all_parameter_identifiers {insert_SymbolTable_paramscount(current_function, params_count);} | ;

all_parameter_identifiers
			: parameter_identifier multiple_parameters;

multiple_parameters
			: ',' parameters
			| ;

parameter_identifier
			: identifier {insert_parameters(); insert_type(); insert_SymbolTable_nest(current_identifier,1); params_count++;} extended_parameter;

extended_parameter
			: '[' ']'
			| ;

statement
			: expression_statment | multiple_statement
			| conditional_statements | iterative_statements
			| return_statement | break_statement
			| variable_dec;

multiple_statement
			:{current_nested_val++;} '{' statments '}' {remove_scope(current_nested_val);current_nested_val--;} ;

statments
			: statement statments
			| ;

expression_statment
			: expression ';'
			| ';' ;

conditional_statements
			: IF '(' simple_expression ')' {if($3!=1){yyerror("ERROR: Here, condition must have integer value!\n");exit(0);}} statement extended_conditional_statements;

extended_conditional_statements
			: ELSE statement
			| ;

iterative_statements
			: WHILE '(' simple_expression ')'{if($3!=1){yyerror("ERROR: Here, condition must have integer value!\n");exit(0);}} statement
			| FOR '(' for_initialization simple_expression ';' {if($4!=1){yyerror("Here, condition must have integer value!\n");exit(0);}} expression ')'
			| DO statement WHILE '(' simple_expression ')' {if($5!=1){yyerror("ERROR: Here, condition must have integer value!\n");exit(0);}} ';';

for_initialization
			: variable_dec
			| expression ';'
			| ';' ;

return_statement
			: RETURN ';' {if(strcmp(currfunctype,"void")) {yyerror("ERROR: Cannot have void return for non-void function!\n"); exit(0);}}
			| RETURN expression ';' { 	if(!strcmp(currfunctype, "void"))
										{
											yyerror("Non-void return for void function!"); exit(0);
										}

										if((currfunctype[0]=='i' || currfunctype[0]=='c') && $2!=1)
										{
											yyerror("Expression doesn't match return type of function\n"); exit(0);
										}

			                     	};

break_statement
			: BREAK ';' ;


expression
			: mutable '=' expression              {					strcpy(previous_operator,"=");
																	  if($1==1 && $3==1)
																	  {
			                                                          $$=1;
			                                                          }
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }
			| mutable ADD_EQUAL expression     {					strcpy(previous_operator,"+=");
																	  if($1==1 && $3==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }
			| mutable SUBTRACT_EQUAL expression  {					strcpy(previous_operator,"-=");
																	  if($1==1 && $3==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }

			| mutable MULTIPLY_EQUAL expression {					strcpy(previous_operator,"*=");
																	  if($1==1 && $3==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }
			| mutable DIVIDE_EQUAL expression 		{				strcpy(previous_operator,"/=");
																	  if($1==1 && $3==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }
			| mutable MOD_EQUAL expression 		{					strcpy(previous_operator,"%=");
																	  if($1==1 && $3==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); exit(0);}
			                                                       }

			| mutable INCREMENT 							{if($1 == 1) $$=1; else $$=-1;}
			| mutable DECREMENT 							{if($1 == 1) $$=1; else $$=-1;}
			| simple_expression {if($1 == 1) $$=1; else $$=-1;} ;


simple_expression
			: simple_expression OR_OR and_expression {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| and_expression {if($1 == 1) $$=1; else $$=-1;};

and_expression
			: and_expression AND_AND unary_relation_expression {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			  |unary_relation_expression {if($1 == 1) $$=1; else $$=-1;} ;

unary_relation_expression
			: NOT unary_relation_expression {if($2==1) $$=1; else $$=-1;}
			| regular_expression {if($1 == 1) $$=1; else $$=-1;} ;

regular_expression
			: regular_expression relational_operators sum_expression {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			  | sum_expression {if($1 == 1) $$=1; else $$=-1;} ;

relational_operators
			: GREAT_EQUAL{strcpy(previous_operator,">=");}
			| LESS_EQUAL{strcpy(previous_operator,"<=");}
			| GREAT{strcpy(previous_operator,">");}
			| LESS{strcpy(previous_operator,"<");}
			| EQUAL{strcpy(previous_operator,"==");}
			| NOT_EQUAL{strcpy(previous_operator,"!=");} ;

sum_expression
			: sum_expression sum_operators term  {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| term {if($1 == 1) $$=1; else $$=-1;};

sum_operators
			: '+'
			| '-' ;

term
			: term MULOP factor {if($1 == 1 && $3==1) $$=1; else $$=-1;}
			| factor {if($1 == 1) $$=1; else $$=-1;} ;

MULOP
			: '*' | '/' | '%' ;

factor
			: immutable {if($1 == 1) $$=1; else $$=-1;}
			| mutable {if($1 == 1) $$=1; else $$=-1;} ;

mutable
			: identifier {
			              if(!check_scope(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Identifier undeclared\n");exit(0);}
			              if(!check_array(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Array Identifier has No Subscript\n");exit(0);}
			              if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
			              $$ = 1;
			              else
			              $$ = -1;
			              }
			| array_identifier {if(!check_scope(current_identifier)){printf("%s\n",current_identifier);yyerror("Identifier undeclared\n");exit(0);}} '[' expression ']'
			                   {if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
			              		$$ = 1;
			              		else
			              		$$ = -1;
			              		};

immutable
			: '(' expression ')' {if($2==1) $$=1; else $$=-1;}
			| call
			| constant {if($1==1) $$=1; else $$=-1;};

call
			: identifier '('{ strcpy(previous_operator,"(");
			             if(!check_declaration(current_identifier, "Function"))
			             { yyerror("Function not declared"); exit(0);}
			             insert_SymbolTable_function(current_identifier);
						 strcpy(currfunccall,current_identifier);
			             } arguments ')'
						 { if(strcmp(currfunccall,"printf"))
							{
								if(getSTparamscount(currfunccall)!=call_params_count)
								{
									yyerror("Number of parameters not same as number of arguments during function call!");
									//printf("Number of arguments in function call %s doesn't match number of parameters\n", currfunccall);
									exit(8);
								}
							}
						 };

arguments
			: arguments_list | ;

arguments_list
			: expression { call_params_count++; } A ;

A
			: ',' expression { call_params_count++; } A
			| ;

constant
			: integer_constant 	{  insert_type(); $$=1; }
			| string_constant	{  insert_type(); $$=-1;}
			| float_constant	{  insert_type(); }
			| character_constant{  insert_type();$$=1; };


%%

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
	yyparse();

	if(flag == 0)
	{
		printf("VALID PARSE\n");
		printf("%30s SYMBOL TABLE \n", " ");
		printf("%30s %s\n", " ", "------------");
		printSymbolTable();

		printf("\n\n%30s CONSTANT TABLE \n", " ");
		printf("%30s %s\n", " ", "--------------");
		printConstantTable();
	}
}

void yyerror(char *s)
{
	printf("Line No. : %d %s %s\n",yylineno, s, yytext);
	flag=1;
	printf("\nUNSUCCESSFUL: INVALID PARSE\n");
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
