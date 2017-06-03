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
	int n;
	struct Queue* q1 = create_Queue(100);
	struct Queue* q2 = create_Queue(100);
	struct Queue* q3 = create_Queue(100);
	int sum=0,a[1000],aux[1000];
	cout<<"Enter no of elements ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];	
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]%3==0)
			enqueue(q1,a[i]);
		else if(a[i]%3==1)
			enqueue(q2,a[i]);
		else if(a[i]%3==2)
			enqueue(q3,a[i]);
	}
	int i=0;
	//cout<<sum<<"\n";
	if(sum%3==1)
	{
		int count=0;
		if(!isEmpty(q2))
			dequeue(q2);
		else
		{
			while(!isEmpty(q3)&&count<2)
			{
				dequeue(q3);
				count++;
			}
			if(count<1)
			return 0;
		}
					
	}
	else if(sum%3==2)
	{
		int count=0;
		if(!isEmpty(q3))
			dequeue(q3);
		else
		{
			while(!isEmpty(q2)&&count<2)
			{
				dequeue(q2);
				count++;
			}
			if(count<1)
			return 0;
		}
			
	}	
	while(!isEmpty(q1))
	{
		aux[i]=dequeue(q1);
		//cout<<q1->size<<" ";
		i++;
	}
	while(!isEmpty(q2))
	{
		aux[i]=dequeue(q2);
		//cout<<q2->size<<" ";
		i++;
	}
	while(!isEmpty(q3))
	{
		aux[i]=dequeue(q3);
		i++;
	}
	int size=i;	
	//cout<<size;
	sort(aux,aux+size);
	reverse(aux,aux+size);
	for(int i=0;i<size;i++)
		cout<<aux[i];
    return 0;
}
