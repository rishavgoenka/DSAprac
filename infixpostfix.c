#include<stdio.h>
#include<conio.h>
char Stack[20];
int top = -1;
void Push(char x)
{
    Stack[++top] = x;
}
char Pop()
{
    if(top == -1)
	return -1;
    else
	return Stack[top--];
}
int Priority(char x)
{
    if(x == '(')
	return 0;
    if(x == '+' || x == '-')
	return 1;
    if(x == '*' || x == '/')
	return 2;
    if(x == '^')
	return 3;
}
void main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression:");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
	if(isalnum(*e))
	    printf("%c",*e);
	else if(*e == '(')
	    Push(*e);
	else if(*e == ')'||*e=='\0')
	{
	    while((x = Pop()) != '(')
		printf("%c", x);
	}
	else
	{
	    while(Priority(Stack[top]) >= Priority(*e))
		printf("%c",Pop());
	    Push(*e);
	}
	e++;
    }
    while(top != -1)
    {
	printf("%c",Pop());
    }
    getch();
}