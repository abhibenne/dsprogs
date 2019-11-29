
#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	struct node* link;int data;
} node;

typedef struct list
{
	int num;node* head;
}L;


L* new_list()
{
	L* new=(L*)malloc(sizeof(L));
	new->num=0;new->head=NULL;
	return new;
}

node* new_node(int data)
{
	node* new=(node*)malloc(sizeof(node));
	new->link=new;
	new->data=data;
	return new;
}
void insert(L* list,int data)
{
	list->num+=1;
	node* new=new_node(data);
	node* temp=list->head;
	if(list->head==NULL)
	{
		list->head=new;
		return;
	}
	while(temp->link!=list->head)
	{
		temp=temp->link;
	}
	temp->link=new;new->link=list->head;
	return;
}
void disp(L* list)
{
	node* temp=list->head;
	if(temp==NULL)
		return;
	do
	{	
		printf("%d\t", temp->data);
		temp=temp->link;
	}while(temp!=list->head);
}

int josephus(L* list)
{
	node* temp=list->head;node* prev=NULL;
	while(temp->link!=temp)
	{
		prev=temp->link;
		temp->link=temp->link->link;
		temp=temp->link;
		free(prev);
	}
	if(temp)
	return temp->data;
	else
	return -1;
}

int main()
{
	L* list=new_list();
	insert(list,10);
	insert(list,20);
	insert(list,30);
	insert(list,40);
	insert(list,50);
	insert(list,60);
	disp(list);
	printf("\n");
	printf("%d is the last one \n",josephus(list) );
	return 0;
}
