#include <iostream>
#include <math.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el   '\n'

int32_t main() {
    FastIO;
    istream &in(cin);
    ostream &out(cout);
    try {
        int x, y;
        cin >> x >> y;
        if (!cin || x < 0 || x > pow(10, 6) || y < 0 || y > pow(10, 6))
            throw -1;
        cout <<  (int)(x ^ y) << el;
    }
    catch (...) {
        cout << "Invalid input. Please refer to the question description." << endl;
        return 0;
    }
}