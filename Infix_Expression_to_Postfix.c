#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

typedef struct
{
	char a[MAX];
	int top;
}stack;

void push(stack *s, char ele)
{
	s->top++;
	s->a[s->top] = ele;
}

int isempty(stack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;	
}

char pop(stack *s)
{
	char x;
	x=s->a[s->top];
	s->top--;
	return x;
}

char stacktop(stack *s)
{
	return s->a[s->top];
}

int precedence(char x)
{
	switch(x)
	{
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '%':
		case '/': return 2; 
	}
	return -1;
}

void convert(char infix[], char post[])
{
	stack s;
	s.top=-1;
	int i=0,k=0;
	char x,ele;
	
	for(i = 0 ; i <= strlen(infix); i++)
	{
		x = infix[i];
		if(x == '(') 
	/* push left parenthesis into stack. */
			push(&s,x);
		else if(x == ')')
	/* if right parenthesis is found, pop stack and append to postfix expression until left parenthesis is found,
			dont append parenthesis. */
		{
			while(1)
			{
				if(isempty(&s)==1)
				{
					printf("Please check your expression.");
					exit(0);
				}
				else
				{
					ele = pop(&s);
					if(ele == '(')  
						break;
					post[k++] = ele;
				}
			}
		}
		else if(isalnum(x))
	/* if operand then append to postfix expression */
			post[k++] = x;
		else if(isempty(&s)) 
	/* from here assuming x is operator.push operator into stack if its empty. */	 
			push(&s,x);  
		else if(precedence(x) > precedence(stacktop(&s)))  
	/* if stack isnt empty and if precedence of incoming operator greater than stacktop, push into stack. */
			push(&s,x);
		else
		{
	/* if stacktop operator has greater precedence then pop stack and append until stacktop has lower precedence or until stack becomes empty.
	then push incoming operator into stack. */
			while((isempty(&s) == 0) && (precedence(x) <= precedence(stacktop(&s)))) 
			{
				ele = pop(&s);
				post[k++] = ele;
			}
			push(&s,x);
		}
	}
	/* after the infix string ends, pop and append remaining stack elements, to postfix expression. */
		while(isempty(&s) == 0)
		{
			ele = pop(&s);
			post[k++] = ele;
		}
		post[k] = '\0'; //Ends the string
}

int main()
{
	char infix[50];
	char post[50];
	printf("\nEnter infix expression \n");
	gets(infix);
	convert(infix,post);
	printf("Postfix expression = %s \n", post);
	return 0;
}
