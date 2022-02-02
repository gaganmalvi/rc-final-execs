#include <iostream>
typedef long long int ll;
#include <cmath>
#define max 1000000000000000
using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll commDiv(ll a, ll b)
{
    ll n = gcd(a, b);
    ll result = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                result += 1;
            }
            else
            {
                result += 2;
            }
        }
    }
    return result;
}

int main()
{
    try
    {
        ll a, b;
        cin >> a >> b;
        if (a <= 0 || b <= 0 || a > max || b > max || cin.fail())
        {
            throw -1;
        }
        cout << commDiv(a, b) << endl;
    }
    catch (...)
    {
        cout << "Invalid Input. Please Check The Question Description." << endl;
        return 0;
    }
}