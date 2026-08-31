class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";

        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                temp += strs[i][j] + 1;
            }
            temp += " ";
        }

        return temp;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int idx = 0;
        string temp = "";
        while(idx < s.size()){
            if(s[idx] != ' '){
                temp += s[idx]-1;
            }else{
                ans.push_back(temp);
                temp = "";
            }
            idx++;
        }

        return ans;
    }
};
