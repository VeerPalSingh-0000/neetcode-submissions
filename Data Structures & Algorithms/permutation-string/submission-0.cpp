class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);

        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }

        int l = s1.size();

        if(l > s2.size()) return false;

        for(int i=0;i<s2.size();i++){
            if(i < l){
                v2[s2[i]-'a']++;
            }else{
                v2[s2[i]-'a']++;
                v2[s2[i-l]-'a']--;
            }

            if(v1 == v2) return true;
        }

        return false;
    }
};
