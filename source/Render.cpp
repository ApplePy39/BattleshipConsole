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
            PlayerOneBoard[i][j] = { '#', false };
            PlayerTwoBoard[i][j] = { '#', false };
        }
    }
    TurnFunctionality::beginGame();
}

void Render::renderPlayerOneBoard()
{
    std::cout << "render function\n";
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << PlayerOneBoard[i][j].getCharacter();
        }

        std::cout << std::endl;
    }
    std::cout << "render function";
}

void Render::renderPlayerTwoBoard()
{
    for (int i = 0; i < _boardWidth; i++)
    {
        for (int j = 0; j < _boardHeight; j++)
        {
            std::cout << PlayerTwoBoard[i][j].getCharacter();
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
    /*void getPresetOne(Pieces board[11][11])
    {
        std::fstream presetOneFile;
        presetOneFile.open("../source/saves/presetOne.txt", std::ios::in);

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
    }*/

    void getPresetOne(Pieces board[11][11])
    {
        std::fstream presetOneFile;
        presetOneFile.open("../source/saves/presetOne.txt", std::ios::in);


        // It is always assigning the last chracter of the map to the whole board
        // double for loop in a while loop is to blame I think
        if (presetOneFile.is_open())
        {
/*            int widthCounter = 0;
            int heightCounter = 0;*/
            char currentChar;
            std::cout << "here" << std::endl;
            while (presetOneFile.get(currentChar))
            {
             /*   if (widthCounter < Render::_boardWidth && heightCounter < Render::_boardHeight)
                {
                    std::cout << currentChar << std::endl;
                    PlayerOneBoard[widthCounter][heightCounter].setCharacter(currentChar);
                    widthCounter++;
                    heightCounter++;
                }*/

                for (int i = 0; i < Render::_boardHeight; i++)
                {
                    for (int j = 0; j < Render::_boardWidth; j++)
                    {
                        board[i][j].setCharacter(currentChar);
                    }
                }
            }

            std::cout << "character added: " << currentChar;
            presetOneFile.close();

            Render::renderPlayerOneBoard();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetOne.txt)" << std::endl;
        }
    }

    void getPresetTwo()
    {
        std::fstream presetTwoFile;
        presetTwoFile.open("../source/saves/presetTwo.txt", std::ios::in);

        if (presetTwoFile.is_open())
        {
            std::string currentLine;
            std::cout << "here" << std::endl;
            while (std::getline(presetTwoFile, currentLine))
            {
                std::cout << currentLine << std::endl;

            }

            presetTwoFile.close();
            std::cin.get();
        }

        else
        {
            std::cout << "Unable to open file: (presetTwo.txt)" << std::endl;
        }
    }
    void getPresetThree()
    {
        std::fstream presetThreeFile;
        presetThreeFile.open("../source/saves/presetThree.txt", std::ios::in);

        if (presetThreeFile.is_open())
        {
            std::string currentLine;
            std::cout << "here" << std::endl;
            while (std::getline(presetThreeFile, currentLine))
            {
                std::cout << currentLine << std::endl;

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
