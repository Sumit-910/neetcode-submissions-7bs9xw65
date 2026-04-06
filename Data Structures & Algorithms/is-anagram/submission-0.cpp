class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size())return false;
        vector<int> a(26, 0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(auto& x:a){
            if(x)return false;
        }
        return true;
    }
};
