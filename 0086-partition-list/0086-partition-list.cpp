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
    ListNode* partition(ListNode* head, int x) {
        // Optimal Approach
        // We will use the changing of links approach and change all the links into bigger and smaller
        // We will divide the list hypothetically into bigger and smaller list
        // We use two dummy head ,biggerhead and smallerhead and use two pointer bigger and smaller to iterate over bigger and smaller list
        // We use temp pointer and check if temp->data<x then we put it into smaller list otherwise in bigger list 
        // NOTE: WE DO NOT MAKE NEW NODES AT EVERY CHECK(TEMP->DATA) BECAUSE WE ARE NOT CREATING NEW LINKED LIST WE ARE SIMPLY RECONNECTING THE LINKS 
        // At the we connect the smaller list to bigger list=smaller->bigger

        // Code
        if(head==NULL || head->next==NULL) return head;
        // Dummy node
        ListNode* smallerhead=new ListNode(-1);
        ListNode* biggerhead=new ListNode(-1);
        // For Iteration purpose
        ListNode* smaller=smallerhead;
        ListNode* bigger=biggerhead;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                smaller->next=temp;
                smaller=temp;
            }
            else{
                bigger->next=temp;
                bigger=temp;
            }
            temp=temp->next;
        }
        // Terminating the bigger list
        bigger->next=NULL;
        // Connecting the smaller to bigger list
        // If there is no smaller list then smallerhead is directly connected to bigger list
        // If there is no bigger list then smaller->next is directly connected to NULL due to bigger->next=NULL;
        smaller->next=biggerhead->next;
        head=smallerhead->next;
        // Freeing the memory
        smallerhead->next=NULL;
        biggerhead->next=NULL;
        delete smallerhead;
        delete biggerhead;
        return head;

    }
};