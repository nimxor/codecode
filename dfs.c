#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ll long long int
int hash[500]={0};

struct stack{
	int *a;
	int top;
};

typedef struct stack stack;

stack *createStack()
{
	stack *stk=(stack *)malloc(sizeof(stack));
	stk->a=(int *)malloc(50*sizeof(int));
	stk->top=-1;
	return stk;
}

void push(stack *st,int v)
{
	st->top++;
	st->a[st->top]=v;
}

int pop(stack *st)
{
	//free(st->a[st->top]);
	int p;
	p=st->a[st->top];
	st->top--;
	return p;
}

int main()
{
	stack *st=createStack();	
	int n,i,j,k,e,a,b,l,r;
	printf("\nEnter the number of vertex\n");
	scanf("%d",&n);
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	printf("\nEnter the number of edges\n");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("\nEnter the edge %d",i+1);
		printf("\nEnter the first vertex :");
		scanf("%d",&l);
		printf("\nEnter the second vertex :");
		scanf("%d",&r);
		dp[l][r]=1;
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",dp[i][j]);
			
		printf("\n");
	}
	printf("\n****************************************************\n");
	
	int q,x,y,f=0;
	printf("Enter the quaries\n");
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		st->top=-1;
		for(k=0;k<=100;k++)
			hash[k]=0;
		printf("\n****************************\nEnter the vertex to search for\n");
		printf("Enter vertex A%d :\n",i+1);
		scanf("%d",&l);
		printf("Enter vertex B%d :\n",i+1);
		scanf("%d",&r);
		hash[l]=1;
		push(st,l);
		while(st->top!=-1)
		{
			x=pop(st);
			f=0;
			//printf("%d\n",x);
			if(x==r)
			{
			        f=1;
				printf("\nResult : The two nodes are connected\n");
				break;
			}
			for(j=1;j<=n;j++)
			{
				if(hash[j]!=1 && dp[x][j]==1)
				{
					push(st,j);
					hash[j]=1;
				}
			}			
		}
		if(f==0)
			printf("\nResult : The two  nodes are not connected\n");

	}
	
	return 0;
}

/*6 10 1 2 1 3 1 4 2 3 2 4 4 6 5 3 5 4 6 1 6 5*/
