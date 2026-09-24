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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute force Method
        // We use the concept of hashmap
        // We store <ListNode*,int> in hashmap
        // We use temp and traverse on Linked List A and store all nodes in hashmap
        // then we again use temp and traverse on Linked List B and check if map has the same node as temp then we will return that node because it is the meeting point of two LL
        // If no meeting point then we return NULL

        // Code
        unordered_map<ListNode*,int> mpp;
        ListNode* temp=headA;
        while(temp!=NULL){
            mpp[temp]=1;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()) return temp;
            temp=temp->next;
        }
        return NULL;
    }
};