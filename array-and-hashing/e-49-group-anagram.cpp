class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto i:m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};