#include "Weather.h"
#include "Car.h"
#include "Honda.h"
#include <iostream>
#include <cstring>
using namespace std;
float Honda::GetSpeed(Weather w) {
    switch (w) {
    case Weather::Sunny:
        return 4.5f;
    case Weather::Rainy:
        return 1.5f;
    case Weather::Snowy:
        return 1.0f;
    }
}

float Honda::GetTotalFuel()
{
    return 80.0f;
}

float Honda::GetFuelConsumption(){
    return 0.5f;
}
char* Honda::nume()
{
    char* string= new char[6];
    strcpy(string,"Honda");
    return string;
    delete[] string;
}