class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>right(n, 1);

        int r = 1;
        for(int i=n-1;i>=0;i--){
            right[i] = r;
            r *= nums[i];
        }

        int l =1;

        for(int i=0;i<n;i++){
            right[i] = l*right[i];
            l *= nums[i];
        }

        return right;
    }
};
