// The twin sums are actually sum of the first half 
// of the list and the second half in reverse order.
// A slow and a fast pointer can be used to reach
// middle of the list. After reaching the middle of
// the list, the later half of the list is reversed.
// Now, the twin sums are calculated and the maximum
// one is the solution.


// TC = O(n)
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
    ListNode* reverseList(ListNode* node){

        ListNode* prevNode = nullptr;
        auto currNode = node;

        while(currNode){

            auto nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    int pairSum(ListNode* head) {
    
        auto fast = new ListNode(0, head);
        auto slow = head;

        while(fast->next){

            fast = fast->next->next;
            slow = slow->next;
        }

        auto twinSecond = reverseList(slow);
        auto twinFirst = head;

        int maxTwinSum = 0;

        while(twinSecond){

            maxTwinSum = max(maxTwinSum, twinSecond->val + twinFirst->val);
            twinFirst = twinFirst->next;
            twinSecond = twinSecond->next;
        }
        return maxTwinSum;
    }
};