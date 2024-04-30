//
// Created by OHMCSS on 4/30/2024.
//

#pragma once

class Coordinates {
public:
    Coordinates(short x, short y)
    {
        xValue = x;
        yValue = y;
    }

    short getCoordinateXValue() const;
    void setCoordinateXValue(short xVal);

    short getCoordinateYValue() const;
    void setCoordinateYValue(short yVal);

private:
    short xValue { 0 };
    short yValue { 0 };
};



