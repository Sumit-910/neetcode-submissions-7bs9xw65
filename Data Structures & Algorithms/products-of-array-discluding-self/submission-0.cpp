class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int p = 1, c = 0, ind = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                c++;
                ind = i;
            }
            else p *= nums[i];
        }
        if(c>1)return vector<int>(nums.size(), 0);
        vector<int> ans(n, 0);
        if(c)ans[ind] = p;
        else {
            for(int i=0;i<n;i++)ans[i] = p/nums[i];
        }
        return ans;
    }
};
