#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node* next;
	struct node* prev;
	int data;
};
struct node *append(struct node* head,int data)
{
	struct node *temp=head;
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->next=NULL;
	newn->data=data;
	if(head==NULL)
	{
		head=newn;
		newn->prev=NULL;
		return head;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	newn->prev=temp;
	temp->next=newn;
	return head;
}
struct node* deleten(struct node *head, int pos)
{
	assert(head!=NULL);
	struct node *temp=head;
	int i=0;
	while(temp->next!=NULL&&++i<=pos)
		temp=temp->next;
	assert(i>=pos);
	if(temp->prev!=NULL)
		temp->prev->next=temp->next;
	if(temp->next!=NULL)
	temp->next->prev=temp->prev;
	free(temp);
	return head;
}
void disp(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}
int main()
{
	struct node *head=NULL;
	head=append(head,4);
	head=append(head,5);
	head=append(head,6);
	head=append(head,7);
	head=append(head,8);
	head=deleten(head,4);
	disp(head);
}
