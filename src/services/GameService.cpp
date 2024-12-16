// src/services/GameService.cpp

#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "../storage/Storage.cpp"
#include "PieceService.cpp"
#include "../models/Piece.cpp"

#include <vector>
#include <string>
#include <map>

using namespace std;

class GameService
{
private:
    Storage *storage;
    PieceService *pieceService;

public:
    GameService()
    {
        storage = new Storage();
        pieceService = new PieceService(storage);
        initializeGame();
    }

    void initializeGame()
    {
        for (int i = 0; i < 8; i++)
        {
            Piece *p1 = new Piece(storage->pieces.size(), "W", "P");
            storage->pieces[storage->pieces.size()] = p1;
            Piece *p2 = new Piece(storage->pieces.size(), "B", "P");
            storage->pieces[storage->pieces.size()] = p2;
            storage->board->setPiece(6, i, p1);
            storage->board->setPiece(1, i, p2);
        }
        Piece *n1 = new Piece(storage->pieces.size(), "W", "N");
        Piece *n2 = new Piece(storage->pieces.size(), "W", "N");
        Piece *n3 = new Piece(storage->pieces.size(), "B", "N");
        Piece *n4 = new Piece(storage->pieces.size(), "B", "N");
        Piece *b1 = new Piece(storage->pieces.size(), "W", "B");
        Piece *b2 = new Piece(storage->pieces.size(), "W", "B");
        Piece *b3 = new Piece(storage->pieces.size(), "B", "B");
        Piece *b4 = new Piece(storage->pieces.size(), "B", "B");
        Piece *r1 = new Piece(storage->pieces.size(), "W", "R");
        Piece *r2 = new Piece(storage->pieces.size(), "W", "R");
        Piece *r3 = new Piece(storage->pieces.size(), "B", "R");
        Piece *r4 = new Piece(storage->pieces.size(), "B", "R");
        Piece *q1 = new Piece(storage->pieces.size(), "W", "Q");
        Piece *q2 = new Piece(storage->pieces.size(), "B", "Q");
        Piece *k1 = new Piece(storage->pieces.size(), "W", "P");
        Piece *k2 = new Piece(storage->pieces.size(), "B", "K");
        setPiece(7, 0, r1);
        setPiece(7, 7, r2);
        setPiece(0, 0, r3);
        setPiece(0, 7, r4);

        setPiece(7, 1, n1);
        setPiece(7, 6, n2);
        setPiece(0, 1, n3);
        setPiece(0, 6, n4);

        setPiece(7, 2, b1);
        setPiece(7, 5, b2);
        setPiece(0, 2, b3);
        setPiece(0, 5, b4);

        setPiece(7, 3, q1);
        setPiece(7, 4, k1);
        setPiece(0, 3, q2);
        setPiece(0, 4, k2);
    }

    void setPiece(int row, int col, Piece *p)
    {
        storage->board->setPiece(row, col, p);
    }

    vector<int> convertMoveToCoordinate(string move, string color)
    {
        if (color == "W")
            return {7 - move[1] + '1', move[0] - 'a'};
        else
            return {move[1] - '1', 7 - move[0] + 'a'};
    }
    bool validateMove(string from, string to, string color)
    {
        cout << "Cell validation = " << cellValidation(from, to, color) << endl;
        cout << "Color validation = " << colorValidation(from, to, color) << endl;
        cout << "Move Validation = " << moveValidation(from, to, color) << endl;
        return cellValidation(from, to, color) && colorValidation(from, to, color) && moveValidation(from, to, color);
    }
    bool isInside(int row, int col)
    {
        return row >= 0 && col >= 0 && row < 8 && col < 8;
    }
    bool cellValidation(string from, string to, string color)
    {
        vector<int> f = convertMoveToCoordinate(from, color);
        vector<int> t = convertMoveToCoordinate(to, color);
        return isInside(f[0], f[1]) && isInside(t[0], t[1]) && storage->board->getPiece(f[0], f[1]);
    }
    bool colorValidation(string from, string to, string color)
    {
        vector<int> f = convertMoveToCoordinate(from, color);
        vector<int> t = convertMoveToCoordinate(to, color);
        Piece *p1 = storage->board->getPiece(f[0], f[1]);
        Piece *p2 = storage->board->getPiece(t[0], t[1]);
        return (p1->getColor() == color && ((p2 && p2->getColor() != color) || !p2));
    }
    bool moveValidation(string from, string to, string color)
    {
        vector<int> f = convertMoveToCoordinate(from, color);
        vector<int> t = convertMoveToCoordinate(to, color);
        return pieceService->moveValidity(f, t, color);
    }
    void makeMove(string from, string to, string color)
    {
        vector<int> f = convertMoveToCoordinate(from, color);
        vector<int> t = convertMoveToCoordinate(to, color);
        Piece *p = storage->board->getPiece(f[0], f[1]);
        storage->board->setPiece(f[0], f[1], nullptr);
        storage->board->setPiece(t[0], t[1], p);
    }
    void displayBoard()
    {
        storage->board->display();
    }
    void rotateBoard()
    {
        storage->board->rotate();
    }
    ~GameService();
};

#endif