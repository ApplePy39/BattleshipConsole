//
// Created by OHMCSS on 5/6/2024.
//

#pragma once
#include "Pieces.h"

class Board
{
public:
    Board(Pieces board[11][11]);
    Board() = default;
    ~Board() = default;

private:
    const short _boardHeight { 11 };
    const short _boardWidth { 11 };
};

