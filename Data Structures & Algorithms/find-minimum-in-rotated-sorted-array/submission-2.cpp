class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0, high = n-1;

        int ans = nums[0];
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[n-1]) low = mid + 1;
            else {
                ans = nums[mid];
                high = mid-1;
            }
        }
        return ans;
    }
};