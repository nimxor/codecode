#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
struct Queue
{
    node *front;
    node *rear;
};
typedef struct Queue Queue;
node* createNode(int v)
{
    node *p=(node*)malloc(sizeof(node));
    p->value=v;
    p->next=NULL;
    return p;
}
Queue* createQueue()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}
int isEmpty(Queue *q)
{
    return (q->front==NULL&&q->rear==NULL);
}
void enQueue(Queue *q,int v)
{
    node *p=createNode(v);
    if(isEmpty(q))
    {
        q->rear=p;
        q->front=p;
        return;
    }
    q->rear->next=p;
    q->rear=p;
}
int deQueue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    int x=q->front->value;
    q->front=q->front->next;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    return x;
}

int main()
{
    int i;
    Queue *q=createQueue();
    printf("%d\n",isEmpty(q));
    for(i=0;i<10;i++)
    {
        enQueue(q,i);
    }
    printf("%d\n",isEmpty(q));
    while(!isEmpty(q))
    {
        printf("%d ",deQueue(q));
    }
    printf("\n");
    printf("%d\n",isEmpty(q));
    printf("%d\n",deQueue(q));
}
