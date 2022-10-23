// // Contains Duplicate
// // Using map/dictionary
//   class Solution {
//   public:
//       bool containsDuplicate(vector<int>& nums) {
//           map<int,int> mp;
//           for(auto i : nums) mp[i]++;
//           bool flag = false;
//           for(auto i : mp){
//               if(i.second >= 2) return true;
//           }
//           return flag;
//       }
//   };


// Set Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
    }
};