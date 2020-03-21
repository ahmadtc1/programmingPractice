class Solution {
public:
    int balancedStringSplit(string s) {
        int splits = 0;
        int lCount = 0;
        int rCount = 0;
        std::string l = "L";
        std::string r = "R";
        std::string currentLetter;
        for (int i = 0; i < s.length(); i++) {
            currentLetter = s[i];
            if (string(1, s[i]) == l) {
                lCount++;
            }
            else if (string(1, s[i]) == r) {
                rCount++;
            }
            if (lCount == rCount) {
                splits++;
                lCount = 0;
                rCount = 0;
            }
        }
        return splits;
    }
};
