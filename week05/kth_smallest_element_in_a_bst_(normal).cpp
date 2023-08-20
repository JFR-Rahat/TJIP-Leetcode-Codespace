// Traversing the BST in in-order
// approach would be accessing the 
// elements in increasing order.
// So the moment kth node is traversed, 
// its value is the kth element.

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
    int res;
    void dfs(TreeNode* root, int &k){
        if(root == nullptr) return;
        dfs(root->left, k);
        k--;
        if(k == 0) res = root->val;
        dfs(root->right, k);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};