//Program on binary search using one comparison per loop/cycle

#include<stdio.h>

#define max 20

void read(int [],int);

void print(int [],int);

int binsrch(int [],int,int);

int main()
{
	int a[max];
	int n,key,r;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	printf("\n Enter array in ascending order : \n");
	read(a,n);
	
	printf("\n Array : \n");
	print(a,n);
	
	printf("\n Enter element to search : ");
	scanf("%d",&key);
	r=binsrch(a,n,key);
	
	if(r!=-999)
	printf("\n %d found at %d location",key,r);
	
	else
	printf("\n %d not found",key);
	
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	printf(" %d ",a[i]);
	printf("\n");
}

int binsrch(int a[],int n,int key)
{
	int low=0,high=n,mid;
	
	while(low<(high-1))
	{
		mid=(low+high)/2;
		
		if(key<a[mid])
		high=mid;
		
		else
		low=mid;
	}
	
	if(key==a[low])
	return low;
	
	else
	return -999;
}
