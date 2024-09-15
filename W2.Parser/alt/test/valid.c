// Single line comment
#include<stdio.h>

struct book
{
	char name[10];
	char author[10];
};

union novel
{
	int b;
	int a[10];
	char name[10];
	char author[10];
};

int multiply(int a)
{
	return 2*a;
}

int main()
{
	//Single Line Comment
	int a;
	char es = '\a';
	/* This is the declaration
	of an integer value */
	int a = 5;
	int b = multiply(a);
	printf("%d ", b);

	int A[5] = {1,2,3,4,5};
	char B[10] = "Hello";
	
	if(B[0] == 'H'){
		if(A[0] == '1')
			printf("Hello 1");
		else
			printf("Hello 2");
	}
	else
		printf("Not Hello");
	
	printf("Hello World");

	int num = 3;
	
	for(int i = 0; i<num; i++)
		printf("Hello");
	
	while(num > 0)
	{
		printf("Hello");
		num--;
	}

		for(int i = 0; i<num; i++)
	{
		for(int j = 0; j < num; j++)
			printf("Hello");
	}

	return 0;
}
