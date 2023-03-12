#include "Math.h"
#include <iostream>
using namespace std;

int main()
{
    printf("int %d\n", Math::Add(5,5));
    printf("int %d\n", Math::Add(5,5,5));
    printf("double %f\n", Math::Add(5.5,5.5));
    printf("double %f\n", Math::Add(5.5,5.5,5.5));
    printf("int %d\n", Math::Mul(5,5));
    printf("int %d\n", Math::Mul(5,5,5));
    printf("double %f\n", Math::Mul(5.5,5.5));
    printf("double %f\n", Math::Mul(5.5,5.5,5.5));
    printf("int %d\n", Math::Add(5,5,5,5,5,5));
    char* concat=Math::Add("rebebeca","fineas");
    printf("string %s\n",concat);
    delete[] concat;
}