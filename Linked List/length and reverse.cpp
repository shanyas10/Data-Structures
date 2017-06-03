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
int lengthr(struct node *start)
{
	if(start==NULL)
		return 0;
	else
		return 1+lengthr(start->next);
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
struct node *swapn(struct node* head, int x,int y)
{
	struct node *temp1,*temp2,*prev1,*prev2,*n1;
	temp1=temp2=head;
	prev1=prev2=NULL;
	if(head==NULL)
		cout<<"Invalidh\n";
	else
	{
		while(temp1->data!=x&&temp1->next!=NULL)
		{
			prev1=temp1;
			temp1=temp1->next;
		}
		while(temp2->data!=y&&temp2->next!=NULL)
		{
			prev2=temp2;
			temp2=temp2->next;
		}
		if(temp1->data!=x||temp2->data!=y)
			cout<<"Invalidd\n";
		else
		{
			if(prev1!=NULL)
				prev1->next=temp2;
			else
				head=temp2;
			if(prev2!=NULL)
				prev2->next=temp1;
			else
				head=temp1;
			n1=temp1->next;
			temp1->next=temp2->next;
			temp2->next=n1;
		}
	}
	return head;
}
int main()
{
	struct node *start=NULL;
	start=append(start,1);
	start=append(start,2);
	start=append(start,3);
	start=append(start,4);
	start=append(start,5);
	start=append(start,6);
	start=append(start,7);
	//cout<<lengthi(start);
	start=swapn(start,1,7);
	disp(start);
}
