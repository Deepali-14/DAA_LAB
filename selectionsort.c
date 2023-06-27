//Program on selection sort

#include<stdio.h>

#define max 20

void read(int[],int);

void print(int [],int);

void ssort(int [],int);

int main()
{
	int a[max],n;
	
	printf("\n Enter the number of elements in array : ");
	scanf("%d",&n);

    read(a,n);
    
    printf("\n Unsorted array : \n");
    print(a,n);
    
	ssort(a,n); 
	
	printf("\n Sorted array after selection sort : \n");
	print(a,n);
	
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	printf("\n Enter array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void ssort(int a[],int n)
{
	int i,j,min,t;
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		
		for(j=i+1;j<n;j++)
		  if(a[min]>a[j])
		    min=j;
		
		if(min!=i)
		{
			t=a[i];
		    a[i]=a[min];
		    a[min]=t;
		}
	}
}
