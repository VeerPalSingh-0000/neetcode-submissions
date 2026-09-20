class Solution {
public:

    void helper(vector<int>& nums, int idx, int target, vector<int>& temp, vector<vector<int>>& ans){
        if(target < 0 || idx == nums.size()) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(nums, idx, target-nums[idx], temp, ans);

        temp.pop_back();
        helper(nums, idx+1, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, 0, target, temp, ans);

        return ans;
    }
};
