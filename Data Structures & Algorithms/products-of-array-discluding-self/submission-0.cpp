class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);

        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) prefix[i] = nums[i]*prefix[i-1];

        suffix[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) suffix[i] = nums[i]*suffix[i+1];

        vector<int> ans(n, 1);
        for(int i = 0; i<n; i++) {
            int pre = (i==0 ? 1 : prefix[i-1]);
            int post = (i==n-1 ? 1 : suffix[i+1]);
            ans[i] = pre * post;
        }
        return ans;
    }
};
