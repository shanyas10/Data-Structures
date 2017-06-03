#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *next;
	int data;
};

struct node *addToEmpty(struct node *last,int data)
{
	assert(last==NULL);
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	last=temp;
	last->next=last;
	return last;
}
struct node *addToEnd(struct node *last,int data)
{
	if(last==NULL)
		last=addToEmpty(last,data);
	else
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
	return last;
}
void split(struct node* head, struct node **h1, struct node **h2)
{
	struct node *fast,*slow;
	fast=slow=head;
	while(fast->next!=head&&fast->next->next!=head)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	if(fast->next->next==head)
		fast=fast->next;
	*h1=head;
	if(head->next != head)
		*h2=slow->next;
	fast->next=slow->next;
	slow->next=head;
}
void traverse(struct node *last)
{
	assert(last!=NULL);
	struct node* temp=last->next;
	cout<<temp->data<<"->";
	temp=last->next->next;
	while(temp!=last->next)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
int main()
{
	struct node *h1,*h2,*last = NULL;
    last = addToEnd(last, 4);
    last = addToEnd(last, 2);
    last = addToEnd(last, 8);
    last = addToEnd(last, 12);
    last = addToEnd(last, 16);
    last = addToEnd(last, 14);
    split(last,&h1,&h2);
    //traverse(last);
    traverse(h2);
    cout<<"\n";
	traverse(h1);	
}
