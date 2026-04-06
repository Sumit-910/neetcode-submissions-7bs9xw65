class Solution {
    int find_max(vector<int>& f){
        int maxi = 0;
        for(auto& x:f)maxi = max(maxi, x);
        return maxi;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(26, 0);
        int l = 0, r = 0;
        int ans = min(n, k);
        while(r < n){
            f[s[r] - 'A']++;
            int c = find_max(f);
            int w = r - l + 1;
            while(w - c > k){
                f[s[l++] - 'A']--;
                c = find_max(f);
                w--;
            }
            ans = max(ans, w);
            r++;
        }
        return ans;
    }
};
