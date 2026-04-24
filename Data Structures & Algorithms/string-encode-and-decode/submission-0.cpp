class Solution {
private:
    vector<int> lengths;

public:
    string encode(vector<string>& strs) {
        lengths.assign(strs.size(), 0);
        
        string ans = "";
        int idx = 0;

        for (auto& s : strs) {
            lengths[idx++] = s.size();
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        for (int len : lengths) {
            string temp = s.substr(i, len);
            ans.push_back(temp);
            i += len;
        }

        return ans;
    }
};