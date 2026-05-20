class Solution {
private:
    pair<int, int> findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        int ans = nums[0], ansIdx = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[n-1]) low = mid + 1;
            else {
                ans = nums[mid];
                ansIdx = mid;
                high = mid-1;
            }
        }
        return {ansIdx, ans};
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        auto [firstIdx, firstElem] = findMin(nums);
        int low, high;
        if(target >= firstElem && target <= nums[n-1]) {
            low = firstIdx;
            high = n-1;
        } else {
            low = 0;
            high = firstIdx - 1;
        }

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};
