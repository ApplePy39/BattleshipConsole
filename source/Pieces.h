//
// Created by applepy on 29/04/24.
//

#pragma once
#include <vector>

class Pieces {
public:

    // sizeOfShip will refer to how many grid spaces the ship spans
    // arrangement will determine whether the ship is vertical or horizontal
    // locations will hold the points on which the ship is located, it is located in
    // a vector which contains a list of these points
    Pieces(short sizeOfShip, char arrangement, std::vector<char[1][1]> locations)
    {
        _sizeOfShip = sizeOfShip;
        _arrangement = arrangement;
        _locations = locations;
    }

    ~Pieces() = default;

private:
    short _sizeOfShip;
    char _arrangement;
    std::vector<char[1][1]> _locations;
};

