class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i:nums) pq.push(i);

        int ans;
        int count = 1;

        while(!pq.empty()){
            if(count == k){
                ans = pq.top();
                break;
            }
            pq.pop();
            count++;
        }

        return ans;
    }
};
