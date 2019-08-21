#include<stdio.h>
#define MAX 10

typedef struct
{
	int a[MAX];
	int front,rear;
}queue;

void enqueue(queue *q,int ele)
{
	if(q->rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	q->rear++;
	q->a[q->rear]=ele;
}

int isempty(queue *q)
{
	if(q->rear+1==q->front)
		return 1;
	else 
		return 0;
}

int dequeue(queue *q)
{
	int i,max,pos;
	if(isempty(q))
		return -1;
	max = q->a[q->front];
	pos = q->front;
	/* get the position of the largest element */
	for(i=q->front+1;i<=q->rear;i++)
	{
		if(q->a[i]>max)
		{
			max=q->a[i];
			pos=i;
		}
	}
	/* now left shift elements */
	for(i=pos;i<q->rear;i++)
		q->a[i]=q->a[i+1];
	q->rear--;
	return max;
}

int queuefront(queue *q)
{
	if(isempty(q))
		return -1;
	else 
		return q->a[q->front];
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
		for(i=q->front;i<=q->rear;i++)
			printf("%d\t",q->a[i]);
		printf("\n");
	}
}

int main()
{
	int ch,ele;
	queue q;
	q.front=0;
	q.rear=-1;
	while(1)
	{
		printf("1: Enqueue\n2: Dequeue\n3: QueueFront\n4 :Display\n5 :Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		if(ch==5)
			break;
		switch (ch)
		{
			case 1:
				printf("Enter element to Enqueue\n");
				scanf("%d",&ele);
				enqueue(&q,ele);
				break;
			case 2:
				ele=dequeue(&q);
				if(ele == -1)
					printf("Queue Underflow\n");
				else
					printf("Element dequeued = %d\n",ele);
				break;
			case 3:
				ele=queuefront(&q);
				if(ele == -1)
					printf("Queue Empty\n");
				else
					printf("Queue Front element = %d\n",ele);
				break;
			case 4:
				display(&q);
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
