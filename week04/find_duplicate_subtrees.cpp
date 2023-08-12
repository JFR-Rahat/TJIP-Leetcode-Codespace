// To find all the duplicate subtrees, the first thing
// to do is to uniquely identify each subtree. To do 
// that for each nodes, hashes can be calculated by the
// node value and for the hash of a subtree can be the
// hash of that node, plus its left side hash, plus its
// right side hash. This definitely requires the post-order
// traversal. Then the hashes can be counted and the duplicate
// ones can be found.

// TC = O(n)
// SC = O(n)


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
    unordered_map<string, int> hashes;

    string calHash(TreeNode* root, vector<TreeNode*> &dupTrees){

        if(root == nullptr) return "#";

        string leftHash = calHash(root->left, dupTrees);
        string rightHash = calHash(root->right, dupTrees);
        string subTreeHash = to_string(root->val) + "," + leftHash + "," + rightHash;

        if(hashes[subTreeHash] == 1){
            dupTrees.push_back(root);
        }
        hashes[subTreeHash]++;

        return subTreeHash;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dupTrees;
        calHash(root, dupTrees);

        return dupTrees;
    }       
};