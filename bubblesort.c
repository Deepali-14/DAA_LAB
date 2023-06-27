//Program on bubble sort

#include<stdio.h>

#define max 20

void read(int [],int);

void print(int [],int);

void bsort(int [],int);

int main()
{
	int a[max],n;
	
	printf("\n Enter the number of elements in array : ");
	scanf("%d",&n);
	
	read(a,n);
	
	printf("\n Unsorted array : \n");
    print(a,n);
    
    bsort(a,n);
    
    printf("\n Sorted array after bubble sort : \n");
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

void bsort(int a[],int n)
{
    int i,j,t;
    
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
      	    if(a[j]>a[j+1])
      	    {
      		    t=a[j];
      		    a[j]=a[j+1];
      		    a[j+1]=t;
		    }
}
