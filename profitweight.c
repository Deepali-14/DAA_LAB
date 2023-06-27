//Program on greedy strategy for knapsack problem (profit and weight)

#include<stdio.h>

#define max 20

void GreedyKnapsack(float [], float [], float , int );

void main()
{
	float p[max], w[max], m;
	int n, i;
	
	printf("\n Enter knapsack size : ");
	scanf("%f",&m);
	
	printf("\n Enter total number of profits and weights : ");
	scanf("%d",&n);
	
	printf("\n Enter profits in decreasing order \n");
	
	printf("\n Enter profits : ");
	for(i=1; i<=n; i++)
		scanf("%f",&p[i]);
		
	printf("\n Enter weights : ");
	for(i=1; i<=n; i++)
		scanf("%f",&w[i]);
		
	printf("\n Objects : \t");
	for(i=1; i<=n; i++)
		printf("%d\t",i);
		
	printf("\n Profits : \t");
	for(i=1; i<=n; i++)
		printf("%.2f\t",p[i]);
		
	printf("\n Weights : \t");
	for(i=1; i<=n; i++)
		printf("%.2f\t",w[i]);

	GreedyKnapsack(p,w,m,n);	
}

void GreedyKnapsack(float p[max], float w[max], float m, int n)
{
	float U,x[max];
	int i;
	
	for(i=1; i<=n; i++)
		x[i]=0.0;
		
	U=m;
	
	for(i=1; i<=n; i++)
	{
		if(w[i]>U)
			break;
			
		x[i]=1.0;
		U=U-w[i];
	}
	
	if(i<=n)
		x[i]=U/w[i];
		
	printf("\n Solution vector : ");
	for(i=1; i<=n; i++)
		printf(" %.2f ",x[i]);
	
}
