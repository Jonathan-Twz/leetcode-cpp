class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pos_time(position.size());
        
        // sort the time-to-target by the left distance to target, nearest ranked 1
        for (int i=0; i<position.size(); i++) {
            double timeToTarget = float(target-position[i])/speed[i];
            pos_time[i] = {-position[i], timeToTarget};
        }
        
        sort(pos_time.begin(), pos_time.end());
        
        // stack stores the car fleet arrival times, should be monotonic increase
        stack<double> tof;
        
        for (auto pt:pos_time) {
            double t = pt.second;
            // if tof1 < tof2, which means car2 cannot chase car1
            // if tof1 >= tof2, which means car2 can form a fleet with car1
            if (!tof.empty() && t > tof.top()) {
                tof.push(t);
            }
            if (tof.empty()) tof.push(t);
        }
        
        return tof.size();
    }
};