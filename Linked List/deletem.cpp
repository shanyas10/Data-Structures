#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *append(struct node *head,int data)
{
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	struct node *temp=head;
	if(head==NULL)
	{
		newn->next=head;
		head=newn;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		newn->next=NULL;
		temp->next=newn;
	}
	return head;
}
void disp(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
}
void deletemw(struct node *n)
{
	assert(n!=NULL&&n->next!=NULL);
	
	n->data=n->next->data;
	n->next=n->next->next;
}
int main()
{
	int length;
	struct node *start=NULL;
	start=append(start,1);
	start=append(start,2);
	start=append(start,3);
	start=append(start,4);
	start=append(start,5);
	start=append(start,6);
	deletemw(start->next->next);
	disp(start);
}
