#include<bits/stdc++.h>
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};
struct Stack* createStack(unsigned capacity)
{
	struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
	if(!stack)
		return NULL;
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	if(!stack->array)
		return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}
void push(struct Stack *stack,char data)
{
	stack->array[++stack->top]=data;
}
char pop(struct Stack* stack)
{
	if(!isEmpty(stack))
		return stack->array[stack->top--];
}
void reverse(char* string)
{
	int i;
	struct Stack* stack=createStack(strlen(string));
	for(i=0;string[i];i++)
		push(stack,string[i]);
	i=0;
	while(!isEmpty(stack))
		string[i++]=pop(stack);
	printf("%s",string);
}
int main()
{
	char string[]="Shanya";
	reverse(string);
}
