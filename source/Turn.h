//
// Created by applepy on 29/04/24.
//

#pragma once
#include "Globals.h"

class Turn {
public:
    Turn() = default;
    ~Turn() = default;

    void endTurn();
    void beginGame();
    void playerOneTurn();
    void playerTwoTurn();

private:
    short currentPlayerTurn = 0;
    std::string playerOneName { " " };
    std::string playerTwoName { " " };
};

