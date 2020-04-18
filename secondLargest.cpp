#include <iostream>
#include <vector>

int secondLargestInteger(std::vector<int> arr) {
    int max = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int main() {
    std::vector<int> s;
    s.push_back(10);
    s.push_back(111);
    s.push_back(990);
    s.push_back(20);
    s.push_back(30);
    s.push_back(56450);
    s.push_back(56449);
    s.push_back(40400);
    s.push_back(4440);
    s.push_back(100);

    std::cout << "The second largest element is " << secondLargestInteger(s) << std::endl;
}
