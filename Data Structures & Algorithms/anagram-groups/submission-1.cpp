class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        for(int i = 0; i<n; i++) {
            if(strs[i]=="-1") continue;
            unordered_map<char, int> freq1;
            for(auto& j : strs[i]) freq1[j]++;

            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = i+1; j<n; j++) {
                unordered_map<char, int> freq2;
                for(auto& k : strs[j]) freq2[k]++;
                if(freq1==freq2) {
                    temp.push_back(strs[j]);
                    strs[j] = "-1";
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
