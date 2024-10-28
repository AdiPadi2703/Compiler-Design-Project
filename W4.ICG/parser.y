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
	void push(char *s);
	void codegen();
	void codeassign();
	char* itoa(int num, char* str, int base);
	void reverse(char str[], int length);
	void swap(char*,char*);
	void label1();
	void label2();
	void label3();
	void label4();
	void label5();
	void label6();
	void genunary();
	void codegencon();
	void start_function();
	void end_function();
	void arggen();
	void callgen();


	int insert_flag = 0;
	//int params_count=0;
	int call_params_count=0;
	int array_flag = 0;
	int array_tac_flag = 0;
	int top = 0,count=0,ltop=0,lno=0;
	char temp[3] = "t";

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
	int arr_dim = 0;

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

%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO
%token BREAK CONTINUE GOTO
%token ENDIF
%token SWITCH CASE DEFAULT

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
			| structure_dec
			| error ;

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
			: identifier { push(current_identifier);
						  if(check_function(current_identifier))
						  {yyerror("ERROR: Identifier cannot be same as function name!\n"); }
						  if(duplicate(current_identifier)){yyerror("Duplicate value!\n");}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type(); } extended_identifier
			| array_identifier {if(duplicate(current_identifier)){yyerror("Duplicate value!\n");}insert_SymbolTable_nest(current_identifier,current_nested_val); insert_type();  } extended_identifier;

extended_identifier : array_iden | '='{strcpy(previous_operator,"="); push("=");} simple_expression {codeassign();};

array_iden
			: '[' array_dims 
			|  { insert_dimensions(); arr_dim = 0;};

array_dims
			:   integer_constant ']' {arr_dim++; insert_dimensions(); arr_dim = 0;} initilization {if($$ < 1) {yyerror("Array must have size greater than 1!"); } }
			| ']'  { arr_dim = 1 ;insert_dimensions(); arr_dim = 0;} string_initilization;
			|  integer_constant ']' {arr_dim++;} array_iden ;

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
			: {params_count = 0;} parameters ')' {start_function();} statement {end_function();};

parameters
			: datatype { check_params(current_type); } all_parameter_identifiers {insert_SymbolTable_paramscount(current_function, params_count);} | {insert_SymbolTable_paramscount(current_function, params_count);};

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
			: IF '(' simple_expression ')' {label1(); if($3!=1){yyerror("ERROR: Here, condition must have integer value!\n");}} statement {label2();} extended_conditional_statements;

extended_conditional_statements
			: ELSE statement {label3();}
			| {label3();};

iterative_statements
			: WHILE '(' {label4();} simple_expression ')'{label1();if($4!=1){yyerror("ERROR: Here, condition must have integer value!\n");}} statement {label5();}
			| FOR '(' for_initialization simple_expression ';' {label1();if($4!=1){yyerror("Here, condition must have integer value!\n");}} expression ')' statement {label5();}
			| {label4();} DO statement WHILE '(' simple_expression ')' {label1(); label5(); if($6!=1){yyerror("ERROR: Here, condition must have integer value!\n");}} ';';

for_initialization
			: variable_dec
			| expression ';' {label4();}
			| ';' ;

return_statement
			: RETURN ';' {if(strcmp(currfunctype,"void")) {yyerror("ERROR: Cannot have void return for non-void function!\n");}}
			| RETURN expression ';' { if(!strcmp(currfunctype, "void"))
										{
											yyerror("Non-void return for void function!"); 
										}

										if((currfunctype[0]=='i' || currfunctype[0]=='c') && $2!=1)
										{
											yyerror("Expression doesn't match return type of function\n"); 
										}

			                     	};

break_statement
			: BREAK ';' ;


expression
			: mutable '=' {push("=");} expression            {		strcpy(previous_operator,"=");
																	  if($1==1 && $4==1)
																	  {
			                                                          $$=1;
			                                                          }
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); }
																	  codeassign();
			                                                       }
			| mutable ADD_EQUAL {push("+=");} expression   {		strcpy(previous_operator,"+=");
																	  if($1==1 && $4==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n");}
																	  codeassign();
			                                                       }
			| mutable SUBTRACT_EQUAL {push("-=");} expression {		strcpy(previous_operator,"-=");
																	  if($1==1 && $4==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); }
																	  codeassign();
			                                                       }

			| mutable MULTIPLY_EQUAL {push("*=");} expression   {	strcpy(previous_operator,"*=");
																	  if($1==1 && $4==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); ;}
																	  codeassign();
			                                                       }
			| mutable DIVIDE_EQUAL {push("/=");} expression	{	strcpy(previous_operator,"/=");
																	  if($1==1 && $4==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); }
																	  codeassign();
			                                                       }
			| mutable MOD_EQUAL {push("%=");} expression 		{	strcpy(previous_operator,"%=");
																	  if($1==1 && $4==1)
			                                                          $$=1;
			                                                          else
			                                                          {$$=-1; yyerror("Type Mismatch\n"); }
																	  codeassign();
			                                                       }

			| mutable INCREMENT 							{push("++"); if($1 == 1) $$=1; else $$=-1; genunary();}
			| mutable DECREMENT 							{push("--"); if($1 == 1) $$=1; else $$=-1; genunary();}
			| simple_expression {if($1 == 1) $$=1; else $$=-1;} ;


simple_expression
			: simple_expression OR_OR and_expression {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen();}
			| and_expression {if($1 == 1) $$=1; else $$=-1;};

and_expression
			: and_expression AND_AND unary_relation_expression {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen();}
			  |unary_relation_expression {if($1 == 1) $$=1; else $$=-1;} ;

unary_relation_expression
			: NOT unary_relation_expression {if($2==1) $$=1; else $$=-1; codegen();}
			| regular_expression {if($1 == 1) $$=1; else $$=-1;} ;

regular_expression
			: regular_expression relational_operators sum_expression {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen();}
			  | sum_expression {if($1 == 1) $$=1; else $$=-1;} ;

relational_operators
			: GREAT_EQUAL{strcpy(previous_operator,">="); push(">=");}
			| LESS_EQUAL{strcpy(previous_operator,"<="); push("<=");}
			| GREAT{strcpy(previous_operator,">"); push(">");}
			| LESS{strcpy(previous_operator,"<"); push("<");}
			| EQUAL{strcpy(previous_operator,"=="); push("==");}
			| NOT_EQUAL{strcpy(previous_operator,"!="); push("!=");} ;

sum_expression
			: sum_expression sum_operators term  {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen();}
			| term {if($1 == 1) $$=1; else $$=-1;};

sum_operators
			: '+' {push("+");}
			| '-' {push("-");} ;

term
			: term MULOP factor {if($1 == 1 && $3==1) $$=1; else $$=-1; codegen();}
			| factor {if($1 == 1) $$=1; else $$=-1;} ;

MULOP
			: '*' {push("*");}
			| '/' {push("/");}
			| '%' {push("%");} ;

factor
			: immutable {if($1 == 1) $$=1; else $$=-1;}
			| mutable {if($1 == 1) $$=1; else $$=-1;} ;

mutable
			: identifier {
						  push(current_identifier);
			              if(!check_scope(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Identifier undeclared\n");}
			              if(!check_array(current_identifier))
			              {printf("%s\n",current_identifier);yyerror("Array Identifier has No Subscript\n");}
			              if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
			              $$ = 1;
			              else
			              $$ = -1;
			              }
			| array_identifier {push(current_identifier);
								array_flag = 1;
								if(!check_scope(current_identifier)){printf("%s\n",current_identifier);yyerror("Identifier undeclared\n");}} '[' expression ']'
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
			             { yyerror("Function not declared"); }
			             insert_SymbolTable_function(current_identifier);
						 strcpy(currfunccall,current_identifier);
						 if(gettype(current_identifier,0)=='i' || gettype(current_identifier,1)== 'c')
						 {
			             $$ = 1;
			             }
			             else
			             $$ = -1;
                         call_params_count=0;
			             } arguments ')'
						 { if(strcmp(currfunccall,"printf"))
							{
								if(getSTparamscount(currfunccall)!=call_params_count)
								{
									yyerror("Number of parameters not same as number of arguments during function call!");
									//printf("Number of arguments in function call %s doesn't match number of parameters\n", currfunccall);
									
								}
							}
							callgen();
						 };

arguments
			: arguments_list | ;

arguments_list
			: arguments_list ',' exp { call_params_count++; }
			| exp { call_params_count++; };

exp : identifier {arggen(1);} | integer_constant {arggen(2);} | string_constant {arggen(3);} | float_constant {arggen(4);} | character_constant {arggen(5);} ;

constant
			: integer_constant 	{  insert_type(); codegencon(); $$=1; }
			| string_constant	{  insert_type(); codegencon(); $$=-1;}
			| float_constant	{  insert_type(); codegencon(); }
			| character_constant{  insert_type(); codegencon(); $$=1; };


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
struct stack
{
	char value[100];
	int labelvalue;
}s[100],label[100];


void push(char *x)
{
	strcpy(s[++top].value,x);
}


void codegen()
{
	printf("t%d = %s %s %s\n",count,s[top-2].value,s[top-1].value,s[top].value);
	top = top - 2;
    sprintf(temp, "t%d", count);
	strcpy(s[top].value,temp);
	count++;
}

void codegencon()
{
	if(array_flag == 1){
		printf("t%d = 4 * %s\n",count ,current_value);
		count++;
		printf("t%d = &arr[t%d]\n",count ,count-1);
		array_tac_flag = 1;
	}
	else
		printf("t%d = %s\n",count ,current_value);
	sprintf(temp, "t%d", count);
	push(temp);
	count++;
	array_flag = 0;
}

void codeassign()
{
	if(array_tac_flag == 1)
		printf("*%s = %s\n",s[top-2].value,s[top].value);
	else
		printf("%s = %s\n",s[top-2].value,s[top].value);
	array_tac_flag = 0;
	top = top - 2;
}

int isunary(char *s)
{
	if(strcmp(s, "--")==0 || strcmp(s, "++")==0)
	{
		return 1;
	}
	return 0;
}

void genunary()
{
	char temp1[100], temp2[100], temp3[100];
	strcpy(temp1, s[top].value);
	strcpy(temp2, s[top-1].value);

	if(isunary(temp1))
	{
		strcpy(temp3, temp1);
		strcpy(temp1, temp2);
		strcpy(temp2, temp3);
	}

	if(strcmp(temp2,"--")==0)
	{
		printf("t%d = %s - 1\n", count, temp1);
		printf("%s = t%d\n", temp1, count);
	}

	if(strcmp(temp2,"++")==0)
	{
		printf("t%d = %s + 1\n", count, temp1);
		printf("%s = t%d\n", temp1, count);
	}
	count++;
	top = top -2;
}


void label1()
{
	printf("IF not %s goto L%d\n",s[top].value,lno);
	label[++ltop].labelvalue = lno++;
}

void label2()
{
	printf("goto L%d\n",lno);
	printf("L%d:\n",label[ltop].labelvalue);
	ltop--;
	label[++ltop].labelvalue=lno++;
}

void label3()
{
	printf("L%d:\n",label[ltop].labelvalue);
	ltop--;
}

void label4()
{
	printf("L%d:\n",lno);
	label[++ltop].labelvalue = lno++;
}


void label5()
{
	printf("goto L%d:\n",label[ltop-1].labelvalue);
	printf("L%d:\n",label[ltop].labelvalue);
	ltop = ltop - 2;
}

void start_function()
{
	printf("func begin %s\n",current_function);
}

void end_function()
{
	printf("func end\n\n");
}

void arggen(int i)
{
    if(i==1)
    {
	printf("param %s\n", current_identifier);
	}
	else
	{
	printf("param %s\n", current_value);
	}
}

void callgen()
{
	printf("refparam result\n");
	push("result");
	printf("call %s, %d\n",currfunccall,call_params_count);
}


int main()
{
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

	return 0;
}

void yyerror(char *s)
{
	printf("ehllo");
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
    int len = snprintf(NULL,0,"%d",arr_dim);
	char* result = malloc(len+1);
	snprintf(result,len+1,"%d",arr_dim);
    insert_SymbolTable_arraydim(current_identifier, result);
}

void insert_parameters()
{
    insert_SymbolTable_funcparam(current_function, current_identifier);
}

int yywrap()
{
	return 1;
}
