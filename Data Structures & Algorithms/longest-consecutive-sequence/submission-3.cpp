class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }

        int count = 0;
        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] == nums[i-1] +1){
                count++;
            }else{
                ans = max(ans, count+1);
                count = 0;
            }
        }
        
            ans = max(ans, count+1);
        
        

        return ans;
    }
};
