//Program on deletion from max heap

#include<stdio.h>

#define max 20

void insert(int [],int);

void print(int [],int);

void delmax(int [],int *);

void adjust(int [],int,int *);

int main()
{
	int arr[max];
	int i,n,x;
	
	printf("\n Enter number of elements in the tree : ");
	scanf("%d",&n);
	
	i=1;
	
	while(i<=n)
	{
		printf("\n Enter element : ");
		scanf("%d",&arr[i]);
		
		insert(arr,i);
		
		i++;
	}
	
    print(arr,n);
    
    delmax(arr,&n);
    
    print(arr,n);
    
	return 0;
}

void insert(int arr[], int n) 
{
    int i=n,item=arr[n];
    
    while(i>1 && arr[i/2]<item)
    {
    	arr[i]=arr[i/2];
    	i=i/2;
	}
	
    arr[i]=item;
}

void delmax(int arr[],int *n)
{
	int x;
	
	if(*n==0)
	{
		printf("\n Heap is empty");
		
		return;
	}
	
	else
    {
    	x=arr[1];
    	
    	printf("\n Deleted element : %d",x);
    	
		arr[1]=arr[*n];
		
		*n=*n-1;
		
		adjust(arr,1,n);
	}
}

void adjust(int arr[],int i,int *n)
{
	int j=2*i,item=arr[i];
	
	while(j<=*n)
	{
		if(j<*n && (arr[j]<arr[j+1]))
		j=j+1;
		
		if(item>=arr[j])
		break;
		
		arr[j/2]=arr[j];
		j=2*j;
	}
	
	arr[j/2]=item;
}

void print(int arr[], int n) 
{
	int i;
	
	printf("\n Max heap :\n");
    for(i=1;i<=n;i++)
    printf(" %d ",arr[i]);
}
