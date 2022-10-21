class Solution {
public:
    int maxArea=0;
    
    void update(int s) {
        maxArea = (s>maxArea)? s:maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        
        // refer to this video
        // https://www.youtube.com/embed/zx5Sw9130L0
        // a stack of {index, height}, height should be monotonic increase
        stack<pair<int, int>> st;
        
        for(int i=0; i<heights.size(); i++) {
            int h = heights[i];
            update(h);
            int i_left = i;
            while(!st.empty() && h<=st.top().second){
                int area;
                
                // if not counting the current height
                area = st.top().second * (i-st.top().first);
                update(area);
                
                // if counting the current height
                area = h * (i - st.top().first +1);
                update(area);
                
                // update the stack index if current h is smaller than the left
                i_left = st.top().first;
                st.pop();
            }
            st.push({i_left, h});
        }
        
        // stack is complete, calculate area from right(top of stack) to left
        int idx_right = heights.size()-1;
        while(!st.empty()) {
            int idx_left = st.top().first;
            int h = st.top().second;
            int area = h * (idx_right - idx_left + 1);
            // cout << "{" << idx_left << "," << h << "=" << area << "}" << endl;
            update(area);
            st.pop();
        }
        
        return maxArea;
    }
};