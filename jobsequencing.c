#include<stdio.h>
#define MAX 10

struct job
{
	int d,id;
	float p;
};

void sort(struct job ar[],int n);
int job_seq(struct job ar[],int J[],int n,float *tp);


void main()
{
	struct job ar[MAX];
	int n,i,J[MAX],k;
	float tp=0.0;

	for(i=1;i<MAX;i++)
		J[i]=0;

	printf("total no. of job: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		ar[i].id=i;
	
		printf("enter the job %d profit ",i);
		scanf("%f",&ar[i].p);
		
		printf("enter the job %d deadline ",i);
		scanf("%d",&ar[i].d);
	}
	
	sort(ar,n);
	
	 printf("%10s %10s %10s\n","Job Id","Deadline","Profit");
 	for(i=1;i<=n;i++)
  		printf("%10d %10d %15f \n",ar[i].id,ar[i].d,ar[i].p);
	
	k=job_seq(ar,J,n,&tp);
	
	printf("The total profit is %f ",tp);
	
	printf("The job sequence is: ");
	for(i=1;i<=k;i++)
		printf("%d\t",ar[J[i]].id);
}



void sort(struct job ar[],int n)
{
	int i,j;
	struct job temp;
	
	for(i=1;i<=n;i++)
	{	
		for(j=i+1;j<=n;j++)
		{
			if((ar[i].p)<(ar[j].p))
			{
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
}


int job_seq(struct job ar[],int J[],int n,float *tp)
{
	int k,r,i,q;
	
	ar[0].d=J[0]=0;
	
	J[1]=1;
	k=1;
	*tp=*tp+ar[1].p;
	

	for(i=2;i<=n;i++)
	{
		r=k;
		
		while((ar[J[r]].d>ar[i].d)&&(ar[J[r]].d)!=r)
			r=r-1;
		
		if((ar[J[r]].d<=ar[i].d)&&(ar[i].d)>r)
		{
			for(q=k;q>=r+1;q--)
				J[q+1]=J[q];
			
			J[r+1]=i;
			k=k+1;
			*tp=*tp+ar[i].p;	
			
		}	
	}
	
	return k;
}
