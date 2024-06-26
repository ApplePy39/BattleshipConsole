//
// Created by applepy on 29/04/24.
//

#include "Turn.h"
#include "Render.h"
#include <windows.h>

namespace TurnFunctionality
{
    // Colour some console text next to make it stand out (Windows only)
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    short currentPlayerTurn = 0;
    std::string playerOneName { " " };
    std::string playerTwoName { " " };

    static int shipCounterPlayerOne { 13 };
    static int shipCounterPlayerTwo { 13 };

    Pieces PlayerOneBoard[11][11]{};
    Pieces PlayerTwoBoard[11][11]{};

    Pieces PlayerOneBoardDisplay[11][11]{};
    Pieces PlayerTwoBoardDisplay[11][11]{};

    // Simple continue function to make it visually more appealing
    void continueFunc()
    {
        SetConsoleTextAttribute(h, 11);
        std::cout << "Player One ship count: " << shipCounterPlayerOne << std::endl;
        std::cout << "Player Two ship count: " << shipCounterPlayerTwo << std::endl;
        std::cout << "\nPress ENTER to continue...\n";
        std::cin.get();
        system("cls");
        SetConsoleTextAttribute(h, 15);
    }

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

        std::cout << "Current player's are " << playerOneName << " and " << playerTwoName << std::endl;
        std::cout << "Is this correct? (y/N)" << std::endl;

        std::cin >> answer;

        if (answer == 'y')
        {
            system("cls");
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
            std::cout << "Ship counter turn.cpp: " << shipCounterPlayerOne << std::endl;
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

        continueFunc();

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

        continueFunc();
        // Player one will be going first
        playerOneTurn();
    }

    // Player one will have an empty player two's board drawn, so they can guess where to hit next
    void playerOneTurn()
    {
        short xLoc;
        short yLoc;

        std::cout << playerOneName << "'s turn, enter the coordinates of where you would like to hit" << std::endl;
        SetConsoleTextAttribute(h, 11);
        Render::renderPlayerTwoDisplay();
        SetConsoleTextAttribute(h, 15);

        std::cout << "X Location: ";
        std::cin >> xLoc;

        std::cout << "Y Location: ";
        std::cin >> yLoc;

        std::cout << "Location selected: (" << xLoc << ", " << yLoc << ")" << std::endl;

        if (PlayerTwoBoard[yLoc][xLoc].getIsShip()) // if ship is hit
        {
            PlayerTwoBoard[yLoc][xLoc] = { 'x', true };
            PlayerTwoBoardDisplay[yLoc][xLoc] = { 'x', true };
            SetConsoleTextAttribute(h, 10);
            std::cout << "Ship hit at " << xLoc << ", " << yLoc << std::endl;
            shipCounterPlayerTwo--;
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            PlayerTwoBoard[yLoc][xLoc] = { '~', false };
            PlayerTwoBoardDisplay[yLoc][xLoc] = { '~', false };
            SetConsoleTextAttribute(h, 12);
            std::cout << "Failed to hit any target" << std::endl;
            SetConsoleTextAttribute(h, 15);
        }

        SetConsoleTextAttribute(h, 11);
        Render::renderPlayerTwoDisplay();
        SetConsoleTextAttribute(h, 15);

        if (shipCounterPlayerTwo == 0)
        {
            SetConsoleTextAttribute(h, 11);
            std::cout << playerOneName << " has won with " << shipCounterPlayerOne << "ships left!" << std::endl;
            SetConsoleTextAttribute(h, 15);
        }

        std::cin.get();
        continueFunc();
        playerTwoTurn();
    }

    void playerTwoTurn()
    {
        short xLoc;
        short yLoc;

        std::cout << playerTwoName << "'s turn, enter the coordinates of where you would like to hit" << std::endl;
        SetConsoleTextAttribute(h, 11);
        Render::renderPlayerOneDisplay();
        SetConsoleTextAttribute(h, 15);

        std::cout << "X Location: ";
        std::cin >> xLoc;

        std::cout << "Y Location: ";
        std::cin >> yLoc;

        std::cout << "Location selected: (" << xLoc << ", " << yLoc << ")\n" << std::endl;

        if (PlayerOneBoard[yLoc][xLoc].getIsShip()) // if ship is hit
        {
            PlayerOneBoard[yLoc][xLoc] = { 'x', true };
            PlayerOneBoardDisplay[yLoc][xLoc] = { 'x', true };
            SetConsoleTextAttribute(h, 10);
            std::cout << "Ship hit at " << xLoc << ", " << yLoc << std::endl;
            shipCounterPlayerOne--;
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            PlayerOneBoard[yLoc][xLoc] = { '~', false };
            PlayerOneBoardDisplay[yLoc][xLoc] = { '~', false };
            SetConsoleTextAttribute(h, 12);
            std::cout << "Failed to hit any target" << std::endl;
            SetConsoleTextAttribute(h, 15);
        }

        SetConsoleTextAttribute(h, 11);
        Render::renderPlayerOneDisplay();
        SetConsoleTextAttribute(h, 15);

        if (shipCounterPlayerOne == 0)
        {
            SetConsoleTextAttribute(h, 11);
            std::cout << playerTwoName << " has won with " << shipCounterPlayerTwo << "ships left!" << std::endl;
            SetConsoleTextAttribute(h, 15);
        }


        std::cin.get();
        continueFunc();
        playerOneTurn();
    }
}
