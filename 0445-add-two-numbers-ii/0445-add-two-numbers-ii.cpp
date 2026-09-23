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
    // Calculating Length of list
    int getLength(ListNode* head){
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    // Adding the two list using recursion method
    ListNode* Listadd(ListNode* l1,ListNode* l2,int diff,int& carry){
        // base case
        if(l1==NULL){
            return nullptr;
        }
        ListNode* nextResult;
        if(diff>0){
            // l1 has extra nodes at the beginning
            // Means length of l1> length of l2
            nextResult=Listadd(l1->next,l2,diff-1,carry);
            // Adding that extra node to carry 
            int sum=l1->val+carry;
            l1=new ListNode(sum%10);
            carry=sum/10;
        }
        else{
            // when they both have same length
            nextResult=Listadd(l1->next,l2->next,diff,carry);
            // Both lists are now at the same position
            // Adding both nodes of l1 and l2
            int sum=l1->val+l2->val+carry;
            l1=new ListNode(sum%10);
            carry=sum/10;
        }
          // Put current digit before the result obtained
        l1->next=nextResult;
        return l1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Optimmal Approach
        // We use the method oof recursion because we have add from the last node
        // Our base case is when l1 points to null pointer we return 
        // On backtracking we keep on adding sum and carry and we recah the first node
        // we also have to find the length of list so that we can know which list is bigger and the list which is shorter we add extra 0 node which is hypothetical
        // We will no make a new list we will modify the exisiting list (bigger list) to our new resultant list
        // At the if we left out with carry we will creat a new node and connect it to head

        // Code
        int n1=getLength(l1);
        int n2=getLength(l2);

        ListNode* result;
        int carry=0;
        if(n1>n2){
            result=Listadd(l1,l2,n1-n2,carry);
        }
        else{
            result=Listadd(l2,l1,n2-n1,carry);
        }

        // if carry is still left we have to add it
        if(carry!=0){
            ListNode* newnode=new ListNode(carry);
            newnode->next=result;
            return newnode;
        }
        return result;
    }
};