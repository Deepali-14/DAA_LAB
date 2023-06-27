//Program on sorting using max heap

#include<stdio.h>

#define max 100

void insert(int [],int);

void print(int [],int);

void sort(int [],int);

void delmax(int [],int *,int *);

void adjust(int [],int,int);

int main()
{
	int a[max];
	int n,i;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("\n Enter elements %d : ",i);
		scanf("%d",&a[i]);
		insert(a,i);
	}
	
	printf("\n Max heap :\n");
	print(a,n);
	
	sort(a,n);
	printf("\n Sorted array using max heap :\n");
	print(a,n);
	
	return 0;
}

void insert(int arr[],int n) 
{
    int i=n,item=arr[n];
    
    while(i>1 && arr[i/2]<item)
    {
    	arr[i]=arr[i/2];
    	i=i/2;
	}
	
    arr[i]=item;
}

void print(int arr[],int n) 
{
	int i;
	
    for(i=1;i<=n;i++)
    printf(" %d ",arr[i]);
}

void sort(int arr[],int n)
{
	int i,x;
	
	for(i=n; i>=1; i--)
	{
		delmax(arr,&i,&x);
		arr[i]=x;
	}
}

void delmax(int arr[],int *n,int *x)
{
	if(*n==0)
	{
		printf("\n Heap is empty");
		
		return;
	}
	
	else
    {
		*x=arr[1];
		
		arr[1]= arr[*n];
		
		adjust(arr,1,*n-1);
		
		return;
	}
}

void adjust(int arr[],int i,int n)
{
	int j=2*i,item=arr[i];
	
	while(j<=n)
	{
		if(j<n && (arr[j]<arr[j+1]))
		j=j+1;
		
		if(item>=arr[j])
		break;
		
		arr[j/2]=arr[j];
		j=2*j;
	}
	
	arr[j/2]=item;
}

