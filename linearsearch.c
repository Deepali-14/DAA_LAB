//Program on linear search

#include<stdio.h>

#define max 20

void read(int [],int);

void print(int [],int);

void lsearch(int [],int,int);

int main()
{
	int a[max];
	int n,key;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	read(a,n);
	
	print(a,n);
	
	printf("\n Enter element to search : ");
	scanf("%d",&key);
	
	lsearch(a,n,key);
	
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	printf("\n Enter elements: \n");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
	
	printf("\n Array : \n");
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	printf("\n");
}

void lsearch(int a[],int n,int x)
{
	int i,flag=0;
	
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		{
			printf("\n %d found at location %d",x,i);
		    flag++;
		}
	}
	
	if(flag!=0)
	printf("\n %d found %d times",x,flag);
	
	else
	printf("\n %d not found",x);
}
