// The serialization can be done by 
// traversing the tree in pre-order
// manner and while traversing converting
// the value of the nodes into string and
// adding a seperator after. For nullptr nodes
// a different string can be used.

// TC = O(n)
// SC = O(h)

// For the deserialization the serialized string
// needs to be processed first and split into 
// tokens of nodes skipping the seperator. The
// parsed tokens can be stored in a queue, which
// then can be traversed in pre-order. Each node string
// in the traversal would be converted into integer
// value and the root of the tree can be returned.

// TC = O(n)
// SC = O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return serialize_helper(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> Q;
        populate_queue(Q, data);

        return deserialize_helper(Q);
    }
private:
    string serialize_helper(TreeNode* root){

        if(root == nullptr) return "#";

        return to_string(root->val)
                + ","
                + serialize_helper(root->left)
                + ","
                + serialize_helper(root->right);

    }
    void populate_queue(queue<string>& Q, string& data){
        stringstream stream(data);

        string token;
        while(getline(stream, token, ',')){
            Q.push(token);
        }
    }
    TreeNode* deserialize_helper(queue<string>& Q){
        if(Q.empty()) return nullptr;

        string nodeString = Q.front();
        Q.pop();
        
        if(nodeString == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(nodeString));
        root->left = deserialize_helper(Q);
        root->right = deserialize_helper(Q);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));