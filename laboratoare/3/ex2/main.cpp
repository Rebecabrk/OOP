#include "Canvas.h"
#include <iostream>
using namespace std;

int main()
{
    Canvas canvas(10,10);
    canvas.Clear();
    //canvas.DrawCircle(2,2,6,'r');
    //canvas.FillCircle(2,2,6,'f');
    //canvas.Clear();
    canvas.DrawRect(2,3,7,8,'n');
    canvas.FillRect(2,3,7,8,'x');
    //canvas.Clear();
    //canvas.SetPoint(5,5,'t');
    //canvas.Clear();
    canvas.Print();
    return 0;
}