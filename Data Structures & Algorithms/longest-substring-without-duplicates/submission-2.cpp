class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0, l = 0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i]) != mp.end())l = max(mp[s[i]] + 1, l);
            mp[s[i]] = i;
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
