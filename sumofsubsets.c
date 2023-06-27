#include<stdio.h>

#define max 20

void sumofsub(int s, int k, int r, int m, int x[max], int w[max], int n, int *c) //s,1,r,m,x,w,n,&count
{
	int i;
	
	x[k]=1;
	
	if(s+w[k]==m)
	{
		*c=*c+1;
		printf("\n Solution : \t");
		for(i=1; i<=n; i++)
			printf("  %d  ",x[i]);
		printf("\n");
	}
			
	else if(s+w[k]+w[k+1]<=m)
		sumofsub(s+w[k],k+1,r-w[k],m,x,w,n,c);
		
	if((s+r-w[k]>=m) && (s+w[k+1]<=m))
	{
		x[k]=0;
		sumofsub(s,k+1,r-w[k],m,x,w,n,c);
	}
}

void main()
{
	int n,m,w[max],x[max],i,s=0,r=0,count=0;
	
	printf("\n Enter number of objects : ");
	scanf("%d",&n);
	
	printf("\n Enter total weight : ");
	scanf("%d",&m);
	
	printf("\n Enter weights : ");
	for(i=1; i<=n; i++)
	{
		scanf("%d",&w[i]);
		r+=w[i];
		x[i]=0;
	}
		
	printf("\n Objects : \t");
	for(i=1; i<=n; i++)
		printf("  %d  ",i);
	printf("\n");
	
	printf("\n Weights : \t");
	for(i=1; i<=n; i++)
		printf("  %d  ",w[i]);
	printf("\n");
	
	sumofsub(s,1,r,m,x,w,n,&count);
	
	printf("\n No. of solutions : %d",count);
}
