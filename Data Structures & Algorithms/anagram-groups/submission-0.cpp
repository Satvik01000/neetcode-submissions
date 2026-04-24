class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        vector<vector<string>> ans;
        for(int i = 0; i<n; i++) {
            if(strs[i]=="-1") continue;
            vector<string> temp;
            string a = strs[i];
            temp.push_back(a);
            for(int j = i+1; j<n; j++) {
                string b = strs[j];
                if(a.size() == b.size()) {
                    sort(a.begin(), a.end());
                    sort(b.begin(), b.end());

                    if(a == b) {
                        temp.push_back(strs[j]);
                        strs[j] = "-1";
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
