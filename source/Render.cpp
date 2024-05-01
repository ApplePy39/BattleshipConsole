//
// Created by Anton Frank on 4/29/2024.
//

#include "Render.h"

Render::Render(short boardWidth, short boardHeight, Pieces board[11][11])
{
    boardWidth = 11;
    boardHeight = 11;
    playerOneBoard[11][11] = board[boardWidth][boardHeight];
    playerTwoBoard[11][11] = board[boardWidth][boardHeight];
}

void Render::StartGame()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            playerOneBoard[i][j] = { '#', false };
            playerTwoBoard[i][j] = { '#', false };
        }
    }

    // begin game function here (Turn.h)

}

void Render::renderPlayerOneBoard()
{
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << playerOneBoard[i][j].getCharacter();
        }

        std::cout << std::endl;
    }
}

void Render::renderPlayerTwoBoard()
{
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << playerTwoBoard[i][j].getCharacter();
        }

        std::cout << std::endl;
    }
}

short Render::returnBoardHeight() const
{
    return _boardHeight;
}

short Render::returnBoardWidth() const
{
    return _boardWidth;
}