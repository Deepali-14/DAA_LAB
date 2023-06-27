#include<stdio.h>
#define MAX 20
struct edge
{
 int v1;
 int v2;
 float w;
};

float kruskal(struct edge a[],int ne,int n,int t[][3]);
int simplefind(int p[],int i);
void simpleunion(int p[],int i,int j);

void adjustInMin(struct edge a[],int i,int ne);
void Minheapify(struct edge a[],int ne);
void delmin(struct edge a[],int *ne,struct edge *x);

void main()
{
 int n,ne,u,v,i,j,t[MAX][3];
 float mincost=0.0f,c;
 struct edge a[MAX];
    
    printf("\nEnter the number of vertices/nodes:");
    scanf("%d",&n);
    
    printf("\nEnter the number of edges:");
    scanf("%d",&ne);
    
    for(i=1;i<=ne;i++)
    {
     printf("\nEnter the terminal vertex of edge %d:",i);
     scanf("%d",&u);
     
     printf("\nEnter the terminal vertex of edge %d:",i);
     scanf("%d",&v);
     
     printf("\nEnter the cost of edge %d:",i);
     scanf("%f",&c);
     
  a[i].v1=u; //initialize cost btw the 2 vertices that have an edge (non directional graph)
  a[i].v2=v;
  a[i].w=c;
 }
	
 mincost=kruskal(a,ne,n,t);
 printf("\nTotal cost of minimum cost spanning tree: %f",mincost);
 for(i=1;i<=n-1;i++)
  printf("\nEdge number %d: (%d, %d)",i,t[i][1],t[i][2]);
}
//E is the set of edges in G,arranged in non-decreasing order
//of cost .G has n vertices
//cost[u,v] is the cost of the edge (u,v)
//t is the set of edges in the minimum cost spanning tree
//The final cost is returned
float kruskal(struct edge a[],int ne,int n,int t[][3])
{
 int i,j,k,r,c,u,v,parent[MAX];
 float mincost;
 struct edge x;
	
 //construct a minheap out of the edge costs using heapify()
 Minheapify(a,ne);
	
 for(i=1;i<=ne;i++)
 {
  parent[i]=-1;
 }
	
 i=0;
 mincost=0.0f;
	
 while(i<n-1 && ne!=0)
 {
  //delete a minimum cost edge(u,v) from the minheap and rehapify using Adjust();
  delmin(a,&ne,&x);
  
  j=simplefind(parent,x.v1);
  k=simplefind(parent,x.v2);
  
  if(j!=k)
  {
   i=i+1;
   t[i][1]=x.v1;
   t[i][2]=x.v2;
   
   mincost = mincost + x.w;
   
   simpleunion(parent,j,k);
  }
 }
 if(i!=(n-1))
  printf("\nNo Spanning tree");
 else
  return mincost;
}
int simplefind(int p[],int i)
{
 while(p[i]>=0)
  i=p[i];
  
 return i;
}
void simpleunion(int p[],int i,int j)
{
 p[i]=j;
}
void delmin(struct edge a[],int *ne,struct edge *x)
{
 if(*ne==0)
 {
  printf("\nHeap is empty");
  return;
 }
 *x=a[1];
 a[1]=a[*ne];
 --(*ne);
	
 adjustInMin(a,1,*ne);
 return;
}
void adjustInMin(struct edge a[],int i,int ne)
{   
 int j;
 struct edge item;
 item=a[i];
 j=2*i;
 while(j<=ne)
 {
  if((j<ne) && (a[j].w>a[j+1].w))
   j=j+1;
  
  if(item.w<=a[j].w)
   break;
  
  a[j/2]=a[j];
  j=2*j;
 }
 a[j/2]=item;
}
void Minheapify(struct edge a[],int ne)
{
 int i;
	
 for(i=ne/2;i>=1;i--)
  adjustInMin(a,i,ne);
}
