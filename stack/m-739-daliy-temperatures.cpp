// O(n^2) for tc, my initial try

// class Solution {
// public:
    
//     int getDates(int temp, vector<int> temp_future) {
//         for (int i=0; i<temp_future.size(); i++) {
//             if(temp_future[i]>temp) return i+1;
//         }
//         return 0;
//     }
    
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> answer;
//         int s = temperatures.size();
//         for(int i=0; i<s; i++) {
//             int curr_temp = temperatures[0];
//             temperatures.erase(temperatures.begin());
//             answer.push_back(getDates(curr_temp, temperatures));
//         }
//         return answer;
//     }
// };

// using stack from the back, see post at
// https://leetcode.com/problems/daily-temperatures/discuss/1574806/C%2B%2B-EASY-standard-sol-oror-INTUITIVE-approach-with-DRY-RUN-oror-STACK-appraoch

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& t) {
            int n = t.size();
            vector<int> nge(n, 0);
            stack<int> st;
            
            for(int i=n-1; i>=0; i--) {
                // if stack's top is less than current temperature, pop stack
                // until find the greater temperature than the current temp
                int t_curr = t[i];
                while(!st.empty() && t[st.top()] <= t_curr) {
                    st.pop();
                }
                
                if(!st.empty()) {
                // assign the difference between stack's top and current index
                    nge[i] = st.top() - i;
                }
                
                // push current index to stack for later use
                st.push(i);
            }
            return nge;
        }
};