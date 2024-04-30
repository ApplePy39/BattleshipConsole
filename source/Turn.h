//
// Created by applepy on 29/04/24.
//

#pragma once

class Turn {
public:
    Turn() = default;
    ~Turn() = default;

    // endTurn() will end the current players turn and change the currentPlayerTurn counter
    // to either 1 or 0, the opposite of the current, it will call a redraw of the other players board
    // so the current player can guess where to hit.
    void endTurn();

private:
    short currentPlayerTurn = 0;
};

