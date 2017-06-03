#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};
struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
	if(!stack)
		return NULL;
	stack->capacity=capacity;
	stack->top=-1;
	
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	if(!stack->array)
		return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}
void push(struct Stack* stack,char data)
{
	stack->array[++stack->top]=data;
}
char pop(struct Stack* stack)
{
	if(!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}
int isOperand(char op)
{
	return(op>='a'&&op<='z')||(op>='A'&&op<='Z');
}
int Prec(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1;
}
int in2po(char *exp)
{
	int i,j,k;
	struct Stack* stack=createStack(strlen(exp));
	if(!stack)
		return -1;
	for(i=0,k=-1;exp[i];++i)
	{
		if(isOperand(exp[i]))
			exp[++k]=exp[i];
		else if(exp[i]=='(')
			push(stack,exp[i]);
		else if(exp[i]==')')
		{
			while(!isEmpty(stack)&&peek(stack)!='(')
				exp[++k]=pop(stack);
			if(!isEmpty(stack)&&peek(stack)!='(')
				return -1;
			else
				pop(stack);
		}
		else
		{
			while(!isEmpty(stack)&&Prec(exp[i])<Prec(peek(stack)))
				exp[++k]=pop(stack);
			push(stack,exp[i]);
		}
	}
	while(!isEmpty(stack))
			exp[++k]=pop(stack);
	exp[++k]='\0';
	printf("%s",exp);
}
int main()
{
	char exp[] = "a+b*c+d+e*g";
    in2po(exp);
    return 0;
}
