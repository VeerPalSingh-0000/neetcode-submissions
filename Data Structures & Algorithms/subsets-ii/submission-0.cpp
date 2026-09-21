class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[idx]);
        helper(nums, idx+1, temp, ans);

        temp.pop_back();
        int nxt = idx+1;
        while(nxt < nums.size() && nums[nxt] == nums[idx]) nxt++;
        helper(nums, nxt, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, 0, temp, ans);

        return ans;
    }
};
