//
// Created by Anton Frank on 4/29/2024.
//

#pragma once
#include "Globals.h"
#include "Pieces.h"
#include "Turn.h"

class Render {
public:
    Render(short boardWidth, short boardHeight, Pieces board[11][11]);
    Render() = default;
    ~Render() = default;

    void StartGame();
    void renderPlayerOneBoard();
    void renderPlayerTwoBoard();
    short returnBoardWidth() const;
    short returnBoardHeight() const;

private:
    const short _boardHeight { 11 };
    const short _boardWidth { 11 };
    Pieces playerOneBoard[11][11]{};
    Pieces playerTwoBoard[11][11]{};
};


