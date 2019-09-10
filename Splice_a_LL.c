#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef struct {
	node *start;
}LL;

void insertEnd(LL *l, int ele) {
	node *newnode,*p;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = ele;
	newnode->next = NULL;
	
	if(l->start == NULL) 
		l->start = newnode;
	else {
		p = l->start;
		while(p->next != NULL)
			p = p->next;
			p->next = newnode;
	}
}

void display(LL *l) {
	node *p;
	if(l->start == NULL) {
		printf("Linked list is Empty\n");
		return;
	}
	p = l->start;
	while(p != NULL) {
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

void splice(LL *l1,LL *l2, int ele) {
	node *p;
	if(ele == l1->start->data) {
		// if ele is the start element
		l2->start = l1->start;
		l1->start = NULL;
		return;
	}
	/* search for the ele node */
	p = l1->start;
	while(p->next != NULL) {
		if(ele == p->next->data) {
			break;
		}
		else
			p = p->next;
	}
	//here even if ele not found then l2->start will be at NULL
	l2->start = p->next;
	p->next = NULL;
}

int main() {
	LL l1,l2;
	int n,ele,i;
	l1.start = NULL;
	l2.start = NULL;
	printf("Enter No of element in First linked list\n");
	scanf("%d",&n);
	printf("Enter elements of First linked list\n");
	for(i = 0;i < n;i++) {
		printf("Enter %d element\n",(i+1));
		scanf("%d",&ele);
		insertEnd(&l1,ele);
	}
	printf("First Linked list :");
	display(&l1);
	printf("Enter value from where to split\n");
	scanf("%d",&ele);
	splice(&l1,&l2,ele);
	printf("After Spliting\n");
	printf("First list\n");
	display(&l1);
	printf("Second list\n");
	display(&l2);
	return 0;
}
