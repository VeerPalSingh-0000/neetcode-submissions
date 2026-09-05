class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        vector<int>left;
        vector<int>right(heights.size());

        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()){
                left.push_back(-1);
            }else{
                left.push_back(s.top());
            }

            s.push(i);
        }

        while(!s.empty()) s.pop();

        int n = heights.size();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()){
                right[i] = n;
            }else{
                right[i] = s.top();
            }

            s.push(i);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans = max(ans, heights[i]*(right[i]-left[i]-1));
        }

        return ans;
    }
};
