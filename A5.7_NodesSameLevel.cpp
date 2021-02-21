#include <iostream>
using namespace std;
#include <queue>
// A tree node
struct Tree
{
    char data;
    Tree *left;
    Tree *right;
 Tree *right_neighbor;
 Tree(char data)
   {
       this -> data = data;
       left = NULL;
       right = NULL;
       right_neighbor = NULL;
   }
};
// Function to print the right_neighbor of the nodes
void PreOrderTraversal(Tree *node)
{
    if(node == NULL){
      return;
 }
 else{
   if(node -> right_neighbor != NULL){
     cout << node -> data << "-> " << node -> right_neighbor -> data << endl;
   }
   else{
     cout << node -> data << "-> NULL" << endl;
   }
   PreOrderTraversal(node -> left);
   PreOrderTraversal(node -> right);
 }
}
int main() {
  // The tree
  Tree *root = new Tree('a');
  root -> left = new Tree('b');
  root -> right = new Tree('c');
  root -> left -> left = new Tree('d');
  root -> left -> right = new Tree('e');
  queue <Tree*> Q;
  // Enqueue the root node
  Q.push(root);
  // Enqueue NULL to serve a partition between levels
  Q.push(NULL);
  while (!Q.empty()){
    // Dequeue the element from the front of the queue
    Tree *node = Q.front();
    Q.pop();
    if(node == NULL){
      // This shows that a level has finished, so enqueue
      // NULL to denote that.
      if(!Q.empty()){
      Q.push(NULL);
      }
    }
    else{
      // Peek at the element at the front of the queue and
      // set the right pointer to the adjacent element in the queue
      node -> right_neighbor = Q.front();
      // Enqueue its left and right children if they exist
      if(node -> left != NULL){
        Q.push(node -> left);
      }
      if(node -> right != NULL){
        Q.push(node -> right);
      }
    }
  }
  PreOrderTraversal(root);
  return 0;
}
