class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void helper(int i, vector<int>& nums, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(target < 0) return;
        
        for(int j = i; j<nums.size(); j++) {
            temp.push_back(nums[j]);
            helper(j, nums, target-nums[j]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        helper(0, nums, target);
        return ans;
    }
};
