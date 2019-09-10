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

void read(LL *l) {
	int i,ele,n;
	printf("Enter No of terms : ");
	scanf("%d",&n);
	for(i = 0;i < n; i++) {
		printf("Enter Element\n");
		scanf("%d",&ele);
		insertEnd(l,ele);
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

void merge(LL *l1,LL *l2) {
	node *p;
	p=l1->start;
	while(p->next != NULL)
		p = p->next;
	p->next = l2->start;
	l2->start = NULL;
}

int main() {
	LL l1,l2;
	l1.start = l2.start = NULL;
	printf("Enter First Linked list\n");
	read(&l1);
	printf("Enter Second Linked list\n");
	read(&l2);
	printf("First Linked list : ");
	display(&l1);
	printf("Second Linked list : ");
	display(&l2);
	merge(&l1,&l2);
	printf("Merged Linked list : ");
	display(&l1);
	return 0;
}
