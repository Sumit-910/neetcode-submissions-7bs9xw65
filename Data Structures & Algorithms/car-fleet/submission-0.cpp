class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>> v(n, vector<int>(2));

        for(int i=0;i<n;i++)v[i] = {position[i], speed[i]};
        sort(v.rbegin(), v.rend());

        stack<double> st;
        for(auto& x:v){
            double time = (target - x[0])/(x[1] * 1.0);

            if(st.empty())st.push(time);
            else if(time <= st.top())continue;
            else st.push(time);
        }

        return st.size();
    }
};
