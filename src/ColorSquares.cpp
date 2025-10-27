#include "ColorSquares.h"
#include <Arduino.h>
#include <GroveColorSensor.h>

GroveColorSensor RGBsensor;

void vInitColorSensor()
{
    RGBsensor.ledStatus = 1; // Enable LED
}

unsigned char ucDetectColorSquare()
{
    int iRed; 
    int iGreen; 
    int iBlue;

    RGBsensor.readRGB(&iRed, &iGreen, &iBlue);
    if ( (iRed > 200) && (iGreen < 100) && (iBlue > 150) )
    {
        return PINK_SQUARE;
    }
    else if ( (iRed < 100) && (iGreen > 200) && (iBlue < 100) )
    {
        return GREEN_SQUARE;
    }
    else if ( (iRed < 100) && (iGreen < 100) && (iBlue > 200) )
    {
        return BLUE_SQUARE;
    }
    else if ( (iRed > 200) && (iGreen > 200) && (iBlue < 100) )
    {
        return YELLOW_SQUARE;
    }
    else if ( (iRed < 50) && (iGreen < 50) && (iBlue < 50) )
    {
        return NO_SQUARE;
    }
    else
    {
        return WTF_KINDA_COLOR_SQUARE;
    }
}
