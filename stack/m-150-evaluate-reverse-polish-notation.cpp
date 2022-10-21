class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(string i:tokens){
            if(i=="+" or i=="-" or i=="*" or i=="/") {
                long l, r;
                r = st.top();
                st.pop();
                l = st.top();
                st.pop();
                long res;
                if (i=="+") res = l+r;
                else if (i=="-") res = l-r;
                else if (i=="*") res = l*r;
                else if (i=="/") res = l/r;
                st.push(res);
            } else {
                st.push(stol(i));
            }
        }
        return st.top();
    }
};