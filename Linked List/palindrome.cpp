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
string lltos(struct node *head)
{
	string st="";
	while(head!=NULL)
	{
		st.append(head->data);
		head=head->next;
	}
	return st;
}
bool ispalindrome(string st)
{
	int i,j,size=st.size();
	for(i=0,j=size-1;i<=j;i++,j--)
	{
		if(st[i]!=st[j])
			return false;
	}
	return true;
}
int main()
{
	struct node* start=NULL;
	start=append(start,"37");
	start=append(start,"4");
	start=append(start,"73");
	string st=lltos(start);
	if(ispalindrome(st))
		cout<<"true\n";
	else
		cout<<"false\n";
}
