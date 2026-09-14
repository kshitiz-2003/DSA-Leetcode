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
    ListNode* detectCycle(ListNode* head) {
        // Brute force 
        // We keep record of the nodes we have visted so we use hashmap
        // We store <Node*,int>. in our hashmap
        // if anytime we revisit the node we return that node as it is the starting point in our node
        unordered_map<ListNode*,int> mpp;
        ListNode* temp=head;
        while(temp!=NULL){
            // Checking if the Node is already visited or not
            if(mpp.find(temp)!=mpp.end()) return temp;
            else{
            mpp[temp]=1;
            temp=temp->next;
            }
        }
        // No Node is visited
        return NULL;
    }
};