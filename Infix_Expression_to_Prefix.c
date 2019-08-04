#include<stdio.h>
#include<string.h>
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

char pop(stack *s)
{
	char x;
	x=s->a[s->top];
	s->top--;
	return x;
}

int isempty(stack *s)
{
	if(s->top == -1)
		return 1;
	else
		return 0;	
}

char stacktop(stack *s)
{
	return s->a[s->top];
}

void stringrev(char infix[])
{
	int i;
	/* reverse infix string and evaluate it same as the postfix expression*/
	strrev(infix);
	/* change '(' to ')' and vice versa */
	for(i = 0 ;i <= strlen(infix);i++)
	{
		if(infix[i]=='(')
			infix[i]=')';
		else if(infix[i]==')')
			infix[i]='(';
	}
}
/* rest function is same as postfix program*/
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

void convert(char infix[], char pre[])
{
	stack s;
	s.top=-1;
	int i=0,k=0;
	char x,ele;

	stringrev(infix);

	for(i = 0 ; i <= strlen(infix); i++)
	{
		x = infix[i];
		if(x == '(') 
	/* push left parenthesis into stack. */
			push(&s,x);
		else if(x == ')')
	/* if right parenthesis is found, pop stack and append to prefix expression until left parenthesis is found,
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
					pre[k++] = ele;
				}
			}
		}
		else if(isalnum(x))  
	/* if operand then append to prefix expression */
			pre[k++] = x;
		else if(isempty(&s)) 
	/* from here x is operator.push operator into stack if its empty. */	 
			push(&s,x);  
		else if(icp(x) > isp(stacktop(&s)))  
	/* if stack isnt empty and if precedence of incoming operator greater then stacktop, push into stack. */
			push(&s,x);
		else
		{
	/* if stacktop operator has greater precedence then pop stack and append until stacktop has lower precedence or until stack becomes empty.
	then push incoming operator into stack. */
			while((isempty(&s) == 0) && (icp(x) <= isp(stacktop(&s)))) 
			{
				ele = pop(&s);
				pre[k++] = ele;
			}
			push(&s,x);
		}
	}
	/* after the infix string ends, pop and append remaining stack elements, if any to prefix expression. */
		while(isempty(&s) == 0)
		{
			ele = pop(&s);
			pre[k++] = ele;
		}
		pre[k] = '\0'; //End of string
		/* Reverse the prefix expression to get the result */
		strrev(pre);
}

int main()
{
	char infix[50];
	char pre[50];
	printf("\nEnter infix expression \n");
	gets(infix);
	convert(infix,pre);
	printf("Prefix expression = %s \n", pre);
	return 0;
}
