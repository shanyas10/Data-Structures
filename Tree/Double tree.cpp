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
int height(struct node* node)
{
	if(node==NULL)
		return 0;
	int left=height(node->left)+1;
	int right=height(node->right)+1;
	if(left>right)
		return left;
	else return right;
};
int levelOrder(struct node *node, int level, int i)
{
	if(node==NULL)
		return 0;
	if(level==1)
		cout<<node->data;
	if(i%2==0)
	{
		levelOrder(node->left,level-1,i);
		levelOrder(node->right,level-1,i);
	}
	else
	{
		levelOrder(node->right,level-1,i);
		levelOrder(node->left,level-1,i);
	}
		
} 
void SpiralOrder(struct node *node)
{
	if(node==NULL)
		return;
	int high=height(node);
	//cout<<high<<"\n";
	for(int temp=1;temp<=high;temp++)
		levelOrder(node,temp,temp);}
int main()
{
	struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
 	SpiralOrder(root);
 
}

