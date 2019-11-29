#include<stdio.h>
#include<stdlib.h>

struct node
{
	char c;
	struct node* left;
	struct node* right;
};
typedef struct node node;


node* newNode(char c)
{
	node* new=(node*)malloc(sizeof(node));
	new->left=new->right=NULL;
	new->c=c;
	return new;
}

node* create(char *s)
{
	int i=0;node* root=NULL;
	node* temp=NULL;
	while(s[i])
	{
		node* new=newNode(s[i]);
		if(temp==NULL)
		{
			root=new;
			temp=root;
		}
		else
		{
			i++;
			if(s[i])
			{
				node* right=newNode(s[i]);
				new->right=right;
			}
			new->left=temp;
			temp=new;
		}
		i++;
	}
	return temp;
}


void inorder(node* p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%c",p->c);
	inorder(p->right);
}

void postorder(node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%c",root->c);
}

int toInt(char c)
{
	return c-48;
}

int solve2(node* root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return toInt(root->c);
	// if(root->left)
		int l=solve2(root->left);
	// if(root->right)
		int r=solve2(root->right);
	if(root->c=='+')
		return l+r;
	if(root->c=='-')
		return l-r;
	if(root->c=='*')
		return l*r;
	if(root->c=='/')
		return l/r;
}


int main()
{
	char s[]="a*b+c/d";
	char z[]="1*3+9/4";
	node* root= create(s);
	node* root2=create(z);
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("%d ",solve2(root2));
	return 0;
}
