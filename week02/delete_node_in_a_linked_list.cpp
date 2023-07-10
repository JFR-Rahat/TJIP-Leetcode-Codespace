// The exact node can not be deleted, rather we can
// copy the next node in the current node and then 
// delete the next node while re-linking the current 
// node.


// TC = O(1)
// SC = O(1)

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
    void deleteNode(ListNode* node) {
        
        auto nodeToRemove = node->next;
        node->val = nodeToRemove->val;
        node->next = nodeToRemove->next;

        delete(nodeToRemove);
    }
};