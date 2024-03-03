#pragma once

// #include <Arduino.h>
#include <FastLED.h>
class MinMax
{
public:
    MinMax(String name);
    void update(float value);
    void update(uint32_t value);
    void update(int value);
    void update(double value);
    float getMin();
    float getMax();
    void reset();

private:
    String name;
    float minf;
    float maxf;
    double mind;
    double maxd;
    uint32_t min32;
    uint32_t max32;
    int min_int;
    int max_int;
};
MinMax::MinMax(String name)
{
    this->name = name;
    minf = 999999;
    maxf = 0;
    mind = 999999;
    maxd = 0;
    min32 = 999999;
    max32 = 0;
    min_int = 999999;
    max_int = 0;
}
void MinMax::update(float value)
{
    if (value < minf)
    {
        minf = value;
    }
    if (value > maxf)
    {
        maxf = value;
    }
    EVERY_N_SECONDS(1)
    {
        Serial.print(name);
        Serial.print(" (F)Min: ");
        Serial.print(minf);
        Serial.print(" (F)Max: ");
        Serial.println(maxf);
    }
}

void MinMax::update(uint32_t value)
{
    if (value < min32)
    {
        min32 = value;
    }
    if (value > max32)
    {
        max32 = value;
    }
    EVERY_N_SECONDS(1)
    {
        Serial.print(name);
        Serial.print("(32)Min: ");
        Serial.print(min32);
        Serial.print(" (32)Max: ");
        Serial.println(max32);
    }
}

void MinMax::update(int value)
{
    if (value < min_int)
    {
        min_int = value;
    }
    if (value > max_int)
    {
        max_int = value;
    }
}

void MinMax::update(double value)
{
    if (value < mind)
    {
        mind = value;
    }
    if (value > maxd)
    {
        maxd = value;
    }
    EVERY_N_SECONDS(1)
    {
        Serial.print(name);
        Serial.print("(D)Min: ");
        Serial.print(mind);
        Serial.print(" (D)Max: ");
        Serial.println(maxd);
    }
}

float MinMax::getMin()
{
    return minf;
}

float MinMax::getMax()
{
    return maxf;
}

void MinMax::reset()
{
    minf = 999999;
    maxf = 0;
    min32 = 999999;
    max32 = 0;
    min_int = 999999;
    max_int = 0;
}
