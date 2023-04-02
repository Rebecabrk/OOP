#include "Weather.h"
#include "Car.h"
class Honda : public Car{
    float GetSpeed(Weather w);
    float GetTotalFuel();
    float GetFuelConsumption();
    char* nume();
};