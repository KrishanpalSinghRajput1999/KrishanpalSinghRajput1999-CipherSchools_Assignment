#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node * next;
};
 
Node* getLoopstart(Node *loop_node, Node *head)
{
    Node *ptr1 = loop_node;
    Node *ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /* Move both pointers at the same pace,
    they will meet at loop starting node */
    while (ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}
 
Node* detectAndgetLoopstarting(Node *head)
{
    Node *slow_p = head, *fast_p = head,*loop_start;
 
    //Start traversing list and detect loop
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet then find
           the loop starting node*/
        if (slow_p == fast_p)
        {
            loop_start = getLoopstart(slow_p, head);
            break;
        }
    }
 
    // Return starting node of loop
    return loop_start;
}
 
// Utility function to check if a linked list with loop
// is palindrome with given starting point.
bool isPalindromeUtil(Node *head, Node* loop_start)
{
    Node *ptr = head;
    stack<int> s;
    int count = 0;
    while (ptr != loop_start || count != 1)
    {
        s.push(ptr->data);
        if (ptr == loop_start)
            count = 1;
        ptr = ptr->next;
    }
    ptr = head;
    count = 0;
 
    // Traverse linked list until last node is
    // equal to loop_start second time
    while (ptr != loop_start || count != 1)
    {
        // Compare data of node with the top of stack
        // If equal then continue
        if (ptr->data == s.top())
            s.pop();
 
        // Else return false
        else
            return false;
 
        if (ptr == loop_start)
            count = 1;
        ptr = ptr->next;
    }
 
    // Return true if linked list is palindrome
    return true;
}
 
// Function to find if linked list is palindrome or not
bool isPalindrome(Node* head)
{
    // Find the loop starting node
    Node* loop_start = detectAndgetLoopstarting(head);
 
    // Check if linked list is palindrome
    return isPalindromeUtil(head, loop_start);
}
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
/* Driver program to test above function*/
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(20);
    head->next->next->next->next = newNode(50);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    isPalindrome(head)? cout << "\nPalindrome"
                     : cout << "\nNot Palindrome";
 
    return 0;
}
