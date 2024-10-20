#!/bin/bash

yacc -d parser.y
lex lexer.l
gcc lex.yy.c y.tab.c
echo "----------------------------------------------------------------------------------------------------------------------------"
for n in ./test_cases/*.c;
do
    echo $n
    echo "";
    cat $n;
    echo "";
    echo "----------------------------------------------------------------------------------------------------------------------------"
    ./a.out < $n;
    echo "----------------------------------------------------------------------------------------------------------------------------"
done