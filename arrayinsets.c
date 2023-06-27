//Program on element array and parent array in sets

#include<stdio.h>

#define max 20

int main()
{
	int p[max];
	int n,i,j,s,e,ne,rt;
	
	printf("\n Enter total number of elements in the entire collection of disjoint sets : ");
	scanf("%d",&n);
	
	printf("\n Enter total number of disjoint sets : ");
	scanf("%d",&s);
	
	for(i=1;i<=s;i++)
	{
		printf("\n Enter total number of elements in set %d : ",i);
		scanf("%d",&ne);
		
		for(j=1;j<=ne;j++)
		{
			printf("\n Enter element %d : ",j);
			scanf("%d",&e);
			
			if(j==1)
			{
				p[e]=-1;
				rt=e;
			}
			else
				p[e]=rt;
		}
	}
	
	printf("\n Element array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",i);
	
	printf("\n Parent array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",p[i]);
	
	return 0;
}
