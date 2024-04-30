//
// Created by Anton Frank on 4/29/2024.
//

#pragma once
#include "Globals.h"

class Render {
public:
    Render() = default;
    ~Render() = default;

    void StartGame();
private:
    char board[11][11]{};
};


