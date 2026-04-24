class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int, int>> nums(n);
        for(int i = 0; i<n; i++) nums[i]={arr[i], arr[i]};
        for(auto& i : nums) i.first = abs(i.first - x);
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for(int i = 0; i<k; i++) ans.push_back(nums[i].second);
        sort(ans.begin(), ans.end());
        return ans;
    }
};