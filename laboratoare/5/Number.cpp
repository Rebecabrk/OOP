#include <iostream>
#include <cstring>
#include "Number.h"
using namespace std;

int charToInt(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char intToChar(int n)
{
	if (n >= 0 && n <= 9)
		return (char)(n + '0');
	else
		return (char)(n + 'A' - 10);
}

int toDeci(Number a, int base){
    int n10=0,pBase=1,l=strlen(a.num);
    for (int i = l - 1; i >= 0; i--)
	{
		n10 += charToInt(a.num[i]) * pBase;
		pBase *= base;
	}
	return n10;
}
char* fromDeci(int value, int base)
{
    char* s = new char[256];
	int nrc = 0;
	while (value)
	{
		s[nrc] = intToChar(value % base);
		value /= base;
		nrc++;
	}
	s[nrc] = '\0';

	char* s1 = new char[nrc + 1];
	for (int i = 0; i < nrc; i++)
	{
		s1[i] = s[nrc - i - 1];
	}
	s1[nrc] = '\0';
	delete[] s;
	return s1;
}

Number::Number(int n)
{
	strcpy(num, fromDeci(n, 10));
	base = 10;
}

Number::Number(const char* value, int base)
{
    num=new char[100];
    strcpy(num,value);
    this->base=base;
}
Number operator+(Number a, Number b)
{
    int x=toDeci(a,a.base);
    int y=toDeci(b,b.base);
    Number c("",10);
    if(a.base > b.base)
    {
        strcpy(c.num,fromDeci(x+y,a.base));
        c.base=a.base;
    }
    else 
    {
        strcpy(c.num,fromDeci(x+y,b.base));
        c.base=b.base;
    }
    return c;
}
Number operator-(Number a, Number b)
{
    int x=toDeci(a,a.base);
    int y=toDeci(b,b.base);
    Number c("",10);
    if(a.base > b.base)
    {
        strcpy(c.num,fromDeci(x-y,a.base));
        c.base=a.base;
    }
    else 
    {
        strcpy(c.num,fromDeci(x-y,b.base));
        c.base=b.base;
    }
    return c;
}
Number Number::operator = (Number a)
{
	base = a.base;
	strcpy(num, a.num);
	return(*this);
}
Number Number::operator= (int n)
{
	strcpy(num, fromDeci(n,base));
	return (*this);
}

Number Number::operator= (const char* val)
{
    Number c(val,base);
	int n = toDeci(c, 10);
	strcpy(num, fromDeci(n, base));
	return(*this);
}
Number Number::operator += (Number a)
{
	int x = toDeci(*this, base);
	int y = toDeci(a, a.base);
	strcpy(num,fromDeci(x+y, base));
	return (*this);
}
char Number:: operator[](int index)
{
    return num[index];
}
bool Number::operator<(Number a)
{
     int x=toDeci(*this,this->base);
     int y=toDeci(a,a.base);
    if(x<y)
        return true;
    else 
        return false;
}
bool Number::operator>(Number a)
{
    int x=toDeci(*this,this->base);
     int y=toDeci(a,a.base);
    if(x>y)
        return true;
    else 
        return false;
}
bool Number::operator<=(Number a)
{
    int x=toDeci(*this,this->base);
     int y=toDeci(a,a.base);
    if(x<=y)
        return true;
    else 
        return false;
}
bool Number::operator>=(Number a)
{
    int x=toDeci(*this,this->base);
     int y=toDeci(a,a.base);
    if(x>=y)
        return true;
    else 
        return false;
}
bool Number::operator==(Number a)
{
    if(strcmp(this->num,a.num)==0)
        return true;
    else 
        return false;
}
Number Number::operator-- ()
{
	strcpy(num, num + 1);
	return(*this);
}

Number Number::operator-- (int n)
{
	num[(strlen(num) - 1)] = '\0';
	return(*this);
}
void Number::SwitchBase(int newBase)
{
	int n = toDeci(*this,base);
	strcpy(num, fromDeci(n, newBase));
	base = newBase;
}
void Number::Print()
{
    cout<<"The number is: "<<this->num<<" and it is in base: "<<base<<"."<<endl;
}
int Number::GetDigitsCount()
{
    return strlen(num);
}
int Number::GetBase()
{
    return base;
}
Number::~Number()
{
    if(num)
    delete[] num;
}