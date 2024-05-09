//
// Created by applepy on 29/04/24.
//

#include "Turn.h"
#include "Render.h"

namespace TurnFunctionality
{
    short currentPlayerTurn = 0;
    std::string playerOneName { " " };
    std::string playerTwoName { " " };

    Pieces PlayerOneBoard[11][11]{};
    Pieces PlayerTwoBoard[11][11]{};


    Pieces PlayerOneBoardDisplay[11][11]{};
    Pieces PlayerTwoBoardDisplay[11][11]{};

    void endTurn()
    {
        if (currentPlayerTurn == 0)
        {
            currentPlayerTurn = 1;
        }
        else
        {
            currentPlayerTurn = 0;
        }
    }

// beginGame() will get the players names as well as their ship layout
    void beginGame()
    {
        char answer;

        std::cout << "Player 1 name: ";
        std::cin >> playerOneName;

        std::cout << "Player 2 name: ";
        std::cin >> playerTwoName;

        std::cout << "Current player's are " << playerOneName << " " << playerTwoName << std::endl;
        std::cout << "Is this correct? (y/N)" << std::endl;

        std::cin >> answer;

        if (answer == 'y')
        {
            chooseShipLocations();
        }

        else
        {
            exit;
        }
    }

    // Players will choose the placement for their ships
    // At the moment this will be implemented as presets,
    // if time permits, I will add custom ship placement
    void chooseShipLocations()
    {
        int playerOneSelectedPreset { 1 };
        int playerTwoSelectedPreset { 1 };

        std::cout << playerOneName << ", which preset would you like for your ships? (1-3)" << std::endl;
        std::cin >> playerOneSelectedPreset;

        std::cout << "The chosen preset for " << playerOneName << " is:" << std::endl;

        if (playerOneSelectedPreset == 1)
        {
            readPresets::getPresetOne(TurnFunctionality::PlayerOneBoard);
            Render::renderPlayerOneBoard();
        }

        else if (playerOneSelectedPreset == 2)
        {
            readPresets::getPresetTwo(TurnFunctionality::PlayerOneBoard);
            Render::renderPlayerOneBoard();
        }

        else if (playerOneSelectedPreset == 3)
        {
            readPresets::getPresetThree(TurnFunctionality::PlayerOneBoard);
            Render::renderPlayerOneBoard();
        }

        std::cin.get();

        system("cls");

        std::cout << playerTwoName << ", which preset would you like for your ships? (1-3)" << std::endl;
        std::cin >> playerTwoSelectedPreset;

        std::cout << "The chosen preset for " << playerTwoName << " is:" << std::endl;

        if (playerTwoSelectedPreset == 1)
        {
            readPresets::getPresetOne(TurnFunctionality::PlayerTwoBoard);
            Render::renderPlayerTwoBoard();
        }

        else if (playerTwoSelectedPreset == 2)
        {
            readPresets::getPresetTwo(TurnFunctionality::PlayerTwoBoard);
            Render::renderPlayerTwoBoard();
        }

        else if (playerTwoSelectedPreset == 3)
        {
            readPresets::getPresetThree(TurnFunctionality::PlayerTwoBoard);
            Render::renderPlayerTwoBoard();
        }


        // Player one will be going first
        playerOneTurn();
    }

    // Player one will have an empty player two's board drawn, so they can guess where to hit next
    void playerOneTurn()
    {
        short xLoc;
        short yLoc;

        std::cout << playerOneName << "'s turn, enter the coordinates of where\nyou would like to hit" << std::endl;
        Render::renderPlayerTwoDisplay();

        std::cout << "X Location: ";
        std::cin >> xLoc;

        std::cout << "Y Location: ";
        std::cin >> yLoc;

        std::cout << "Location selected: (" << xLoc << ", " << yLoc << ")" << std::endl;

        PlayerTwoBoard[xLoc][yLoc] = { 'x', true };

        for (int i = 0; i < Render::_boardWidth; i++)
        {
            for (int j = 0; j < Render::_boardHeight; j++)
            {

            }
        }
    }

    void playerTwoTurn()
    {

    }
}
