class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 1;
        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else if(nums[i] == nums[i-1] +1){
                count++;
            }else{
                ans = max(ans, count);
                count = 1;
            }
        }

        ans = max(ans, count);

        return ans;
    }
};
