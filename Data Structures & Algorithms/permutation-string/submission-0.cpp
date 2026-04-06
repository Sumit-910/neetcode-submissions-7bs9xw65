class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m)return false;
        int s = 0;
        for(auto& x:s1)s += pow(x - 'a', 2);
        int i = 0, ns = 0;
        while(i < n)ns += pow(s2[i++] - 'a', 2);
        if(ns == s)return true;
        while(i < m){
            ns -= pow(s2[i-n] - 'a', 2);
            ns += pow(s2[i] - 'a', 2);

            if(ns == s)return true;
            i++;
        }
        return false;
    }
};