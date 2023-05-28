#include <iostream>
#include <cstring>
#include "Agenda.h"
#include "Contact.h"
#include "Type.h"
using namespace std;


    Agenda::Agenda()
    {
        size=0;
        capacity=1;
        contacte= new Contact [capacity];
    }
    Agenda::~Agenda()
    {
        delete[] contacte;
    }
    bool Agenda::SearchByName(const char* name)
    {
        for(int i=0; i<size; i++)
        {
            if(strcmp(contacte[i].name,name)==0)
                return 1;
        }
        return 0;
    }
    void Agenda::Delete(const char* name)
    {
        for(int i=0; i<size; i++)
        {
            if(strcmp(contacte[i].name,name)==0)
                //delete
                {
                    for(int j=i; j<size-1;j++)
                        contacte[j]=contacte[j+1];
                    break;
                }
        }
    }
    void Agenda::AddContact(Contact a)
    {
        if(size==capacity)
        {
           
            capacity*=2;
            Contact* contacteNoi = new Contact [capacity];
            for(int i=0; i<size; i++)
                contacteNoi[i]=contacte[i];
            delete[] contacte;
            contacte=contacteNoi;
            delete[] contacteNoi;
        }
        contacte[size++]=a;
    }
    void Agenda::AddContact(const char* n, Type t)
    {
        if(size==capacity)
        {
           
            capacity*=2;
            Contact* contacteNoi = new Contact [capacity];
            for(int i=0; i<size; i++)
                contacteNoi[i]=contacte[i];
            delete[] contacte;
            contacte=contacteNoi;
            delete[] contacteNoi;
        }
        contacte[size].name=n;
        contacte[size++].type=t;
    }
    void Agenda::GetFriends()
    {
        bool exista=0;
        cout<<"Contacte prietene din agenda: "<<endl;
        for(int i=0;i<size;i++)
            {
                if(contacte[i].type==Type::Prieten)
                    {
                        exista=1;
                        cout<<"Prietenul "<<i<<" : "<<contacte[i].name<<endl;
                    }
            }
        if(exista==0) cout<<"Nu exista contacte prietene in agenda"<<endl;
    }
