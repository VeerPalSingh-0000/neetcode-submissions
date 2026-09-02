class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int ans = 1;
        string extra = "";

        int l = 0;

        for(int i=0;i<s.size();i++){
            if(extra.find(s[i]) > extra.size()){
                extra += s[i];
            }else{
                l = extra.size();
                ans = max(ans, l);
                extra = s[i];
            }
        }
        l = extra.size();
        ans = max(ans, l);

        return ans;
    }
};
