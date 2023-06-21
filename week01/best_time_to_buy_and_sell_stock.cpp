// The idea is to buy the stock with the minimum possible price
// and sell it with the maximum possible price in one of the future
// day. So we'll try to sell the stock every day and calculate profit
// from the minimum buying price up to that point. The maximum among 
// the profit would be the solution.

// TC = O(n)
// SC = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProf = 0, buy = INT_MAX;
        
        for(int i=0; i < prices.size(); i++){

            buy = min(buy, prices[i]);
            maxProf = max(maxProf, prices[i] - buy);
            
        }

        return maxProf;
    }
};