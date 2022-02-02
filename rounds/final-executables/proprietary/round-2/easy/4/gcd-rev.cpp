/*
    Author: DF
    Question: Reverse GCD
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

long long GCD(long long a, long long b) {
    if (b > a)
        return GCD(b, a);
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void solveMyProblem(int n) {
    long long rev = 0, copy = n;
    while (copy > 0)
        rev = (rev * 10) + (copy % 10), copy /= 10;
    cout << GCD(n, rev) << el;
}

int main() {
    FastIO;
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 1 || n > 1000000000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
