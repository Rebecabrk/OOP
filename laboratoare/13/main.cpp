#include <iostream>
#include "Contact.h"
#include "Type.h"
#include "Agenda.h" //de separat header de cpp
using namespace std;
//codul genereaza malloc error(SIGABRT), dar nu am reusit sa aflu unde exact e eroarea folosind lldb
int main()
{
    Agenda a;
    a.AddContact("Rebeca",Type::Prieten);
    a.AddContact("Hannah",Type::Cunoscut);
    a.AddContact("Fineas",Type::Coleg);
    a.Delete("Rebeca");
    if(a.SearchByName("Rebeca")==1) {cout<<"ceva e ciudat"; return 0;}
    if(a.SearchByName("Fineas")==1) {cout<<"ceva nu e ciudat"; }
    a.GetFriends();

    Agenda b;
    a.AddContact("Rebeca",Type::Prieten);
    a.AddContact("Hannah",Type::Prieten);
    a.AddContact("Fineas",Type::Prieten);
    return 0;
}