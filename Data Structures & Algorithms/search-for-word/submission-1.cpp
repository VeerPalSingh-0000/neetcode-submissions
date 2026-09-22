class Solution {
public:

    bool helper(vector<vector<char>>& board, string& word, int idx, int i, int j, int n, int m){

        if(idx == int(word.size()-1)){
            return true;
        }

        if(i > 0 && board[i-1][j] == word[idx+1]){
            if(helper(board, word, idx+1, i-1, j, n, m)) return true;
        }
        if(i < n-1 && board[i+1][j] == word[idx+1]){
            if(helper(board, word, idx+1, i+1, j, n, m)) return true;
        }
        if(j < m-1 && board[i][j+1] == word[idx+1]){
            if(helper(board, word, idx+1, i, j+1, n, m)) return true;
        }
        if(j > 0 && board[i][j-1] == word[idx+1]){
            if(helper(board, word, idx+1, i, j-1, n, m)) return true;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0] == board[i][j]){
                    if(helper(board, word, 0, i, j, n, m)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
