
#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	struct node* rlink;
	struct node* llink;
	int data;
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
	new->rlink=NULL;new->llink=NULL;
	new->data=data;
	return new;
}

void insert(L* list,int data,int pos)
{
	if(pos>list->num)
	return;
	node* temp=list->head;node* new=new_node(data);
	list->num+=1;
	if(pos>0 && temp==NULL)
		return;
	if(temp==NULL && pos==0)
	{
		list->head=new;
		printf("%d inserted\n",new->data);
		return;
	}
	int c=0;
	while(temp->rlink)
	{	
		if(c==pos) break;
		c++;
		temp=temp->rlink;
	}
	if(pos==0)
	{
		temp->llink=new;
		new->rlink=temp;
		list->head=new;
	}
	else if(temp->rlink==NULL && pos==(list->num-1))
	{
		temp->rlink=new;new->llink=temp;
	}
	else
	{
		temp->llink->rlink=new;
		new->llink=temp->llink;
		new->rlink=temp;
		temp->llink=new;
	}
	printf("%d inserted\n",new->data);
	return;
}


void disp(L* list)
{
	node* temp=list->head;
	while(temp)
	{
		printf("%d\t",temp->data);
		temp=temp->rlink;
	}
}


void delete(L* list,int pos)
{
	if(list->head==NULL)
		return;
	if(pos>list->num)
		return;
	node* temp=list->head;list->num-=1;
	int c=0;
	while(temp->rlink)
	{
		if(c==pos) break;c++;
		temp=temp->rlink;
	}
	if(pos==0)
	{
		list->head=temp->rlink;
		temp->rlink->llink=NULL;
		free(temp);
	}
	else if(temp->rlink==NULL && pos==(list->num-1))
	{
		temp->llink->rlink=NULL;
		free(temp);
	}
	else
	{
		temp->llink->rlink=temp->rlink;
		temp->rlink->llink=temp->llink;
		free(temp);
	}
}


int main()
{
	L* list=new_list();
	insert(list,10,0);
	insert(list,12,2);
	insert(list,20,1);
	insert(list,30,1);
	insert(list,40,1);
	insert(list,30,7);
	insert(list,50,3);
	insert(list,70,3);
	insert(list,99,6);
	printf("\n");
	disp(list);
	delete(list,1);
	delete(list,0);
	printf("\n");
	disp(list);
	delete(list,10);
	printf("\n");
	disp(list);
	printf("\n");
	return 0;
}
