#include "Weather.h"
#include "Car.h"
#include "Renault.h"
#include <iostream>
#include <cstring>
using namespace std;
float Renault::GetSpeed(Weather w) {
    switch (w) {
    case Weather::Sunny:
        return 4.5f;
    case Weather::Rainy:
        return 1.9f;
    case Weather::Snowy:
        return 3.0f;
    }
}

float Renault::GetTotalFuel()
{
    return 90.0f;
}

float Renault::GetFuelConsumption(){
    return 1.2f;
}

char* Renault::nume()
{
    char* string= new char[8];
    strcpy(string,"Renault");
    return string;
    delete[] string;
}