//
// Created by Anton Frank on 4/29/2024.
//

#pragma once
#include "Globals.h"
#include "Pieces.h"
#include "Turn.h"

namespace readPresets
{
    extern void getPresetOne(Pieces board[11][11]);
    extern void getPresetTwo(Pieces board[11][11]);
    extern void getPresetThree(Pieces board[11][11]);
}

class Render {
public:
    Render(short boardWidth, short boardHeight, Pieces board[11][11]);
    Render() = default;
    ~Render() = default;

    void StartGame();
    static void renderPlayerOneBoard();
    static void renderPlayerTwoBoard();

    static void renderPlayerOneDisplay(); // Player two will see this
    static void renderPlayerTwoDisplay(); // Player one will see this

    short returnBoardWidth() const;
    short returnBoardHeight() const;
    Pieces playerOneBoard[11][11]{};
    Pieces playerTwoBoard[11][11]{};
    static const short _boardHeight { 11 };
    static const short _boardWidth { 11 };
private:
};


