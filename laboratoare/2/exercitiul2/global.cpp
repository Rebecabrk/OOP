#include "global.h"
#include <iostream>
using namespace std;

int compareName(char name1[], char name2[])
{
    if(strcmp(name1,name2)>0)
        return 1;
    else if (strcmp(name1,name2)==0)
            return 0;
    else if(strcmp(name1,name2)<0)
                return -1;
    return 0;
}
int compareGrade(float grade1, float grade2)
{
    if(grade1==grade2)
        return 0;
    else if(grade1<grade2)
            return -1;
        else if(grade1>grade2)
                return 1;
    return 0;
}
int compareAverage(float average1, float average2)
{
    if(average1==average2)
        return 0;
    else if(average1<average2)
            return -1;
        else if(average1>average2)
                return 1;
    return 0;
}