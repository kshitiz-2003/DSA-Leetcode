/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // hashmap approach
        // We use temp pointer to iterate over original linked list and we use hashmap to deeply memorize all nodes of given Linked List
        // We store <node,node> in hashmap where nodes are nodes of original Linked List and nodes of copied linked list
        // So we keep on traversing with temp on original linked list ,then we create a new node similar to orginal linked list data and store both copied list node and original list node in hashmap
        // After storing all nodes in the hashmap we once again iterate over the original linked list using temp and connect the links of copied list of next and random
        // copied list node->next=that(key) original list node->next
        // copied list node->random=that(key) original list node->random

        // code
        Node* temp=head;
        unordered_map<Node*,Node*> mpp;
        // Storing both nodes original and copied(after creating) into hashmap
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        // Connecting the links of newly created nodes of copied Linked List
        temp=head;
        while(temp!=NULL){
            Node* copiedNode=mpp[temp];
            // Creating link of copied node with copied node next
            // Creating link of copied node with copied node random
            copiedNode->next=mpp[temp->next];//return copy of temp->next 
            copiedNode->random=mpp[temp->random];//return copy of temp->random
            temp=temp->next;
        }
        // return head of copied node
        return mpp[head];

    }
};