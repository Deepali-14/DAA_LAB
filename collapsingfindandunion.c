//Program on weighted union and collapsing find

#include<stdio.h>

#define max 20

void display(int [],int);

void weightedunion(int [],int,int);

int collapsingfind(int [],int);

int main()
{
	int p[max];
	int n,i,j,s,e,ne,rt,rt1,rt2,x,r;
	
	printf("\n Enter total number of elements in the entire collection of disjoint sets : ");
	scanf("%d",&n);
	
	printf("\n Enter total number of disjoint sets : ");
	scanf("%d",&s);
	
	for(i=1;i<=s;i++)
	{
		printf("\n Enter total number of elements in set %d : ",i);
		scanf("%d",&ne);
		
		for(j=1;j<=ne;j++)
		{
			if(j==1)
			{
				printf("\n Enter root element %d : ",j);
			    scanf("%d",&e);
				p[e]=-ne;
				rt=e;
			}
			
			else
			{
				printf("\n Enter element %d : ",j);
			    scanf("%d",&e);
			    p[e]=rt;
			}
		}
	}
	
	display(p,n);
	
	printf("\n Enter two roots on which weighted union is to be performed : ");
	scanf("%d %d",&rt1,&rt2);
	
	weightedunion(p,rt1,rt2);
	
	printf("\n After weighted union : \n");
	
	display(p,n);
	
	printf("\n Enter element to find : ");
	scanf("%d",&x);
	
	r=collapsingfind(p,x);
	
	printf("\n %d is found in a set with root %d \n",x,r);
	
	printf("\n After collapsing find : \n");
	
	display(p,n);
	
	return 0;
}
		
void display(int p[],int n)
{
	int i;
	
	printf("\n Element array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",i);
	
	printf("\n");
	
	printf("\n Parent array : \n");
	for(i=1;i<=n;i++)
	printf(" %d\t",p[i]);
		
	printf("\n");
}

void weightedunion(int p[],int r1,int r2)
{
	int temp;
	
	temp=p[r1]+p[r2];
	
	if(p[r1]>p[r2])
	{
		p[r1]=r2;
		p[r2]=temp;
	}
	
	else
	{
		p[r2]=r1;
		p[r1]=temp;
	}
}

int collapsingfind(int p[],int x)
{
	int r=x,s;

	while(p[r]>0)
	r=p[r];
	
	while(x!=r)
	{
		s=p[x];
		p[x]=r;
		x=s;
	}
	
	return r;
}
