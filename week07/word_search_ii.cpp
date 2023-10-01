class Solution {
public:
    class TrieNode {
    public:
        TrieNode* next[26];
        string word;

        TrieNode(){
            word = "";
            for(int i=0; i<26; i++){
                next[i] = nullptr;
            }
        }
    };

int n, m;
vector<int> dr{+1, 0, -1, 0, +1};

TrieNode* generateTrie(vector<string>& words){
    TrieNode* root = new TrieNode();
    for(auto &word: words){
        TrieNode* currNode = root;
        for(auto &ch: word){
            if(currNode->next[ch - 'a'] == nullptr){
                currNode->next[ch - 'a'] = new TrieNode();
            }
            currNode = currNode->next[ch - 'a'];
        }
        currNode->word = word;
    }
    return root;
}

void dfs(int x, int y, vector<vector<char>>& board, vector<string>& words, vector<string>& wordsOnBoard, vector<vector<bool>>& visited, TrieNode* currNode){

    char ch = board[x][y];
    if(visited[x][y] || (currNode && currNode->next[ch - 'a'] == nullptr)) return;

    visited[x][y] = true;
    currNode = currNode->next[ch - 'a'];
    
    if(currNode && currNode->word.size() > 0){
        wordsOnBoard.push_back(currNode->word);
        currNode->word.clear();

    }

    for(int i=0; i<4; i++){
        int nx = x + dr[i];
        int ny = y + dr[i+1];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
        
        dfs(nx, ny, board, words, wordsOnBoard, visited, currNode);
    }
    visited[x][y] = false;
}

void searchWords(vector<vector<char>>& board, vector<string>& words, vector<string>& wordsOnBoard){

    TrieNode* root = generateTrie(words);
    n = board.size();
    m = board[0].size();

    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dfs(i, j, board, words, wordsOnBoard, visited, root);
        }
    }
}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> wordsOnBoard;
        searchWords(board, words, wordsOnBoard);

        return wordsOnBoard;
    }
};
