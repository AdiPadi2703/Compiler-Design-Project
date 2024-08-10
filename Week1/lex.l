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

int main(){
    struct symbol{
        char name[MAX_NAME]; // symbol name
        char token[MAX_SYM]; // symbol type
        int type;  // token number 
        struct symbol *next;
    };

    //struct symbol *s=malloc(sizeof(struct symbol*));
    struct symbol *symbol_table[MAX_TABLE];
    for (int i=0;i<MAX_TABLE;i++){
        symbol_table[i] = NULL;
    }
    void print_table(){
        int iter = 0;
        struct symbol *pointer;
        for (int i=0;i<MAX_TABLE;i++){
            if (symbol_table[i]!=NULL){
                pointer = symbol_table[i];
                while(pointer!=NULL){
                    printf("%d %s\t\t%s\t\t%d -->",iter,pointer->name,pointer->token,pointer->type);
                    pointer = pointer->next;
                }
                printf("|\n");
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

    void add(struct symbol *s){
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

    char *lexeme;
    int tokenNumber = yylex();
    print_table();
    while(tokenNumber){

        lexeme = strdup(yytext);
        if(tokenNumber == 17){
            printf("ERR_UNMATCHED_COMMENT: On Line Number %d found %s\n",yylineno, lexeme);
        }
        else if(tokenNumber == 18){
            printf("ERR_INCOMPLETE_STRING: On Line Number %d found %s\n",yylineno, lexeme);
        }
        printf("On Line Number %d found token: %s - %s\n",yylineno, tokens[tokenNumber - 1], lexeme);;
        struct symbol *s=malloc(sizeof(struct symbol));
        strncpy(s->token,tokens[tokenNumber - 1],MAX_SYM);
        s->type = tokenNumber;
        strncpy(s->name,lexeme,MAX_NAME);
        add(s);
        tokenNumber = yylex();
    }
    printf("###SYMBOL TABLE###\n\n");
    print_table();
    return 0;
}