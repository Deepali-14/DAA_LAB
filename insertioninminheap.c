//Program on insertion in min heap

#include<stdio.h>

#define max 20

void insert(int [],int);

void print(int [],int);

int main()
{
	int arr[max];
	int i,n;
	
	printf("\n Enter number of elements in the tree : ");
	scanf("%d",&n);
	
	i=1;
	
	while(i<=n)
	{
		printf("\n Enter element %d : ",i);
		scanf("%d",&arr[i]);
		
		insert(arr,i);
		
		i++;
	}
	
    print(arr,n);
    
	return 0;
}

void insert(int arr[], int n) 
{
    int i=n,item=arr[n];
    
    while(i>1 && arr[i/2]>item)
    {
    	arr[i]=arr[i/2];
    	i=i/2;
	}
	
    arr[i]=item;
}

void print(int arr[], int n) 
{
	int i;
	
	printf("\n Min heap :\n");
    for(i=1;i<=n;i++)
    printf(" %d ",arr[i]);
}
