class Solution {
public:

    vector<int> helper(vector<int>& nums, int f, int s){
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == f){
                ans.push_back(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] == s){
                ans.push_back(i);
            }
        }

        return ans;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> extra = nums;
        sort(extra.begin(), extra.end());

        int st = 0, e = nums.size()-1;

        while(st < e){
            if(extra[st] + extra[e] == target){
                return helper(nums, extra[st], extra[e]);
            }else if(extra[st] + extra[e] < target){
                st++;
            }else{
                e--;
            }
        }

        return {-1, -1};
    }
};
