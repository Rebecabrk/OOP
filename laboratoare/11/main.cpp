#include <iostream>
#include "exceptions.cpp"
using namespace std;

int main()
{
    Array<int> a;
    a+=5;
    a+=6;
    a+=7;
    a+=8;
    a+=9;
    a.Print();
    a.Insert(5,10);
    a.Print();
    Array<int> b;
    b+=3;
    b.Print();
    a.Insert(6,b);
    a.Print();
    a.Delete(2);
    a.Print();
    if(a = b)
    {
        cout<<"sunt egale"<<endl;
    }
    else cout<<"nu sunt egale"<<endl;
    return 0;
}