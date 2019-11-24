#include<stdio.h>

int n;
int adj[15][15]={0},visited[15]={0};

void dfs(int node)
{
	int i;
	visited[node]=1;
	printf("%d ",node+1);
	for(i=0;i<n;i++)
	{
		/* if edge exists and vertex isnt visited traverse to next vertex */
		if(adj[node][i]==1 && visited[i]==0)
			dfs(i);
	}
}

int main()
{
	int e,i,v1,v2,node;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter number of edges\n");
	scanf("%d",&e);
	printf("Enter edge Details\n");
	for(i=0;i<e;i++)
	{
		printf("Enter edge\n");
		/* for edge between vertex 1 and 2 enter "1 space 2" */
		scanf("%d%d",&v1,&v2);
		adj[v1-1][v2-1]=adj[v2-1][v1-1]=1;
	}
	printf("Enter starting vertex\n");
	scanf("%d",&node);
	dfs(node-1);
	return 0;
}
