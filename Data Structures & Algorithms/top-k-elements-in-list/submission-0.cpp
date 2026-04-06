class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& x:nums)mp[x]++;
        priority_queue<pair<int, int>> pq;
        for(auto& [u,v]:mp)pq.push({v,u});
        vector<int> ans;
        while(!pq.empty() && k){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};
