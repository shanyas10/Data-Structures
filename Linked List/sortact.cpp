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
struct node *sortact(struct node* head)
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		if(temp->data<0)
			head=push(head,temp->data);
	}
	return head;
}
int main()
{
	struct node *start=NULL;
	start=append(start,1);
	start=append(start,-2);
	start=append(start,3);
	start=append(start,-4);
	start=append(start,5);
	start=append(start,-6);
	start=append(start,7);
	start=sortact(start);
	disp(start);
}
