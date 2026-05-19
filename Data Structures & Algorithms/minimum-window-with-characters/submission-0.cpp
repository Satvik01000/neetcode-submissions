class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        int n = s.size(), m = t.size();

        unordered_map<char, int> sFreq, tFreq;
        for(auto& i : t) tFreq[i]++;

        int count = 0;
        int low = 0, high = 0;

        int minLen = INT_MAX;
        int start = 0;

        while(high < n) {
            sFreq[s[high]]++;

            if(tFreq.count(s[high]) && sFreq[s[high]] == tFreq[s[high]]) count++;

            while(count == tFreq.size()) {
                int len = high - low + 1;

                if(len < minLen) {
                    minLen = len;
                    start = low;
                }

                sFreq[s[low]]--;

                if(tFreq.count(s[low]) && sFreq[s[low]] < tFreq[s[low]]) count--;
                low++;
            }
            high++;
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};