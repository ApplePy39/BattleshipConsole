//
// Created by applepy on 29/04/24.
//

#include "Pieces.h"

Pieces::Pieces(char displayVal, bool isShip) : _displayValue(displayVal), _isShip(isShip)
{
}

// sizeOfShip will refer to how many grid spaces the ship spans
// arrangement will determine whether the ship is vertical or horizontal
// locations will hold the points on which the ship is located, it is located in
// a vector which contains a list of these points
Pieces::Pieces(char displayVal, bool isShip, short sizeOfShip, char arrangement, std::vector<Coordinates> locations) :
    _displayValue(displayVal), _isShip(isShip), _sizeOfShip(sizeOfShip), _arrangement(arrangement), _locations(locations)
{
}

char Pieces::getCharacter() const
{
    return this->_displayValue;
}

void Pieces::setCharacter(char character)
{
    this->_displayValue = character;
}