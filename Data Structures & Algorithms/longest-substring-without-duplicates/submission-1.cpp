class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0, high = 0;
        unordered_map<char, int> mpp;

        int ans = 0;
        
        while(high < n) {
            if(mpp.count(s[high])) {
                ans = max(ans, high - low);
                while(mpp.count(s[high])) {
                    mpp[s[low]]--;
                    if(mpp[s[low]]==0) mpp.erase(s[low]);
                    low++;
                }
            }
            mpp[s[high]]++;
            high++;
        }
        return max(ans, high - low);
    }
};
