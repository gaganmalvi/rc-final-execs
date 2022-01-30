#include<iostream>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(long long n) {
    int k = 2*n;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {
            cout << j << " ";
        }

        for(int j = i-1; j >= 0; j--) {
            cout << j << " ";
        }

        cout << "\n";
        k -= 2;
    }

    k = 2;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < k; j++) {
            cout << " ";
        }

        for(int j = 0; j <= i; j++) {
            cout << j << " ";
        }

        for(int j = i-1; j >= 0; j--) {
            cout << j << " ";
        }

        cout << "\n";
        k += 2;
    }

    cout << "\n";
}

int main() {
    FastIO;

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 5) {
            throw -1;
        }

        for(int T = 0; T < testcases; T++) {
            int n;
            cin >> n;
            if(!cin || n < 1 || n > 15) {
                throw -2;
            }

            solve(n);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
