class Solution {
public:

    bool isValid(vector<vector<char>>& board, int r, int c, char dig){
        // row wise
        for(int i=0;i<9;i++){
            if(i != c && board[r][i] == dig) return false;
        }

        // col wise
        for(int i=0;i<9;i++){
            if(i != r && board[i][c] == dig) return false;
        }

        // box
        int b_r = (r/3)*3;
        int b_c = (c/3)*3;

        for(int i=b_r;i<b_r+3;i++){
            for(int j=b_c;j<b_c+3;j++){
                if((i != r || j != c) && board[i][j] == dig) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int r, int c){
        if(r == 9){
            return true;
        }

        int next_r = r;
        int next_c = c+1;
        if(next_c == 9){
            next_r = r+1;
            next_c = 0;
        }


        if(board[r][c] != '.'){
            if(!isValid(board, r, c, board[r][c])){
                return false;
            }

            return helper(board, next_r, next_c);
        }

        return helper(board, next_r, next_c);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return helper(board, 0,0);
    }
};
