#include<stdio.h>
#define MAX 5

typedef struct
{
	int a[MAX];
	int front,rear;
	int count;  /* to get the count of elements in queue */
}cqueue;

void enqueue(cqueue *q,int ele)
{
	if(q->count==MAX)
	{
		printf("Circular queue overflow\n");
		return;
	}
	q->count++;
	q->rear=(q->rear+1)%MAX;  
	q->a[q->rear]=ele;
}

int isempty(cqueue *q)
{
	if(q->count==0)
		return 1;
	else
		return 0;
}

int dequeue(cqueue *q)
{
	int x;
	if(isempty(q))
		return -1;
	q->count--;
	x=q->a[q->front];
	q->front=(q->front+1)%MAX;
	return x;
}

int queuefront(cqueue *q)
{
	if(isempty(q))
		return -1;
	else
		return q->a[q->front];
}

void display(cqueue *q)
{
	int i;
	if(isempty(q))
	{
		printf("Queue Underflow\n");
		return;
	}
	i=q->front;
	while(1)
	{
		printf("%d\t",q->a[i]);
		if(i==q->rear)
			break;
		i=(i+1)%MAX;
	}
	printf("\n");
}


int main()
{
	int ch,ele;
	cqueue q;
	q.front=0;
	q.rear=MAX-1;
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
