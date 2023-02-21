#include <iostream>
using namespace std;

bool isPrime(int n)
{

    for (int tr = 2; tr < n / 2; tr++)
        if ((n % 2) == 0)
            return 0;
    return true;
}

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;

    if (isPrime(n))
        cout << n << " is prime !";
    else 
        cout << n << " is NOT prime !";
    return 0;
}