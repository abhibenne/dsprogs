#include<stdio.h>
#include<stdlib.h>

int a[100][100];
int visit[100];
int n;
int q[100];int f;int r;
void create()
{
	int i,j;
	while(1)
	{
		printf("Enter source and destination\n");
		scanf("%d %d",&i,&j);
		if(i==-1 && j==-1)
			break;
		a[i][j]=a[j][i]=1;
	}
}

void dfs(int v)
{
	printf("%d\t",v);
	visit[v]=1;int i;
	for(i=1;i<=n;i++)
	{
		if(visit[i]==0 && a[v][i]==1)
		{
			dfs(i);
		}	
	}
}



int component()
{
	int i;
	int label=0;
	for(i=0;i<=n;i++)
		visit[i]=0;
	for(i=1;i<=n;i++)
	{
		if(visit[i]==0)
		{
			++label;
			dfs(i);
		}
	}
	return label;
}


void bfs(int v)
{
	int i;
	for(i=1;i<=n;i++)
		visit[i]=0;
	visit[v]=1;
	printf("%d\t", v);
	q[++r]=v;
	while(f!=-1)
	{
		if(f==(r+1))
		{
			f=-1;break;
		}
		int in=q[f++];
		for(i=1;i<=n;i++)
		{
			if(a[in][i]==1 && visit[i]==0)
			{
				printf("%d\t", i);
				q[++r]=i;
				visit[i]=1;
			}
		}
	}
}

int main()
{
	int source,i;f=0;r=-1;
	scanf("%d",&n);
	create();
	for(i=1;i<=n;i++)
	visit[i]=0;
	scanf("%d",&source);
	printf("\n");
	bfs(source);
//	dfs(source);
//	printf("The number of components: %d\n",component());
	return 0;
}
