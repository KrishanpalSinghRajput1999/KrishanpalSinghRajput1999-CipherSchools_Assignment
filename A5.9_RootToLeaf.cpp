#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a binary tree node
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
 
// Function to check if a given node is a leaf node or not
bool isLeaf(Node* node)
{
    return (node->left == nullptr && node->right == nullptr);
}
 
// Recursive function to find paths from the root node to every leaf node
void printRootToleafPaths(Node* node, vector<int> &path)
{
    // base case
    if (node == nullptr) {
        return;
    }
 
    // include the current node to the path
    path.push_back(node->data);
 
    // if a leaf node is found, print the path
    if (isLeaf(node))
    {
        for (int data: path) {
            cout << data << " ";
        }
        cout << endl;
    }
 
    // recur for the left and right subtree
    printRootToleafPaths(node->left, path);
    printRootToleafPaths(node->right, path);
 
    // remove the current node after the left, and right subtree are done
    path.pop_back();
}
 
// The main function to print paths from the root node to every leaf node
void printRootToleafPaths(Node* node)
{
    // vector to store root-to-leaf path
    vector<int> path;
 
    printRootToleafPaths(node, path);
}
 
int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
               /     \
              8       9
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->right->right = new Node(9);
 
    // print all root-to-leaf paths
    printRootToleafPaths(root);
 
    return 0;
}
