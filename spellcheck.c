#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ll long long int
#define mod 100013

/*ll evaluate(char *s)
{
	int i,j;
	int n=strlen(s);
	ll sum=0;
	for(i=0;s[i]!='\0';i++)
	{
		sum+=s[i]*pow(31,n-i-1);
		sum%=mod;		
	}	
	return sum%mod;
}*/

struct node{
	char *name;
	struct node *next;
};

typedef struct node node;

node *CreateNode(char a[])
{
	node *q=(node *)malloc(sizeof(node));
	q->name=(char *)malloc(50*sizeof(char));
	strcpy(q->name,a);
	q->next=NULL;
	return q;
}

ll evaluate(char *s)
{
	int x=31,cnt=0,i,n;
	n=strlen(s);
	ll sum=0;
	sum+=(x*(s[0]%mod))%mod;
	for(i=1;s[i]!='\0';i++)
	{
		cnt++;
		sum+=s[i]%mod;
		sum%=mod;
		if(cnt==n-1)
			break;
		sum+=(x*sum)%mod;
		sum%=mod;		
	}
	return sum%mod;	
}

node *push(node *head,char a[])
{
	node *q=CreateNode(a);
	node *p=head;
	if(p==NULL)
	{
		p=q;
	}
	else
	{
		q->next=p;
		p=q;
	}
	return p;
}

void search(node *head,char *s)
{
	node *p=head;
	while(p!=NULL)
	{
		if(strcmp(p->name,s)==0)
		{
			printf("Found\n");
			return ;
		}
		p=p->next;
	}	
	printf("Not Found\n");
}

int main()
{
	node *head[mod]={NULL};
	int i,j,key,hash[mod],cnt=0,n;
	char s[50],str[50];
	for(i=0;i<25147;i++)
	{
		hash[i]=0;
	}
	FILE *fptr;
	fptr=fopen("dictionary.txt","r");
	if(fptr!=NULL)
	{
		while(fscanf(fptr,"%s",s)!=EOF)
		{		
			key=evaluate(s);
			head[key]=push(head[key],s);
			hash[key]++;
		}
		
	}
	else
		printf("\n\n ERROR OPEING FILE");

	fclose(fptr);

	printf("Enter the number of string you want to search\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nPlease Enter the string you want to get searched\n");
		scanf("%s",str);
		key=evaluate(str);
		if(hash[key]==0)
			printf("\nNo string found\n");
		else
		{
			search(head[key],str);
		}
	}
	for(i=0;i<mod;i++)
	{
		if(hash[i]>4)
			cnt++;
	}
	printf("\n\nThe count of the number are : %d\n",cnt);
	return 0;
}




/*s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]*/
