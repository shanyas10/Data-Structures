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

struct node *buildTree(int in[], int pre[], int start, int end)
{
	static int preIndex=0;
	int inIndex;
	if(start>end)
		return NULL;
	struct node *tNode=newNode(pre[preIndex++]);
	if(start==end)
		return tNode;
	inIndex=search(tNode->data,in,start,end);
	//cout<<inIndex<<" ";
	tNode->left=buildTree(in,pre,start,inIndex-1);
	tNode->right=buildTree(in,pre,inIndex+1,end);
	return tNode;
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
	int in[] = {4, 2, 5, 1, 6, 3};
	int pre[] = {1, 2, 4, 5, 3, 6};
	int len = sizeof(in)/sizeof(in[0]);
	struct node *root = buildTree(in, pre, 0, len - 1);
	inOrder(root);
}

