// src/services/PieceService.cpp

#ifndef PIECESERVICE_H
#define PIECESERVICE_H

#include "../storage/Storage.cpp"

#include <vector>
#include <string>
#include <map>

using namespace std;

class PieceService
{
private:
    Storage *storage;

public:
    PieceService(Storage *s) : storage(s) {}
    bool moveValidity(vector<int> from, vector<int> to, string color)
    {
        // cout << from[0] << " " << from[1] << endl;
        string type = getPieceType(from[0], from[1]);
        // cout<<type<<endl;
        if (type == "P")
        {
            return PawnValidity(from, to);
        }
        else if (type == "K")
        {
            return kingValidity(from, to);
        }
        else if (type == "N")
        {
            return knightValidity(from, to);
        }
        else if (type == "R")
        {
            return rookValidity(from, to);
        }
        else if (type == "B")
        {
            return bishopValidity(from, to);
        }
        else if (type == "Q")
        {
            return queenValidity(from, to);
        }
        return false;
    }

    string getPieceType(int row, int col)
    {
        if (storage->board->getPiece(row, col))
            return storage->board->getPiece(row, col)->getType();
        else
            return "INVALID PIECE";
    }

    bool knightValidity(vector<int> from, vector<int> to)
    {
        int rd = abs(to[0] - from[0]);
        int cd = abs(to[1] - from[1]);
        return (rd != cd && ((rd >= 1 && rd <= 2) || (cd >= 1 && cd <= 2)));
    }
    bool PawnValidity(vector<int> from, vector<int> to)
    {
        int rd = to[0] - from[0];
        int cd = abs(to[1] - from[1]);
        if (storage->board->getPiece(to[0], to[1]))
        {
            return cd == 1 && rd == 1;
        }
        else
        {
            return cd == 0 && ((from[0] != 6 && rd == 1) || (from[0] == 6 && rd <= 2));
        }
    }
    bool kingValidity(vector<int> from, vector<int> to)
    {
        int rd = abs(to[0] - from[0]);
        int cd = abs(to[1] - from[1]);
        return rd <= 1 && cd <= 1;
    }
    bool bishopValidity(vector<int> from, vector<int> to)
    {
        int rd = abs(to[0] - from[0]);
        int cd = abs(to[1] - from[1]);
        return rd == cd;
    }
    bool queenValidity(vector<int> from, vector<int> to)
    {
        return bishopValidity(from, to) || rookValidity(from, to);
    }
    bool rookValidity(vector<int> from, vector<int> to)
    {
        int rd = abs(to[0] - from[0]);
        int cd = abs(to[1] - from[1]);
        return ((rd != 0 && cd >= 0) || (cd != 0 && rd >= 0));
    }

    ~PieceService() = default;
};

#endif