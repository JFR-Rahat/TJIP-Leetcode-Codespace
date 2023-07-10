// Nodes in the same level of the tree points
// to its next node. BFS can be used for the level
// order search. Nodes of the same level are pushed
// in the queue together. Now while these nodes gets
// linked together, their children are also pushed in
// the queue. But the linking process of that level 
// finishes the moment all nodes of that level are popped
// out of the queue. This way all the nodes will point to
// the next node of its level.


// TC = O(n)
// SC = O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void bfs(Node* root){

        queue<Node*> Q;
        if(root) 
            Q.push(root);
        
        while(!Q.empty()){

            int lenQ = Q.size();
            for(int i=0; i<lenQ; i++){

                auto currNode = Q.front();
                Q.pop();

                if(i+1 < lenQ) currNode->next = Q.front();
                if(currNode->left) Q.push(currNode->left);
                if(currNode->right) Q.push(currNode->right);
            }   
        }
    }

public:
    Node* connect(Node* root) {
        
        bfs(root);

        return root;
    }   
};