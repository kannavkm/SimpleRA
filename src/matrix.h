//
// Created by exclowd on 9/2/21.
//
#pragma once

#include "cursor.h"

class Matrix {
public:
    Matrix() = default;

    explicit Matrix(const string &);

    bool blockify();

    bool load();

    void makePermanent();

    void print() const;

    void transpose();

    void unload() const;

    [[nodiscard]] bool isPermanent() const;

    [[nodiscard]] Cursor getCursor() const;

    bool extractSize(const string &);

    vector<size_t> rowsPerBlockCount;
    vector<size_t> columnsPerBlockCount;
    size_t maxDimPerBlock{};

    string sourceFileName;
    string matrixName;
    size_t size{};
    size_t blockCount{};
};

