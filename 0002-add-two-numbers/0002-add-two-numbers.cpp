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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Optimal Approach
        // We use the dummy node assign to zero and a temp pointing to dummy node
        // We use L1 pointing to l1 and L2 pointing to l2
        // Now we use two variables sum and carry

        // Repeat these steps unitl L1==NULL or L2==NULL or carry==zero
        // Now we check if L1!=NULL then add it to sum
        // if L2!=NULL then add it to sum 
        // if there is a carry!=0 add it to sum and assign 0 to carry
        // Now make a newnode with value sum=sum%10 and point temp to it and move temp to new node
        // assign value to carry=sum/10;
        
        // Code
        ListNode* dummyNode=new ListNode(0);
        ListNode* temp=dummyNode;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            // Adding carry
            sum+=carry;
            // asssigning new value to carry
            carry=sum/10;
            // Creating newnode with value sum%10
            ListNode* newnode=new ListNode(sum%10);
            // Connecting the links of temp
            temp->next=newnode;
            temp=newnode;
        }
        // Returning head of our new LL which is result of adding of two numbers
        return dummyNode->next;

    }
};