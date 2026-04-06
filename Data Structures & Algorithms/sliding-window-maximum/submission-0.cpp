class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        int n = nums.size();

        for(int i=0;i<k && i<n;i++){
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(pq.top());

        for(int i=k;i<n;i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
            mp[nums[i-k]]--;

            while(mp[pq.top()] == 0)pq.pop();
            ans.push_back(pq.top());
        }

        return ans;
    }
};
