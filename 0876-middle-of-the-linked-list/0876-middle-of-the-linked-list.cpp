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
public:
    ListNode* middleNode(ListNode* head) {
        // brute force using count variable
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int middleNode=(cnt/2)+1;
        temp=head;
        cnt=0;
        while(temp!=NULL){
            cnt++;
            if(cnt==middleNode) return temp;
            temp=temp->next;
        }
        return temp;
    }
};