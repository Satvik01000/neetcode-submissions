class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        
        for(int i = 0; i<n; i++) {
            int goal = target - nums[i];
            if(mpp.count(goal)) {
                int a = min(i, mpp[goal]);
                int b = max(i, mpp[goal]);

                return {a, b};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
