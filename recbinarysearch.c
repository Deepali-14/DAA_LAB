//Program on recursive binary search

#include<stdio.h>

#define max 20

void read(int [],int);

void print(int [],int);

int binsrch(int [],int,int,int);

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
	r=binsrch(a,0,n-1,key);
	
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

int binsrch(int a[],int l,int h,int key)
{
	int mid;
	
	if(l==h)
	{
		if(key==a[l])
		return l;
		
		else
		return -999;
	}
	
	else
	{
		mid=(l+h)/2;
		
		if(key==a[mid])
	    	return mid;
		
		else if(key<a[mid])
	    	return binsrch(a,l,mid-1,key);
		
	    else
	    	return binsrch(a,mid+1,h,key);
	}
}
