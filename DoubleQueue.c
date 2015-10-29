#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
struct DeQueue
{
    node *front;
    node *rear;
    int size;
};
typedef struct DeQueue DeQueue;
node* createNode(int v)
{
    node *p=(node*)malloc(sizeof(node));
    p->value=v;
    p->next=NULL;
    return p;
}
DeQueue* createDeQueue()
{
    DeQueue *q=(DeQueue*)malloc(sizeof(DeQueue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    return q;
}
int isEmpty(DeQueue *q)
{
    return (q->front==NULL&&q->rear==NULL);
}
void insertFront(DeQueue *q,int v)
{
    node *p=createNode(v);
    if(isEmpty(q))
    {
        q->rear=p;
        q->front=p;
        q->size++;
        return;
    }
    p->next=q->front;
    q->front=p;
    q->size++;
}
void insertBack(DeQueue *q,int v)
{
    node *p=createNode(v);
    if(isEmpty(q))
    {
        q->rear=p;
        q->front=p;
        q->size++;
        return;
    }
    q->rear->next=p;
    q->rear=p;
    q->size++;
}
int eraseFront(DeQueue *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    int x=q->front->value;
    q->front=q->front->next;
    q->size--;
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    return x;
}
int eraseBack(DeQueue *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    int x=q->rear->value;
    if(q->front==q->rear)
    {
        q->rear=NULL;
        q->front=NULL;
        q->size--;
        return x;
    }
    node *temp=q->front;
    while(temp->next!=q->rear)
    {
        temp=temp->next;
    }
    q->rear=temp;
    temp->next=NULL;
    q->size--;
    if(q->rear==NULL)
    {
        q->front=NULL;
    }
    return x;
}
int front(DeQueue *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    return q->front->value;
}
int rear(DeQueue *q)
{
    if(isEmpty(q))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    return q->rear->value;
}
int size(DeQueue *q)
{
    return q->size;
}
int main()
{
    int i;
    DeQueue *q=createDeQueue();
    printf("%d\n",size(q));
    for(i=0;i<10;i++)
    {
        insertFront(q,i);
    }
    printf("%d\n",size(q));
    while(!isEmpty(q))
    {
        printf("%d ",eraseBack(q));
    }
    printf("\n");
    printf("%d\n",size(q));
    for(i=10;i<20;i++)
    {
        insertBack(q,i);
    }
    printf("%d\n",size(q));
    while(!isEmpty(q))
    {
        printf("%d ",eraseBack(q));
    }
    printf("\n");
    printf("%d\n",size(q));
    printf("%d\n",isEmpty(q));
    printf("%d ",eraseFront(q));
}

