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
void nge(int *a,int n)
{
	Stack nge(n);
	int p;
	nge.push(a[0]);
	int ng[n];
	for(int i=1;i<n;i++)
	{
		while(!nge.isEmpty())
		{
			p=nge.pop();
			
			if(p>a[i])
			{
				nge.push(p);
				break;	
			}	
			else
				cout<<p<<" "<<a[i]<<"\n";
		}
		nge.push(a[i]);
	}
	cout<<a[n-1]<<" "<<"-1\n";
}
int main()
{
	int array[]={4,5,12,3,7,1,8,13};
	int l=sizeof(array)/sizeof(array[0]);
	nge(array,l);
}
