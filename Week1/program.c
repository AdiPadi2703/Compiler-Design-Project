
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MACRO 2

struct Node{

    int data;
    struct Node* next;

};
typedef struct Node Node;

int function(int a, int b){
    
    return a + b;

}

int main(){

    // this is an error
    
    \\


    // this is a single line comment
    float f = 10.9404;
    Node *n = (Node*)malloc(sizeof(Node));
    bool v = true;
    n->data = 10;
    n->next = NULL;
    int b = n->next?10:12;
    int a = 10;
    for(int i = 0;i < a;i++){

        printf("%d\n", i);
        /*
            This is
            a multiline comment
            /*nested comment*/
        */
    }
    if(a >= 10){
        a = 100;
    }
    else{
        a = 20;
    }
    int n = 10;
    char *s = "Adithya";
    int *k = (int*)malloc(sizeof(int));
    int a[] = {1,2,3,4};
    scanf("%d", &n);

    return 0;
        /*
            This is
            a multiline comment
            /*nested comment*/
        */

}
