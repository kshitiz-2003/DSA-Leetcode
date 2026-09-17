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
    ListNode* oddEvenList(ListNode* head) {
        // Brute force 
        // We will use an array and use temp
        // first we start with head and move temp 2 step and store all odd index value in array;
        // then we start with head->next and move temp 2 step and store all even inbdex element in the array
        // the we once again start with temp=head and store all elements of array into temp->data with temp moving one step only

        //Edge case
        if(head==NULL || head->next==NULL) return head;
        // For odd Index
        ListNode* temp=head;
        vector<int> arr;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        // checking if last element is added or not in array
        if(temp!=NULL) arr.push_back(temp->val);

        // For even Index
        temp=head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        // checking if last element is added or not in array
        if(temp!=NULL) arr.push_back(temp->val);

        // Now putting all values od arr in Linked List
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;

    }
};