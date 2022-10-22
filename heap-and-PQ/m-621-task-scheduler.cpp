class Solution {
public:
    int cnt[26], maxcnt = 0, e = 0;
    int leastInterval(vector<char>& tasks, int n) {
        // get histogram
        for (char c : tasks) cnt[c-'A']++;
        
        // get the most frequent letter count
        for (int i = 0; i < 26; i++) maxcnt = max(maxcnt, cnt[i]);
        
        // if multiple letter shows the same freq
        for (int i = 0; i < 26; i++) 
            if (cnt[i] == maxcnt) e++;
        // (n+1) * (maxcnt-1) + repeated max elements
        return max((int)tasks.size(), (maxcnt-1)*(n+1) + e);
    }
};