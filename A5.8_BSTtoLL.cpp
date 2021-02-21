#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
void printDLL(Node* &head)
{
    Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}
{
    
    if (curr == nullptr) {
        return;
    }
 
    // recursively convert the left subtree first
    convert(curr->left, head, prev);
 
    // adjust pointers
    if (prev != nullptr)
    {
        // set the current node's left child to `prev`
        curr->left = prev;
 
        // make the previous node's right child as `curr`
        prev->right = curr;
    }
 
    // if `prev` is null, then update the head of doubly linked list
    // as this is the first node in inorder
    else {
        head = curr;
    }
    prev = curr;
 
    // recursively convert the right subtree
    convert(curr->right, head, prev);
}
 
// In-place convert a given binary tree into a doubly linked list
void convert(Node* root)
{
    // `prev` keeps track of the previously processed node in the
    // inorder traversal
    Node* prev = nullptr;
 
    // convert the above binary tree into doubly linked list
    // (using inorder traversal)
    convert(root, root, prev);

    printDLL(root);
}
 
int main()
{
    /* Construct the following tree
              1
           /     \
          2       3
         / \     / \
        4   5   6   7
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    convert(root);
 
    return 0;
}
