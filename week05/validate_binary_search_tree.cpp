// A BST is valid if for each of its node, 
// the left subtree has no greater value than
// the subroot and the right subtree has no
// smaller value than the subroot. The left
// most child can be the lowest possible value
// and the right most child can be the highest
// possible value. Therefore to not make the 
// solution bound to any specific data type
// the leftmost and rightmost possible nodes
// are kept as nullptr until explored.

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
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(root == nullptr) return true;

        return (minNode == nullptr || minNode->val < root->val) && 
                (maxNode == nullptr || maxNode->val > root->val) &&
                isValidBST(root->left, minNode, root) &&
                isValidBST(root->right, root, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};