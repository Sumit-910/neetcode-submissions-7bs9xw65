class Solution {
public:
    bool isPalindrome(string str) {
        string s = "";
        for(auto& x:str){
            if(x >= '0' && x <= '9')s += x;
            else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))s += tolower(x);
        }
        int n = s.size();
        int i = 0, j = n - 1;
        while(i<j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
};
