#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;
}node;

typedef struct 
{
	node *root;
}tree;

node* create()
{
	int x;
	node *p;
	printf("\nEnter data(-1 for no data)\n");
	scanf("%d",&x);
	if(x == -1)
		return NULL;
	p = (node *)malloc(sizeof(node));
	p->data = x;
	printf("Enter left child of %d: ",x);
	p->left = create();
	printf("Enter right child of %d: ",x);
	p->right = create();
	return p;
}

void inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		printf("%d ",x->data);
		inorder(x->right);
	}
}

void preorder(node *x)
{
	if(x!=NULL)
	{
		printf("%d ",x->data);
		preorder(x->left);
		preorder(x->right);
	}
}

void postorder(node *x)
{
	if(x!=NULL)
	{
	    postorder(x->left);
		postorder(x->right);
		printf("%d ",x->data);
	}
}

int main()
{
	tree t;
	int ch,ele;
	t.root=NULL;
	
	while(1)
	{
	printf("1: Create\n2: Inorder\n3: Preorder\n4: Postorder\n5: Exit\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		if(ch == 5)
			break;
		switch(ch)
		{
			case 1:
				t.root = create();
			    break;
			case 2:
				printf("Inorder: ");
			    inorder(t.root);
			    printf("\n");
			    break;
			case 3:
				printf("Preorder: ");
		        preorder(t.root);
		        printf("\n");
		        break;
			case 4:
				printf("Postorder: ");
			    postorder(t.root);
			    printf("\n");
			    break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}


