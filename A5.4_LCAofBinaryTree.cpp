
#include<stdio.h>
#include<malloc.h>
#include<vector>
#include<iostream>
using namespace std;
typedef struct binaryTree
{
	struct binaryTree * left;
	struct binaryTree *	right;
	int value;
} binaryTree;

binaryTree* newNode(int data) 
{
  binaryTree* node = (binaryTree*)
                       malloc(sizeof(binaryTree));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

int findLCA(binaryTree *root,int a,int b)
{
	if(root == NULL)
		return -1;
	if(root->value == a || root->value == b)
		return root->value;

	int l = findLCA(root->left,a,b);
	int r = findLCA(root->right,a,b);

	if(l != -1 && r!= -1)
		return root->value;
	else
	{
		if(l!= -1)
			return l;
		else
			return r;
	}
}

int main()
{
    binaryTree * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
}
