class Solution {
public:
    vector<string> ans;
    
    void helper(int left, int right, string curr, int n){
        if (curr.length() == 2*n){
            ans.push_back(curr);
            return ;
        }
        
        if(left<n) helper(left+1, right, curr+"(", n);
        if(right<left) helper(left, right+1, curr+")", n);
    }
    
    vector<string> generateParenthesis(int n) {
        helper(0, 0, "", n);
        return ans;
    }
};