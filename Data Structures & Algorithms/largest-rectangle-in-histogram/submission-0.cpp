class Solution {
    vector<int> sl(vector<int>& h){
        int n = h.size();
        stack<int> st;
        vector<int> l(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && h[i] <= h[st.top()])st.pop();
            if(st.empty())l[i] = -1;
            else l[i] = st.top();
            st.push(i);
        }

        return l;
    }

    vector<int> sr(vector<int>& h){
        int n = h.size();
        stack<int> st;
        vector<int> r(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[i] <= h[st.top()])st.pop();
            if(st.empty())r[i] = n;
            else r[i] = st.top();
            st.push(i);
        }

        return r;
    }
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        vector<int> l, r;
        l = sl(h); r = sr(h);

        int ans = 0;
        for(int i=0;i<n;i++){
            int base = r[i] - l[i] - 1;
            int hi = h[i];

            ans = max(ans, base*hi);
        }

        return ans;
    }
};
