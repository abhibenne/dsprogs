#include<stdio.h>


void bot_up_heap(int *h,int n)
{
	int k;
	for(k=(n-1)/2;k>=0;k--)
	{
		int j=k;
		int key=h[j];
		int i=2*j+1;
		while(i<=n)
		{
			if((i+1)<=n)
			{
				if(h[i+1]>h[i])
					i++;
			}
			if(h[i]>key)
			{
				h[j]=h[i];
				j=i;
				i=2*j+1;
			}
			else
				break;
		}
		h[j]=key;
	}
}

void top_down(int* h,int n)
{
	int k;
	for(k=1;k<=n;k++)
	{
		int i=k;
		int key=h[i];
		int j=(i-1)/2;
		while((i>0) && h[j]>key)
		{
			h[i]=h[j];
			i=j;
			j=(i-1)/2;
		}
		h[i]=key;
	}	
}


int main()
{
	int a[]={1,2,3,4,5,6,12,7,8,9};
	int n=sizeof(a)/sizeof(int);
	bot_up_heap(a,n-1);int i;
	printf("max heaps\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
	top_down(a,n-1);
	printf("Now min heap\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
