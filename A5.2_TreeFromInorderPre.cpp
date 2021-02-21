#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{ public:
  int info;
  node* left;
  node* right;
};
int search(int arr[], int strt, int end, int value);
node* newNode(int info);

node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{  static int preIndex = 0;
   if (inStrt > inEnd)
        return NULL;
  /* Pick current node from Preorder traversal using preIndex and increment preIndex */
    
   node* tNode = newNode(pre[preIndex++]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    
     int inIndex = search(in, inStrt, inEnd, tNode->info);

    /* Using index in Inorder traversal, construct left and right subtress */
    
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}
int search(int arr[], int strt, int end, int value)
{   int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

node* newNode(int info)
{   
    node* Node = new node();
    Node->info = info;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
void printInorder(node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout<<node->info<<" ";

    /* now recur on right child */
    printInorder(node->right);
}
int main()
{   int in[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    int pre[] = {50, 25, 12, 37, 30, 40, 75, 62, 60, 70, 87};
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
