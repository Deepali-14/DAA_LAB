//Program on binary search

#include<stdio.h>

#define max 20

void read(int[],int);

void print(int [],int);
 
int binsearch(int [],int,int);

int main()
{
	int a[max];
	int n,x,r;
	
	printf("\n Enter the number of elements in array : ");
	scanf("%d",&n);
	
	read(a,n);
		
    print(a,n);
    
	printf("\n Read element to search : ");
    scanf("%d",&x);
    
	r=binsearch(a,n,x);
	
	if(r!=-999)
	    printf("\n %d found at location %d",x,r);
	else
    	printf("\n %d not found",x);    
    
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	printf("\n Enter array in ascending order : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
    
    printf("\n Array : \n");
	for(i=0;i<n;i++)
	    printf("%d ",a[i]);
	printf("\n");
} 

int binsearch(int a[],int n,int x)
{
	int l=0,h=n-1,m;
	
	do
	{
		m=(l+h)/2;
		
		if(x<a[m])
		  h=m-1;
		  
		else if(x>a[m])
		  l=m+1;
		  
		else
		  return m;	
	}while(l<=h);
	
	return -999;
}
