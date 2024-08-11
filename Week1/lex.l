%option nounput yylineno

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

#define MAX_SYM 256
#define MAX_NAME 1024 
#define MAX_TABLE 256

char tokens[100][100] = {
    "KEYWORD",
    "OPERATOR", 
    "IDENTIFIER", 
    "PREPROCESSOR", 
    "SEMICOLON", 
    "LITERAL", 
    "HEADERDIRECTORY", 
    "OPENCURLY",
    "CLOSEDCURLY", 
    "OPENPAREN", 
    "CLOSEDPAREN", 
    "OPENREC", 
    "CLOSEDREC", 
    "COMMA", 
    "SINGLELINECOMMENT", 
    "MULTILINECOMMENT",
    "UNMATCHEDCOMMENT", 
    "UNMATCHEDSTRING" 
};

%}

%%

"auto"|"const"|"break"|"goto"|"continue"|"switch"|"case"|"do"|"default"|"double"              {return KEYWORD;}
"register"|"static"|"while"|"volatile"|"extern"|"short"|"unsigned"|"signed"|"int"|"char"      {return KEYWORD;}
"float"|"void"|"bool"|"main"|"for"|"return"|"sizeof"|"struct"|"union"|"typedef"|"if"|"else"   {return KEYWORD;}
\#"include"|\#"define" {return PREPROCESSOR;}
"<"[_a-zA-Z/]*".h>"    {return HEADERDIRECTORY;}
[_a-zA-Z][_a-zA-Z0-9]* {return IDENTIFIER;}
([0-9]*)|(\"(\\.|[^"\\])*\")|(\'(\\.|[^"\\])\')|([0-9]*\.[0-9]*) {return LITERAL;}  
\"(\\.|[^"\\])*   {return UNMATCHEDSTRING;}  
"{"               {return OPENCURLY;}
"}"               {return CLOSEDCURLY;}
"("               {return OPENPAREN;}
")"               {return CLOSEDPAREN;}
"["               {return OPENREC;}
"]"               {return CLOSEDREC;}
"++"|"--"|"?"|":"|"="|"+"|"-"|"*"|"/"|">"|"<"|">="|"<="|"=="|"!="|"&&"|"||"|"!"|"->"|"&"|"%"|"+="|"/="|"-="|"*="  {return OPERATOR;}      
","           {return COMMA;}
";"           {return SEMICOLON;}
\/\/(.*)      {return SINGLELINECOMMENT;}
"/*"([^*]|\*+[^*/])*\*+"/" {return MULTILINECOMMENT;}
"/*"([^*]|\*+[^*/])*       {return UNMATCHEDCOMMENT;}
[ \n\t]     {;}
.           {printf("ERR_UNEXPECTED_CHARACTER: On Line Number %d found %s\n",yylineno, yytext);}

%%

int yywrap(void){
    return 1;
}

struct symbol{
        char name[MAX_NAME]; // symbol name
        char token[MAX_SYM]; // symbol type
        int type;  // token number 
        struct symbol *next;
    };
struct constant{
        char name[MAX_NAME];//symbol name
        char value[MAX_NAME];//value
        char datatype[MAX_SYM]//data type of constant
        struct constant* next;
    };

void print_table(struct symbol *symbol_table[]){
        int iter = 0;
        struct symbol *pointer;
        printf("\n\n***********************************************************************************************\n");
        printf("*                                      SYMBOL TABLE                                           *\n");
        printf("***********************************************************************************************\n");
        printf("Hash Value                    Lexeme                    Token                      Token Number\n");
        printf("***********************************************************************************************\n");
        printf("*                                                                                             *\n");
        for (int i=0;i<MAX_TABLE;i++){
            if (symbol_table[i]!=NULL){
                pointer = symbol_table[i];
                while(pointer!=NULL){
                    printf("%d",iter);
                    for(int j = 0;j < 35 - (int)strlen(pointer->name);j++){
                        printf(" ");
                    }
                    printf("%s",pointer->name);
                    for(int j = 0;j < 25 - (int)strlen(pointer->token);j++){
                        printf(" ");
                    }
                    printf("%s",pointer->token);
                    for(int j = 0;j < 25;j++){
                        printf(" ");
                    }
                    printf("%d",pointer->type);
                    pointer = pointer->next;
                    printf("\n");
                }
                printf("-----------------------------------------------------------------------------------------------\n");
                iter++;
            }
        }printf("\n\n");
    }
void print_const_table(struct constant *const_table[]){
        int iter = 0;
        struct constant *pointer;
        printf("\n\n***********************************************************************************************\n");
        printf("*                                      CONSTANT TABLE                                           *\n");
        printf("***********************************************************************************************\n");
        printf("Hash Value                    Name                    Value                      Data Type\n");
        printf("***********************************************************************************************\n");
        printf("*                                                                                             *\n");
        for (int i=0;i<MAX_TABLE;i++){
            if (const_table[i]!=NULL){
                pointer = const_table[i];
                while(pointer!=NULL){
                    printf("%d",iter);
                    for(int j = 0;j < 35 - (int)strlen(pointer->name);j++){
                        printf(" ");
                    }
                    printf("%s",pointer->name);
                    for(int j = 0;j < 25 - (int)strlen(pointer->value);j++){
                        printf(" ");
                    }
                    printf("%s",pointer->value);
                    for(int j = 0;j < 25 - (int)strlen(pointer->datatype);j++){
                        printf(" ");
                    }
                    printf("%s",pointer->datatype);
                    pointer = pointer->next;
                    printf("\n");
                }
                printf("-----------------------------------------------------------------------------------------------\n");
                iter++;
            }
        }printf("\n\n");
    }

unsigned int hash(char *name){
        int length = strlen(name);
        if(length > MAX_NAME)length = MAX_NAME;
        unsigned int hash_value=0;
        for (int i=0;i<length;i++){
            hash_value+=name[i];
            hash_value*=name[i];
        }
        hash_value%=MAX_TABLE;
        return hash_value;
    }

void add(struct symbol *s, struct symbol* symbol_table[]){
        if (s!=NULL){
            int index = hash(s->name);
            int flag =1;
            struct symbol *pointer = symbol_table[index];
            while(pointer!=NULL){
                if (!strcmp(symbol_table[index]->name,s->name)){
                    flag = 0;
                    break;
                }
                pointer = pointer->next;
            }
            if(flag){
                s->next = symbol_table[index];
                symbol_table[index] = s;
            }
        }
    }
void add_const(struct constant *c,struct constant *const_table[]){
        if (c!=NULL){
            int index = hash(c->name);
            int flag =1;
            struct constant *pointer = const_table[index];
            while(pointer!=NULL){
                if (!strcmp(const_table[index]->name,c->name)){
                    flag = 0;
                    break;
                }
                pointer = pointer->next;
            }
            if(flag){
                c->next = const_table[index];
                const_table[index] = c;
            }
        }
    }

int main(){
    
    struct symbol *symbol_table[MAX_TABLE];
   struct constant *const_table[MAX_TABLE];
    for (int i=0;i<MAX_TABLE;i++){
        symbol_table[i] = NULL;
    }

    char *lexeme;
    int tokenNumber = yylex();
    print_table(symbol_table);
    print_const_table(const_table);
    while(tokenNumber){

        lexeme = strdup(yytext);
        if(tokenNumber == 17){
            printf("ERR_UNMATCHED_COMMENT: On Line Number %d found %s\n",yylineno, lexeme);
        }
        else if(tokenNumber == 18){
            printf("ERR_INCOMPLETE_STRING: On Line Number %d found %s\n",yylineno, lexeme);
        }
        else if(tokenNumber == 1 && strcmp(lexeme,'const')==0){
            printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
            struct symbol *s=malloc(sizeof(struct symbol));
            strncpy(s->token,tokens[tokenNumber - 1],MAX_SYM);
            s->type = tokenNumber;
            strncpy(s->name,lexeme,MAX_NAME);
            add(s,symbol_table);
            tokenNumber = yylex();
            lexeme=strdup(yytext);
            struct constant *c=malloc(sizeof(struct constant));
            strncpy(c->datatype,lexeme,MAX_SYM);
            tokenNumber = yylex();
            lexeme=strdup(yytext);
            strncpy(c->name,lexeme,MAX_SYM);
            tokenNumber = yylex();
            printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
            struct symbol *s1=malloc(sizeof(struct symbol));
            strncpy(s1->token,tokens[tokenNumber - 1],MAX_SYM);
            s1->type = tokenNumber;
            strncpy(s1->name,lexeme,MAX_NAME);
            add(s1,symbol_table);
            tokenNumber = yylex();
            lexeme=strdup(yytext);
            strncpy(c->value,lexeme,MAX_SYM);
            add_const(c,const_table);
        }
        else if(tokenNumber == 2 && strcmp(lexeme,"define") == 0){
            printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
            struct symbol *s=malloc(sizeof(struct symbol));
            struct constant *c=malloc(sizeof(struct symbol));
            strncpy(s->token,tokens[tokenNumber - 1],MAX_SYM);
            s->type = tokenNumber;
            strncpy(s->name,lexeme,MAX_NAME);
            add(s,symbol_table);
            tokenNumber = yylex();
            lexeme=strdup(yytext);
            strncpy(c->name,lexeme,MAX_SYM);
            tokenNumber = yylex();
            printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
            struct symbol *s1=malloc(sizeof(struct symbol));
            strncpy(s1->token,tokens[tokenNumber - 1],MAX_SYM);
            s1->type = tokenNumber;
            strncpy(s1->name,lexeme,MAX_NAME);
            add(s1,symbol_table);
            tokenNumber = yylex();
            lexeme=strdup(yytext);
            strncpy(c->value,lexeme,MAX_SYM);
            strncpy(c->datatype,'int',MAX_SYM);
            add_const(c,const_table);
        }
        else{
            printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
            struct symbol *s=malloc(sizeof(struct symbol));
            strncpy(s->token,tokens[tokenNumber - 1],MAX_SYM);
            s->type = tokenNumber;
            strncpy(s->name,lexeme,MAX_NAME);
            add(s,symbol_table);
        }
    }
    printf("###SYMBOL TABLE###\n\n");
    print_table(symbol_table);
    print_const_table(const_table);
    return 0;
}
