#include "NumberList.h"
#include <iostream>

int main()
{
    NumberList vector;
    vector.Init();
    vector.Add(10);
    vector.Add(9);
    vector.Add(8);
    vector.Add(7);
    vector.Add(6);
    vector.Add(5);
    vector.Add(4);
    vector.Add(3);
    vector.Add(2);
    vector.Add(1);
    vector.Sort();
    vector.Print();
}