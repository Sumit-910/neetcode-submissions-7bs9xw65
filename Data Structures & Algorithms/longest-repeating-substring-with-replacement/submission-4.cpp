class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(26, 0);
        int l = 0, r = 0;
        int ans = min(n, k);
        int c = 0;
        while(r < n){
            int ind = s[r] - 'A';
            f[ind]++;
            c = max(c, f[ind]);
            int w = r - l + 1;
            while(l<=r && w - c > k){
                int indd = s[l++] - 'A';
                f[indd]--;
                w--;
            }
            ans = max(ans, w);
            r++;
        }
        return ans;
    }
};
