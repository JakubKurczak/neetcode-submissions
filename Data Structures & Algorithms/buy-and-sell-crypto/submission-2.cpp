class Solution {
public:
    int maxProfit(vector<int>& prices) {

    int min_buy = prices[0];
    int  max_price = 0;

    for(auto sell: prices){
        max_price= std::max(max_price,sell-min_buy);
        min_buy = std::min(min_buy, sell);
    }

    return max_price;
    }
};
