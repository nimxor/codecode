#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
struct Stack
{
    node *top;
};
typedef struct Stack Stack;
Stack* createStack()
{
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->top=NULL;
    return s;
}
node* createNode(int v)
{
    node *p=(node*)malloc(sizeof(node));
    p->value=v;
    p->next=NULL;
    return p;
}
int isEmpty(Stack *s)
{
    return s->top==NULL;
}
void push(Stack *s,int v)
{
    node *p=createNode(v);
    p->next=s->top;
    s->top=p;
}
void print(Stack *s)
{
    node *temp=s->top;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}
int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Empty Stack\n");
        return INT_MIN;
    }
    int x=s->top->value;
    node *temp=s->top;
    s->top=s->top->next;
    free(temp);
    return x;
}
int top(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Empty Stack\n");
        return INT_MIN;
    }
    return s->top->value;
}
int main()
{
    Stack *s=createStack();
    int i=0;
    printf("%d\n",pop(s));
    for(i=0;i<10;i++)
    {
        push(s,i);
    }
    print(s);
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    print(s);
    printf("%d\n",top(s));
    return 0;
}

