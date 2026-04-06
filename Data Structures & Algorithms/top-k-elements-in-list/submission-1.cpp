class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& x:nums)mp[x]++;
        int n = nums.size();
        vector<vector<int>> f(n + 1);
        for(auto& [u,v]:mp)f[v].push_back(u);
        vector<int> ans;
        for(int i=n;i>=0;i--){
            for(auto& x:f[i]){
                ans.push_back(x);
                k--;
                if(!k)break;
            }
            if(!k)break;
        }
        return ans;
    }
};
