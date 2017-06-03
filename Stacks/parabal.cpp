#include<bits/stdc++.h>
using namespace std;
class Stack
{
	int top;
	int size;
	char *array;
	public:
	Stack(int n)
	{
		cout<<n<<"\n";
		size=n;
		array=new char[n];
		top=-1;
	}
	void push(char x)
	{
		if(top<size-1)
			array[++top]=x;
		else
			cout<<"Stack Overflow";
	}
	char pop()
	{
		if(!isEmpty())
			return array[top--];
		else
			cout<<"Stack Underflow";
	}
	int isEmpty()
	{
		return top==-1;
	}
};
int isBalanced(string s)
	{
		char p;
		Stack par(s.size());
		for(int i=0;s[i];i++)
		{
			if(s[i]=='{'||s[i]=='('||s[i]=='[')
				par.push(s[i]);
			else if(s[i]=='}'||s[i]==')'||s[i]==']')
			{
				if(!par.isEmpty())
				{
					p=par.pop();
				}
				else
					return 0;
				switch(s[i])
				{
					case '}':
					{
						if(p!='{')
							return 0;	
						break;
					}
					case ')':
					{
						if(p!='(')
							return 0;	
						break;
					}
					case ']':
					{
						if(p!='[')
							return 0;
						break;	
					}	
				}	
			}
		}
	return 1;
}
int main()
{
	string s="{()(){}}}[]";
	if(isBalanced(s))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}

