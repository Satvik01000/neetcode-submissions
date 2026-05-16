class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for(auto& i : nums) mpp[i]++;

        int ans = 0;
        for(auto& i : mpp) {
            int num = i.first;
            int count = 1;
            while(mpp.count(num+1)) {
                count++;
                num++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
