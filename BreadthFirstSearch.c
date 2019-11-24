#include<stdio.h>

int n;
int adj[15][15]={0}, visited[15]={0};

/* using queue operations directly */
void bfs(int node)
{
	int q[20], front = -1,rear = -1, i, nd;
	/* nd is variable used to access queue elements */
	visited[node]=1;
	/* enqueue */
	q[++rear]=node;
	while(front!=rear)
	{
		/* dequeue */
		nd=q[++front];
		printf("%d ",nd+1);
		for(i=0;i<n;i++)
		{
			if(adj[nd][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				/* enqueue */
				q[++rear]=i;
			}
		}
	}
}
int main()
{
	int e,i,v1,v2,node;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter number of edges\n");
	scanf("%d",&e);
	printf("Enter edge details\n");
	for(i=0;i<e;i++)
	{
		printf("Enter edge\n");
		scanf("%d %d",&v1,&v2);
		adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
	}
	printf("Enter starting vertex\n");
	scanf("%d",&node);
	bfs(node-1);
	return 0;
}
