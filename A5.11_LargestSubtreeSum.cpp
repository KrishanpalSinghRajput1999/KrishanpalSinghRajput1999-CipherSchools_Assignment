#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Node{
    Node *left, *right;
    int val;
    
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node* createTree(){
    /*
            3
           / \
          2   20
         /   /  \
        7   5   -8
    
    */
    Node* root = new Node(3);
    
    // Creating 2nd level:
    Node* one = new Node(2);
    Node* two = new Node(20);
    root->left = one;
    root->right = two;
    
    // Creating 3rd level:
    Node* three = new Node(7);
    Node* four = new Node(5);
    Node* five = new Node(-8);
    one->left = three;
    two->left = four;
    two->right = five;
    
    return root;
}

int findMaxSum(Node* root, int &globalMax){
    // Reached end of tree:
    if(root == NULL)
        return 0;
    
    // Find the max sum of children sub-trees recursively:
    int left = findMaxSum(root->left, globalMax);
    int right = findMaxSum(root->right, globalMax);
    
    // Find max of the first three cases:
    int returnMax = std::max(std::max(left, right) + root->val, root->val);
    
    // Find max of the first four cases to update globalMax:
    int max = std::max(returnMax, left + right + root->val);
    
    // Update globalMax:
    if(max > globalMax)
        globalMax = max;
    
    // Return returnMax:
    return returnMax;
}

int main(){
    // Create tree:
    Node* myTree = createTree();
    
    // Set globalSum to minimum possible value:
    int globalMax = INT_MIN;
    findMaxSum(myTree, globalMax);
    
    // Compute and display result:
    cout << "Maximum possible sum: " << globalMax << endl;
    
    return 0;
}
