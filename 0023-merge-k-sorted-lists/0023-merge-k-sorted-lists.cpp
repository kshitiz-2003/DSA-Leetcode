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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Brrute force 
        // We use another Vector to store all elements of LinkedList
        // We use temp pointer to traverse over horizontal Linked list 
        // Since each horizontal Linked list have child linked list 
        // so we use temp2 pointer to traverse through vertical Linked list then we store all value into the vector array
        // then we sort this vector array 
        // Now last we convert this vector array into required Linked list(horizontal or vertical) and return head of that Linked list

        // Code
        // Edge case
        if(lists.size()==0) return NULL;
        int temp=0;
        vector<int> arr;
        // Storing all nodes in the vector
        for(int i=0;i<lists.size();i++){
            ListNode* temp2=lists[i];
            while(temp2!=NULL){
                arr.push_back(temp2->val);
                temp2=temp2->next;
            }

        }
        if(arr.size()==0) return NULL;
        // Sorting the vector
        sort(arr.begin(),arr.end());
        // Converting into linked list
        ListNode* head=new ListNode(arr[0]);
        ListNode* temp1=head;
        for(int i=1;i<arr.size();i++){
            ListNode* newNode=new ListNode(arr[i]);
            temp1->next=newNode;
            temp1=newNode;
        }
        return head;

    }
};