class Solution {
    bool s(vector<int>& piles, int h, int m){
        for(auto& x:piles)h -= ceil((x*1.0)/m);
        return h >= 0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = l + ((r-l)>>1);
            if(s(piles,h,mid))r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
