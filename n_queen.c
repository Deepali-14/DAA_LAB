#include<stdio.h>
#include<math.h>

int place(int k,int x[10],int l)
{
	int i;
	
	for( i=1;i<=(k-1);i++)
	{
		if(x[i]==l||(abs(x[i]-l)==abs(i-k)))
			return 0;
	}
	
	return 1;	
	
}
void nqueen(int k,int x[20],int n,int *c)
{
	int i,l;
	for(l=1;l<=n;l++)
	{
		if(place(k,x,l)==1)
		{
			x[k]=l;
			if(k==n)
			{
				*c=*c+1;
				printf("queens placed in columns: ");
				for(i=1;i<=n;i++)
					printf("%d ",x[i]);
				printf("\n");
			}			
			else
				nqueen(k+1,x,n,c);	
		}
	}
}


int main()
{
	int n,x[10],count=0;
	printf("enter no. of queen: ");
	scanf("%d",&n);
	nqueen(1,x,n,&count);
	printf("No. of solution: %d",count);
	return 0;
}
