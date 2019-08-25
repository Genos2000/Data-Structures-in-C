#include<stdio.h>
#define MAX 10

typedef struct
{
	int a[MAX];
	int front,rear;
}queue;

void EnqueueRight(queue *q,int ele)
{
	if(q->rear == MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	q->rear++;
	q->a[q->rear]=ele;
}

void EnqueueLeft(queue *q,int ele)
{
	if(q->front == -1)
	{
		printf("Queue Overflow\n");
		return;
	}
	q->a[q->front]=ele;
	q->front--;
}

int isempty(queue *q)
{
	if(q->rear == q->front)
		return 1;
	else 
		return 0;
}

int DequeueRight(queue *q) // from rear end
{
	int x;
	if(isempty(q))
		return -1;
	x=q->a[q->rear];
	q->rear--;
	return x;
}

int DequeueLeft(queue *q) // from front end
{
	int x;
	if(isempty(q))
		return -1;
	q->front++;
	x = q->a[q->front];
	return x;
}

void display(queue *q)
{
	int i;
	if(isempty(q))
	{
		printf("Queue Empty\n");
		return;
	}
	else
	{
		for(i=q->front+1;i<=q->rear;i++)
		printf("%d\t",q->a[i]);
		printf("\n");
	}
}

int main()
{
	int ch,ele;
	queue q;
	q.front = MAX/2;
	q.rear = MAX/2;
	while(1)
	{
			printf("1: Enqueue Right\n2: Enqueue Left\n3: Dequeue Right\n4: Dequeue Left\n5: Display\n6: Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		if(ch==6)
			break;
		switch (ch)
		{
			case 1:
				printf("Enter element to Enqueue\n");
				scanf("%d",&ele);
				EnqueueRight(&q,ele);
				break;
			case 2:
				printf("Enter element to Enqueue\n");
				scanf("%d",&ele);
				EnqueueLeft(&q,ele);
				break;
			case 3:
				ele=DequeueRight(&q);
				if(ele == -1)
					printf("Queue Underflow\n");
				else
					printf("Element dequeued = %d\n",ele);
				break;
			case 4:
				ele=DequeueLeft(&q);
				if(ele == -1)
					printf("Queue Underflow\n");
				else
					printf("Element dequeued = %d\n",ele);
				break;
			case 5:
				display(&q);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
