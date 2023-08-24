// The tree is symmetric if its left and right
// subtree are mirrored equal to each other.
// That is the left child of the left subtree
// must be equal to the right child of the right 
// subtree and the right child of the left subtree 
// must be equal ot the left child of the right
// subtree.

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
    bool isMirror(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;

        return (p->val == q->val) &&
                    isMirror(p->left, q->right) &&
                        isMirror(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};