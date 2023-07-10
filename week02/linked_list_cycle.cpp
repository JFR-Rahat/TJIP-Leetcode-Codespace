// Slow and fast pointer can be used to solve the 
// problem. The fast pointer will be moving forward
// two times, while the slow moves one time. If a
// cycle exists in the list then, the fast and slow
// pointer will become the same when slow iterates
// the list one time.


// TC = O(n)
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
    bool hasCycle(ListNode *head) {
        
        auto frontNode = head;
        auto rearNode = head;

        while(frontNode && frontNode->next){

            frontNode = frontNode->next->next;
            rearNode = rearNode->next;

            if(frontNode == rearNode) return true;
        }
        return false;
    }
};