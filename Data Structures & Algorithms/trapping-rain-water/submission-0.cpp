class Solution {
public:
    int trap(vector<int>& h) {
        int i = 1, j = h.size() - 2;
        int l = h[i - 1], r = h[j + 1];
        int ans = 0;
        while(i<=j){
            if(l < r){
                ans += max(0, l - h[i]);
                l = max(l, h[i]);
                i++;
            }
            else {
                ans += max(0, r - h[j]);
                r = max(r, h[j]);
                j--;
            }
        }
        return ans;
    }
};
