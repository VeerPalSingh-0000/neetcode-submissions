class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k >= points.size()) return points;

        map<int, vector<pair<int,int>>> m;
        vector<vector<int>>ans;

        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int val = (x*x)+(y*y);

            m[val].push_back({x, y}); 
        }
        int count = 0;
        for(auto i:m){
            for(auto j : i.second){
                if(count == k) break;
                ans.push_back({j.first, j.second});
                count++;
            }
        }

        return ans;
    }
};
