/*
    Author: DF
    Question: Pascals Triangle
*/

// clang-format off
#include <iostream>
#include <vector>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

void solveMyProblem(long long n) {
    vector <vector <int> > arr(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
                cout << 1 << " ";
            } else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                cout << arr[i][j] << " ";
            }
        }
        cout << el;
    }
}

int main() {
    FastIO;
    try {
        long long n;
        cin >> n;
        if (!cin || (n < 0 || n > 20))
            throw -1;
        solveMyProblem(n);
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}
