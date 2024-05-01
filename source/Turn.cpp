//
// Created by applepy on 29/04/24.
//

#include "Turn.h"

// endTurn() will end the current players turn and change the currentPlayerTurn counter
// to either 1 or 0, the opposite of the current, it will call a redraw of the other players board
// so the current player can guess where to hit.
void Turn::endTurn()
{
    if (currentPlayerTurn == 0)
    {
        currentPlayerTurn = 1;
    }
    else
    {
        currentPlayerTurn = 0;
    }
}

// beginGame() will get the players names as well as their ship layout
void Turn::beginGame()
{
    std::cout << "Player 1 name: ";
    std::cin >> playerOneName;
}

// Player one will have player two's board drawn, so they can guess where to hit next
void Turn::playerOneTurn()
{

}

void Turn::playerTwoTurn()
{

}