#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;int pty;
};
typedef struct node node;


void insert(node* pq,int* count)
{
	node temp;
	printf("Enter key and priority\n");
	scanf("%d %d",&temp.key,&temp.pty);
	int i=*count;
	pq[i]=temp;
	++*count;
	int j=(i-1)/2;
	while((i>0) && (temp.pty>pq[j].pty))
	{
		pq[i]=pq[j];
		i=j;
		j=(i-1)/2;
	}
	pq[i]=temp;
}

void display(node* pq,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		printf("%d is element and %d is priority\n",pq[i].key,pq[i].pty);
	}
}

void heapify(node* pq,int count)
{
	node key=pq[0];
	int j=0;
	int i=2*j+1;
	while(i<=count)
	{
		if((i+1)<=count)
		{
			if(pq[i+1].pty>pq[i].pty)
				i++;
		}
		if(key.pty < pq[i].pty)
		{
			pq[j]=pq[i];
			j=i;i=2*j+1;
		}
		else
			break;
	}
	pq[j]=key;
}

void delete(node* pq,int* count)
{
	node del=pq[0];
	pq[0]=pq[*count-1];
	--*count;
	heapify(pq,*count-1);
}

int main()
{
	node pq[100];int count=0;
	
	insert(pq,&count);
	insert(pq,&count);
	insert(pq,&count);
	insert(pq,&count);
	insert(pq,&count);
	display(pq,count);
	printf("\n\n");
	delete(pq,&count);
	display(pq,count);
	return 0;
}
