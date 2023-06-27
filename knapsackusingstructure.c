#include<stdio.h>
#define MAX 20

struct item
{
	float id,p,w,x;
};

typedef struct item ITEM;

void sorting(ITEM Arr[MAX],int n);
void knapsack(ITEM arr[MAX],int n,float m,float *tp);

void main()
{
	ITEM arr[MAX];
	int n,j;
	float m,tp=0.0;
	
	printf("Enter the total no of items: ");
	scanf("%d",&n);
	
	printf("\nEnter the capacity of knapsack: ");
	scanf("%f",&m);
	
	for(j=1;j<=n;j++)
	{
		printf("\nEnter the id of item %d: ",j);
		scanf("%d",&arr[j].id);
		
		printf("\nEnter the profit for item %d: ",j);
		scanf("%f",&arr[j].p);
		
		printf("\nEnter the weight for item %d: ",j);
		scanf("%f",&arr[j].w);
		
		arr[j].x=0.0;
	}
	
	sorting(arr,n);
	
	knapsack(arr,n,m,&tp);
	
	printf("\ntotal profit=%f",tp);
}

void sorting(ITEM arr[MAX],int n)
{
	int k,j;
	ITEM temp;
	
	for(k=1;k<=n;k++)
	{
		for(j=k+1;j<=n;j++)
		{
			if((arr[k].p/arr[k].w)<(arr[j].p/arr[j].w))
			{
				temp=arr[k];
				arr[k]=arr[j];
				arr[j]=temp;
				
			}
		}
	}
}

void knapsack(ITEM arr[MAX],int n,float m,float *tp)
{
	float U;
	int i;
	
	U=m;
	
	for(i=1;i<=n;i++)
	{
		if(arr[i].w > U)
			break;
			
		arr[i].x=1.0;
		U=U-arr[i].w;
		*tp=*tp+arr[i].p;		
	}	
	
	if(i<=n)
	{
		arr[i].x=U/arr[i].w;
		
		*tp=*tp + (arr[i].p)*(arr[i].x);
	}	
	
	printf("\nsolution is:: ");
	
	for(i=1;i<=n;i++)
		printf("\nfraction of object %d to be included = %f",i,arr[i].x);
}



