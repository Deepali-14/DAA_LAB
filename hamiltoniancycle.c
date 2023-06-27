#include<stdio.h>
#define MAX 20

void nextvalue(int k,int a[MAX][MAX],int n,int x[MAX],int *c)
{
	int j;
	while(1)
	{
		x[k]=((x[k]+1)%(n+1));
		
		if(x[k]==0)
			return;
		if(a[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<=k-1;j++)
				if(x[j]==x[k])
					break;
	
		if(j==k)
			if((k<n)||((k==n)&&a[x[n]][x[1]]!=0))
				return;
		}
	}
}

void hamiltonian(int k,int a[MAX][MAX],int n,int x[MAX],int *c)
{
	int i;
	while(1)
	{
		nextvalue(k,a,n,x,c);
		if(x[k]==0)
			return;
		if(k==n)
		{
			*c=*c+1;
			printf("Possible hamiltonian cycle %d is: ",*c);
			for(i=1;i<=n;i++)
				printf("%d ",x[i]);
			printf("1 \n");
		}	
		
		else
			hamiltonian(k+1,a,n,x,c);
	}
}



int main()
{
	int a[MAX][MAX],n,ne,i,u,v,j,x[MAX],count=0;
	
	printf("Enter the total no. of vertices: ");
	scanf("%d",&n);
	
	printf("Enter the total no. of edges: ");
	scanf("%d",&ne);

	for(i=0;i<MAX;i++)
	{
		x[i]=0;
		for(j=0;j<MAX;j++)
			a[i][j]=0;
			
	}
		
	for(i=1;i<=ne;i++)
	{	
		printf("\n First terminal vertex for egde %d :  ",i);
		scanf("%d",&u);
		
		printf("\n Second terminal vertex  for egde %d :  ",i);
		scanf("%d",&v);
		
		a[u][v]=a[v][u]=1;
	}
	
	x[1]=1;
	
	hamiltonian(2,a,n,x,&count);
	printf("No. of solution: %d",count);
	
	return 0;
}
