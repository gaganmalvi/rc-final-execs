/*
    Author: DF
    Question: Take XOR of all Numbers
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

void solveMyProblem(long long n, vector<long long> &arr) {
    long long k = arr[0];
    for (long long i = 1; i < n; i++) {
        k = k ^ arr[i];
    }
    cout << k << el;
}

int main() {
    FastIO;
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 3 || n > 100000) || (n % 2 == 0))
            throw -1;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            if ((!cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(n, arr);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}