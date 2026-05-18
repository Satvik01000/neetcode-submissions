class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int low = 0, high = 0;

        int maxFreq = 0, ans = 1;

        while (high < n) {
            freq[s[high] - 'A']++;

            maxFreq = max(maxFreq, freq[s[high] - 'A']);

            int len = high - low + 1;

            while (len - maxFreq > k) {
                freq[s[low] - 'A']--;
                low++;
                maxFreq = *max_element(freq.begin(), freq.end());
                len = high - low + 1;
            }

            ans = max(ans, len);
            high++;
        }

        return ans;
    }
};