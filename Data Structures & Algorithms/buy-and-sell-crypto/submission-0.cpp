class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0], ans = 0;
        for(auto& x:prices){
            ans = max(ans, x - m);
            m = min(m, x);
        }
        return ans;
    }
};
