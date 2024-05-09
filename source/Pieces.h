//
// Created by applepy on 29/04/24.
//

#pragma once
#include <vector>
#include "Coordinates.h"

class Pieces {
public:
    Pieces() = default;
    ~Pieces() = default;
    Pieces(char displayVal, bool)
    Pieces(char displayVal, bool isShip);
    Pieces(char displayVal, bool isShip, short sizeOfShip, char arrangement, std::vector<Coordinates> locations);

    char getCharacter() const;
    void setCharacter(char character);

    bool getIsShip() const;
    void setIsShip(bool value);

private:
    bool _isShip;
    char _displayValue;
    short _sizeOfShip;
    char _arrangement;
    std::vector<Coordinates> _locations {};
};

