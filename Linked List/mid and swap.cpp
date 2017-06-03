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
int lengthi(struct node* start)
{
	int length=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;	
	}
	return length;
}
int middle(struct node* start,int length)
{
	struct node *temp=start;
	int mid,i=0;
	if(length%2==0)
		mid=length/2;
	else
		mid=(length+1)/2;
	while(++i<mid)
		temp=temp->next;
	return temp->data;
}
int mid(struct node *start)
{
	struct node *s,*d;
	s=d=start;
	while(d->next->next!=NULL)
	{
		d=d->next->next;
		s=s->next;
	}
	return s->data;
}
struct node *reverse(struct node *head)
{
	struct node *curr,*prev,*next;
	curr=head;
	prev=NULL;
	if(head==NULL)
		return NULL;
	do
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		if(next!=NULL)
			curr=next;
	}while(next!=NULL);
	head=curr;
	return head;
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
	disp(start);
	cout<<"\n";
	start=reverse(start);
	disp(start);
	//length=lengthi(start);
	//cout<<mid(start);
}
