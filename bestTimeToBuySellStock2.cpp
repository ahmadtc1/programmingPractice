class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int currentMin = INT_MAX;
        int potentialProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < currentMin) {
                currentMin = prices[i];
            }
            
            if ((prices[i] > currentMin && (prices[i] - currentMin) > potentialProfit)) {
                potentialProfit = prices[i] - currentMin;
            }
            
            if (potentialProfit > prices[i] - currentMin || (i == prices.size() - 1)) {
                totalProfit += potentialProfit;
                potentialProfit = 0;
                currentMin = prices[i];
            }
        }
        return totalProfit;
    }
};
