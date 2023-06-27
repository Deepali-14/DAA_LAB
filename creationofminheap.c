//Program on creation of min heap

#include<stdio.h>

#define max 20

void read(int [],int);

void heapify(int [],int);

void adjust(int [],int,int);

void print(int [],int);

int main()
{
	int a[max];
	int i,n;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	read(a,n);
	
	heapify(a,n);
	
    print(a,n);
    
	return 0;
}

void read(int arr[],int n)
{
	int i;
	
	printf("\n Enter elements: \n");
	for(i=1;i<=n;i++)
	   scanf("%d",&arr[i]);
}

void heapify(int arr[], int n) 
{
	int i;
	
    for(i=n/2;i>=1;i--)
    	adjust(arr,i,n);
}

void print(int arr[], int n) 
{
	int i;
	
	printf("\n Min heap :\n");
    for(i=1;i<=n;i++)
    printf(" %d ",arr[i]);
}

void adjust(int arr[],int i,int n)
{
	int j=2*i,item=arr[i];
	
	while(j<=n)
	{
		if(j<n && (arr[j]>arr[j+1]))
		j=j+1;
		
		if(item<=arr[j])
		break;
		
		arr[j/2]=arr[j];
		j=2*j;
	}
	
	arr[j/2]=item;
}
