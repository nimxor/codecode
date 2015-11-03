#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *right;
	struct node *left;
};

typedef struct node node;

node *CreateNode(int v)
{
	node *nt=(node *)malloc(sizeof(node));
	nt->data=v;
	nt->right=NULL;
	nt->left=NULL;
	return nt;
}

node *insert(node *nt,int v)
{
	if(nt==NULL)
		return CreateNode(v);
		
	if(nt->data > v)
		nt->left=insert(nt->left,v);
	else
		nt->right=insert(nt->right,v);
		
	return nt;
	
}

void inorder(node *nt)
{
	if(nt==NULL)
		return;
		
	inorder(nt->left);
	printf("%d ",nt->data);
	inorder(nt->right);
}

void delete()
{
	
}

node *search(node *nt,int v)
{
	if(nt->data==v || nt==NULL)
		return nt;
		
	if(nt->data > v)
		nt->left=search(nt->left,v);
	else
		nt->right=search(nt->right,v);
}

int main()
{
	node *nt=NULL;
	int t,n,m,i,j,k;
	
	while(1)
	{
		printf("Enter 1 for inserting a node\nEnter 2 for deleting a node\nEnter 3 for searching a node\nEnter 4 to print the tree\nEnter 5 to quit\n************************************************\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : printf("\nEnter the value to be inserted\n");
				 scanf("%d",&n);
				 nt=insert(nt,n);
				 break;
				 
		        case 2 : printf("\nEnter the value you want to delete\n");
		        	 scanf("%d",&n);
		        	 delete(nt,n);
		        	 break;
		        	 
		        case 3 : printf("\nThe searched value is......");
		        	 scanf("%d",&n);
		        	 node *l=search(nt,n);
		        	 if(l->data == n) printf("FOUND\n");
		        	 else printf("NOT FOUND\n");
		        	 break;
		        	 
		        case 4 : printf("\nInorder traversal of the tree is\n");
		        	 inorder(nt);
		        	 break;
		        	 
		        case 5 : exit(0);	 
		}
	}
	return 0;
}
