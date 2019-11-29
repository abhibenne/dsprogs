#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node* left;struct node* right;
	int lt,rt;
	int data;
} node;


node* insert(node* root,int data)
{
	node* prev=NULL;node* cur=root;
	while(cur)
	{
		if(cur->data==data)
			return root;
		prev=cur;
		if(cur->data>data)
		{
			if(cur->lt==0)
				cur=cur->left;
			else
				break;
		}
		else
		{
			if(cur->rt==0)
				cur=cur->right;
			else
				break;
		}
	}
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->lt=temp->rt=1;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{
		root=temp;return root;
	}
	if(prev->data> data)
	{
		temp->right=prev;
		temp->left=prev->left;
		prev->lt=0;
		prev->left=temp;
	}
	else
	{
		temp->left=prev;
		temp->right=prev->right;
		prev->rt=0;
		prev->right=temp;
	}
	return root;
}

void preorder(node* root)
{
	if(!root)
	{
		printf("Empty\n");return;
	}
	node* cur=root;
	while(cur)
	{
		printf("%d\t", cur->data);
		if(cur->left && cur->lt==0)
			cur=cur->left;
		else if(cur->right && cur->rt==0)
			cur=cur->right;
		else
		{
			while(cur->right && cur->rt==1)
				cur=cur->right;
			if(cur->right==NULL)
				break;
			else
				cur=cur->right;
		}
	}
}

int main()
{
	node* root=NULL;
	root=insert(root,10);
	root=insert(root,6);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,18);
	root=insert(root,19);
	root=insert(root,25);
	root=insert(root,22);
	root=insert(root,35);
	root=insert(root,10);
	root=insert(root,16);
	preorder(root);
	return 0;
}
