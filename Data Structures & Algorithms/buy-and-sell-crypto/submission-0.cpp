class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = prices[0];
        int profit = 0;

        for(int i=1;i<prices.size();i++){
            profit = max(profit, (prices[i]-best_buy));
            best_buy = min(best_buy, prices[i]);
        }

        return profit;
    }
};
