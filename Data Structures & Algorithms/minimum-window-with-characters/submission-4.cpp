class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m)return "";
        unordered_map<char, int> ft, fs;
        for(auto& x:t)ft[x]++;
        int matches = 0, ft_size = ft.size();

        int i = 0, j = 0;
        int ai = -1, aj = -1, len = n+1;
        int have = 0, need = ft.size();
        
        for(int j=0;j<n;j++){
            char c = s[j];
            if(ft.find(c) == ft.end())continue;
            fs[c]++;
            if(fs[c] == ft[c])have++;

            while(have == need){
                if(j-i+1 < len){
                    len = j-i+1;
                    ai = i; aj = j;
                }
                char cs = s[i++];
                if(ft.find(cs) == ft.end())continue;
                fs[cs]--;
                if(fs[cs] == ft[cs] - 1)have--;

            }
        }

        if(ai == -1)return "";
        return s.substr(ai, aj-ai+1);
    }
};
