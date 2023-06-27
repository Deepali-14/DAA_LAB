#include<stdio.h>
#define MAX 20

void nextvalue(int k,int a[MAX][MAX],int n,int x[MAX],int m,int *c)
{
	int j,i;
	while(1)
	{
		x[k]=((x[k]+1)%(m+1));
		
		if(x[k]==0)
			return;
			
		for(j=1;j<=n;j++)
		{
			if((a[k][j]!=0)&&(x[k]==x[j]))
				break;
		}
		if(j==(n+1))
			return;
	}
}
void mcolouring(int k,int a[MAX][MAX],int n,int x[MAX],int m,int *c)
{
	int i;
	while(1)
	{
		nextvalue(k,a,n,x,m,c);
		if(x[k]==0)
			return;
		if(k==n)
		{
			*c=*c+1;
			printf("solution: ");
			for(i=1;i<=n;i++)
				printf("%d ",x[i]);
			printf("\n");
		}	
		
		else
			mcolouring(k+1,a,n,x,m,c);
	}
}



void main()
{
	int a[MAX][MAX],n,ne,m,i,j,k,l,x[MAX],count=0;
	
	printf("Enter the total no. of vertices: ");
	scanf("%d",&n);
	
	printf("Enter the total no. of edges: ");
	scanf("%d",&ne);
	
	printf("Enter no of colours: ");
	scanf("%d",&m);

	for(k=0;k<MAX;k++)
		for(l=0;l<MAX;l++)
			a[k][l]=0;
		
	for(k=0;k<MAX;k++)
		x[k]=0;
		
	for(k=1;k<=ne;k++)
	{	
		
		
		printf("\n First terminal vertex for egde %d :  ",k);
		scanf("%d",&i);
		
		printf("\n Second terminal vertex  for egde %d :  ",k);
		scanf("%d",&j);
		
		a[i][j]=a[j][i]=1;
	}
	
	mcolouring(1,a,n,x,m,&count);
	printf("No. of solution: %d",count);
}
