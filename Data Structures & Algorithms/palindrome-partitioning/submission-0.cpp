class Solution {
public:

    bool isValid(string& s, int st, int e){

        while(st < e){
            if(s[st] != s[e]) return false;

            st++; e--;
        }

        return true;
    }

    void helper(string& s, int idx, vector<string>& temp, vector<vector<string>>& ans){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isValid(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                helper(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        helper(s, 0, temp, ans);

        return ans;
    }
};
