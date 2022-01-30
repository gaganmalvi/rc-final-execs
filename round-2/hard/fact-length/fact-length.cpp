/*
    Author: DF
    Question: Min Num Factorial Length
*/

// clang-format off
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

const double e = 2.7182818284;
const double pi = 3.1415926535;

int findDigits(int n) {
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    double x = ((n * log10(n / e) + log10(2 * pi * n) / 2.0));
    return (int)floor(x) + 1;
}

void solveMyProblem(int n) {
    int low = 0, hi = 2 * n;
    if (findDigits(low) == n) {
        cout << low << el;
        return;
    }
    while (low <= hi) {
        int mid = low + (hi - low) / 2;
        if (findDigits(mid) >= n && findDigits(mid - 1) < n) {
            cout << mid << el;
            return;
        } else if (findDigits(mid) < n)
            low = mid + 1;
        else
            hi = mid - 1;
    }
    cout << low << el;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    FastIO;
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 1 || n > 100000))
            throw -1;
        solveMyProblem(n);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
