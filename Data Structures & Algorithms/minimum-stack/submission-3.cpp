class MinStack {
    stack<int> st, m;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(!m.empty())m.push(min(m.top(), val));
        else m.push(val);
    }
    
    void pop() {
        st.pop();
        m.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
    }
};
