#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int postfix_eval(char* s)
{
	int i=0;int top=-1;int stack[strlen(s)];
	while(s[i])
	{
		if(isalnum(s[i]))
		{
			stack[++top]=s[i]-'0';
		}
		else
		{
			int t1=stack[top--];
			int t2=stack[top--];int res;
			if(s[i]=='+')
				res=t1+t2;
			if(s[i]=='-')
				res=t2-t1;
			if(s[i]=='*')
				res=t1*t2;
			if(s[i]=='/')
				res=t2/t1;
			stack[++top]=res;
		}
		i++;
	}
	return stack[top];
}



int main()
{
	char s[]="231*+9-";
	int eval=postfix_eval(s);
	printf("%d\n", eval);
	return 0;
}
