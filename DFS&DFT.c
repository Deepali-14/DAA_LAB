//Program on DFS and DFT

#include<stdio.h>

#define max 20

void dfs(int [][max], int [], int, int);

void dft(int [][max], int);

int main()
{
	int graph[max][max], n, ne, t1, t2, i, j;
	
	printf("\n Enter number of vertices : ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			graph[i][j]=0;
			
	printf("\n Enter number of edges : ");
	scanf("%d", &ne);
	
	for(i=1; i<=ne; i++)
	{
		printf("\n Enter the first terminal vertex of %d edge : ",i);
		scanf("%d", &t1);
		
		printf("\n Enter the second terminal vertex of %d edge : ",i);
		scanf("%d", &t2);
		
		graph[t1][t2]=1;
		graph[t2][t1]=1;
	}
	
	printf("\n Adjacency matrix : \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf(" %d\t", graph[i][j]);
		printf("\n");
	}
	
	printf("\n Vertices visited as : ");	
	dft(graph,n);
	
	return 0;
}

void dft(int graph[][max], int n)
{
	int visited[max], i;
	
	for(i=1; i<=n; i++)
		visited[i]=0;
		
	for(i=1; i<=n; i++)
	{
		if(visited[i]==0)
		dfs(graph, visited, i, n);
	}
}

void dfs(int graph[][max], int visited[max], int v, int n)
{
	int w;
	
	visited[v]=1;
	printf(" %d ",v);
	
	for(w=1; w<=n; w++)
	{
		if(graph[v][w]==1 && visited[w]==0)
		{
			if(visited[w]==0)
				dfs(graph,visited,w,n);
		}
	}
}
