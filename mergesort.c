//Program on merge sort

#include<stdio.h>

#define max 25

void read(int [], int);

void print(int [], int);

void mergesort(int[], int, int);

void merge(int [], int, int, int);

int main()
{
	int a[max];
	int n;
	
	printf("\n Enter size of array : ");
	scanf("%d", &n);
	
	read(a, n);
	
	printf("\n Array : \n");
	print(a, n);
	
	mergesort(a, 1, n);
	
	printf("\n Array after merge sort : \n");
	print(a, n);
	
	return 0;
}

void read(int a[], int n)
{
	int i;
	
	printf("\n Enter array : \n");
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

void print(int a[], int n)
{
	int i;
	
	for(i = 1; i <= n; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

void mergesort(int a[], int low, int high)
{
	int mid;
	
	if (low < high)
	{
		mid = (low + high) / 2;
		
		mergesort (a, low, mid);
		mergesort (a, mid+1, high);
		merge (a, low, mid, high);
	}
}

void merge(int a[], int low, int mid, int high)
{
	int b[max];
	int h = low, i = low, j = mid+1, k;
	
	while ( (h <= mid) && (j <= high) )
	{
		if (a[h] <= a[j])
			b[i++] = a[h++];
		
		else
			b[i++] = a[j++];	
	}
	
	if(h > mid)
		for(k = j; k <= high; k++)
			b[i++] = a[k];
			
	else
		for(k = h; k <= mid; k++)
			b[i++] = a[k];
			
	for(k = low; k <= high; k++)
		a[k] = b[k];
}
