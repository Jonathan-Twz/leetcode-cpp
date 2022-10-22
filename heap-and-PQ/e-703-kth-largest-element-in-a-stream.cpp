class KthLargest {
public:
    int k_;
    priority_queue<int,vector<int>,greater<int>> pq_;
    
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(auto i:nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if(pq_.size() < k_) {
            pq_.push(val);
        } else {
            if (val>pq_.top()) {
                pq_.pop();
                pq_.push(val);
            }
        }
        return pq_.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */