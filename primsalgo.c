#include<stdio.h>

#define max 20

void prim(float cost[][max],int n1,int t[][max],float *);
	
void main()
{
	float cost[max][max],w,mincost=0.0f;
	int t[max][max], n1, n2, ft1, ft2, i, j;
	
	printf("\n Enter number of vertices : ");
	scanf("%d", &n1);
	
	printf("\n Enter number of edges : ");
	scanf("%d", &n2);
	
	for(i=1; i<=n1; i++)
		for(j=1; j<=n1; j++)
		{
			if(i==j)
				cost[i][j]=0.0f;
			
			else
				cost[i][j]=999.0f;
		}
	
	for(i=1; i<=n2; i++)
	{
		printf("\n Enter the first terminal vertex of %d edge : ",i);
		scanf("%d", &ft1);
		
		printf("\n Enter the second terminal vertex of %d edge : ",i);
		scanf("%d", &ft2);
		
		printf("\n Enter weight of %d edge : ",i);
		scanf("%d", &w);
		
		cost[ft1][ft2]=cost[ft2][ft1]=w;
	}
	
	printf("\n Adjacency matrix : \n");
	for(i=1; i<=n1; i++)
	{
		for(j=1; j<=n1; j++)
			printf(" %d\t", cost[i][j]);
		printf("\n");
	}
	
	prim(cost,n1,t,&mincost);
	
	printf("\n The minimum cost spanning tree edges : \n");
	
	for(i=n1; i<=n1-1; i++)
	{
		printf("edge(%d\t,%d) cost=%f", t[i][1], t[i][2], cost[t[i][1]][t[i][2]]);
		printf("\n");
	}
	
	printf("\n Cost of mst=%0.2f",mincost);
}

void prim(float cost [][max], int n1, int t[20][20], float *mincost)
{
	int i,j,k,l,v,near[20];
	float min;
	
	min=999.0f;
	
	for(i=1; i<=n1; i++)
		for(j=1; j<=n1; j++)
			if(i!=j && min>cost[i][j])
			{
				min=cost[i][j];
				k=i;
				l=j;
			}
			
	t[1][1]=k;
	t[1][2]=l;
	*mincost=*mincost+cost[k][l];
	
	for(i=1; i<=n1; i++)
	{
		if(cost[i][k]<cost[i][j])
			near[i]=k;
			
		else
			near[i]=l;
	}
	
	near[k]=0;
	near[l]=0;
	
	for(i=2; i<=n1-1; i++)
	{
		min=999.0f;
		
		for(j=1; j<=n1; j++)
		{
			if(near[j]!=0 && cost[j][near[j]]<min)
			{
				min=cost[j][near[j]];
				v=j;
			}
		}
		
		*mincost=*mincost+min;
		t[i][1]=v;
		t[i][2]=near[v];
		
		near[v]=0;
		
		for(k=1; k<=n1; k++)
		{
			if(near[k]!=0 && cost[k][v]<cost[k][near[k]])
				near[k]=v;
		}
	}
}
