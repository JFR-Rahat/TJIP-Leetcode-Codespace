// Since Kth element is searched for several times
// and also in the increasing order, preserving the 
// recursive stack for the in-order traversal is 
// required to optimize the solution. The stack
// would be populated with all the left most nodes
// in the tree initially. To perform the iterative
// patter in the search for kth element, the next
// kth element would be provided by the top element
// of the stack. The node then gets popped up from the 
// stack and if the top node has any right child the 
// stack again gets populated by that nodes left most
// childs.

// TC = O(n)
// SC = O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    class BSTIterator {
        private:
            TreeNode* root;
            stack<TreeNode*> nodesStack;
        public:
            BSTIterator(TreeNode* _root){
                root = _root;
                populateStack(root);
            }
            void populateStack(TreeNode* node){
                while(node){
                    nodesStack.push(node);
                    node = node->left;
                }
            }
            int getNext(){
                TreeNode* topNode = nodesStack.top();
                nodesStack.pop();

                populateStack(topNode->right);
                return topNode->val;
            }
    };
public:
    int kthSmallest(TreeNode* root, int k) {
        BSTIterator bst(root);
        int result;
        for(int i=0; i<k; i++){
            result = bst.getNext(); 
        }
        return result;
    }
};