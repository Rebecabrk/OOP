#include <iostream>
using namespace std;

class Data
{
    const int x=5;
    const float y=10.5f;
    const bool t=true;
    public:
    Data():x(10){ cout<<x<<" "<<y<<" "<<t;}
};
int main()
{
    Data d;
}