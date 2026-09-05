class Solution {
public:

    bool isValid(vector<int>& piles, int k, int h){
        int curr_k = 0;
        int s = 0;

        while(s < piles.size()){
            if(piles[s]%k == 0){
                curr_k += piles[s]/k;
            }else{
                curr_k += piles[s]/k +1;
            }
            s++;
        }

        return curr_k <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        
        int s = 1, e = 0;

        for(int i=0;i<piles.size();i++) e = max(e, piles[i]);

        int ans;

        while(s <= e){
            int mid = s + (e-s)/2;

            if(isValid(piles, mid, h)){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
        }


        return ans;

    }
};
