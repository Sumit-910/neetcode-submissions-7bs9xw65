class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), j = 0, ans = 0;
        unordered_set<char> st;

        for(int i=0;i<n;i++){
            if(st.find(s[i]) != st.end()){
                ans = max(ans, (int)st.size());
                while(s[i] != s[j])st.erase(s[j++]);
                if(s[i] == s[j])st.erase(s[j++]);
            }
            st.insert(s[i]);
        }

        return max(ans, (int)st.size());
    }
};
