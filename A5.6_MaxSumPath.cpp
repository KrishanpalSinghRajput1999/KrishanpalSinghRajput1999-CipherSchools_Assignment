#include <iostream>
#include <climits>
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
 
// Recursive function to find the maximum sum path between two leaves
// in a binary tree
int maxSumPath(Node *root, int &max_sum)
{
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }
 
    // find the maximum sum node-to-leaf path starting from the left child
    int left = maxSumPath(root->left, max_sum);
 
    int right = maxSumPath(root->right, max_sum);
 
    int cur_sum = left + right + root->data;

    max_sum = max(cur_sum, max_sum);
    if (root->left == nullptr) {
        return right + root->data;
    }
 
    // case 2: right child is null
    if (root->right == nullptr) {
        return left + root->data;
    }
 
    // case 3: both left and right child exists
    return max(left, right) + root->data;
}
int maxSumPath(Node* root)
{
    int max_sum = INT_MIN;
    maxSumPath(root, max_sum);
 
    return max_sum;
}
int main()
{
    Node* root = nullptr;
    /* Construct the following tree
          1
        /   \
       /     \
      2       3
       \     / \
       -4   5   6
           / \
          7   8
    */
 
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(-4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    cout << maxSumPath(root) << endl;
 
    return 0;
}
