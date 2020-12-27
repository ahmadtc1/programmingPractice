// Hash map implementation in C++
// Implemented by Ahmad Chaudhry
#include "hashMap.hpp"
#include <iostream>
#include <string>

Map::Map()
{
    size = 0;
}

Map::~Map()
{
    for (auto& node: arr)
    {
        while (node != nullptr)
        {
            HashNode* next = node -> next;
            delete node;
            node = next;
        }
        node = nullptr;
    }
}

int& Map::operator [](std::string key)
{
    int index = hashFunction(key);
    HashNode* curr = arr[index];
    while (curr != nullptr)
    {
        if (curr -> id == key)
        {
            return curr -> val;
        }
        curr = curr -> next;
    }
}
    
int Map::operator [](std::string key) const
{
    int index = hashFunction(key);
    HashNode* curr = arr[index];
    while (curr != nullptr)
    {
        if (curr -> id == key)
        {
            return curr -> val;
        }
        curr = curr -> next;
    }
}

int Map::hashFunction(std::string key) const
{
    int total = 0;
    for (const auto& letter: key)
    {
        total += int(letter);
    }

    return total % 50;
}

bool Map::insert(std::string key, int value)
{
    int index = hashFunction(key);
    // std::cout << "Hashed Value for " << key << ": " << index << std::endl;
    HashNode* newNode = new HashNode(key, value);
    
    if (arr[index] == nullptr)
    {
        arr[index] = newNode;
    }
    else
    {
        HashNode* curr = arr[index];
        while (curr -> next != nullptr)
        {
            if (curr -> next -> id == key)
            {
                std::cout << "This key already exists. No duplicates possible. Use update(key, value) if looking to update" << std::endl;
                return false;
            }
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
    std::cout << "Inserted succesfully" << std::endl;
    ++size;
    return true;
}

bool Map::insertOrAssign(std::string key, int value)
{
    int index = hashFunction(key);
    HashNode* newNode = new HashNode(key, value);
    
    if (arr[index] == nullptr)
    {
        arr[index] = newNode;
    }
    else
    {
        HashNode* curr = arr[index];
        while (curr -> next != nullptr)
        {
            if (curr -> next -> id == key)
            {
                curr -> next -> val = value;
                delete newNode;
                newNode = nullptr;
                return true;
            }
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
    std::cout << "Inserted succesfully" << std::endl;
    ++size;
    return true;
}

int Map::search(std::string key)
{
    int index = hashFunction(key);
    HashNode* curr = arr[index];

    while (curr != nullptr)
    {
        if (curr -> id == key)
        {
            return curr -> val;
        }
        curr = curr -> next;
    }
    return -1;
}

bool Map::update(std::string key, int value)
{
    int index = hashFunction(key);
    if (arr[index] != nullptr)
    {
        HashNode* curr = arr[index];
        while (curr != nullptr)
        {
            if (curr -> id == key)
            {
                curr -> val = value;
                return true;
            }
            else
            {
                curr = curr -> next;
            }
        }
    }
    std::cout << "The key " << key << " does not exist in this map! Now inserting" << std::endl;
    return insert(key, value);
}

bool Map::remove(std::string key)
{
    int index = hashFunction(key);
    if (arr[index] != nullptr)
    {
        if (arr[index] -> id == key)
        {
            delete arr[index];
            arr[index] = nullptr;
            return true;
        }
        else
        {
            HashNode* curr = arr[index] -> next;
            HashNode* prev = arr[index];
            while (curr != nullptr)
            {
                if (curr -> id == key)
                {
                    HashNode* next = curr -> next;
                    delete curr;
                    prev -> next = next;
                    return true;
                }
                curr = curr -> next;
                prev = prev -> next;
            }
        }
    }
    return false;
}

bool Map::clear()
{
    for (auto& node: arr)
    {
        while (node != nullptr)
        {
            HashNode* next = node -> next;
            delete node;
            node = next;
        }
        node = nullptr;
    }
    return true;
}

bool Map::empty()
{
    return size == 0;
}

int Map::getSize()
{
    return size;
}

void Map::print()
{
    std::cout << "******** PRINTING CONTENTS OF MAP ********" << std::endl;
    for (auto& node : arr)
    {
        while (node != nullptr)
        {
            std::cout << node -> id << ": " << node -> val << std::endl;
            node = node -> next;
        }
    }
    std::cout << "******** DONE PRINTING CONTENTS OF MAP ********" << std::endl;
}

int main()
{
    Map counts;
    counts.insert("String", 100);
    counts.insert("Ahmad", 10000);
    counts.insert("K", 99);
    counts.insertOrAssign("M", 57);
    std::cout << counts.search("K") << std::endl;
    // std::cout << counts.search("Ahmad") << std::endl;
    counts.update("non-existent", 50);
    counts.print();
    std::cout << counts.getSize() << std::endl;
}
