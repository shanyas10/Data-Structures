#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *push(struct node *head, int data)
{
	struct node *newn= (struct node*)malloc(sizeof(struct node));
	newn->data=data;
	if(head==NULL)
	{
		head=newn;
		newn->next=NULL;
	}
	else
	{
		newn->next=head;
		head=newn;
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
struct node *pushp(struct node* head, int data,int pos)
{
	int i=0;
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	struct node* temp=head;
	while(temp->next!=NULL&&++i<pos)
		temp=temp->next;
		
	if(i<pos)
		cout<<"Invalid\n";
	else
	{
		newn->next=temp->next;
		temp->next=newn;	
	}
	return head;
}
int main()
{
	struct node *start=NULL;
	int ele;
	char ch;
	disp(start);
	do
	{
		cout<<"Enter the element\n";
		cin>>ele;
		start=append(start,ele);	
		cout<<"Want to enter mre y/n\n";
		cin>>ch;
	}while(ch=='y');
	start=pushp(start,9,4);
	disp(start);
}
