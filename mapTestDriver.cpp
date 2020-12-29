#include "hashMap.hpp"

// Implementations of testing for the map test driver
MapTestDriver::MapTestDriver()
{

}

bool MapTestDriver::testInsert()
{
    Map map;
    map.insert("Ahmad", 50);
    map.insert("Testing", 30);
    map.insert("Chico", 75);
    map.insert("Chico", 50);
    assert(map.size == 3);
    assert(map.search("Chico") == 75);
    assert(map.search("Ahmad") == 50);

    map.insert("testing", 500);
    assert(map.size == 4);
    // map.print();

    return true;
}

bool MapTestDriver::testUpdate()
{
    Map map;
    map.insert("Ahmad", 50);
    map.insert("Testing", 30);
    map.insert("Chico", 75);
    assert(map.search("Chico") == 75);
    // ensure element updating works as expected
    map.update("Chico", 50);
    assert(map.search("Chico") == 50);

    // ensure that updating a non-existing element inserts it into the map (expected behavior)
    map.update("Does Not Exist", 999);
    assert(map.size == 4);
    assert(map.search("Does Not Exist") == 999);
    
    // map.print();
    return true;
}

bool MapTestDriver::testInsertOrAssign()
{
    Map map;
    // ensure that if not existing, the new key value is inserted
    map.insertOrAssign("Ahmad", 50);
    map.insertOrAssign("Chico", 75);
    map.insertOrAssign("Testing", 30);

    // ensure that if it already exists, the existing key's value is updated
    map.insertOrAssign("Chico", 50);
    //map.print();
    assert(map.size == 3);
    assert(map.search("Chico") == 50);
    assert(map.search("Ahmad") == 50);

    map.insertOrAssign("testing", 99);
    assert(map.size == 4);

    return true;
}

bool MapTestDriver::testEmpty()
{
    Map map;
    assert(map.empty() == true);

    map.insert("Test", 90);
    assert(map.empty() == false);
    map.clear();
    assert(map.empty() == true);
    
    return true;
}
    
bool MapTestDriver::testGetSize()
{
    Map map;
    map.insert("One", 1);
    assert(map.size == 1);
    map.insert("Two", 2);
    assert(map.size == 2);
    map.clear();
    assert(map.size == 0);
    map.insert("One", 1);
    assert(map.size == 1);
    // map.print();
    map.remove("One");
    // map.print();
    assert(map.size == 0);
    
    return true;
}

bool MapTestDriver::testClear()
{
    Map map;
    map.insert("Ahmad", 1);
    map.insert("Waterloo", 2);
    map.insert("gwah", 5);
    assert(map.size == 3);
    map.clear();
    assert(map.size == 0);
    assert(map.search("Ahmad") == -1);
    assert(map.search("Waterloo") == -1);
    assert(map.search("gwah") == -1);

    return true;
}

bool MapTestDriver::testRemove()
{
    Map map;
    map.insert("Ahmad", 1);
    map.insert("Waterloo", 2);
    map.insert("SYDE", 5);
    assert(map.search("Ahmad") == 1);
    assert(map.remove("Ahmad") == true);
    assert(map.search("Ahmad") == -1);
    assert(map.remove("sjdfsjksa") == false);
    
    return true;
}

bool MapTestDriver::testSearch()
{
    Map map;
    map.insert("Ahmad", 1);
    map.insert("Waterloo", 2);
    map.insert("SYDE", 5);
    assert(map.search("Ahmad") == 1);
    map.remove("Ahmad");
    assert(map.search("Ahmad") == -1);

    return true;
}

bool MapTestDriver::testHashFunction()
{
    Map map;
    assert(map.hashFunction("Ahmad") == 25);
    assert(map.hashFunction("ahmad") != 25);
    assert(map.hashFunction("ahmad") == 7);

    return true;
}

bool MapTestDriver::runTestSuite()
{
    bool passed = true;
    passed &= testInsert();
    passed &= testClear();
    passed &= testEmpty();
    passed &= testGetSize();
    passed &= testHashFunction();
    passed &= testInsertOrAssign();
    passed &= testRemove();
    passed &= testSearch();
    passed &= testUpdate();
    if (passed)
    {
        std::cout << "All test cases passed!" << std::endl;
    }
    return passed;
}