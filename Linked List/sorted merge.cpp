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
struct node *sortmg(struct node*headA,struct node *headB)
{
    struct node *temp;
    if(headA==NULL)
    	return headB;
    if(headA->data<headB->data)
    	headA->next=sortmg(headA->next,headB);
    else
    {
    	temp=headB;
    	headB=headB->next;
    	temp->next=headA;
    	headA=temp;
    	headA->next=sortmg(headA->next,headB);
	}
	return headA;
	return headA;
}
int main()
{
	int length;
	struct node *a,*b,*res;
	a=b=NULL;
	a=append(a,1);
	b=append(b,2);
	a=append(a,3);
	a=append(a,4);
	b=append(b,5);
	a=append(a,6);
	b=append(b,7);
	res=sortmg(a,b);
	disp(res);
}
