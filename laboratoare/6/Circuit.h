#pragma once
#include "Weather.h"
#include "Car.h"
class Circuit
{   
    Car** cars;
    float* times;
    int length,ithCar;
    Weather weather;

    public:
    Circuit();
    ~Circuit();
    void SetLength(int x);
    void SetWeather(Weather x);
    void AddCar(Car* car);
    void Race();
    void SortTimes();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

    void PrintLenght();
    void PrintWeather();
};