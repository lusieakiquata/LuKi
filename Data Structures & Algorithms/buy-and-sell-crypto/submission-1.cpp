class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minl = prices[0];
        int res = 0;
        for(int i = 0 ; i < prices.size(); i++){
            minl = min(prices[i],minl);
            res = max(res, prices[i] - minl);
        }
        return res;
    }
};
