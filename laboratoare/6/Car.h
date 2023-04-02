#pragma once
#include "Weather.h"
class Car
{
    public:
    virtual float GetSpeed(Weather w) = 0;
    virtual float GetTotalFuel() = 0;
    virtual float GetFuelConsumption() = 0;
    virtual char* nume()=0;
};





