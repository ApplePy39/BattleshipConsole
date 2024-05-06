//
// Created by applepy on 29/04/24.
//

#include "Turn.h"
#include "Render.h"

// endTurn() will end the current players turn and change the currentPlayerTurn counter
// to either 1 or 0, the opposite of the current, it will call a redraw of the other players board
// so the current player can guess where to hit.

namespace TurnFunctionality
{
    short currentPlayerTurn = 0;
    std::string playerOneName { " " };
    std::string playerTwoName { " " };

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
        int playerOneSelectedPreset = 1;

        std::cout << playerOneName << ", which preset would you like for your ships? (1-3)" << std::endl;
        std::cin >> playerOneSelectedPreset;

        if (playerOneSelectedPreset == 1)
        {
            readPresets::getPresetOne();
        }
    }

// Player one will have player two's board drawn, so they can guess where to hit next
    void playerOneTurn()
    {

    }

    void playerTwoTurn()
    {

    }
}
