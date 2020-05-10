#include <iostream>
#include <vector>

void swap(int* a, int* b);
void shiftZeroes(std::vector<int>& vec);
void printVec(std::vector<int> vec);

int main() {
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);
    // [0, 1, 0, 3, 12]
    shiftZeroes(v);
    printVec(v);
}

void printVec(std::vector<int> vec) {
    for (int& elem: vec) {
        std::cout << elem << std::endl;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void shiftZeroes(std::vector<int>& vec) {
    int firstZeroIndex = NULL;

    for (int i = 0; i < vec.size(); ++i) {
        if (firstZeroIndex == NULL && vec[i] == 0) {
            firstZeroIndex = i;
        }
        if (vec[i] != 0) {
            swap(&vec[i], &vec[firstZeroIndex]);
            int temp = firstZeroIndex;
            firstZeroIndex = NULL;
            for (int j = temp; j <= i; ++j) {
                if (firstZeroIndex == NULL && vec[j] == 0) {
                    firstZeroIndex = j;
                    break;
                }
            }
        }
    }
}
