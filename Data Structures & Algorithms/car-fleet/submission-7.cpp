class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,double> m;
       

        for(int i=0;i<speed.size();i++){
            double x = (target-position[i])/speed[i];
            
                m[position[i]] = x;
            
        }

        sort(position.begin(), position.end());

        stack<int> s;

        for(int i=0;i<position.size();i++){
            s.push(position[i]);
        }

        int count = 0;

        while(!s.empty()){

            double maxi = m[s.top()]; s.pop();
            while(!s.empty() && m[s.top()] <= maxi){
                s.pop();
            }
            count++;
        }

    return count;
        
    }
};
