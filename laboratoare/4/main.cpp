#include<iostream>
#include "Sort.h"
#include<ctime>
#include <initializer_list>
using namespace std;

int main()
{
    //pentru primul constructor   
    /*
    Sort s(5,10,50);
    s.Print();
    s.BubbleSort(true);
    s.Print();
    s.BubbleSort(false);
    s.Print();
    cout<<s.GetElementsCount()<<endl;
    cout<<s.GetElementFromIndex(2)<<endl;
    */
    //pentru al treilea constructor
    /*
    int v[10],e=0;
    for(int i=45;i>35;i--)
        v[e++]=i;
    Sort s(v,10);
    s.Print();
    s.BubbleSort(false);
    s.Print();
    cout<<s.GetElementsCount()<<endl;
    cout<<s.GetElementFromIndex(3)<<endl;
    */
    //pentru al patrulea constructor
    /*
    Sort s(5,10,20,30,27,16);
    s.Print();
    s.BubbleSort(true);
    s.Print();
    s.BubbleSort(false);
    s.Print();
    cout<<s.GetElementsCount()<<endl;
    cout<<s.GetElementFromIndex(3)<<endl;
    */
    //pentru al cincilea constructor
    char sorting[50];
    strcpy(sorting,"10,40,100,5,70");
    Sort s(sorting);
    s.Print();
    //s.BubbleSort();
    //s.Print();
    //s.BubbleSort(true);
    //s.Print();
    s.InsertSort(false);
    s.Print();
    cout<<s.GetElementsCount()<<endl;
    cout<<s.GetElementFromIndex(3)<<endl;
    return 0;
}