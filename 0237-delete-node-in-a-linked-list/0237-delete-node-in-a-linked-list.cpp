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
    void deleteNode(ListNode* node) {
        //Copying th next node data into current code
        node->val=node->next->val;
        //setting the next of current node to the next of next node
        node->next=node->next->next;
    }
};