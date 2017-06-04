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
}
int levelOrder(struct node *node, int level)
{
	if(node==NULL)
		return 0;
	if(level==1)
		return 1;
	return levelOrder(node->left,level-1)+
	levelOrder(node->right,level-1);	
} 
int getWidth(struct node *node)
{
	int width,high,max=0;
	if(node==NULL)
		return 0;
	high=height(node);
	cout<<high<<"\n";
	for(int temp=1;temp<=high;temp++)
	{
		width=levelOrder(node,temp);
		if(width>max)
			max=width;
	}
	return max;
}
int main()
{
	struct node *root 	= newNode(10);
    root->left 			= newNode(12);
    root->right 		= newNode(15);
    root->left->left 	= newNode(25);
    root->left->right 	= newNode(30);
    root->right->left 	= newNode(36);
    root->right->right 	= newNode(0);
 	int width=getWidth(root);
 	cout<<width;
 
}

