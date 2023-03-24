#include "Sort.h"
#include <ctime>
#include <initializer_list>
#include <cstdarg>
#include <cstring>
#include<iostream>
#include <cstdarg>
#include <initializer_list>
using namespace std;
Sort::Sort(int number, int minimum, int maximum)
{
    this->vector=new int[number];
    size=number;
    srand(time(NULL));
    for(int i=0; i<number; i++)
    {
        int x=minimum+rand()%(maximum-minimum+1);
        this->vector[i]=x;
    }   
}
/*Sort::Sort(initializer_list<int> list)
{
    int i=0,number=0;
    for (int x : list)
    {
        number++;
    }
    this->vector= new int[number];
    size=number;
    for (int x : list)
    {
        this->vector[i]=x;
        i++;
    }
}*/
Sort::Sort(int *vector, int size)
{
    this->vector=new int[size];
    this->size=size;
    for(int i=0;i<size;i++)
        this->vector[i]=vector[i];
}
Sort::Sort(int number, ...)
{
    this->vector=new int[number];
    size=number;
    va_list list;
    va_start(list, number);
    for (int i = 0; i < number; i++) {
        int x = va_arg(list, int);
        this->vector[i]=x;
    }
}
Sort::Sort(char *string)
{
    char newString[strlen(string)+1];
    strcpy(newString,string);
    char *p; int number=0;
    p=strtok(string,",");
    while(p)
    {
        ++number;
        p=strtok(NULL,",");
    }
    this->vector=new int[number];
    size=number;
    p=strtok(newString,",");
    int i=0;
    while(p)
    {
        this->vector[i]=atoi(p);
        p=strtok(NULL,",");
        i++;
    }
}
void Sort::BubbleSort(bool ascendent)
{
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(ascendent==false)
            {
                //descrescator
                if(vector[i]<vector[j])
                    swap(vector[i],vector[j]);
            }
            else 
            {
                //crescator
                if(vector[i]>vector[j])
                    swap(vector[i],vector[j]);
            }
}
void Sort::QuickSort(bool ascendent)
{
    int low=1, high=size, pi;
    if (low < high) {
        int pivot = vector[high]; 
        int i = (low- 1);           
        for (int j = low; j <= high - 1; j++) {
            if (vector[j] < pivot) {
                i++; 
                swap(vector[i], vector[j]);
            }
        }
        swap(vector[i + 1], vector[high]);
        pi=i+1;
        //QuickSort(vector), low, pi - 1);
        //QuickSort(vector,pi+1,high);
    }
}
void Sort::InsertSort(bool ascendant)
{
    if(ascendant==true)
    {
        for (int step = 1; step < size; step++) {
            int key = vector[step];
        int j = step - 1;
        while (key < vector[j] && j >= 0) {
            vector[j + 1] = vector[j];
            --j;
        }
        vector[j + 1] = key;
        }
    }
    else{
        for (int step = 1; step < size; step++) {
            int key = vector[step];
            int j = step - 1;
            while (key > vector[j] && j >= 0) {
            vector[j + 1] = vector[j];
            --j;
            }
        vector[j + 1] = key;
        }
    }
}
void Sort::Print()
{
    for(int i=0;i<size;i++)
        cout<<vector[i]<<" ";
    cout<<endl;
}
int Sort::GetElementsCount()
{
    return size;
}
int Sort::GetElementFromIndex(int index)
{
    return vector[index];
}
Sort::~Sort()
{
    delete[] vector;
}