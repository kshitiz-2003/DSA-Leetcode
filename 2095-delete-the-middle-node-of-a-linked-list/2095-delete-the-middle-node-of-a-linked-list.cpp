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
    ListNode* deleteMiddle(ListNode* head) {
        // brute force 
        // we find the length of linked List say n
        // then we reach the floor(n/2) of the linked list
        // then we delete the next node
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int node=floor(n/2);
        temp=head;
        while(temp!=NULL){
            node--;
            if(node==0){
                ListNode* deleteNode=temp->next;
                temp->next=temp->next->next;
                deleteNode->next=NULL;
                delete deleteNode;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};