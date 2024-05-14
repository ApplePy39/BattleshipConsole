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
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            TurnFunctionality::PlayerOneBoard[i][j] = { '#', false };
            TurnFunctionality::PlayerTwoBoard[i][j] = { '#', false };

            TurnFunctionality::PlayerOneBoardDisplay[i][j] = { '#', false };
            TurnFunctionality::PlayerTwoBoardDisplay[i][j] = { '#', false };
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
            std::cout << TurnFunctionality::PlayerOneBoard[i][j].getCharacter();
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
            std::cout << TurnFunctionality::PlayerTwoBoard[i][j].getCharacter();
        }

        std::cout << std::endl;
    }
}

void Render::renderPlayerOneDisplay()
{
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << TurnFunctionality::PlayerOneBoardDisplay[i][j].getCharacter();
        }

        std::cout << std::endl;
    }
}

void Render::renderPlayerTwoDisplay()
{
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << TurnFunctionality::PlayerTwoBoardDisplay[i][j].getCharacter();
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
    // Something is wrong with where it copies the ships, not critical, will fix later
    void getPresetOne(Pieces board[11][11])
    {
        std::fstream presetOneFile;
        presetOneFile.open("../source/saves/presetOne.txt", std::ios::in);

        if (presetOneFile.is_open())
        {
            int widthCounter = 0;
            int heightCounter = 0;
            char currentChar;

            while (presetOneFile.get(currentChar))
            {
                if (widthCounter < Render::_boardWidth && heightCounter < Render::_boardHeight) {
                    if (currentChar == 's')
                    {
                        board[widthCounter][heightCounter].setIsShip(true);
                    }

                    board[widthCounter][heightCounter].setCharacter(currentChar);
                    widthCounter++;
                }

                if (widthCounter == Render::_boardWidth)
                {
                    widthCounter = 0;
                    heightCounter++;
                }
            }

            presetOneFile.close();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetOne.txt)" << std::endl;
        }
    }

    void getPresetTwo(Pieces board[11][11])
    {
        std::fstream presetTwoFile;
        presetTwoFile.open("../source/saves/presetTwo.txt", std::ios::in);

        if (presetTwoFile.is_open())
        {
            int widthCounter = 0;
            int heightCounter = 0;
            char currentChar;

            while (presetTwoFile.get(currentChar))
            {
                if (widthCounter < Render::_boardWidth && heightCounter < Render::_boardHeight) {
                    if (currentChar == 's')
                    {
                        board[widthCounter][heightCounter].setIsShip(true);
                    }
                    board[widthCounter][heightCounter].setCharacter(currentChar);
                    widthCounter++;
                }

                if (widthCounter == Render::_boardWidth)
                {
                    widthCounter = 0;
                    heightCounter++;
                }
            }

            presetTwoFile.close();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetTwo.txt)" << std::endl;
        }
    }

    void getPresetThree(Pieces board[11][11])
    {
        std::fstream presetThreeFile;
        presetThreeFile.open("../source/saves/presetThree.txt", std::ios::in);

        if (presetThreeFile.is_open())
        {
            int widthCounter = 0;
            int heightCounter = 0;
            char currentChar;

            while (presetThreeFile.get(currentChar))
            {
                if (widthCounter < Render::_boardWidth && heightCounter < Render::_boardHeight) {
                    if (currentChar == 's')
                    {
                        board[widthCounter][heightCounter].setIsShip(true);
                    }
                    board[widthCounter][heightCounter].setCharacter(currentChar);
                    widthCounter++;
                }

                if (widthCounter == Render::_boardWidth)
                {
                    widthCounter = 0;
                    heightCounter++;
                }
            }

            presetThreeFile.close();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetThree.txt)" << std::endl;
        }
    }
}
