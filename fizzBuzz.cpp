class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<std::string> fizzBuzz;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                fizzBuzz.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                fizzBuzz.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                fizzBuzz.push_back("Buzz");
            }
            else {
                fizzBuzz.push_back(std::to_string(i));
            }
        }
        return fizzBuzz;
    }
};
