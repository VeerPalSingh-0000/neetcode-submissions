class Solution {
public:
    int findMin(vector<int> &nums) {

        if(nums.size() == 1){
            return nums[0];
        }

        int l = 0;
        int r = nums.size() - 1;

        if(nums[l] <= nums[r]) return nums[l];
        if(nums[l] >= nums[r]) return nums[r];

        while(l <= r){
            int mid = l + (r-l)/2;
            // base cases
            if(mid == 0){
                if(nums[mid] < nums[mid+1]) return nums[mid];
                else l = mid + 1;
            }
            if(mid == nums.size()-1){
                if(nums[mid] < nums[mid-1]) return nums[mid];
                else r = mid - 1;
            }
            //------------
            if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) return nums[mid];
            else if(nums[mid] >= nums[l]){ // left sorted
                l = mid + 1;
            }else{
                r = mid -1;
            }
        }

        return -1;
    }
};
