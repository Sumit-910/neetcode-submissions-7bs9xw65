class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(26, 0);
        int l = 0, r = 0;
        int ans = min(n, k);
        unordered_map<int, int> mp;
        int c = 0;
        while(r < n){
            int ind = s[r] - 'A';
            if(mp.find(f[ind]) != mp.end() && mp[f[ind]] != 0)mp[f[ind]]--;
            f[ind]++;
            mp[f[ind]]++;
            c = max(c, f[ind]);
            int w = r - l + 1;
            while(l<=r && w - c > k){
                int indd = s[l++] - 'A';
                mp[f[indd]]--;
                f[indd]--;
                mp[f[indd]]++;
                if(mp[c] == 0)c--;
                w--;
            }
            ans = max(ans, w);
            r++;
        }
        return ans;
    }
};
