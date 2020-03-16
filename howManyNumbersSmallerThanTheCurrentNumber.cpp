class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> smallerNumbers;
        int currentCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] != nums[i] && nums[j] < nums[i]) {
                    currentCount++;
                }
            }
            smallerNumbers.push_back(currentCount);
            currentCount = 0;
        }
        return smallerNumbers;
    }
};
