class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }else{
            int mini = s.top().second;
            mini = min(mini, val);

            s.push({val, mini});
        }
        return;
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
            return;
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top().first;
        }else{
            return -1;
        }
    }
    
    int getMin() {
        if(!s.empty()){
            return s.top().second;
        }else{
            return -1;
        }
    }
};
