class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    MedianFinder() { }
    
    void addNum(int num) {
        // maxHeap is the smaller part of the data;
        // minHeap is the larger part of the data;
        // push to smaller part, pop the top to larger part;
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // smaller part size is greater than larger part;
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {    
        if(minHeap.size()==maxHeap.size()) {
            return (minHeap.top() + maxHeap.top())/2.0;
        } else {
            return (double)maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */