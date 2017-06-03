#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class Dequeue
{
	int arr[MAX];
	int front;
	int rear;
	int size;
	
	public:
		Dequeue(int size)
		{
			front =-1;
			rear=0;
			this->size=size;
		}
	void insertFront(int key);
	void insertRear(int key);
	void deleteFront();
	void deleteRear();
	bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
bool Dequeue::isFull()
{
	return((front==0&&rear==size-1)||(front==rear+1));
}
bool Dequeue::isEmpty()
{
	return(front==-1);
}
void Dequeue::insertFront(int key)
{
	if(isFull())
		return;
	if(isEmpty())
	{
		front=rear=0;
	}
	else if(front==0)
		front=size-1;
	else
		front--;
	arr[front]=key;
}
void Dequeue::insertRear(int key)
{
	if(isFull())
		return;
	if(isEmpty())
	{
		front=rear=0;
	}
	else if(rear==size-1)
		rear=0;
	else
		rear++;
	arr[rear]=key;
}
void::Dequeue::deleteFront()
{
	if(isEmpty())
		return;
	if(front==size-1)
		front=0;
	else if(front==rear)
	{
		front=-1;
		rear=-1;	
	}
	else
		front++;
}
void::Dequeue::deleteRear()
{
	if(isEmpty())
		return;
	if(rear==0)
		rear=size-1;
	else if(front==rear)
	{
		front=-1;
		rear=-1;	
	}
	else
		rear--;
}
int Dequeue::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Dequeue::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[rear];
}
 
// Driver program to test above function
int main()
{
    Dequeue dq(5);
    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);
 
    cout << "get rear element " << " "
         << dq.getRear() << endl;
 
    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "inserting element at front end \n";
    dq.insertFront(15);
 
    cout << "get front element " << " "
         << dq.getFront() << endl;
 
    dq.deleteFront();
 
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;
    return 0;
}
