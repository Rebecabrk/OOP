#include "Weather.h"
#include "Car.h"
#include "Peugeot.h"
#include <iostream>
#include <cstring>
using namespace std;
float Peugeot::GetSpeed(Weather w) {
    switch (w) {
    case Weather::Sunny:
        return 5.5f;
    case Weather::Rainy:
        return 2.5f;
    case Weather::Snowy:
        return 2.2f;
    }
}

float Peugeot::GetTotalFuel()
{
    return 100.0f;
}

float Peugeot::GetFuelConsumption(){
    return 0.4f;
}
char* Peugeot::nume()
{
    char* string= new char[8];
    strcpy(string,"Peugeot");
    return string;
    delete[] string;
}