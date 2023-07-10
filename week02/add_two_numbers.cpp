// Both lists gets iterated at the same time and the two
// digits of the nodes get summed together (with the carry). 
// The sum is added to a new node of the answer list. If a 
// carry exists, it is transfered to be summed up together with 
// the next digits. If any of the list finishes before the other
// that list is not needed for the summation.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ansHead = new ListNode();
        ListNode* currAnsNode = ansHead;

        int sum = 0, carry = 0;

        while(l1 || l2 || carry){

            int currSum = carry;
            if(l1){
                currSum += l1->val;
                l1 = l1->next;
            }
                
            if(l2){
                currSum += l2->val;
                l2 = l2->next;
            }

            sum = currSum % 10;
            carry = currSum / 10;

            ListNode* newNode = new ListNode(sum);
            currAnsNode->next = newNode;
            currAnsNode = currAnsNode->next;
                
        }

        return ansHead->next;
    }
};