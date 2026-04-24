#define p pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<int, int> mpp;
        for(auto& i : nums) mpp[i]++;

        for(auto& i : mpp) {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
