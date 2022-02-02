/*
    Author: DF
    Question: Dictionary Strings
*/

// clang-format off
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

void solveMyProblem(string s) {
    int p = 1, c = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        c = c + ((s[i] - 'A' + 1) * (p));
        p *= 26;
    }
    cout << c << el;
}

int main() {
    FastIO;
    try {
        string s;
        cin >> s;
        int n = (int)s.length();
        if (!cin || (n < 1 || n > 6))
            throw -1;
        for (char i : s)
            if (i > 'Z' || i < 'A')
                throw -1;
        solveMyProblem(s);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
