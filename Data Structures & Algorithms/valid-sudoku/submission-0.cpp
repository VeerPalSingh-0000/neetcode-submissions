class Solution {
public:

    bool isValid(vector<vector<char>>& board, int r, int c, char dig){
        // row wise
        for(int i=0;i<9;i++){
            if(board[r][i] == dig) return false;
        }

        // col wise
        for(int i=0;i<9;i++){
            if(board[i][c] == dig) return false;
        }

        // box
        int b_r = (r/3)*3;
        int b_c = (c/3)*3;

        for(int i=b_r;i<b_r+3;i++){
            for(int j=b_c;j<b_c+3;j++){
                if(board[i][j] == dig) return false;
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
            return helper(board, next_r, next_c);
        }

        for(char dig = '1';dig <= '9'; dig++){
            if(isValid(board, r, c, dig)){
                board[r][c] = dig;
                if(helper(board, next_r, next_c)){
                    return true;
                }
                    
                board[r][c] = '.';
            }
        }

        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return helper(board, 0,0);
    }
};
