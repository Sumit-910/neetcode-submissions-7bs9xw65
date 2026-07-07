class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = lower_bound(
            matrix.begin(),
            matrix.end(),
            target,
            [](const vector<int>& row, int val){
                return row[0] <= val;
            }
        ) - matrix.begin() - 1;
        
        if(row < 0)return false;
        int ind = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        if(ind >= 0 && ind < matrix[row].size() && matrix[row][ind] == target)return true;
        return false;
    }
};
