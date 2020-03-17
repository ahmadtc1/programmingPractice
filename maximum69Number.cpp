class Solution {
public:
    int maximum69Number (int num) {
        int numCopy = num;
        std::vector<int> digits;
        while (numCopy > 0) {
            digits.push_back(numCopy % 10);
            numCopy /= 10;
        }
        for (int i = digits.size() -1; i >= 0; --i) {
            if (digits[i] == 6) {
                num -= (pow(10, (i)) * 6);
                num += (pow(10,(i)) * 9);
                return num;
            }
        }
        return num;
    }
};
