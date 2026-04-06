class Solution {
    int calc(int a, int b, string op){
        if(op == "+")return a + b;
        else if(op == "-")return a - b;
        else if(op == "*")return a * b;
        else if(op == "/")return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for(auto& x:tokens){
            if(ops.find(x) != ops.end()) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calc(a, b, x));
            }
            else st.push(stoi(x));
        }
        return st.top();
    }
};
