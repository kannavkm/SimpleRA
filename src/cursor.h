#pragma once

#include "bufferManager.h"
#include <vector>

/**
 * @brief The cursor is an important component of the system. To read from a
 * table, you need to initialize a cursor. The cursor reads rows from a page one
 * at a time.
 *
 */
class Cursor {
public:
    Page page;
    int pageIndex;
    string tableName;
    int pagePointer;

public:
    Cursor(const string &tblName, int pgIndex);


    vector<int> getNext();

    void nextPage(int pgIndex);
};