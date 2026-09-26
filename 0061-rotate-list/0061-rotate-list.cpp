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
    ListNode* rotateRight(ListNode* head, int k) {
        // Optimal approach
        // First we find the tail of the Linked List and find length also together by using tail pointer
        // Then we connect tail to head of the linked list
        // Now we use a temp pointer and then traverse upto(n-k) node
        // We store temp->next as our new head as we have to rotate the linked list by k steps then as newhead
        // Then we point temp=null to brak our circular linked list and return newhead as the head of the linked list

        // Edge cases
        // if k=length of linked list(n),then we do not have to do anything we simply return head

        // if k>length of linked list(n) and k is a multiple of length of linked list(n),then we also don't have to do anything we simply return head for example if n=5 and k=15 then we have to rotate linked list by 5+5+5 rotation whuch is equivalent to 5 rotations

        // if k>length of linked list(n) and is not multple of length of linked list(n),then our new k become k=k%n for example if n=5 and we have to do k=13 rotations the we have to do 5+5+3 rotation which is equivalent to 3 rotations as 5 rotation is nothing. 

        //code
        if(head==NULL || head->next==NULL) return head;
        ListNode* tail=head;
        int len=1;
        // Finding length of LL
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        // Covering Edge cases
        if(k%len==0) return head;
        k=k%len;
        // Connecting tail to head
        tail->next=head;
        // Finding n-k node
        ListNode* temp=head;
        int cnt=1;
        while(temp!=NULL){
            if(cnt==len-k) break;
            cnt++;
            temp=temp->next;
        }
        // Connecting the links
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};