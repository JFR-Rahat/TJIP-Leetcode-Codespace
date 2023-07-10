// The copied list needs to be inside the original
// list to accurately point to the random node in
// the list. Each copied node is inserted after its
// original node. Then the random pointer of the copied 
// nodes can be assigned with the next node of the random 
// pointer of the original node if it is not null. Then
// the copied list is extracted as the copied nodes are
// at the even positions.

// TC = O(n)
// SC = O(1)

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

        if(!head) return nullptr;
        
        auto currNodeOriginal = head;

        while(currNodeOriginal){

            auto newNode = new Node(currNodeOriginal->val);
            newNode->next = currNodeOriginal->next;
            currNodeOriginal->next = newNode;

            currNodeOriginal = currNodeOriginal->next->next;
        }

        currNodeOriginal = head;
        
        while(currNodeOriginal){

            auto currNodeCopy = currNodeOriginal->next; 
            currNodeCopy->random = (currNodeOriginal->random ? currNodeOriginal->random->next : nullptr);

            currNodeOriginal = currNodeOriginal->next->next;
        }

        currNodeOriginal = head;
        auto copyHead = head->next;

        while(currNodeOriginal){

            auto currNodeCopy = currNodeOriginal->next;

            currNodeOriginal->next = currNodeOriginal->next->next;
            currNodeOriginal = currNodeOriginal->next;

            currNodeCopy->next = (currNodeCopy->next ? currNodeCopy->next->next : nullptr);

        }

        return copyHead;
    }
};