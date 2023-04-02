#include "Weather.h"
#include "Car.h"
class Renault : public Car {
    float GetSpeed(Weather w);
    float GetTotalFuel();
    float GetFuelConsumption();
    char* nume();
};