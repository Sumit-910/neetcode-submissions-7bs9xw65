class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m > n)return false;
        vector<int> f1(26, 0), f2(26, 0);
        for(auto& x:s1)f1[x - 'a']++;
        int matches = 0, dont_match = 0;
        for(auto& x:f1){
            if(x)dont_match++;
        }
        matches = 26 - dont_match;
        cout<<matches<<endl;
        int i = 0;
        while(i < m){
            int ind = s2[i] - 'a';
            f2[ind]++;
            if(f2[ind] == f1[ind])matches++;
            else if(f2[ind] - 1 == f1[ind])matches--;
            i++;
        }
        if(matches == 26)return true;
        while(i < n){
            int prev = s2[i - m] - 'a';
            f2[prev]--;
            if(f2[prev] == f1[prev])matches++;
            else if(f2[prev] + 1 == f1[prev])matches--;

            int ind = s2[i] - 'a';
            f2[ind]++;
            if(f2[ind] == f1[ind])matches++;
            else if(f2[ind] - 1 == f1[ind])matches--;
            
            if(matches == 26)return true;
            i++;
        }
        return  false;
    }
};