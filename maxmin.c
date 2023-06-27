//Program to find maximum and minimum (straight forward)

#include<stdio.h>

#define m 100

void straightmaxmin(int [], int, int *, int *);

void main()
{
	int a[m],n,max,min,i;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	printf("\n Enter elements : \n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	straightmaxmin(a,n,&max,&min);
	
	printf("\n Maximum element : %d",max);
	printf("\n Minimum element : %d",min);
}

void straightmaxmin(int a[m], int n, int *max, int *min)
{
	int i;
	
	*max=*min=a[0];
	
	for(i=1;i<n;i++)
	{
		if(a[i]>*max)
			*max=a[i];
		
		if(a[i]<*min)
			*min=a[i];
	}
}
