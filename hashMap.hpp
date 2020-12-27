// Hash map implementation in C++
// Implemented by Ahmad Chaudhry
#include <iostream>
#include <string>

class Map
{
private:
    struct HashNode
    {
        HashNode* next = nullptr;
        std::string id;
        int val;

        HashNode(std::string newId, int newVal): id(newId), val(newVal) {}
    };

    int size;
    HashNode* arr[50] = {nullptr};

public:
    Map();
    ~Map();

    int& operator [](std::string key);

    int operator [](std::string key) const;

    bool insert(std::string key, int value);

    bool insertOrAssign(std::string key, int value);

    int search(std::string key);

    int hashFunction(std::string key) const;

    bool update(std::string key, int value);

    bool remove(std::string key);

    bool clear();

    bool empty();

    int getSize();

    void print();
};