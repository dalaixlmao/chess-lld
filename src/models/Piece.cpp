// src/models/Piece.cpp

#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>
using namespace std;

class Piece
{
private:
    int id;
    string color, type;

public:
    Piece(int id, string color, string type) : id(id), color(color), type(type) {}
    int getId() { return id; }
    string getColor()
    {
        return color;
    }
    string getType()
    {
        // cout << type << endl;
        return type;
    }
    ~Piece() = default;
};

#endif