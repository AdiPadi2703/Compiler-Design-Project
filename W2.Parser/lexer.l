%option nounput yylineno

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

%}

%%

"auto"  {return AUTO;}
"printf" {return PRINTF;}
"scanf" {return SCANF;}
"const" {return CONST;}
"break" {return BREAK;}
"goto"  {return GOTO;}
"continue" {return CONTINUE;}
"switch" {return SWITCH;}
"case" {return CASE;}
"do" {return DO;}
"default" {return DEFAULT;}
"register" {return REGISTER;}
"static" {return STATIC;}
"while" {return WHILE;}
"volatile"  {return VOLATILE;}
"extern"    {return EXTERN;}
"short"     {return SHORT;}
"unsigned"  {return UNSIGNED;}
"signed"    {return SIGNED;}
"int"       {return INT;}
"char"     {return CHAR;}
"float"     {return FLOAT;}
"void"         {return VOID;}
"main"      {return MAIN;}
"for"       {return FOR;}
"return"    {return RETURN;}
"sizeof"    {return SIZEOF;}
"struct"    {return STRUCT;}
"union"     {return UNION;}
"if"        {return IF;}
"else"      {return ELSE;}
\#"include" {return INCLUDE;}
\#"define" {return DEFINE;}
"<"[_a-zA-Z/]*".h>"    {return HEADERPATH;}
[_a-zA-Z][_a-zA-Z0-9]* {return IDENTIFIER;}
[0-9]*                  {return INT_LIT;}
\'(\\.|[^"\\])\'        {return CHAR_LIT;}
[0-9]*\.[0-9]*          {return FLOAT_LIT;}
\"(\\.|[^"\\])*   {return UNMATCHEDSTRING;}  
"{"               {return OPENCURLY;}
"}"               {return CLOSEDCURLY;}
"("               {return OPENPAREN;}
")"               {return CLOSEDPAREN;}
"["               {return OPENREC;}
"]"               {return CLOSEDREC;}
"++"|"--"|"!"     {return UNARY;}
"?"               {return QTERTIARY;}
":"           {return CTERTIARY;}
"+"|"*"|"/"|"&&"|"||"|"->"|"&"|"%"|"+="|"/="|"-="|"*=" {return BINARY;}
"-" {return MINUS;}
">"|"<"|">="|"<="|"=="|"!=" {return RELOP;}
"=" {return ASSIGN;}
","           {return COMMA;}
";"           {return SEMICOLON;}
\/\/(.*)      {return SINGLELINECOMMENT;}
"/*"([^*]|\*+[^*/])*\*+"/" {return MULTILINECOMMENT;}
"/*"([^*]|\*+[^*/])*       {return UNMATCHEDCOMMENT;}
"*/"                       {return UNMATCHEDCOMMENTCLOSED;}
[ \n\t]     {;}
.           {printf("ERR_UNEXPECTED_CHARACTER: On Line Number %d found %s\n",yylineno, yytext);}

%%

int yywrap(void){
    return 1;
}