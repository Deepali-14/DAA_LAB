#include<stdio.h>
#define MAX 20
struct item
{
	float id,p,w;
	int x;
};
typedef struct item ITEM;

float Bound(float cp,float cw,int k,ITEM arr[MAX],int n, float m,float y[MAX]);
void Bknap(int k,float cp,float cw,ITEM arr[MAX],int n,float m,float*fp,float*fw,float y[MAX]);
void sorting(ITEM arr[MAX],int n);

int main()
{
	ITEM arr[MAX];
	int n,j,i,k;
	float m,tp=0.0,cw=0.0,cp=0.0,fp=0.0,fw=0.0,y[MAX];
	
	printf("Enter the total no of items: ");
	scanf("%d",&n);
	
	printf("\nEnter the capacity of knapsack: ");
	scanf("%f",&m);
	
	for(j=1;j<=n;j++)
	{
		arr[j].id=j;
		
		printf("\nEnter the profit for item %d: ",j);
		scanf("%f",&arr[j].p);
		
		printf("\nEnter the weight for item %d: ",j);
		scanf("%f",&arr[j].w);
		
		arr[j].x=0;
	}
	
	sorting(arr,n);
	
	Bknap(1,0,0,arr,n,m,&fp,&fw,y);
	
	printf("\ntotal profit=%f",fp);
	
	for(i=1;i<=n;i++)
		printf("\n fraction of object %d considered in knapsack is %d",arr[i].id,arr[i].x);
	
	return 0;	
}


float Bound(float cp,float cw,int k,ITEM arr[MAX],int n, float m,float y[MAX])
{
	int i;
	float np,nw;
	
	np=cp;
	nw=cw;
	
	for(i=k+1;i<=n;i++)	
	{
		nw=nw+arr[i].w;
		if(nw<m)
			np=np+arr[i].p;
		else
			return(np+(1-(nw-m)/arr[i].w)*arr[i].p);	
	}
	return np;
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
void Bknap(int k,float cp,float cw,ITEM arr[MAX],int n,float m,float*fp,float*fw,float y[MAX])
{
	int j;
	
	if(cw+arr[k].w<=m)
	{
		y[k]=1;
		if(k<n)
			Bknap(k+1,cp+arr[k].p,cw+arr[k].w,arr,n,m,fp,fw,y);
		if((cp+arr[k].p>*fp)&&(k==n))
		{
			*fp=cp+arr[k].p;
			*fw=cw+arr[k].w;
			
			for(j=1;j<=k;j++)
				arr[j].x=y[j];
		}
	}
	
	if(Bound(cp,cw,k,arr,n,m,y)>=*fp)
	{
		y[k]=0;
		if(k<n)
			Bknap(k+1,cp,cw,arr,n,m,fp,fw,y);
			
		if((cp>*fp)&&(k==n))
		{
			*fp=cp;
			*fw=cw;
			
			for(j=1;j<=k;j++)
				arr[j].x=y[j];
		}
	}
}

