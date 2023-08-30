// TC = O(nm * 3^L)
// SC = O(L)

class Solution {
private:
    int n, m;
    constexpr static int dr[] = {+1, 0, -1, 0, +1};

    bool search(int x, int y, int pos, string word, vector<vector<char>>& board, vector<vector<bool>>& visited){
        if(pos >= word.size()) return true;

        if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y]) return false;

        visited[x][y] = true;
        bool status = false;

        for(int i=0; i<4; i++){
            int nx = x + dr[i];
            int ny = y + dr[i+1];

            if(board[x][y] == word[pos]){
                status |= search(nx, ny, pos+1, word, board, visited);
            }
            if(status) break;
        }

        visited[x][y] = false;
        return status;
    }
    bool search(int x, int y, string word, vector<vector<char>>& board){
        n = board.size();
        m = board[0].size();

        vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
        return search(x, y, 0, word, board, visited);
    }
    bool searchResult(vector<vector<char>>& board, string word){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(search(i, j, word, board)) return true;    
                }
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        return searchResult(board, word);
    }
};