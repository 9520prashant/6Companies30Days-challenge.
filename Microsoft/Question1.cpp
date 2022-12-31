// Leetcode - 150. Evaluate Reverse Polish Notation
// T.C->O(N) and S.C->O(N) where N is the number of elements in array 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                if(tokens[i] == "+"){
                    s.push(top1 + top2);
                }else if(tokens[i] == "-"){
                    s.push(top2 - top1);
                }else if(tokens[i] == "*"){
                    s.push(top1 * top2);
                }else{
                    s.push(top2 / top1);
                }
            }else{
                stringstream ss(tokens[i]);
                int data;
                ss >> data;
                s.push(data);
            }
        }
        return s.top();
    }
};