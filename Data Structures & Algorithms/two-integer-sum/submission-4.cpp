class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int first, sec; 
        
        for(int i=0;i<nums.size();i++){
            first = nums[i];
            sec = target - first;

            if(m.find(sec) != m.end()){
                return {m[sec], i};
            }
                m[first] = i;
            
        }
        return {-1,-1};
    }
};
