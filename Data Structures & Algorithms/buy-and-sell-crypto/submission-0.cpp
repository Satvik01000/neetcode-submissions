class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = INT_MAX, ans = 0;
        for(auto& i : prices) {
            minVal = min(minVal, i);
            ans = max(ans, i-minVal);
        }
        return ans;
    }
};
