#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int v;
	struct node *next;
};

typedef struct node node;

struct Queue
{
	int *a;
	int front;
	int capacity;
	int rear;
	int flag;
};

typedef struct Queue Queue;

Queue *CreateQueue(int v)
{
	Queue *qt=(Queue *)malloc(sizeof(Queue));
	qt->a=(int *)malloc(v*sizeof(int));
	qt->front=-1;
	qt->rear=-1;
	qt->capacity=0;
	qt->flag=-1;
	return qt;
}

node *CreateNode(int v)
{
	node *p=(node *)malloc(sizeof(node));
	p->v=v;
	p->next=NULL;
	return p;
}

node *insert(node *head,int v)
{
	node *p=CreateNode(v);
	if(head==NULL)
		head=p;
	else
	{
		p->next=head;
		head=p;
	}
	return head;
}

void enqueue(int v,Queue *qt)
{
	qt->rear++;
	qt->capacity++;
	qt->a[qt->rear]=v;
}

int dequeue(Queue *qt)
{
	qt->front++;
	qt->capacity--;
	return qt->a[qt->front];
}

void BFS(int v,int *visit,node **head)
{
	//printf("hello\n");
	int i,j,k;
	printf("\n");
	Queue *q=CreateQueue(v);
	enqueue(v,q);
	q->flag++;
	visit[v]=1;
	while(q->capacity!=0)
	{
		node *s=head[q->a[q->flag]];
		while(s!=NULL)
		{
			if(visit[s->v]==0)
			{
				visit[s->v]=1;
				enqueue(s->v,q);
			}
			s=s->next;
		}
		printf("%d ",dequeue(q));
		q->flag++;		
	} 
}

int main()
{
	int *visit,n,r,i,j,k,e,f,s;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	visit=(int *)calloc(n,sizeof(int));
	node **head=(node **)malloc(n*sizeof(node *));
	printf("\nEnter the number of edges\n");
	scanf("%d",&e);
	while(e--)
	{
		printf("\nFirst : ");
		scanf("%d",&f);
		printf("\nSecond : ");
		scanf("%d",&s);
		head[f]=insert(head[f],s);
	}
	
	printf("\nStart of BFS : ");
	scanf("%d",&k);
	BFS(k,visit,head);
}

