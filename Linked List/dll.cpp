#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node* next;
	struct node* prev;
	int data;
};
struct node *push(struct node *head, int data)
{
	struct node *temp=head;
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	newn->next=head;
	newn->prev=NULL;
	head=newn;
	return head;
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
struct node* insertA(struct node* pNode,int data)
{
	struct node *newn=(struct node*)malloc(sizeof(struct node));
	newn->data=data;
	newn->next=pNode->next;
	newn->prev=pNode;
	pNode->next=newn;
	if(newn->next!=NULL)
		newn->next->prev=newn;
	return pNode;
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
	head=push(head,3);
	head=append(head,4);
	head->next=insertA(head->next,9);
	head=append(head,10);
	disp(head);
}
