class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::map<int, int> numbers;
        for (int i = 0; i < arr.size(); ++i) {
            if (numbers.find(arr[i]) != numbers.end()) {
                numbers[arr[i]] ++;
            }
            else {
                numbers[arr[i]] = 1;
            }
        }
        int largestLuckyNum = -1;
        std::map<int, int>::iterator it;
        for (it = numbers.begin(); it != numbers.end(); it++) {
            if (it -> first == it -> second && it -> first > largestLuckyNum) {
                largestLuckyNum = it -> first;
            }
        }
        return largestLuckyNum;
    }
};
