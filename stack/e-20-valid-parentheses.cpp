class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(char i:s){
            if (i=='(' || i=='[' || i=='{') {
                stk.push(i);
            } else {
                if (stk.empty() || (i==')'&&stk.top()!='(') || (i==']'&& stk.top()!='[') || (i=='}'&&stk.top()!='{')) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};