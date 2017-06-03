#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
	bool visited=false;
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
bool loop(struct node *head)
{
	if(head==NULL)
		return false;
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->visited==false)
			temp->visited=true;
		else
			return true;
		temp=temp->next;
	}
	return false;
}
bool loopP(struct node *start)
{
	struct node *s,*d;
	s=d=start;
	while(d->next->next!=NULL&&d!=s)
	{
		d=d->next->next;
		s=s->next;
	}
	if(d==s)
		return true;
	return false;
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
	//start->next->next->next->next->next->next->next=start->next;
	if(loop(start)==true)
		cout<<"true\n";
	else
		cout<<"false\n";
}
