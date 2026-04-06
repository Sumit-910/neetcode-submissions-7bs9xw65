class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto& x:nums){
            if(st.find(x-1) == st.end()){
                int c = 0, num = x;
                while(st.find(num) != st.end())c++, num++;
                ans = max(ans, c);
            }
        }
        return ans;
    }
};