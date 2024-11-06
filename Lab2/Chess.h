#pragma once
#ifndef CHESS_H
#define CHESS_H
#include <iostream>
#include <string>

using namespace std;

class Chess {
private:
    string pieceType;
    string position;

public:
    Chess(const string& type, const string& pos);

    Chess(const Chess& other);

    Chess(Chess&& other) noexcept;

    Chess& operator=(const Chess& other);

    Chess& operator=(Chess&& other) noexcept;

    void printInfo() const;

    ~Chess();
};

#endif
