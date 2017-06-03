#include<bits/stdc++.h>
using namespace std;
struct Node
{
	struct Node *next;
	int data;
};
struct Node* push(struct Node* head, int data)
{
	struct Node* newN=(struct Node*)malloc(sizeof(struct Node));
	newN->data=data;	
	if(head==NULL)
		newN->next=NULL;
	else
		newN->next=head;
	head=newN;
	return head;
}
void disp(struct Node *head)
{
	while(head!=NULL)
	{
		printf("%d",head->data);
		head=head->next;
	}
}
void sum(struct Node *h1, struct Node *h2)
{
	int s,carry=0,d1,d2;
	struct Node *h3=NULL;
	while(h1!=NULL||h2!=NULL)
	{
		if(h1==NULL)
		{
			d1=0;
			d2=h2->data;
			h2=h2->next;	
		}
		else if(h2==NULL)
		{
			d2=0;
			d1=h1->data;
			h1=h1->next;
		}
		else if(h1!=NULL&&h2!=NULL)
		{
			d1=h1->data;
			d2=h2->data;
			h1=h1->next;
			h2=h2->next;
		}
		s=d1+d2+carry;
		carry=s/10;
		s=s%10;
		h3=push(h3,s);
	}
	disp(h3);
}
int main()
{
	struct Node *h1,*h2;
	h1=h2=NULL;
	h1=push(h1,2);
	h1=push(h1,5);
	h1=push(h1,0);
	h2=push(h2,3);
	h2=push(h2,5);
	sum(h1,h2);
}
