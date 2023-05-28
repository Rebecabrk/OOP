#include <iostream>
#include "Type.h"
#pragma once
using namespace std;

class Contact
{   
    public:
    const char* name;
    Type type;
};

class Prieten : public Contact
{
    const char* birthDate;
    const char* telephone;
    const char* adress;
    public:
    void SetType(Type type);
    Type GetType(Contact);
};

class Cunoscut : public Contact
{
    const char* telephone;
    public:
    int ConvertTelephone(const char* );
    void SetType(Type type);
    Type GetType(Contact);
};

class Coleg : public Contact
{
    const char* telephone;
    const char* adress;
    const char* agency;
    public:
    int ConvertTelephone(const char* );
    void SetType(Type type);
    Type GetType(Contact);
};