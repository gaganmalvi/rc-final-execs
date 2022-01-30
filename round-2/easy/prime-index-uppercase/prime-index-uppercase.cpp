#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<bool> prime(100001, true);

void generate() {
    prime[0] = false;
    prime[1] = false;
    int n = 100000;
    for(int p = 2; p*p <= n; p++) {
        if(prime[p]) {
            for(int i = p*p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
}

void solve(string s, int n) {
    char c;
    for(int i = 0; i < n; i++) {
        if(prime[i]) {
            c = s[i] - 32;
            cout << c;
        } else {
            cout << s[i];
        }
    }

    cout << "\n";
}

int main() {
    FastIO;

    generate();

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 10) {
            throw -1;
        }

        int n;

        for(int T = 0; T < testcases; T++) {
            string s;
            cin >> s;
            n = s.length();
            if(!cin || n < 1 || n > 1000) {
                throw -2;
            }

            for(int i = 0; i < n; i++) {
                if(s[i] < 'a' || s[i] > 'z') {
                    throw -3;
                }
            }

            solve(s, n);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
