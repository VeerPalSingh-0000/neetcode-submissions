class Solution {
public:

    void helper(vector<int>&nums, vector<vector<int>>&ans, vector<int>&check){
        int pivot = -1;
        int n = nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
        }else{
            for(int i=n-1;i>=0;i--){
                if(nums[pivot] < nums[i]){
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin()+pivot+1, nums.end());
        }

        if(check == nums){
            return;
        }else{
            ans.push_back(nums);
            helper(nums, ans, check);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        // 1. pehle num push krdu
        // 2. next per lu fir save krta rhu
        // 3. jab tk ki next per pehla ke equal na ho jaye

        vector<vector<int>> ans;
        vector<int>check = nums;

        ans.push_back(nums);

        if(nums.size() < 1) return ans;

        helper(nums, ans, check);

        return ans;
    }
};
