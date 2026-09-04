class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> m;
        int count = 0;

        for(int i=0;i<speed.size();i++){
            int x = (target-position[i])/speed[i];
            if(m.find(x) == m.end()){
                count++;
                m[x] = 0;
            }else{
                continue;
            }
        }

        return count;
    }
};
