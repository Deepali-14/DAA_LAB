//Program on element and parent array in sets taking each element as root

#include<stdio.h>

#define max 25

int main()
{
	int p[max];
	int i,n;
	
	printf("\n Enter number of elements in the set : ");
	scanf("%d",&n);
	
	printf("\n Each element is itself a root node having value in parent array as -1\n");
	for(i=1;i<=n;i++)
		p[i]=-1;
	
	printf("\n Element array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",i);
	
	printf("\n Parent array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",p[i]);
	
	return 0;
}
