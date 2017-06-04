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
void printArray(int path[],int pathLen)
{
	for(int temp=0;temp<pathLen;temp++)
		cout<<path[temp]<<" ";
	cout<<"\n";
}
void printRtoL(struct node* node,int path[],int pathLen) 
{
	if (node == NULL) 
		return;
	path[pathLen++]=node->data;
	if(node->left==NULL&&node->right==NULL)
		printArray(path,pathLen);
	printRtoL(node->left,path,pathLen);
	printRtoL(node->right,path,pathLen);
}  

int main()
{
	struct node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5); 
	int path[10000];
	printRtoL(root,path,0);
}

