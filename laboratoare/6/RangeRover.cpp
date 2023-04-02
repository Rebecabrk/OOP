#include "Weather.h"
#include "Car.h"
#include "RangeRover.h"
#include <cstring>
#include <iostream>
using namespace std;

float RangeRover::GetSpeed(Weather w) {
    switch (w) {
    case Weather::Sunny:
        return 6.5f;
    case Weather::Rainy:
        return 1.0f;
    case Weather::Snowy:
        return 3.5f;
    }
}

float RangeRover::GetTotalFuel()
{
    return 120.0f;
}

float RangeRover::GetFuelConsumption(){
    return 1.4f;
}
char* RangeRover::nume()
{
    char* string= new char[11];
    strcpy(string,"RangeRover");
    return string;
    delete[] string;
}