class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        priority_queue<vector<int>> maxHeap;
        for(auto p:points) {
            int x = p[0], y = p[1];
            int dis = x*x + y*y;
            maxHeap.push({dis, x, y});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        for(int i=0; i<k; i++) {
            int x = maxHeap.top()[1];
            int y = maxHeap.top()[2];
            maxHeap.pop();
            ans[i] = {x, y};
        }
        
        return ans;
    }
};