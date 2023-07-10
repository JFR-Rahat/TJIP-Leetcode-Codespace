// Slow and fast pointers can be used to solve the problem.
// Since the node is nth from the end of the list, the fast
// pointer is forwarded n times initially. This would keep
// distance of n between the slow and fast pointer. So when 
// the fast pointer reaches the last node in the list, the
// slow pointer would be at the node before the nth node.
// It can be then removed easily from there. Both pointer is
// initialized from a dummy head node to simplify the delete
// process.

// TC = O(1)
// SC = O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = new ListNode(0, head);
        auto fast = head;
        head = slow;
        
        while(n--){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        auto toRemoved = slow->next;
        slow->next = slow->next->next;
        delete(toRemoved);
        return head->next;
    }
};