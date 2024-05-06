//
// Created by Anton Frank on 4/29/2024.
//

#include <fstream>
#include "Render.h"
#include "Turn.h"

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

    TurnFunctionality::beginGame();
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

namespace readPresets
{
    void getPresetOne()
    {
        std::fstream presetOneFile;
        presetOneFile.open("../source/saves/presetOne.txt", std::ios::in);
      /*  presetOneFile.open("/saves/presetOne.txt", std::ios::in);
        presetOneFile.open("BattleshipConsole/source/saves/presetOne.txt", std::ios::in);
*/
        if (presetOneFile.is_open())
        {
            std::string currentLine;
            std::cout << "here" << std::endl;
            while (std::getline(presetOneFile, currentLine))
            {
                std::cout << currentLine << std::endl;

            }

            presetOneFile.close();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetOne.txt)" << std::endl;
        }
    }
}
