#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el   '\n'

int32_t main() {
    FastIO;
    istream &in(cin);
    ostream &out(cout);
    try {
        string x, y;
        cin >> x;
        if (!cin || x.length() < 1 || x.length() > 2*pow(10,5))
            throw -1;
        y = x;
        reverse(y.begin(), y.end());
        if (y == x)
            cout << "YES" << el;
        else
            cout << "NO" << el;    
    }
    catch (...) {
        cout << "Invalid input. Please refer to the question description." << endl;
        return 0;
    }
}