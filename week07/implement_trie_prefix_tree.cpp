// TC = O(L); Length of word
// SC = O(T); Total trie nodes

class Trie {
private:
    class TrieNode{
    public:
        bool isEnd;
        TrieNode* next[26];
        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++){
                next[i] = nullptr;
            }
        }
        ~TrieNode(){
            for(int i=0; i<26; i++){
                delete next[i];
            }
        }
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for(char ch: word){
            int id = ch - 'a';
            if(currNode->next[id] == nullptr){
                currNode->next[id] = new TrieNode();
            }
            currNode = currNode->next[id];
        }
        currNode->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for(char ch: word){
            int id = ch - 'a';
            if(currNode->next[id] == nullptr){
                return false;
            }
            currNode = currNode->next[id];
        }
        return currNode && currNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for(char ch: prefix){
            int id = ch - 'a';
            if(currNode->next[id] == nullptr){
                return false;
            }
            currNode = currNode->next[id];
        }
        return currNode;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
