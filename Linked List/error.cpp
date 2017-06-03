#include<bits/stdc++.h>
using namespace std;
struct node
{
	char *data;
	struct node *next;
};
struct node* append(struct node *head,char *data)
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
int main()
{
	struct node* start=NULL;
	start=append(start,"37");
	start=append(start,"4");
	start=append(start,"5");
}
