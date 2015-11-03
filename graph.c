#include<stdio.h>
#include<stdlib.h>

struct node{
	int v;
	struct node *next;
};

typedef struct node node;

node *CreateNode(int v)
{
	node *nt=(node *)malloc(sizeof(node));
	nt->v=v;
	nt->next=NULL;
	return nt;
}

node *insert(node *nt,int v)
{
	node *p=CreateNode(v);
	if(nt==NULL)
	{
		nt=p;
	}	
	else
	{
		p->next=nt;
		nt=p;
	}
	return nt;
}

void print(node *head)
{
	while(head!=NULL)
	{
		printf("%d -----> ",head->v);
		head=head->next;
	}
}

int main()
{
	int n,i,j,k,e,f,s;
	printf("\nEnter the number of nodes you want\n");
	scanf("%d",&n);
	node **head=(node **)malloc(n*sizeof(node *));
	printf("\nEnter the number of edges\n");
	scanf("%d",&e);
	while(e--)
	{
		printf("\nEnter the first point :\n");
		scanf("%d",&f);
		printf("\nEnter the second point :\n");
		scanf("%d",&s);
		head[f]=insert(head[f],s);
		head[s]=insert(head[s],f);
	}
	printf("\n*****************************\n");
	for(i=0;i<n;i++)
	{
		print(head[i]);
		printf("\n");
	}
	printf("\n*****************************\n");
	return 0;
}
