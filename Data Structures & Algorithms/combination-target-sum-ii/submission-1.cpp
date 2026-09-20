class Solution {
public:

    void helper(vector<int>& nums, int idx, int target, vector<int>& temp, vector<vector<int>>& ans){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || idx == nums.size()) return;
        
        temp.push_back(nums[idx]);
        helper(nums, idx+1, target-nums[idx], temp, ans);

        temp.pop_back();
        int new_idx = idx+1;
        while(new_idx < nums.size() && nums[new_idx] == nums[idx]) new_idx++;
        helper(nums, new_idx, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, 0, target, temp, ans);

        return ans;
    }
};
