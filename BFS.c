#include<stdio.h>
#define MAX 10
void insertq(int);
int deleteq();
void adjacency(int a[10][10],int);
void BFT(int [10][10],int);
void BFS(int [10][10],int,int [10],int);
int q[10];
int F=-1,R=-1;

int q_underflow()
{
	if(F=R=-1)
		return 1;
	else
		return 0;	
}

void main()
{
	
	int a[10][10];
	int ne,nv,i,j;

	printf("Enter the total no. of vertices: ");
	scanf("%d",&nv);
	
	printf("Enter the total no. of edges: ");
	scanf("%d",&ne);
	
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=nv;j++)
			a[i][j]=0;
	}
	
	adjacency(a,ne);
	
	BFT(a,nv);
}

void adjacency(int a[10][10],int ne)
{
	int i,j,k;
	for(k=1;k<=ne;k++)
	{	
		printf("\n First terminal vertex for egde %d :  ",k);
		scanf("%d",&i);
		
		printf("\n Second terminal vertex  for egde %d :  ",k);
		scanf("%d",&j);
		
		a[i][j]=a[j][i]=1;
	}
	
}

void insertq(int x)
{
	if(R==-1)
		F=R=0;
	else
		R++;
	q[R]=x;	
			
}

int deleteq()
{
	int x;
	x=q[F];
	
	if(F==R)
		F=R=0;
	else
		F++;	
	return x;	
}

void BFS(int a[10][10],int v,int visited[10], int nv)
{
	int u=v;
	int j,w;
	visited[v]=1;
	printf("\n visited vertex::");
	printf("%d\t",v);
	while(1)
	{
		for(w=1;w<=nv;w++)
		{
			if(a[w][u]==1)
			{
				if(visited[w]==0)
				{
					insertq(w);
					visited[w]=1;
					printf("%d\t",w);
				}
			}	
		}
		
		if(q_underflow())
			return;
	u=deleteq();	 		
	}	
}

void BFT(int a[10][10],int nv)
{
	int i,j,visited[10];
		for(i=1;i<=nv;i++)
			visited[i]=0;
			
		for(i=1;i<=nv;i++)
		{
			if(visited[i]==0)
				BFS(a,i,visited,nv);	
		}	
}

