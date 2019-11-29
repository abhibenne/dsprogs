// infix to postfix using stack
#include<stdio.h>
#include<string.h>

int precedence(char c)
{
	if(c=='(' || c=='{' || c=='[')
		return 0;
	if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/' || c=='%')
		return 2;
	else
		return 3;
}



void infix_to_postfix(char* s)
{
	char out[strlen(s)];int j=0;
	int i=0;int top=-1;int stack[strlen(s)];
	while(s[i])
	{
		if(isalnum(s[i]))
		{
			out[j++]=s[i];
		}
		else if(s[i]=='(' || s[i] == '{' || s[i] =='[')
		{
			stack[++top]=s[i];
		}
		else if(s[i]==')' || s[i] == '}' || s[i] ==']')
		{
			if(s[i]==')')
			{
				while(top!=-1 && stack[top]!='(')
				{
					out[j++]=stack[top--];
				}
			}
			if(s[i]=='}')
			{
				while(top!=-1 && stack[top]!='{')
				{
					out[j++]=stack[top--];
				}
			}
			if(s[i]==']')
			{
				while(top!=-1 && stack[top]!='[')
				{
					out[j++]=stack[top--];
				}
			}
			stack[top--];
		}
		else
		{
			while(top!=-1 && precedence(s[i])<=precedence(stack[top]))
			{
				out[j++]=stack[top--];
			}
			stack[++top]=s[i];
		}
		i++;
	}
	while(top!=-1)
	{
		out[j++]=stack[top--];
	}
	for(i=0;i<j;i++)
	{
		printf("%c",out[i]);
	}
}

int main()
{
	char s[]="A+(B*C-(D/E^F)*G)*H";//  ABC*DEF^/G*-H*+
	infix_to_postfix(s);int i=0;
	return 0;
}
