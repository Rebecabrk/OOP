#include <iostream>
#include "Contact.h"
#include "Type.h"
using namespace std;

void Prieten::SetType(Type type)
{
    this->type=type;
}
Type Prieten::GetType(Contact x)
{
    return x.type;
}

void Cunoscut::SetType(Type type)
{
    this->type=type;
}
Type Cunoscut::GetType(Contact x)
{
    return x.type;
}

void Coleg::SetType(Type type)
{
    this->type=type;
}
Type Coleg::GetType(Contact x)
{
    return x.type;
}

