/*
    Author: DF
    Question: Set Bits
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

void solveMyProblem(vector<long long> &arr) {
    for (long long &i : arr) {
        int ans = 0;
        while (i > 0) {
            if (i & 1)
                ans++;
            i /= 2;
        }
        cout << ans << el;
    }
}

int main() {
    FastIO;
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 0 || n > 100000))
            throw -1;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            if ((!cin && i <= n - 1) || (arr[i] < 0 || arr[i] > 1000000000))
                throw -1;
        }
        solveMyProblem(arr);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
