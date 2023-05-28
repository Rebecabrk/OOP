#include <iostream>
#include "Contact.h"
#include "Type.h"
using namespace std;

class Agenda 
{ 
    Contact* contacte;
    int size,capacity;
    public:
    Agenda();
    ~Agenda();
    bool SearchByName(const char* name);
    void Delete(const char* name);
    void AddContact(Contact a);
    void AddContact(const char* n, Type t);
    void GetFriends();
};