// Since the array is strictly in increasing order
// the root for the BST would be the middle element
// of the array and the left and right subtree would 
// be the left sided element and right sided element
// of the array. For the left and right side, the root
// for that subtree will again be the middle element
// in that range and so on. So recursively generating
// the left and right subtrees the whole BST would 
// be built.

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
    TreeNode* buildBST(int L, int R, vector<int>& nums){
        if(L > R) return nullptr;

        int M = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[M]);

        root->left = buildBST(L, M - 1, nums);
        root->right = buildBST(M + 1, R, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0, nums.size() - 1, nums);
    }
};