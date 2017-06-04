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
void mergeSort(struct Node *head)
{
	struct Node *a;
	struct Node *b;
	struct Node *temp;
	if(temp==NULL)
		return;
	Frontbacksplit(head,a,b);
	MergeSort(a);
	MergeSort(b);
	
	head=SortedMerge(a,b);
}
struct Node* SortedMerge(struct Node *h1, struct Node* h2)
{
	struct node *result=NULL:
	if(h1==NULL)
		return h2;
	else if(h2==NULL)
		return h1;
	if(h1->data<h2->data)
	{
		result =h1;
		result->next=SortedMrge(h1->next,h2);
	}
	if(h2->data<h2->data)
	{
		result =h2;
		result->next=SortedMrge(h1,h2->next);
	}
	return result;
}
