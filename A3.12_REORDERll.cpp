// This solution is submiitted by me on LEETCODE.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    
     void reorderList(ListNode* head) {
        if(head==NULL)
            return;
        vector<ListNode*> node;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            node.push_back(temp);
            temp=temp->next;
        }
        bool chance=true;
        int i=1;
        ListNode* curr=head;
        int j=node.size()-1;
        //true means from the back
        // 
        while(i<=j)
        {
            if(chance)
            {
                curr->next=node[j];
                curr=node[j];
                j--;
                chance=false;
            }
            else
            {
                curr->next=node[i];
                curr=node[i];
                i++;
                chance=true;
            }
        }
        curr->next=NULL;
        return;
    }   
};
