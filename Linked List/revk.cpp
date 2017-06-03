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
struct node* revk(struct node* start,int k)
{
	int count=0;
	struct node *prev,*next,*current=start;
	prev=NULL;
	while(current!=NULL&&count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	count=0;
	if(start!=NULL)
		start->next=current;
	while(current!=NULL&&count<k-1)
	{
		count++;
		current=current->next;
	}
	if(current!=NULL)
		current->next=revk(current->next,k);
	return prev;
}
struct node* revg(struct node* start,int k)
{
	int count=0;
	struct node *prev,*next,*current=start;
	prev=NULL;
	while(current!=NULL&&count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	if(current!=NULL)
		start->next=revg(current,k);
	return prev;
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
	start=append(start,7);
	start=append(start,8);
	start=append(start,9);
	//start=revk(start,2);
	start=revg(start,3);
	disp(start);
}
