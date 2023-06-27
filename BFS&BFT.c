//Program on BFS and BFT

#include<stdio.h>

#define max 20

void bft(int [][max], int);

void bfs(int [][max], int [], int, int);

int dequeue(int [], int *, int *);

void enqueue(int [], int *, int *, int, int);

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
	bft(graph,n);
	
	return 0;
}

void bft(int graph [][max], int n)
{
	int visited[max],i;
	
	for(i=1; i<=n; i++)
 		visited[i]=0;
 		
 	for(i=1; i<=n; i++)
 		if(visited[i]==0)
 			bfs(graph, visited, i, n);
}

void bfs(int graph[][max], int visited[max], int i, int n)
{
	int queue[max];
	int u=i, w, r=-1, f=-1, x;
	
	
	visited[i]=1;
	printf(" %d ",i);
	
	do
	{
		for(w=1; w<=n; w++)
		{
			if(graph[u][w]==1 && visited[w]==0)
			{
				enqueue(queue, &f, &r, n, w);
				visited[w]=1;
				printf(" %d ",w);
			}
		}
		
		if(f==-1 && r==-1 || r==f-1)
			return;
			
		else
			u=dequeue(queue, &f, &r);
	}while(1);
}

void enqueue(int queue[], int *f, int *r, int n, int w)
{
	if(*r==n-1)
		return;
		
	if(*r==-1)
	{
		*r=*f=0;
		queue[*r]=w;
	}
	
	else
	{
		(*r)++;
		queue[++(*r)]=w;
	}
}

int dequeue(int queue[], int *f, int *r)
{
	int x;
	
	if(*f==-1)
		return;
		
	else
	{
		x=queue[*f--];
		if(*f==*r)
	  	*f=*r=-1;
	   	else
	   	(*f)++;
	   	
		return x;
	}
}
