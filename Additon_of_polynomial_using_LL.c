#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int c,e;
	struct node *next;
}node;

typedef struct {
	node *start;
}LL;

void insertEnd(LL *l, int cc, int ee) {
	node *newnode,*p;
	newnode = (node *)malloc(sizeof(node));
	newnode->c = cc;
	newnode->e = ee;
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
	int i,n,cc,ee;
	printf("Enter No of terms : ");
	scanf("%d",&n);
	for(i = 0;i < n; i++) {
		printf("Enter Coefficient and Power\n");
		scanf("%d%d",&cc,&ee);
		insertEnd(l,cc,ee);
	}
}

void display(LL *l) {
	node *p;
	if(l->start == NULL){
		printf("No Polynomial\n");
		return;
	}
	p = l->start;
	while(p != NULL) {
		printf("%dx^%d  ",p->c,p->e);
		p = p->next;
	}
	printf("\n");
}

void addPoly(LL *l1,LL *l2,LL *l3) {
	node *p,*q;
	p = l1->start;
	q = l2->start;
	while(p != NULL && q != NULL) {
		if(p->e > q->e) {
			insertEnd(l3,p->c,p->e);
			p = p->next;
		} else if(q->e > p->e) {
			insertEnd(l3,q->c,q->e);
			q = q->next;
		} else {
			insertEnd(l3, p->c + q->c, p->e);
			p = p->next;
			q = q->next;
		}
	}
	while(p != NULL) {
		insertEnd(l3,p->c,p->e);
		p = p->next;
	}
	while(q != NULL) {
		insertEnd(l3,q->c,q->e);
		q = q->next;
	}
}

int main() {
	LL l1,l2,l3;
	l1.start = l2.start = l3.start = NULL ;
	printf("Enter First Polynomial :\n");
	read(&l1);
	printf("Enter Second Polynomial :\n");
	read(&l2);
	addPoly(&l1,&l2,&l3);
	printf("First Polynomail\n");
	display(&l1);
	printf("Second Polynomail\n");
	display(&l2);
	printf("Result Polynomail\n");
	display(&l3);
	return 0;
}

