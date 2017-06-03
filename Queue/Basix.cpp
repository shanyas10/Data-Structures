#include<bits/stdc++.h>
using namespace std;
struct Queue
{
	int *array;
	int front,rear,size;
	unsigned capacity;
};
struct Queue* create_Queue(int capacity)
{
	struct Queue* newQ=(struct Queue*)malloc(sizeof(struct Queue));
	newQ->capacity=capacity;
	newQ->front=newQ->size=0;
	newQ->rear=newQ->capacity-1;
	newQ->array=(int*)malloc(sizeof(newQ->capacity*sizeof(int)));
}
int isFull(struct Queue* Q)
{
	return (Q->size==Q->capacity);
}
int isEmpty(struct Queue* Q)
{
	return (Q->size==0);
}
void enqueue(struct Queue* Q,int item)
{
	if(isFull(Q))
		return;
	Q->rear=(Q->rear+1)%(Q->capacity);
	Q->array[Q->rear]=item;
	Q->size=Q->size+1;
}
int dequeue(struct Queue* Q)
{
	int item;
	if(isEmpty(Q))
		return 0;
	item=Q->array[Q->front];
	Q->front=(Q->front+1)%Q->capacity;
	Q->size=Q->size-1;
	return item;
}
int front(struct Queue* Q)
{
	if(!isEmpty(Q))
		return Q->array[Q->front];
}
int rear(struct Queue* Q)
{
	if(!isEmpty(Q))
		return Q->array[Q->rear];
}
int main()
{
	struct Queue* queue = create_Queue(10);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n", dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}
