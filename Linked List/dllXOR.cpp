#include<bits/stdc++.h>
using namespace std;
struct node
{
	struct node *npx;
	int data;
};
struct node* XOR (struct node *a, struct node *b)
{
    return (struct node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
struct node *insert(struct node* head,int data)
{
	
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	
	newn->npx=XOR(head,NULL);
	newn->data=data;
	if(head!=NULL)
	{
		struct node *next=XOR((head->npx),NULL);
		head->npx=XOR(next,newn);
	}
	head=newn;
	
	//cout<<head->data;
	//if(next!=NULL)
		//cout<<next->data;
	return head;
}
void printList(struct node *head)
{
	struct node *current,*prev,*next;
	assert(head!=NULL);
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		cout<<current->data<<"->";
		next=XOR((current->npx),prev);
		prev=current;
		current=next;
	}
}
int main()
{
	struct node *head = NULL;
    head=insert(head, 10);
    head=insert(head, 20);
    head=insert(head, 30);
    head=insert(head, 40);
 
    // print the created list
    printList (head);
}
