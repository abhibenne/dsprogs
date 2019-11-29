
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
	new->link=NULL;
	new->data=data;
	return new;
}

void insert(L* sll,int data,int pos)
{
	node* temp=sll->head;
	if(pos>sll->num)
	{
		return;
	}
	node* new=new_node(data);
	sll->num+=1;
	if(temp==NULL && pos==0)
	{
		sll->head=new;
	}
	int c=0;node* prev=NULL;
	while(temp)
	{
		if(c==pos) break;
		prev=temp;
		temp=temp->link;
		c++;
	}
	if(prev==NULL)
	{
		new->link=temp;
		sll->head=new;
	}
	else
	{
		prev->link=new;
		new->link=temp;
	}
	printf("inserted %d",new->data);
}

void disp(L* list)
{
	node* temp=list->head;
	while(temp)
	{
		printf("%d\t", temp->data);
		temp=temp->link;
	}
}

void delete(L* list,int pos)
{
	if(list->head==NULL)
		return;
	node* temp=list->head;node* prev=NULL;int c=0;
	while(temp)
	{
		if(c==pos) break;
		c++;
		prev=temp;
		temp=temp->link;
	}
	if(prev==NULL)
	{
		list->head=temp->link;
		free(temp);
	}
	else if(temp==NULL || c!=pos)
	{
		return;
	}
	else
	{
		prev->link=temp->link;
		free(temp);
		temp=NULL;
	}
}

void alternate(L* list)
{
	node* temp=list->head;
	while(temp)
	{
		printf("%d\n",temp->data);
		if(temp->link)
			temp=temp->link->link;
		else
			break;
	}
}


void insert_ascending(L* sll,int data)
{
	node* temp=sll->head;
	node* new=new_node(data);
	sll->num+=1;
	if(temp==NULL)
	{
		sll->head=new;return;
	}
	node* prev=NULL;
	while(temp)
	{
		if(temp->data>data) break;
		prev=temp;
		temp=temp->link;
	}
	if(prev==NULL)
	{
		sll->head=new;new->link=temp;
	}
	else if(temp==NULL)
	{
		prev->link=new;
	}
	else
	{
		prev->link=new;new->link=temp;
	}
	printf("inserted %d",new->data);
}

int main()
{
	L* list=new_list();
	// insert(list,10,0);
	// insert(list,12,2);
	// insert(list,20,1);
	// insert(list,30,1);
	// insert(list,40,1);
	// insert(list,30,7);
	// insert(list,50,3);
	// insert(list,70,3);
	// insert(list,99,6);
	insert_ascending(list,10);
	insert_ascending(list,12);
	insert_ascending(list,20);
	insert_ascending(list,30);
	insert_ascending(list,40);
	insert_ascending(list,30);
	insert_ascending(list,50);
	insert_ascending(list,70);
	insert_ascending(list,99);
	printf("\n");
	disp(list);
	delete(list,1);
	delete(list,0);
	// delete(list,10);
	printf("\n");
	 disp(list);
	  delete(list,10);
	  printf("\n");
	  disp(list);
	  printf("\n");
	 alternate(list);
	return 0;
}
