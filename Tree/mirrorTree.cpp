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
 
void mirror(struct node *node)
{
	if(node==NULL)
		return;
	mirror(node->left);
	mirror(node->right);
	
	struct node *temp=node->left;
	node->left=node->right;
	node->right=temp;
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
	struct node *root = newNode(5);
  root->left        = newNode(6);
  root->right       = newNode(8);
  root->left->left  = newNode(4);
  root->left->right = newNode(3); 
   
  printf("\n Constructed Tree \n");
  inOrder(root);
  mirror(root); 
  printf("\n Mirror Tree \n");  
  inOrder(root);	
}
