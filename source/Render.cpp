//
// Created by Anton Frank on 4/29/2024.
//

#include "Render.h"

void Render::StartGame()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            board[i][j] = '~';
            std::cout << "X: " << i << " Y: " << j << std::endl;
        }
    }
}