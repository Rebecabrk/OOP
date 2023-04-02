#include "Weather.h"
#include "Car.h"
class RangeRover : public Car {
    float GetSpeed(Weather w);
    float GetTotalFuel();
    float GetFuelConsumption();
    char* nume();
};