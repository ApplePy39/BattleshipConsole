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

    extern short currentPlayerTurn;
    extern std::string playerOneName;
    extern std::string playerTwoName;
}