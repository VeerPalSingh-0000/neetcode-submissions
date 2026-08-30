class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;

        int idx = 0;
        for(int i=0; i<strs.size(); i++){
            string extra = strs[i];
            sort(extra.begin(), extra.end());

            if(m.find(extra) == m.end()){
                m[extra] = idx;
                ans.push_back({});
                idx++;
            }
            ans[m[extra]].push_back(strs[i]);
        }

        return ans;
    }
};
