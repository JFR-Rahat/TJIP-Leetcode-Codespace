// TC = O(N*L); N: number of products, L: maximum size of string
// SC = O(N*L); N: number of products, L: maximum size of string

class Solution {
public:
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
    };
    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }

        void insert(string product){
            auto currNode = root;
            for(char ch: product){
                int id = ch - 'a';
                if(currNode->next[id] == nullptr){
                    currNode->next[id] = new TrieNode();
                }
                currNode = currNode->next[id];
            }
            currNode->isEnd = true;
        }
    };
public:
    Trie* trie;
    void initializeTrie(vector<string>& products){
        trie = new Trie();
        for(auto &product: products){
            trie->insert(product);
        }
    }
    void dfs(TrieNode* u, string &currWord, vector<string>& suggestion){
        if(u == nullptr || suggestion.size() == 3) return;
        if(u->isEnd){
            suggestion.push_back(currWord);
        }
        for(int i=0; i<26; i++){
            if(u->next[i] == nullptr) continue;
            currWord.push_back((char)i+'a');
            dfs(u->next[i], currWord, suggestion);
            currWord.pop_back();
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        initializeTrie(products);
        vector<vector<string>> suggestions;
        
        TrieNode* currNode = trie->root;
        string typedWord;
        for(auto ch: searchWord){
            typedWord.push_back(ch);
            vector<string> suggestion;
            currNode = currNode ? currNode->next[ch - 'a'] : nullptr;
            dfs(currNode, typedWord, suggestion);
            suggestions.push_back(suggestion);
        }
        return suggestions;
    }
};
