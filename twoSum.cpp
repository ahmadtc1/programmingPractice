class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        std::map<int, int> numTrack;
        for (int i = 0; i < nums.size(); ++i) {
            if (numTrack.find((target - nums[i])) != numTrack.end()) {
                std::map<int, int>::iterator it = numTrack.find(target-nums[i]);
                solution.push_back( it -> second);
                solution.push_back(i);
                return solution;
            }
            else {
                numTrack[(nums[i])] = i;
            }
        }
        return solution;
    }
};
