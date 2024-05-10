//
// Created by applepy on 29/04/24.
//

#pragma once
#include "Globals.h"
#include "Pieces.h"

namespace TurnFunctionality
{
    extern void endTurn();
    extern void beginGame();
    extern void chooseShipLocations();
    extern void playerOneTurn();
    extern void playerTwoTurn();
    extern void continueFunc();

    extern Pieces PlayerOneBoard[11][11];
    extern Pieces PlayerTwoBoard[11][11];
    extern Pieces PlayerOneBoardDisplay[11][11];
    extern Pieces PlayerTwoBoardDisplay[11][11];

    extern short currentPlayerTurn;

    extern std::string playerOneName;
    extern std::string playerTwoName;
}