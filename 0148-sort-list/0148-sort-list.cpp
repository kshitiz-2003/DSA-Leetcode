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
    ListNode* sortList(ListNode* head) {
        // Brute force
        // we will take an array and store all the values of Linked list into array
        // Then we sort the array 
        // Then we take out all elements of array and store in temp->data while traversing through Linked List

        ListNode* temp=head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        int i=0;
        temp=head;
        while(temp!=NULL){
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;

    }
};