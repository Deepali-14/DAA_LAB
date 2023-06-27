//Program on heap sort in descending order using min heap

#include<stdio.h>

#define max 20

void read(int [],int);

void print(int [],int);

void swap(int [],int,int);

void heapify(int [],int);

void heapsort(int [],int);

void adjust(int [],int,int);

int main()
{
	int arr[max];
	int i,n;
	
	printf("\n Enter number of elements in the array : ");
	scanf("%d",&n);
	
	printf("\n Enter array : \n");
	read(arr,n);
	
	printf("\n Original array : \n");
    print(arr,n);
    
    heapsort(arr,n);
    
    printf("\n Sorted array in descending order after heap sort : \n");
    print(arr,n);
    
	return 0;
}

void read(int arr[],int n)
{
	int i;
	
	for(i=1;i<=n;i++)
	scanf("%d",&arr[i]);
}

void print(int arr[], int n) 
{
	int i;
	
    for(i=1;i<=n;i++)
    printf(" %d ",arr[i]);
    printf("\n");
}

void heapsort(int arr[],int n)
{
	int temp,i;
	
	heapify(arr,n);
	
	for(i=n;i>1;i--)
	{
		swap(arr,i,1);
		
		adjust(arr,1,i-1);
	}
}

void heapify(int arr[],int n)
{
	int i;
	
	for(i=n/2;i>=1;i--)
	adjust(arr,i,n);
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

void swap(int arr[],int i,int j)
{
	int temp;
	
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
