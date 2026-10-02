class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(std::size(prices) <= 1){
            return 0;
        }
        int buy_index = 0;
        int maxProfit = prices[1] - prices[0];
        for(int index=1;index< std::size(prices);index++){
            if(prices[buy_index] < prices[index]){
                int profit = prices[index] - prices[buy_index];
                maxProfit = std::max(maxProfit, profit);                
            } else {
                buy_index = index;
            }
        }

        return maxProfit < 0 ? 0 : maxProfit;
    }
};
