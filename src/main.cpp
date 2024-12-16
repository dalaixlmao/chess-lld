// src/main.cpp

#include "services/GameService.cpp"

#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    GameService *game = new GameService();
    int currPlayer = 1;
    string color;
    int rotated = 0;
    game->initializeGame();
    game->displayBoard();
    while (true)
    {
        string m1, m2;
        cin >> m1 >> m2;
        if (currPlayer)
            color = "W";
        else
        {
            if (!rotated)
            {
                game->rotateBoard();
                rotated = 1;
            }
            color = "B";
        }
        if (game->validateMove(m1, m2, color))
        {
            game->makeMove(m1, m2, color);
            cout<<endl;
            game->displayBoard();
            currPlayer = 1 - currPlayer;
            if (rotated)
            {
                game->rotateBoard();
                rotated = 0;
            }
        }
        else
        {
            cout << "INVALID MOVE! Move again." << endl;
        }
    }
}