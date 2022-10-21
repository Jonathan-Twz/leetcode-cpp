// First try using stack;
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> st;
//         for (auto i:s){
//             if (!st.empty() && i==st.top()) {
//                 st.pop();
//             } else {
//                 st.push(i);
//             }
//         }
//         string str;
//         while(!st.empty()){
//             char i = st.top();
//             st.pop();
//             str.insert(0,1,i);
//         }
//         return str;
//     }
// };

// Optimal solution
class Solution {
    public:
        string removeDuplicates(string s) {
            string ans;
            ans.push_back(s[0]);
            for (int i=1; i<s.size(); i++) {
                if(ans.size()!=0 && s[i]==ans.back()) {
                    ans.pop_back();
                } else {
                    ans.push_back(s[i]);
                }
            }
            return ans;
        }  
};