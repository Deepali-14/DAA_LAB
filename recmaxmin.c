//Program to find maximum and minimum recursively

#include<stdio.h>

#define m 100

void maxmin(int [], int, int, int *, int *);

void main()
{
	int a[m],n,max,min,i=0;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	printf("\n Enter elements : \n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	maxmin(a,0,n-1,&max,&min);
	
	printf("\n Maximum element : %d",max);
	printf("\n Minimum element : %d",min);
}

void maxmin(int a[m], int i, int j, int *max, int *min)
{
	int max1, min1, mid;
	
	if(i==j)
		*max=*min=a[i];
	
	else if(i==j-1)
	{
		if(a[i]<a[j])
		{
			*min=a[i];
			*max=a[j];
		}
		
		if(a[i]>a[j])
		{
			*min=a[j];
			*max=a[i];
		}
	}
	
	else
	{
		mid=(i+j)/2;
		maxmin(a, i, mid, max, min);
		maxmin(a, mid+1, j, &max1, &min1);
		
		if(max1>*max)
			*max=max1;
			
		if(min1<*min)
			*min=min1;
	}
}
