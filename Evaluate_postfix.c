#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

typedef struct
{
	int a[MAX];
	int top;
}stack;

void push(stack *s, int ele)
{
	s->top++;
	s->a[s->top] = ele;
}

int pop(stack *s)
{
	if (s->top==-1)
	{
		printf("Invalid Expression");
		exit(0);	
	}
	int x;
	x=s->a[s->top];
	s->top--;
	return x;
}

 int EvaluatePostfix(char post[])
 {
	stack s;
	s.top=-1;
	int op1,op2,i,v;
	char x;
	for(i=0;i<strlen(post);i++)
	{
		x=post[i];
		if(isdigit(x))
		/*Substracting ascii value of operand by ascii value of zero and type casting the result into an integer.*/
			push(&s,(int)x-'0');
		else
		{ //x is operator.
			op2=pop(&s);  /*first pop goes to the second operand. */
			op1=pop(&s);  /*second pop goes to the first operand. */
			switch(x)
			{
				case '+': v = op1 + op2 ; break;
				case '-': v = op1 - op2 ; break;
				case '*': v = op1 * op2 ; break;
				case '/': v = op1 / op2 ; break;
				case '%': v = op1 % op2 ; break;
				default : printf("Invalid Expression"); exit(0);
			}
			/* push the value obtained above onto the stack */
			push(&s,v);					
		}
	}
	return pop(&s);
 }
 
 int main()
 {
	char post[10];
	printf("Enter Postfix Expression\n");
	gets(post);
	printf("Result = %d", EvaluatePostfix(post));
	return 0;
 }

