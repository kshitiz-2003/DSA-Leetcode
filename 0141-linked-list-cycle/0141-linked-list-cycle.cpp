/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       //Optimal Approach
        //We use tortoise and hare algorithm 
        //slow will move one step and fast will move two step simultaneously 
        // if any time slow==fast as they meet ,means loop is present in our Linked List
        // if fast=NULL(n=even) or fast->next=NULL(n=odd) then no loop is present
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};