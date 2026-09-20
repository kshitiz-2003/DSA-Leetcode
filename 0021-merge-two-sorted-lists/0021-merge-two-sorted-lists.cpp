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
    ListNode* convert(vector<int> arr){
        if(arr.empty()) return NULL;
        ListNode* head=new ListNode(arr[0]);
        ListNode* temp=head;
        for(int i=1;i<arr.size();i++){
            ListNode* newNode=new ListNode(arr[i],NULL);
            temp->next=newNode;
            temp=temp->next;
        }
        return head;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Brute force
        // We put all the elements of L1 and L2 into an array 
        // Then we sort the array
        // Then we convert the array into Linked List and return head

        if(list1==NULL && list2==NULL) return NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        vector<int> arr;
        while(temp1!=NULL){
            arr.push_back(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            arr.push_back(temp2->val);
            temp2=temp2->next;
        }
        sort(arr.begin(),arr.end());
        // Converting Array to Linked List
        ListNode* head=convert(arr);
        return head;
    }
};