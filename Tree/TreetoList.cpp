/*	Program to convert a binary tree to cicular doubly linked list which stores the elements in InOrder fashion.
	We first make a left and a right circular doubly LL which contains the left and the right subtree respectively.
	Thereafter, we concatenate the Left LL to the node and then this entire List to the right LL.*/

#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data)
 
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}
 
int search (int data,int arr[],int start, int end)
{
	int i;
	for(i = start; i <= end; i++)
  	{
    	if(arr[i] == data)
      	return i;
  	}	
}
struct node *concatenate(struct node *h1, struct node *h2)
{
	if(h1==NULL&&h2==NULL)
		return NULL;
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	
	struct node* temp	=h1->left;
	h2->left->right		=h1;
	h1->left->right		=h2;
	h1->left			=h2->left;
	h2->left			=temp;
	return h1;
}
struct node *bTreetoList(struct node* node) 
{
	if (node == NULL) 
		return NULL; 
	struct node* left=bTreetoList(node->left);
	struct node* right=bTreetoList(node->right);
	node->left=node->right=node;
	return concatenate(concatenate(left,node),right);
}  
void display(struct node *head)
{
	struct node* temp=head;
	if(head==NULL)
		return;
	while(temp->right!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->right;
	}
	cout<< temp->data;
}
void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}  
int main()
{
	struct node *root 	= newNode(10);
    root->left 			= newNode(12);
    root->right 		= newNode(15);
    root->left->left 	= newNode(25);
    root->left->right 	= newNode(30);
    root->right->left 	= newNode(36);
 	inOrder(root);
	 cout<<"\n";	
    struct node *head = bTreetoList(root);
    display(head);
 
}

