#include<bits/stdc++.h>
using namespace std;

struct Stack
{
	int capacity;
	int top;
	int *arr;
};
struct Stack* createStack(int capacity)
{
	struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
	s->capacity=capacity;
	s->arr=(int*)malloc(sizeof(sizeof(int)*capacity));
	s->top=-1;
}
int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top--];
}

void insSorted(struct Stack* stack, int data)
{
	if(isEmpty(stack)||data>stack->top)
		push(stack,data);
	else
	{
		int temp=pop(stack);
		insSorted(stack,data);
		
		push(stack,temp);
	}
}

void sortStack(struct Stack *stack)
{
	if(!isEmpty(stack))
	{
		int temp=pop(stack);
		sortStack(stack);
		
		insSorted(stack,temp);
	}
}

int main()
{
	struct Stack* stack = createStack(100);
 
    push(stack, -3);
    push(stack, 14);
    push(stack, 18);
    push(stack, -5);
    push(stack, 30);
     	
 	sortStack(stack);
 	cout<<"---------------------";
 	cout<<pop(stack)<<"\n";
 	cout<<pop(stack)<<"\n";
 	cout<<pop(stack)<<"\n";
 	cout<<pop(stack)<<"\n";
 	cout<<pop(stack)<<"\n";
}
 
