//Program on quick sort

#include<stdio.h>

#define max 100

void read(int [],int);

void print(int [],int);

void quicksort(int [], int, int);

int partition(int [], int, int);

void interchange(int [], int, int);

int main()
{
	int a[max],n;
	
	printf("\n Enter the number of elements in array : ");
	scanf("%d",&n);
	
	read(a,n);
	
	printf("\n Unsorted array : \n");
    print(a,n);
    
    a[n+1]=9999;
    
    quicksort(a,1,n);
    
    printf("\n Sorted array after quick sort : \n");
    print(a,n);
    
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	printf("\n Enter array : \n");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
	printf("\n");
    for(i=1;i<=n;i++)
	    printf("%d ",a[i]);
    printf("\n");
}

void quicksort(int a[], int p, int q)
{
	int j;
	
	if(p<q)
	{
		j=partition(a,p,q+1);
		quicksort(a,p,j-1);
		quicksort(a,j+1,q);
	}
}

int partition(int a[], int p, int q)
{
	int t=a[p], i=p, j=q;
	
    do
    {
    	do
    	{
    		i=i+1;
    		
		}while(a[i]<t);
		
		do
		{
			j=j-1;
			
		}while(a[j]>t);
		
		if(i<j)
		interchange(a,i,j);
		
	}while(i<j);
	
	a[p]=a[j];
	a[j]=t;

	return j;
}

void interchange(int a[], int i, int j)
{
	int temp;
	
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
