#include <iostream>

class MapTestDriver
{
public:

    MapTestDriver();

    bool testInsert();

    bool testUpdate();

    bool testInsertOrAssign();

    bool testEmpty();

    bool testGetSize();

    bool testClear();

    bool testRemove();

    bool testSearch();

    bool testHashFunction();
    
    bool runTestSuite();
};