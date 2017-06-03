#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node* next;
	struct node* prev;
	int data;
};
void disp(struct node *head)
{
	while(head!=NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}
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
struct node *reverse(struct node *head)
{
	struct node *next,*current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=current->prev;
		current->prev=next;
		if(next==NULL)
			next=current;
		current=current->prev;
	}
	head=next;
	return head;
}
int main()
{
	struct node *head=NULL;
	head=append(head,4);
	head=append(head,5);
	head=append(head,6);
	head=append(head,7);
	head=append(head,8);
	disp(head);
	head=reverse(head);
	disp(head);
}
