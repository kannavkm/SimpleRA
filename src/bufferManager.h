#pragma once

#include "page.h"
#include "matrixPage.h"
#include <deque>

/**
 * @brief The BufferManager is responsible for reading pages to the main memory.
 * Recall that large files are broken and stored as blocks in the hard disk. The
 * minimum amount of memory that can be read from the disk is a block whose size
 * is indicated by BLOCK_SIZE. within this system we simulate blocks by
 * splitting and storing the file as multiple files each of one BLOCK_SIZE,
 * although this isn't traditionally how it's done. You can alternatively just
 * random access to the point where a block begins within the same
 * file. In this system we assume that the the sizes of blocks and pages are the
 * same. 
 * 
 * <p>
 * The buffer can hold multiple pages quantified by BLOCK_COUNT. The
 * buffer manager follows the FIFO replacement policy i.e. the first block to be
 * read in is replaced by the new incoming block. This replacement policy should
 * be transparent to the executors i.e. the executor should not know if a block
 * was previously present in the buffer or was read in from the disk. 
 * </p>
 *
 */
class BufferManager {

    deque<PageBase*> pages;

    bool inPool(const string &pageName);

    PageBase* getFromPool(const string &pageName);

    Page insertIntoPool(const string &tblName, size_t pageIndex);

    template<typename T>
    MatrixPage<T> insertIntoPool(const string &matName, size_t rowIndex, size_t colIndex);

public:

    BufferManager();

    static void deleteFile(const string &fileName);

    Page getPage(const string &tableName, size_t pageIndex);

    static void writePage(const string& tableName, size_t pgIndex, const vector<vector<int>>& rows, int rowCount);

    void deleteFile(const string &tableName, int pageIndex);

    template<typename T>
    MatrixPage<T> getPage(const string &matrixName, size_t rowIndex, size_t colIndex);

    static void writePage(const string& matrixName, size_t rowIndex, size_t colIndex, const vector<vector<int>>& data, size_t rCount, size_t cCount);

    void deleteFile(const string &matrixName, int rowIndex, int colIndex);
};