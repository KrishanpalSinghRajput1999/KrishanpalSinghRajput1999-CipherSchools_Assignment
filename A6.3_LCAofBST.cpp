#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
};
Node* create(int x){
  Node* temp=new Node;
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
Node *lca(Node* root ,int n1 ,int n2 )
{
   if(root==NULL)return NULL;
   if(root->data==n1||root->data==n2)return root;
   Node* left=lca(root->left,n1,n2);
   Node* right=lca(root->right,n1,n2);
   if(!left&&!right)return NULL;
   if(left&&right)return root;//lca found
   if(!left&&right)return right;
   if(!right&&left)return left;
}
int main(){
  Node* root=create(1);
  root->left=create(2);
  root->left->right=create(3);
  root->left->right->left=create(4);
  root->left->right->right=create(5);
  root->right=create(6);
  root->right->left=create(7);
  root->right->left->right=create(8);
  root->right->right=create(9);
  Node* temp=lca(root,8,9);
  if(temp)
  cout<<"LCA of node 8 and 9 is: "<<temp->data<<endl;
  else cout<<" Not found "<<endl;
}
