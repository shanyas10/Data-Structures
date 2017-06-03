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
struct node *addToBeg(struct node *last,int data)
{
	if(last==NULL)
		last=addToEmpty(last,data);
	else
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
	}
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
	struct node *last = NULL;
    last = addToEmpty(last, 6);
    last = addToBeg(last, 4);
    last = addToBeg(last, 2);
    last = addToEnd(last, 8);
    last = addToEnd(last, 12);
	traverse(last);	
}
