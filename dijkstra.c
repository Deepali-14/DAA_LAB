#include<stdio.h>
#define MAX 20

void djistra(int v,float cost[MAX][MAX],float d[MAX],int n);

void main()
{
	int n,visit,i,j,u,v,ne;
	float cost[MAX][MAX],d[MAX],c;
	
	printf("\nEnter total number of nodes:");
	scanf("%d",&n);
	
	printf("\nEnter total number of edges:");
	scanf("%d",&ne);
	
	for(i=1;i<=ne;i++)
	{
		for(j=1;j<=ne;j++)
			cost[i][j]=999999;
	}
	
	for(i=1;i<=ne;i++)
	{	
		printf("\n First terminal vertex for egde %d :  ",i);
		scanf("%d",&u);
		
		printf("\n Second terminal vertex  for egde %d :  ",i);
		scanf("%d",&v);
		
		printf("\ncost of egde %d :  ",i);
		scanf("%f",&c);
		
		cost[u][v]=c;
	}
	
	
	
	printf("\nEnter the source vertex:");
	scanf("%d",&visit);
	
	djistra(visit,cost,d,n);
	
	printf("\n----shortest path---");
	
	for(i=1;i<=n;i++)
		if(i!=visit)
			printf("\n%d->%d, length=%f",visit,i,d[i]);
}

void djistra(int v,float cost[MAX][MAX],float d[MAX],int n)
{
	int u,i,num,w,s[MAX],min;
	
	for(i=1;i<=n;i++)
	{
		s[i]=0;
		d[i]=cost[v][i];
	}
	
	s[v]=1;
	d[v]=0;
	num=2;
	
	for(num=2;num<=n;num++)
	{
		min=9999;
		s[u]=1;
		
		for(w=1;w<=n;w++)
			if(d[w]<min && !s[w])
			{
				min=d[w];
				u=w;
			}
		num++;
		for(w=1;w<=n;w++)
			if(((d[u]+cost[u][w])<d[w]) && !s[w])
				d[w]=d[u]+cost[u][w];
	}
}
