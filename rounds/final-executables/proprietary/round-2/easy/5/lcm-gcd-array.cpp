#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

long long getGcd(long long x, long long y) {
    if(y == 0) {
        return x;
    }
    return getGcd(y, x%y);
}

void solve(vector<long long> vi, long long n) {
    // O(nlogn approach)
    long long lcm, gcd;

    lcm = vi[0];
    gcd = vi[0];

    for(int i = 1; i < n; i++) {
        gcd = getGcd(vi[i], gcd);
        lcm = (vi[i] * lcm) / getGcd(vi[i], lcm);
    }
    cout << lcm - gcd << "\n";
}

int main() {
    FastIO;

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 100) {
            throw -1;
        }

        for(int T = 0; T < testcases; T++) {
            int n;
            cin >> n;
            if(!cin || n < 1 || n > 5) {
                throw -2;
            }

            
            set<long long> s;

            for(int i = 0; i < n; i++) {
                long long tmp;
                cin >> tmp;
                s.insert(tmp);
                if(!cin || tmp < 1 || tmp > 10000) {
                    throw -3;
                }
            }

            vector<long long> vi;
            for(auto x : s) {
                vi.push_back(x);
            }

            n = vi.size();

            solve(vi, n);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
