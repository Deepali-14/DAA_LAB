#include<stdio.h>
#define MAX 20

void Cost(int cost[MAX][MAX],int ne)
{
	int i,j,k;
	int c;
	
	for(k=1;k<=ne;k++)
	{	
		printf("\n First terminal vertex for egde %d :  ",k);
		scanf("%d",&i);
		
		printf("\n Second terminal vertex  for egde %d :  ",k);
		scanf("%d",&j);
		
		printf("\ncost of egde %d :  ",k);
		scanf("%d",&c);
		
		cost[i][j]=cost[j][i]=c;
	}
	
}

int prim(int cost[MAX][MAX],int nv,int t[MAX][3])
{
	int min_c;
	int near[MAX],k,l,i,j,m;
	
	int min=99999;
	
	 for(i=1;i<=nv;i++)
	 	for(j=1;j<i;j++)
	 		if(min>cost[i][j])
	 		{
			 	min=cost[i][j];
	 			k=i;
	 			l=j;
	 		}
		 
	 
	 min_c=cost[k][l];
	 t[1][1]=k;
	 t[1][2]=l;
	 
	for(i=1;i<=nv;i++)
		if(cost[i][k]<cost[i][l])
			near[i]=k;
		else
			near[i]=l;
	
	
	near[k]=near[l]=0;
	
	for(i=2;i<nv;i++)
	{
		min=9999;
		
		for(m=1;m<=nv;m++)
	 		if((near[m]!=0)&&(cost[m][near[m]]<min))
	 		{
			 	min=cost[m][near[m]];
	 			j=m;
	 		}
		 
		t[i][1]=j;
		t[i][2]=near[j];
		min_c=min_c+cost[j][near[j]];
		near[j]=0;
		
		for(k=1;k<=nv;k++)
		{
			if((near[k]!=0)&&(cost[k][near[k]]>cost[k][j]))
				near[k]=j;
		}
		
	}
	return min_c;
}

void main()
{
	int nv,ne,i,j,t[MAX][3];
	
	int cost[MAX][MAX],m;
	
	printf("Enter the total no. of vertices: ");
	scanf("%d",&nv);
	
	printf("Enter the total no. of edges: ");
	scanf("%d",&ne);
	
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=nv;j++)
		{
			if(i==j)
				cost[i][j]=0;
			else
				cost[i][j]=999;		
		}
	}
	
	Cost(cost,ne);
	
	m=prim(cost,nv,t);
	
	printf("\nmin cost=%d",m);
	
	for(i=1;i<=nv-1;i++)
		printf("\nedge : %d %d \n",t[i][1],t[i][2]);
			
}
