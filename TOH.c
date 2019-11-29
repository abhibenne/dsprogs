#include<stdio.h>


void TOH(int n,char s,char t,char d)
{
	if(n==1)
	{
		printf("%d to be moved from %c to %c\n",n,s,d);
		return;
	}
	else
	{
		TOH(n-1,s,d,t);
		printf("%d to be moved from %c to %c\n",n,s,d);
		TOH(n-1,t,s,d);
	}
}



int main()
{
	int n=3;
	TOH(n,'s','t','d');
	return 0;
}