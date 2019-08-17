#include<stdio.h>
#define MAX 10

typedef struct
{
	int a[MAX];
	int top1,top2; 
}stack;

void push1(stack *s,int ele)
{
	if(s->top1+1==s->top2)
	{
		printf("Stack Overflow\n");
		return;
	}
	s->top1++;
	s->a[s->top1]=ele;		
}

void push2(stack *s,int ele)
{
	if(s->top1+1==s->top2)
	{
		printf("Stack Overflow\n");
		return;
	}
	s->top2--;
	s->a[s->top2]=ele;		
}

int isempty1(stack *s)
{
	if(s->top1==-1)
		return -1;
	return 0;
}

int isempty2(stack *s)
{
	if(s->top2==MAX-1)
		return -1;
	return 0;
}

int pop1(stack *s)
{
	int x;
	if(isempty1(s))
		return -1;
	x=s->a[s->top1];
	s->top1--;
	return x;
}

int pop2(stack *s)
{
	int x;
	if(isempty2(s))
		return -1;
	x=s->a[s->top2];
	s->top2++;
	return x;
}

int stacktop1(stack *s)
{
	if(isempty1(s))
		return -1;
	return s->a[s->top1];
}

int stacktop2(stack *s)
{
	if(isempty2(s))
		return -1;
	return s->a[s->top2];
}

void display1(stack *s)
{
	int i;
	if(isempty1(s))
	{
		printf("Stack 1 Underflow\n");
		return;
	}
	for(i=s->top1;i>=0;i--)
		printf("%d\n",s->a[i]);
}

void display2(stack *s)
{
	int i;
	if(isempty2(s))
	{
		printf("Stack 2 Underflow\n");
		return;
	}
	for(i=s->top2;i<MAX;i++)
		printf("%d\n",s->a[i]);
}

int main()
{
	stack s;
	int ch,ele;
	char sch;
	s.top1=-1;
	s.top2=MAX;
	while(1)
	{
		printf("F: First stack\nS: Second Stack\nE: Exit\n");
		fflush(stdin);
		printf("Enter stack choice\n");
		scanf("%c",&sch);
		if(sch=='E')
			break;
			
		if(sch=='F')
		{
			while(1)
			{	
				printf("Stack 1 Menu\n1.Push\n2.Pop\n3.Stacktop\n4.Display\n5.Exit\n");
				printf("Enter Choice : ");
				scanf("%d",&ch);
				if(ch==5)
					break;
		
				switch(ch)
				{
					case 1:
						printf("Enter Element : ");
						scanf("%d",&ele);
						push1(&s,ele); //passing the stack address as an argument to the push function
						break;
			
					case 2:
						ele=pop1(&s);
						if(ele==-1)
							printf("Stack 1 Underflow\n");
						else
							printf("Popped element = %d\n",ele);
						break;			
			
					case 3:
						ele=stacktop1(&s);
						if(ele==-1)
							printf("Stack 1 Underflow\n");
						else
							printf("Top of stack 1 = %d \n",ele);
						break;
					case 4:
						display1(&s);
						break;
					default:
						printf("Invalid choice \n");
				}
			}
		}
		else if(sch == 'S')
		{
			while(1)
			{	
				printf("Stack 2 Menu\n1.Push\n2.Pop\n3.Stacktop\n4.Display\n5.Exit\n");
				printf("Enter Choice : ");
				scanf("%d",&ch);
				if(ch==5)
					break;
		
				switch(ch)
				{
					case 1:
						printf("Enter Element : ");
						scanf("%d",&ele);
						push2(&s,ele); //passing the stack address as an argument to the push function
						break;
			
					case 2:
						ele=pop2(&s);
						if(ele==-1)
							printf("Stack 2 Underflow\n");
						else
							printf("Popped element = %d\n",ele);
						break;			
			
					case 3:
						ele=stacktop2(&s);
						if(ele==-1)
							printf("Stack 1 Underflow\n");
						else
							printf("Top of stack 1 = %d \n",ele);
						break;
					case 4:
						display2(&s);
						break;
					default:
						printf("Invalid choice \n");
				}
			}
		}
		else
			printf("Invalid stack choice\n");
	}
	return 0;
}
