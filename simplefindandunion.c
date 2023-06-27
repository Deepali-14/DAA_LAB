//Program on simple find and simple union

#include<stdio.h>

#define max 20

void display(int [],int);

void simpleunion(int [],int,int);

int simplefind(int [],int);

int main()
{
	int p[max];
	int n,s,e,ne,rt,rt1,rt2,x,r,i,j;
	
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
				p[e]=-1;
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
	
	printf("\n Enter two roots on which simple union is to be performed : ");
	scanf("%d %d",&rt1,&rt2);
	
	simpleunion(p,rt1,rt2);
	
	printf("\n After simple union : \n");
	
	display(p,n);
	
	printf("\n Enter element to find : ");
	scanf("%d",&x);
	
	r=simplefind(p,x);
	
	printf("\n %d is found in a set with root %d \n",x,r);
	
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

void simpleunion(int p[],int r1,int r2)
{
	p[r1]=r2;
}

int simplefind(int p[],int x)
{
	while(p[x]>=0)
	x=p[x];
	
	return x;
}
