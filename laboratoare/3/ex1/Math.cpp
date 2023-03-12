#include "Math.h"
#include <iostream>
#include <cstdarg>
using namespace std;

int Math::Add(int x, int y)
{
    return x+y;
}
int Math::Add(int x, int y, int z)
{
    return x+y+z;
}
double Math::Add(double x, double y)
{
    return x+y;
}
double Math::Add(double x,double y,double z)
{
    return x+y+z;
}
int Math::Mul(int x,int y)
{
    return x*y;
}
int Math::Mul(int x,int y,int z)
{
    return x*y*z;
}
double Math::Mul(double x,double y)
{
    return x*y;
}
double Math::Mul(double x,double y,double z)
{
    return x*y*z;
}
int Math::Add(int count,...)
{
    va_list list;
    va_start(list, count);
    int sum=0;
    for(int i=0; i<count; ++i){
        int x = va_arg(list, int);
        sum += x;
    }
    return sum;
}
char* Math::Add(const char * x, const char * y)
{
    char* t= new char[255];
    if(y==nullptr)
    {
        t=nullptr;
        return t;
    }
    strcpy(t,x);
    strcat(t,y);
    return t;
}
