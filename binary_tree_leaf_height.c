#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	struct node* right;struct node* left;
	int data;
}node;


node* get_node(int data)
{
	node* new=(node*)malloc(sizeof(node));
	new->data=data;new->right=new->left=NULL;
	return new;
}


node* insert(node* root,int data)
{
	node* temp=get_node(data);node* cur=root;node* prev=NULL;
	if(root==NULL)
	{
		root=temp;
		printf("inserted");
		return root;
	}
	while(cur)
	{
		prev=cur;
		if(cur->data>data)
			cur=cur->left;
		else if(cur->data<data)
			cur=cur->right;
		else 
			return;
	}
	if(prev->data>data)
		prev->left=temp;
	else
		prev->right=temp;
	return root;
}

node* create(node* root)
{
	int x;
	while(1)
	{
		printf("Enter number\n");
		scanf("%d",&x);
		if(x==-1)
			break;
		root=insert(root,x);
	}
	return root;
}


void inorder(node* root)
{
	if(!root) 
	{
//		printf("empty\n");
		return;
	}
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

int leaf(node* root)
{
	if(!root)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return leaf(root->right)+leaf(root->left);
}

int height(node* root)
{
	if(!root)
		return -1;
	if(root->left==NULL && root->right==NULL)
		return 0;
	int l=height(root->left);
	int r=height(root->right);
	if(l>r)
		return l+1;
	return r+1;
}



int main()
{
	node* root=NULL;
	root=create(root);
	inorder(root);
	printf("\n%d is the number of leaves\n",leaf(root));
	printf("\n%d is the height\n",height(root));
	return 0;
}
