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
struct node *deleten(struct node *head, int pos)
{
	int i;
	struct node *temp=head;
	if(head==NULL)
		cout<<"Invalid\n";
	else
	{
		while(temp->next!=NULL&&++i<pos)
			temp=temp->next;
		if(i<pos)
			cout<<"Invalid\n";
		else
			temp->next=temp->next->next;
	}
	return head;
}
struct node *deletenode(struct node *head,int key)
{
	struct node *prev,*temp=head;
	if(head==NULL)
		cout<<"Invalid\n";
	else
	{
		if(temp->data==key)
		{
			head=temp->next;
			free(temp);
		}
		else
		{
			while(temp->next!=NULL&&temp->data!=key)
			{
				prev=temp;
				temp=temp->next;
			}
			if(temp->data!=key)
				cout<<"Invalid\n";
			else
			{
				prev->next=temp->next;
				free(temp);	
			}
		}
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
	disp(start);
	start=deletenode(start,1);
	disp(start);
}
