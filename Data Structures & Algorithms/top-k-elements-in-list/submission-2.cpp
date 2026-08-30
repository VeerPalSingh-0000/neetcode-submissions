class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        int count = 1;

        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                pq.push({count, nums[i-1]});
                count = 1;
            }
        }
        pq.push({count, nums[nums.size()-1]});

        vector<int> ans;
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }   

        return ans;
    }
};
