class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        int count = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                pq.push({nums[i-1], count});
                count = 1;
            }
        }
        pq.push({nums[nums.size()-1], count});

        vector<int> ans;
        while(k > 0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }   

        return ans;
    }
};
