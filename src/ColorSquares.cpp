#include "ColorSquares.h"
#include <Arduino.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_101MS, TCS34725_GAIN_4X);

bool readingInProgress = false;

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
    readingInProgress = false;
    uint16_t red, green, blue, clear;
    tcs.getRawData(&red, &green, &blue, &clear);

    if (clear == 0) return NO_SQUARE; // avoid divide-by-zero

    // Normalize by clear
    float r = (float)red / clear;
    float g = (float)green / clear;
    float b = (float)blue / clear;

    // Normalize to sum = 1 (to reduce light intensity effects)
    float sum = r + g + b;
    if (clear < 2500.0f) return NO_SQUARE;  // very dark area

    r /= sum;
    g /= sum;
    b /= sum;

    // Debug output
    Serial.print("R:");
    Serial.print(r, 3);
    Serial.print(" G:");
    Serial.print(g, 3);
    Serial.print(" C:");
    Serial.print(clear);
    Serial.print(" B:");
    Serial.println(b, 3);

    // --- COLOR DECISION LOGIC ---
    if (r > 0.28f && r > g * 0.95f && r < b * 1.05f) {
        return PINK_SQUARE;  // purple-ish
    }
    else if (b > g * 1.05f && b > r * 1.05f) { 
        return BLUE_SQUARE;
    }
    else if ((r + g)/2 > b * 1.05 && fabsf(r - g) < 0.10) {
        return YELLOW_SQUARE;
    }
    else if (g > r * 1.15f && g > b * 1.01f) {
        return GREEN_SQUARE;
    }
    else {
        return NO_SQUARE;
    }
}
