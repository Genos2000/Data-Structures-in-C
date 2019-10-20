#include<stdio.h>
#include<stdlib.h>
#define N 4

typedef struct
{
	int row;
	int col;
}position;

typedef struct node
{
	position *pos;
	struct node *next;
}node;

typedef struct
{
	node *start;
}stack;

void push(stack *s,position *pos)
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->pos=pos;
	newrec->next=s->start;
	s->start=newrec;
}

position* pop(stack *s)
{
	node *p;
	if(s->start==NULL)
	{
		return NULL;
	}
	p=s->start;
	s->start=s->start->next;
	return p->pos;
}

void display(int board[][50],int boardsize)
{
	int i,j;
	for(i = 1; i <= boardsize; i++)
	{
		for(j = 1; j <= boardsize; j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
}

void printline(int startchar, int endchar, char line[], int boardsize)
{
	int i;
	printf("%c",startchar);
	for(i = 1; i <= boardsize ; i++)
	{
		if(i == boardsize)
		{
			printf("%c%c%c",205,205,205);
			break;
		}
		printf("%s",line);
	}
	printf("%c\n",endchar);
}

void drawgrid(int board[][50], int boardsize)
{
	int x,y;
	/* 201 for starting of topline, 187 for ending of topline
	   204 is start of middleline and 185 is end of middleline
	   200 is start is of bottomline and 188 is end of bottomline*/
	char topl[25]={205,205,205,203};
	char midl[25]={205,205,205,206};
	char bottoml[25]={205,205,205,202};
	printf("\n");
	printline(201,187,topl,boardsize);
	for(x = 1; x <= boardsize; x++)
	{
		for(y = 1; y <= boardsize; y++)
		{ 
			if(y == 1)
				printf("%c",186);
			if(board[x][y] == 1)
				printf(" Q");
			else
				printf("  ");
			printf(" %c",186);
		}
		printf("\n");
		if (x < boardsize)
		{
			printline(204,185,midl,boardsize);
		}
	}
	printline(200,188,bottoml,boardsize);
}

void fillboard(stack *s, int boardsize)
{
	int row;
	int col;
	position *pos;
	row = 1;
	col = 0;
	int board[50][50] = {0}; //initialize all values to 0;
	while(row <= boardsize)
	{
		while(col <= boardsize && row <= boardsize)
		{
			col++;
			if(!guarded(board, row, col,boardsize))
			{
				board[row][col] = 1;
				pos = (position *)malloc(sizeof(position));
				pos->row = row;
				pos->col = col;
				push(s,pos);
				row++;
				col = 0;
			}
			while(col >= boardsize)
			{
				pos = pop(s);
				row = pos->row;
				col = pos->col;
				board[row][col] = 0;
				free(pos);
			}
		}
	}
	//drawgrid(board,boardsize); if windows user.
	display(board,boardsize);
}

int guarded(int board[][50], int checkrow, int checkcol, int boardsize)
{
	int row;
	int col;
	col = checkcol;
	// checks column
	for(row = 1; row <= checkrow; row++)
	{
		if(board[row][col] == 1)
			return 1;
	}
	//checks diagonal in right
	for(row = checkrow - 1, col = checkcol + 1; row > 0 && col <= boardsize; row--, col++)
	{
		if(board[row][col] == 1)
			return 1;
	}
	// checks diagonal in left
	for(row = checkrow - 1 , col = checkcol -1; row > 0 && col > 0; row--, col --)
	{
		if(board[row][col] == 1)
			return 1;
	}
	return 0;
}

int main()
{
	int boardsize;
	stack s;
	s.start = NULL;
	int size;
	while(1)
	{
	printf("\nWelcome to N Queens.\n");
	printf("You may select a boardsize greater than 3 and then this program will postion\na queen in each row such that no queen attacks each other.\n");
	printf("Note: There are no solution for boardsize less then 4 x 4\n");
	printf("Please enter the board size: ");
	scanf("%d",&boardsize);
	if(boardsize < 4)
	{	
		printf("cls");
		printf("\nPlease enter boardsize greater than or equal 4\n");
		continue;
	}
	else
		break;
	}	
	fillboard(&s, boardsize);
	return 0;
}
