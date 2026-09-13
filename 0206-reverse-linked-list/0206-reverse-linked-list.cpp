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
class Solution {
    private:
    // Recursion function
    ListNode* Reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        // Decreasing the size of Linked List 
        ListNode* newhead=Reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // Optimal approach using recursion
        return Reverse(head);
    }
};