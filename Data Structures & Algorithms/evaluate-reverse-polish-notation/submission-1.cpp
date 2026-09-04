class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto token:tokens){
            if(token != "+" && token != "-" && token != "*" && token != "/"){
                s.push(stoi(token));
            }else{
                int sec = s.top(); s.pop();
                int first = s.top(); s.pop();

                if(token == "+"){
                    s.push(first+sec);
                }else if(token == "-"){
                    s.push(first-sec);
                }else if(token == "*"){
                    s.push(first*sec);
                }else if(token == "/"){
                    s.push(first/sec);
                }
            }
        }

        return s.top();
    }
};
