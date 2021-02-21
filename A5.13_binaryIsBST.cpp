#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
bool isBST(Node* node, int minKey, int maxKey)
{
    // base case
    if (node == NULL) {
        return true;
    }
 
    // if the node's value falls outside the valid range
    if (node->data < minKey || node->data > maxKey) {
        return false;
    }
 
    // recursively check left and right subtrees with an updated range
    return isBST(node->left, minKey, node->data) &&
            isBST(node->right, node->data, maxKey);
}
 
// Function to determine if a given binary tree is a BST or not
void isBST(Node* root)
{
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("The tree is a BST.");
    }
    else {
        printf("The tree is not a BST!");
    }
}
 
int main()
{
    Node* root = nullptr;
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    for (int key: keys) {
        root = insert(root, key);
    }
    swap(root->left, root->right);
    isBST(root);
 
    return 0;
}
