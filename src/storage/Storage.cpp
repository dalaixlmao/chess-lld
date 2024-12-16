//src/storage/Storage.cpp

#ifndef STORAGE_H
#define STORAGE_H

#include "../models/Board.cpp"
#include "../models/Piece.cpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

class Storage
{
public:
    Board *board;
    map<int, Piece *> pieces;
    Storage()
    {
        board = new Board();
    }
    ~Storage() {}
};

#endif