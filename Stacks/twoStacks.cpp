#include<bits/stdc++.h>
using namespace std;
class twoStacks
{
	int top1,top2;
	int size;
	int *arr;
	public:
		twoStacks(int n)
		{
			size=n;
			arr=new int[n];
			top1=-1;
			top2=size;
		}
		void push1(int n)
		{
			if(top1<top2-1)
				arr[++top1]=n;
			else
				cout<<"Stack Overflow";
		}
		void push2(int n)
		{
			if(top2>top1+1)
				arr[--top2]=n;
			else
				cout<<"Stack Overflow";
		}
		int pop1()
		{
			if(top1!=-1)
				return arr[top1--];
			else
				cout<<"Stack Underflow!";
		}
		int pop2()
		{
			if(top2!=size)
				return arr[top2++];
			else
				cout<<"Stack Underflow!";
		}
};
int main()
{
	twoStacks ts(8);
	ts.push1(1);
	ts.push1(2);
	ts.push1(3);
	cout<<"1 "<<ts.pop1()<<"\n";
	ts.push2(8);
	ts.push2(6);
	ts.push1(9);
	cout<<"2 "<<ts.pop2()<<"\n";
	ts.push2(3);
}
