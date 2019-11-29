#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;struct node* link;
} node;


typedef struct hash
{
	node* head;int count;
}hash;


void insert(hash* hash,int n,int data)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->link=NULL;temp->data=data;
	int index=data%n;

	temp->link=hash[index].head;
	hash[index].count+=1;
	hash[index].head=temp;
}


void delete(hash* h,int n,int key)
{
	int index=key%n;
	node* temp=h[index].head;
	node* prev=NULL;
	while(temp)
	{
		if(temp->data==key) break;
		prev=temp;
		temp=temp->link;
	}
	if(temp==NULL)
	{
		printf("Not found\n");
	}
	else if(prev==NULL)
	{
		h[index].head=temp->link;free(temp);
	}
	else
	{
		prev->link=temp->link;
		free(temp);
	}
}
void display(hash* h,int n)
{
	int i;node* temp=NULL;
	for(i=0;i<n;i++)
	{
		printf("%d\n",i);
		if(h[i].head!=NULL)
		{
			temp=h[i].head;
			while(temp)
			{
				printf("%d\n", temp->data);
				temp=temp->link;
			}
		}
		else
		{
			printf("No elements here");
		}
		printf("\n");
	}
}

int main()
{
	int n,i;
	printf("Enter table size\n");
	scanf("%d",&n);
	hash* hashtable=(hash*)malloc(n*sizeof(hash));
	for(i=0;i<n;i++)
	{
		hashtable[i].head=NULL;
		hashtable[i].count=0;
	}
	insert(hashtable,n,10);
	insert(hashtable,n,11);
	insert(hashtable,n,12);
	insert(hashtable,n,9);
	insert(hashtable,n,20);
	insert(hashtable,n,30);
	display(hashtable,n);
	delete(hashtable,n,10);
	display(hashtable,n);
	delete(hashtable,n,9);
	display(hashtable,n);
	return 0;
}
