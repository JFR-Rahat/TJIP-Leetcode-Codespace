// TC = O(N*32)
// SC = O(N*32)

class Solution {
private:
    class TrieNode{
    public:
        TrieNode* next[2];

        TrieNode(){
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };
    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode* curr = root;
            for(int i=31; i>=0; i--){
                bool bit = ((1 << i) & num) > 0 ? 1 : 0;
                if(curr->next[bit] == nullptr){
                    curr->next[bit] = new TrieNode();
                }
                curr = curr->next[bit];
            }
        }
        int findXORcandidate(int num){
            insert(num);
            TrieNode* curr = root;
            int xorCand = 0;
            for(int i=31; i>=0; i--){
                bool bit = ((1 << i) & num) > 0 ? 1 : 0;
                bool targetBit = bit ^ 1;
                if(curr->next[targetBit]){
                    xorCand = xorCand | (1 << i);
                    curr = curr->next[targetBit];
                }
                else{
                    curr = curr->next[bit];
                }
            }
            return xorCand;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXOR = 0;
        Trie* trie = new Trie();

        for(auto num: nums){
            maxXOR = max(maxXOR, trie->findXORcandidate(num));
        }

        return maxXOR;
    }
};
