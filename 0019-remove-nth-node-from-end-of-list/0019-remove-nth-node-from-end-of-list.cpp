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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Burte force
        // We find the length of the linked list using cnt variable
        // then we do res=cnt-n
        // then we again traverse through the Linked list and find the rest node
        // Then we delete the res+1 node
        if(head==NULL || (head->next==NULL && n==1)) return NULL;
        ListNode* temp=head;
        // Counting Length
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        // Deleting Node
        if(cnt==n){
            ListNode* newhead=head->next;
            head->next=NULL;
            delete head;
            return newhead;
        }
        int res=cnt-n;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp=temp->next;
        }
        ListNode* deleteNode=temp->next;
        temp->next=temp->next->next;
        deleteNode->next=NULL;
        delete deleteNode;
        return head;
    }
};