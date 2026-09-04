class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int first , second, ans ;
        stack<string> s;
        for(int i=tokens.size()-1;i>=0;i--){
            s.push(tokens[i]);
        }

        first = stoi(s.top()); s.pop();
        second = stoi(s.top()); s.pop();
        if(s.top() == "+"){
            first = first + second;s.pop();
        }else if(s.top() == "-"){
            first = first - second;s.pop();
        }else if(s.top() == "*"){
            first = first * second;s.pop();
        }else if(s.top() == "/"){
            first = first / second;s.pop();
        }
        

        while(!s.empty()){
            second = stoi(s.top()); s.pop();
            if(s.top() == "+"){
                first = first + second;s.pop();
            }else if(s.top() == "-"){
                first = first - second;s.pop();
            }else if(s.top() == "*"){
                first = first * second;s.pop();
            }else if(s.top() == "/"){
                first = first / second;s.pop();
            }
        }
        return first;
    }
};
