#include "Number.h"
#include <iostream>
using namespace std;

int main()
{
   Number n1("10110010",2);
   Number n2("734",8);
   Number n3("FF",16);
   
   n1.SwitchBase(10);
   (n1+n2).Print();
   n1=n2+n3;
   n1.Print();
   if (n1 == n2) cout<<"n1 is equal to n2";
   else 
   cout <<"n1 is not equal to n2";
   return 0;
}