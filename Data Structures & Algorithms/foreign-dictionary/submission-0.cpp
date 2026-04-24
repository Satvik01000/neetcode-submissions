class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        vector<set<char>> adjList(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        for (auto &word : words) {
            for (char c : word) present[c - 'a'] = true;
        }

        for(int i = 1; i < n; i++) {
            string a = words[i];
            string b = words[i-1];

            int j = 0, k = 0;

            while(j < a.size() && k < b.size()) {
                if(a[j] != b[k]) {
                    adjList[b[k] - 'a'].insert(a[j]);
                    break;
                }
                j++; k++;
            }

            if(j == a.size() && k < b.size()) return "";
        }

        for(int u = 0; u < 26; u++) {
            for(char v : adjList[u]) {
                indegree[v - 'a']++;
            }
        }

        queue<char> q;
        for(char c = 'a'; c <= 'z'; c++) {
            if(present[c - 'a'] && indegree[c - 'a'] == 0) q.push(c);
        }

        string ans = "";
        while(!q.empty()) {
            char node = q.front();
            q.pop();
            ans+=node;

            for(auto& i : adjList[node-'a']) {
                indegree[i-'a']--;
                if(indegree[i-'a']==0) q.push(i);
            }
        }
        
        int count = 0;
        for(auto i : present) if(i) count++;
        
        if (ans.size() != count) return "";
        return ans;
    }
};