//
// Created by Anton Frank on 4/29/2024.
//

#pragma once
#include "Globals.h"
#include "Pieces.h"

class Render {
public:
    Render() = default;
    ~Render() = default;

    void StartGame();
    void renderBoard() const;
    void returnBoardWidth() const;
    void returnBoardHeight() const;
private:
    Pieces board[11][11]{};
};


