#include<iostream>
using namespace std;
class Tester {
    int total=0, passed=0;
    public:
    // Takes a function; if this function returns false, or throws an exception, the test fails
    void add(bool (*test)(), const char* name)
    {
        try
        {
            if(test())
            {
                cout<<name<<" "<<"(OK)"<<endl;
                passed++;
            }
            else 
                cout<<name<<" "<<"(FAILED)"<<endl;
        }
        catch(const exception& e)
        {
            cout<<name<<" "<<"(FAILED)"<<endl;
        }
        total++;
    }
    void run()
    {
        int procentaj=passed*100/total;
        cout<<"Tests passed: "<<passed<<"/"<<total<<" ("<<procentaj<<"%)";
    }
};

