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
void insertNodeInBetween(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextElement = temp->next;
        Node* copyNode = new Node(temp->val);
        copyNode->next = nextElement;
        temp->next = copyNode;
        temp = nextElement;
    }
}
void randomPointer(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = temp->next;
        if(temp->random != nullptr){
            copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}
Node* nextPointer(Node* head){
    Node* dummy = new Node(-1);
    Node* res = dummy;

    Node* temp = head;
    while(temp != nullptr){
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        insertNodeInBetween(head);
        randomPointer(head);
        return nextPointer(head);
    }
};