#include "Weather.h"
#include "Car.h"
class Peugeot : public Car {
    float GetSpeed(Weather w);
    float GetTotalFuel();
    float GetFuelConsumption();
    char* nume();
};