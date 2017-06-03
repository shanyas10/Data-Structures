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

void insBottom(struct Stack* stack, int data)
{
	if(isEmpty(stack))
		push(stack,data);
	else
	{
		int temp=pop(stack);
		insBottom(stack,data);
		
		push(stack,temp);
	}
}

void revStack(struct Stack *stack)
{
	if(!isEmpty(stack))
	{
		int temp=pop(stack);
		revStack(stack);
		
		insBottom(stack,temp);
	}
}

int main()
{
	struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
 	
 	revStack(stack);
 	
 	cout<<pop(stack);
 	cout<<pop(stack);
 	cout<<pop(stack);
 	cout<<pop(stack);
}
 
