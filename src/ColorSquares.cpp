#include "ColorSquares.h"
#include <Arduino.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_101MS, TCS34725_GAIN_4X);

void vInitColorSensor()
{
    Wire.begin();
    if (tcs.begin()) // Makes sure sensor is detected
    {
        tcs.setInterrupt(false);
        delay(100);
    }
}

unsigned char ucDetectColorSquare()
{
    uint16_t r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);
    float total = r + g + b;
    if (total == 0)
    {
        total = 1;
    }
    float red = (float)r / total;
    float green = (float)g / total;
    float blue = (float)b / total;

    if (red > blue * 1.3 && red > green * 1.3)
    {
        return PINK_SQUARE;
    }
    else if (blue > red * 1.3 && blue > green * 1.3)
    {
        return BLUE_SQUARE;
    }
    else if (green > red * 1.3 && green > blue * 1.3)
    {
        return GREEN_SQUARE;
    }
    else if ((red + green) / 2 > blue * 1.2)
    {
        return YELLOW_SQUARE;
    }
    else
    {
        return NO_SQUARE;
    }
}
