// Depth for each node is the maximum depth of its
// left and right subtree. Therefore recursively 
// calculating the depth for the leaf nodes will
// be able to provide the maximum depth for the whole
// tree.

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
    int getMaxDepth(TreeNode* root){

        if(root == nullptr) return 0;

        int L = getMaxDepth(root->left);
        int R = getMaxDepth(root->right);
        return max(L, R) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        
       return getMaxDepth(root);
    }
};