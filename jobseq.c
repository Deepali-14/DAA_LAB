//Program on job sequencing

#include<stdio.h>

#define max 20

int JS(int [],int [], int);

void ssort(int [], float [], int [], int);

void main()
{
	float p[max];
	int n, i, d[max], j[max], r;
	
	printf("\n Enter total number of jobs to be done : ");
	scanf("%d",&n);
	
	printf("\n Enter profits in decreasing order \n");

	for(i=1; i<=n; i++)
		j[i]=i;
	
	printf("\n Enter profits : ");
	for(i=1; i<=n; i++)
		scanf("%f",&p[i]);
		
	printf("\n Enter deadlines : ");
	for(i=1; i<=n; i++)
		scanf("%d",&d[i]);
		
	ssort(j,p,d,n);
	
	printf("\n Jobs : \t");
	for(i=1; i<=n; i++)
		printf("J%d\t",j[i]);
		
	printf("\n Profits : \t");
	for(i=1; i<=n; i++)
		printf("%.2f\t",p[i]);
		
	printf("\n Deadlines : \t");
	for(i=1; i<=n; i++)
		printf("%d\t",d[i]);
		
	r=JS(d,j,n);
	
	printf("\n %d",r);
}

int JS(int d[max], int j[max], int n)
{
	int k,i,r,q;
	
	d[1]=j[1]=0;
	j[2]=1;
	k=1;
	
	for(i=3; i<=n; i++)
	{
		r=k;
		
		while((d[j[r]] > d[i] && d[j[r]] != r))
			r=r-1;
			
		if((d[j[r]] <= d[i] && d[i] > r))
		{
			for(q=k; q>=r+1; q--)
				j[q+1]=j[q];
				
			j[r+1]=i;
			k=k+1;
		}
	}
	return k;
}

void ssort(int j[max], float p[max], int d[max], int n)
{
	int i,k,min,t;
	
	for(i=1;i<n;i++)
	{
		min=i;
		
		for(k=i+1;k<=n;k++)
		  if(p[min]<p[k])
		    min=k;
		
		if(min!=i)
		{
			t=p[i];
		    p[i]=p[min];
		    p[min]=t;
		    
		    t=j[i];
		    j[i]=j[min];
		    j[min]=t;
		    
		    t=d[i];
		    d[i]=d[min];
		    d[min]=t;
		}
	}
}
