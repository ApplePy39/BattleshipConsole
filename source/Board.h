//
// Created by OHMCSS on 5/6/2024.
//

#pragma once
#include "Pieces.h"

class Board
{
public:
    Board(Pieces board[11][11]);
    Board(short boardWidth, short boardHeight);
    Board() = default;
    ~Board() = default;

private:
     short _boardHeight { 11 };
     short _boardWidth { 11 };
};

