#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int getMax(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

void solve(string a, string b, int n1, int n2) {
    vector<vector<int> > dp(n1+1, vector<int>(n2+1));
    
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = getMax(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n1][n2] << "\n";
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
