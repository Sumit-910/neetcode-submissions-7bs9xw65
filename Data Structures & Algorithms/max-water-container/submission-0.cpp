class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int ans = 0;
        while(i < j){
            int height = min(heights[i], heights[j]);
            int base = j - i;
            int area = base*height;

            ans = max(ans, area);
            if(heights[i] < heights[j])i++;
            else j--;
            
        }
        return ans;
    }
};
