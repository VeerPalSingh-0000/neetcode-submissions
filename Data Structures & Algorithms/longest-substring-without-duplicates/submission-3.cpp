class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string extra = "";
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            while(extra.find(s[i]) != string::npos) {
                extra.erase(0, 1);
            }

            extra += s[i];
            ans = max(ans, (int)extra.size());
        }

        return ans;
    }
};