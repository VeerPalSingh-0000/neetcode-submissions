class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int st = 0, e = nums.size()-1;

        while(st < e){
            if(nums[st] + nums[e] == target){
                return {st, e};
            }else if(nums[st] + nums[e] < target){
                st++;
            }else{
                e--;
            }
        }

        return {-1, -1};
    }
};
