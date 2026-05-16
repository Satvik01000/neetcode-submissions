class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int i : st) {
            if (!st.count(i - 1)) {
                int num = i;
                int count = 1;

                while (st.count(num + 1)) {
                    num++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};