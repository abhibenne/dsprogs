#include<stdio.h>
#include<stdlib.h>


void create(int* tree,int pos)
{
	printf("Enter number\n");int x;
	scanf("%d",&x);
	if(x==-1)
		return;
	tree[pos]=x;
	printf("Enter left sub tree of %d\n",tree[pos]);
	create(tree,2*pos+1);
	printf("Enter right sub tree of %d\n",tree[pos]);
	create(tree,2*pos+2);
}

void inorder(int *tree,int pos)
{
	if(tree[pos]!=-1)
	{
		inorder(tree,2*pos+1);
		printf("%d\t",tree[pos]);
		inorder(tree,2*pos+2);
	}
}

int main()
{
	int tree[100];int i;
	for(i=0;i<100;i++)
		tree[i]=-1;
	int count=0;
	create(tree,0);
	inorder(tree,0);
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;struct node* right;struct node* left;
} node;

typedef struct Tree
{
	int num;struct node* root;
}Tree;


Tree* create_tree()
{
	Tree* new=(Tree*)malloc(sizeof(Tree));
	new->num=0;new->root=NULL;
	return new;
}

node* new_node(int data)
{
	node* new=(node*)malloc(sizeof(node));
	new->data=data;
	new->right=NULL;
	new->left=NULL;
	return new;
}

void construct_binary(Tree* tree,int *a,int n)
{
	int i=0;node* queue[n];int front=-1;int rear=-1;
	while(a[i])
	{
		node* temp=tree->root;
		if(i==0)
		{
			tree->root=new_node(a[i]);
			queue[++front]=tree->root;
			rear=0;
//			printf("%d in queue\n",tree->root->data);
		}
		else
		{
			while(front!=-1)
			{
				node* cur=queue[front++];
				printf("%d in queue\n",cur->data);
				if(a[i])
				{
					printf("one\n");
					cur->left=new_node(a[i]);
					queue[++rear]=cur->left;
					i++;
				}
				else
					break;
				if(a[i])
				{
					printf("two\n");
					cur->right=new_node(a[i]);
					queue[++rear]=cur->right;
					i++;
				}
				else
					break;
			}
			break;
		}
		i++;
	}
}

void inorder(node* root)
{
	if(!root) return;
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}


int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
//	int n=sizeof(a) / sizeof(int);
	int n=9;
	Tree* root=create_tree();
	construct_binary(root,a,n);
	inorder(root->root);
	return 0;
}
*/
