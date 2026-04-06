class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(auto& x:strs){
            string s = "";
            vector<int> f(26, 0);
            for(auto& y:x)f[y-'a']++;
            for(int i=0;i<26;i++){
                if(f[i]){
                    s += ('a' + i);
                    s += to_string(f[i]);
                }
            }
            mp[s].push_back(x);
        }
        for(auto& [u,v]:mp){
            ans.push_back(v);
        }
        return ans;
    }
};
