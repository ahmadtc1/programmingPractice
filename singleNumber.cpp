class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> numCount;
        std::map<int, int>::iterator it;
        int singleNumber;
        for (int i = 0; i < nums.size(); i++) {
            if (numCount.find(nums[i]) != numCount.end()) {
                numCount[nums[i]] ++;
            } 
            else {
                numCount[nums[i]] = 1;
            }
        }
        for (it = numCount.begin(); it != numCount.end(); ++it) {
            if (it -> second == 1) {
                singleNumber = it -> first;
            }
        }
        return singleNumber;
    }
};
