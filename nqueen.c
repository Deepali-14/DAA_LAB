#include<stdio.h>

#include<math.h>

#define max 20

int place(int k, int x[max], int i)
{
	int j;
	
	for(j=1; j<=k-1; j++)
		if((x[j]==i) || abs(x[j]-i)==abs(j-k))
			return 0;
	
	return 1;	
}

void nqueens(int k, int x[max], int n, int *c)
{
	int i,j;
	
	for(i=1; i<=n; i++)
	{
		if(place(k,x,i))
		{
			x[k]=i;
			
			if(k==n)
			{
				*c=*c+1;
				printf("\n Queens placed in columns : \n");
				for(j=1; j<=n; j++)
					printf("%d\t",x[j]);
				printf("\n");
			}
			else
				nqueens(k+1,x,n,c);
				
		}
	}
}
void main()
{
	int n, x[max], count=0;
	
	printf("\n Enter number of queens : ");
	scanf("%d",&n);
	
	nqueens(1,x,n,&count);
	
	printf("\n No. of solutions : %d",count);

}
