#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include "Honda.h"
#include "Peugeot.h"
#include "RangeRover.h"
#include "Renault.h"
using namespace std;

int main()
{
    Circuit c;
    c.SetLength(1000);
    c.SetWeather(Weather::Snowy);
    c.PrintLenght();
    c.PrintWeather();
    c.AddCar(new Honda());
    c.AddCar(new Peugeot());
    c.AddCar(new RangeRover());
    c.AddCar(new Renault());
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
    return 0;
}