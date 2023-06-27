#include<stdio.h>
#define MAX 20
void sum_of_subset(int s,int k,int r,int w[MAX],int x[MAX],int n,int m,int *c)
{
	int i;
	
	x[k]=1;
	
	if(s+w[k]==m)
	{
		*c=*c+1;
		printf("solution: ");
		for(i=1;i<=n;i++)
			printf("%d ",x[i]);
		printf("\n");
	}			
	else
		if(s+w[k]+w[k+1]<=m)
			sum_of_subset(s+w[k],k+1,r-w[k],w,x,n,m,c);	
			
	if((s+r-w[k]>=m)&&(s+w[k+1]<=m))
	{
		x[k]=0;
		
		sum_of_subset(s,k+1,r-w[k],w,x,n,m,c);	
	}
}


void main()
{
	int i,n,x[MAX],w[MAX],m,s=0,r=0,count=0;;

	printf("enter total no of weights: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("enter value %d: ",i);
		scanf("%d",&w[i]);
		
		r+=w[i];
		x[i]=0;
	}	
		
	printf("enter value of m: ");
	scanf("%d",&m);
	
	sum_of_subset(s,1,r,w,x,n,m,&count);
	printf("No. of solution: %d",count);
}
