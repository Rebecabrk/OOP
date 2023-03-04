#include "NumberList.h"
#include <iostream>
using namespace std;

void NumberList::Init(){
    for(int i=0;i<=10;i++)
        numbers[i]=0;
    count=0;
}

bool NumberList::Add(int x){
    count++;
    if(count>=10){
        count--;
        return false;
    }
    numbers[count]=x;
    return true;
}

void NumberList::Sort(){
    //Bubble Sort
    int i,j;
    for(i=1;i<=count;i++)
        for(j=i;j<=count;j++)
        if(numbers[i]>numbers[j])
            swap(numbers[i],numbers[j]);
}

void NumberList::Print(){
    int i;
    for(i=1;i<=count;i++)
        printf("%d ",numbers[i]);
}