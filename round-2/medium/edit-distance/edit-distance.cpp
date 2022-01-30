#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int getMin(int a, int b, int c) {
    int res = a;
    if(b < res) {
        res = b;
    }
    if(c < res) {
        res = c;
    }
    return res;
}

void solve(string a, string b, int n1, int n2) {
    vector<vector<int> > dp(2, vector<int>(n1+1));

    for(int i = 0; i <= n1; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n2; i++) {
        for(int j = 0; j <= n1; j++) {
            if(j == 0) {
                dp[i % 2][j] = i;
            } else if(a[j-1] == b[i-1]) {
                dp[i % 2][j] = dp[(i-1) % 2][j-1];
            } else {
                dp[i % 2][j] = 1 + getMin(
                    dp[(i-1)%2][j],
                    dp[i % 2][j - 1],
                    dp[(i-1) % 2][j-1]
                );
            }
        }
    }
    
    cout << dp[n2 % 2][n1] << "\n";

}

int main() {
    FastIO;

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 50) {
            throw -1;
        }

        int n1, n2;
        string a,b;

        for(int T = 0; T < testcases; T++) {

            cin >> a >> b;
            n1 = a.length();
            n2 = b.length();
            if(!cin || n1 < 1 || n1 > 100 || n2 < 1 || n2 > 100) {
                throw -2;
            }

            int i1 = 0, i2 = 0;
            while(i1 < n1 || i2 < n2) {
                if(i1 < n1) {
                    
                    if(a[i1] >= 'a' && a[i1] <= 'z') {
                        i1++;
                    } else {
                        throw -3;
                    }
                }

                if(i2 < n2) {
                    if(b[i2] >= 'a' && b[i2] <= 'z') {
                        i2++;
                    } else {
                        throw -4;
                    }
                }
            }

            solve(a,b,n1,n2);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
