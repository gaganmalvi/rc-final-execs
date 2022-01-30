#include <iostream>
#include <algorithm>
#include <string>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define el '\n'
using namespace std;
typedef long long int ll;

string addBinary(string A, string B)
{
    if (A.length() > B.length())

        return addBinary(B, A);

    int diff = B.length() - A.length();

    string padding;

    for (int i = 0; i < diff; i++)
        padding.push_back('0');
    A = padding + A;
    string res;
    char carry = '0';

    for (int i = A.length() - 1; i >= 0; i--)
    {
        if (A[i] == '1' && B[i] == '1')
        {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        else if (A[i] == '0' && B[i] == '0')
        {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        else if (A[i] != B[i])
        {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
    if (carry == '1')
        res.push_back(carry);
    reverse(res.begin(), res.end());
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}

int main()
{
    try
    {
        ll testcases;
        cin >> testcases;
        if (testcases <= 0 || testcases > 500)
        {
            throw -1;
        }
        while (testcases--)
        {
            ll n;
            cin >> n;
            if (cin.fail() || n > 100000000000)
            {
                throw -2;
            }
            string s = "";
            while (n > 0)
            {
                s += ((n % 2 == 0) ? "0" : "1");
                n = n >> 1;
            }
            reverse(s.begin(), s.end());
            string revNum = s;
            for (auto &i : revNum)
                i = (i == '1') ? '0' : '1';
            string ans = addBinary(revNum, "1");
            cout << stoi(ans, 0, 2) << el;
        }
    }
    catch (...)
    {
        cout << "Invalid Input. Please Check The Question Description." << endl;
    }
}
