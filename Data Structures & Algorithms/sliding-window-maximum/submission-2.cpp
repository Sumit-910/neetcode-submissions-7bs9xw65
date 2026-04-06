class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> ans(n-k+1);
        int l = 0;
        for(int r=0;r<n;r++){
            while(!dq.empty() && (nums[dq.back()] < nums[r]))dq.pop_back();
            dq.push_back(r);

            if(l > dq.front())dq.pop_front();
            if(r >= k-1)ans[l] = nums[dq.front()], l++;
        }

        return ans;
    }
};
