class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int ans = 1;
        string extra = "";
        
        for(int i=0;i<s.size();i++){
            int j = i;
            
            while(j < s.size()){
                if(extra.find(s[j]) == string::npos){
                    extra += s[j];
                    j++;
                }else{
                    break;
                }
            }
            ans = max(ans, int(extra.size()));
            extra = "";
        }
        

        return ans;
    }
};
