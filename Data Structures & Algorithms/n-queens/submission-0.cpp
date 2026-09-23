class Solution {
public:

    bool isValid(vector<string>&temp, int r, int c, int n){
        for(int i=0;i<n;i++){
            if(temp[r][i] == 'Q') return false;
        }
        for(int i=0;i<n;i++){
            if(temp[i][c] == 'Q') return false;
        }

        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(temp[i][j] == 'Q') return false;
        }
        for(int i=r,j=c;i>=0 && j<n;i--,j++){
            if(temp[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(int r, vector<string>& temp, vector<vector<string>>& ans, int n){

        if(r == n){
            ans.push_back(temp);
            return;
        }

            for(int j=0;j<n;j++){
                if(isValid(temp, r, j, n)){
                    temp[r][j] = 'Q';
                    helper(r+1, temp, ans, n);
                    temp[r][j] = '.';
                }
            }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>temp(n, string(n,'.'));

        helper(0, temp, ans, n);

        return ans;
    }
};
