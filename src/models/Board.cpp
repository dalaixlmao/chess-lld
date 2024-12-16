// src/models/Board.cpp

#ifndef BOARD_H
#define BOARD_H

#include "Piece.cpp"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Board
{
private:
    vector<vector<Piece *>> board;

public:
    Board()
    {
        board = vector<vector<Piece *>>(8, vector<Piece *>(8, nullptr));
    }
    Piece *getPiece(int row, int col)
    {
        return board[row][col];
    }
    void setPiece(int row, int col, Piece *p)
    {
        board[row][col] = p;
    }

    void display()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j])
                {
                    cout << board[i][j]->getColor() + board[i][j]->getType();
                }
                else
                {
                    cout << "--";
                }
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void rotate()
    {
        reverse(board.begin(), board.end());
        for (int i = 0; i < 8; i++)
        {
            reverse(board[i].begin(), board[i].end());
        }
    }

    ~Board();
};
#endif