class Solution {
public:
    int maxArea(vector<int>& heights) {
        int low = 0, high = heights.size()-1;
        int ans = 0;
        while(low<high) {
            int length = high - low;
            int width = min(heights[low], heights[high]);
            ans = max(ans, length*width);

            if(heights[low]<heights[high]) low++;
            else high--;
        }
        return ans;
    }
};