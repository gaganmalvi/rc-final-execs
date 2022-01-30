#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int k = 2; k * k <= n; k++)
        if (n % k == 0)
            return false;
    return true;
}

int sumOfPrimes(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (isPrime(i))
            sum += i;
    return sum;
}

int main()
{
    try
    {
        int k;
        cin >> k;
        if (k > 1000 || k <= 0)
        {
            throw -2;
        }
        while (k--)
        {
            int n;
            cin >> n;
            if (!cin || n < 0 || n > 10000)
            {
                throw -1;
            }
            cout << sumOfPrimes(n) << "\n";
        }
    }

    catch (...)
    {
        cout << "Invalid Input. Please Check The Question Description." << endl;
        return 0;
    }
}
