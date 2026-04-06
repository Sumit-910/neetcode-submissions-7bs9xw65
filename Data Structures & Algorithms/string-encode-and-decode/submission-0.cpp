class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto& str:strs){
            int n = str.size();
            s += to_string(n);
            s += '-' + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, n = s.size();

        while(i<n){
            int num = 0;
            while(s[i] != '-')num = num*10 + (s[i++] - '0');
            i++;
            string str = "";
            while(num--)str += s[i++];
            ans.push_back(str);
        }

        return ans;
    }
};
