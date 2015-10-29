#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
node* createNode()
{
    return (node*)malloc(sizeof(node));
}
void push(node **head,int v)
{
    node* p=createNode();
    p->value=v;
    p->next=*head;
    *head=p;
}
void append(node **head,int v)
{
    node* p=createNode();
    p->value=v;
    p->next=NULL;
    if(*head==NULL)
    {
        *head=p;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}
void print(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->value);
        head=head->next;
    }
    printf("\n");
}
void insertAfter(node *p,int v)
{
    if(p==NULL)
    {
        printf("Invalid node for insertion\n");
        return;
    }
    node *q=createNode();
    q->value=v;
    q->next=p->next;
    p->next=q;
}
void deleteNode(node **head,int n)
{
    node *temp=*head,*prev;
    if(n==1)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    int cnt=1;
    while(cnt!=n)
    {
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    prev->next=prev->next->next;
    free(temp);
}
int main()
{
    int i;
    node *head=NULL;
    for(i=0;i<10;i++)
        append(&head,i);
    insertAfter(head->next->next->next,55);
    print(head);
    deleteNode(&head,5);
    print(head);
    return 0;
}
