#include<iostream>
#include "Vector.cpp"
using namespace std;

int compareInts(int x, int y)
{
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
};

int compareFloats(float x, float y)
{
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}


int main()
{
    Vector<int> vector;
    vector.insert(0,67);
    vector.insert(1,34);
    vector.insert(2,6);
    vector.print();
    Vector<int> w = vector;
    w.print();
    w.remove(0);
    w.print();
    w.sort(compareInts);
    w.print();
}