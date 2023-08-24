// Both nodes are searched in each subtree of
// the binary tree. If a subtree contains both
// of them, then that subroot is the LCA of the
// nodes. If only one of them is in the subtree,
// then this subroot is the LCA. And if none
// exists in the subtree, it results in nullptr.

// TC = O(n)
// SC = O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* searchNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return nullptr;

        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* L_search = searchNode(root->left, p, q);
        TreeNode* R_search = searchNode(root->right, p, q);

        if(L_search && R_search) return root;
        return L_search ? L_search : R_search;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return searchNode(root, p, q);
    }
};