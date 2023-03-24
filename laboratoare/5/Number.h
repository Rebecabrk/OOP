class Number
{
    char* num;
    int base;
public:
   Number (int x);
   Number(const char * value, int base); // where base is between 2 and 16
   ~Number();
   friend Number operator+(Number a, Number b);
   friend Number operator-(Number a, Number b);
   Number operator= (Number a);
   Number operator= (int a);
   Number operator= (const char* value);
   Number operator+= (Number a);
   char operator[](int index);//de la 1 la n
   bool operator<(Number a);
   bool operator>(Number a);
   bool operator<=(Number a);
   bool operator>=(Number a);
   bool operator==(Number a);
   Number operator--();
   Number operator--(int x);
   friend int toDeci(Number a, int base);
   friend char* fromDeci(int value, int base);
   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};