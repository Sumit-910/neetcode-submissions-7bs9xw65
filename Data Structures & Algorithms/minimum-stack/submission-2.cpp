class MinStack {
    stack<int> st, m;
    int mi;
public:
    MinStack() {
        mi = INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        mi = min(mi, val);
        m.push(mi);
    }
    
    void pop() {
        st.pop();
        m.pop();
        if(!m.empty())mi = m.top();
        else mi = INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
    }
};
