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
    // Recursion function for reversing of ll with void data type
    void Reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return;
        Reverse(head->next);
        ListNode* front=head->next;
        head->next=NULL;
        front->next=head;
    }
    // Function for finding Kth Node
    ListNode* FindKthNode(ListNode* temp,int k){
        k -=1;
        while(k!=0 && temp!=NULL){
            temp=temp->next;
            k--;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Optomal approach
        // We separate evry group from the Linked List
        // For first group
        // we use temp=head and kthNode= kth node and separate it 
        // We store nextnode=Kthnode->next 
        // Now we break the group KthNode=NULL
        // Now we reverse(temp,KthNode) and then store lastnode=temp
        // For all other groups
        // we have  lastnode ,our new temp=nextnode and then we find out kth node and then nextnode=kthNode->next
        // we once again reverse(temp,KthNode)
        // Now we connect the links lastnode->next=KthNode
        // now once again store values for next group and perform reverse
        // lastnode=temp,temp=nextnode,kthnode=temp+k,nextnode=kthnode->next

        // Code
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            // Finding the Kth node
            ListNode* KthNode=FindKthNode(temp,k);
            // If no group of k is formed
            if(KthNode==NULL){
                // to check If only k-1 nodes are there in ll
                if(prevNode!=NULL) prevNode->next=temp;
                break;
            }
            //Finding next node
            ListNode* nextNode=KthNode->next;
            // Breaking the List [temp,kthnode]
            KthNode->next=NULL;
            // Reversing the list[temp,kthnode]
            Reverse(temp);
            // Checking if we are reversing first group then making changes accordingly
            if(temp==head) {head=KthNode;}
            else{
                // Connecting the links of previous node
                prevNode->next=KthNode;
            }
             // Changing temp,KthNode,lastNode for new group
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};