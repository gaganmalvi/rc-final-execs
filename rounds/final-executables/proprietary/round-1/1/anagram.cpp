#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool checkAnagram(string a, string b)
{
    size_t len1 = a.length();
    size_t len2 = b.length();
    if (len1 != len2)
    {
        return false;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
        mp[b[i]]--;
    }
    for (auto it : mp)
    {
        if (it.second)
            return false;
    }
    return true;
}
int main()
{
    try
    {
        string a, b;
        cin >> a;
        cin >> b;
        if (cin.fail() || a.length() > 256 || b.length() > 256)
        {
            throw -1;
        }
        if (checkAnagram(a, b))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        return 0;
    }
    catch (...)
    {
        cout << "Invalid Input. Please Check The Question Description." << endl;
        return 0;
    }
}
