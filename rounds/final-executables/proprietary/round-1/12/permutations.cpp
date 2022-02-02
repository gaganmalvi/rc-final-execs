// clang-format off
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el   '\n'
// clang-format on

long long fact(int n) {
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

long long perm(string str) {
    size_t length = str.length();
    vector <int> freq(26, 0);
    for (int i = 0; i < length; i++) {
        freq[str[i] - 'a']++;
    }
    long long f = 1;
    for (int i = 0; i < 26; i++)
        f *= fact(freq[i]);
    return fact((long long)length) / f;
}

int32_t main() {
    FastIO;
    try {
    	int test;
    	cin >> test;
    	if(!cin || test < 1 || test > 50000) {
	    throw -1;
	}
    	
    	for(int t = 0; t < test; t++) {
            string s;
            cin >> s;
            int n = s.length();
            if (!cin || n < 1 || n > 20)
                throw -1;
            
            // check if all letters are lowercase
            for(int i = 0; i < n; i++) {
                if(s[i] < 'a' || s[i] > 'z') {
                    throw -2;
                }
            }
            long long res = perm(s);
            cout << res << "\n";
        }
    } catch (...) {
        cout << "Invalid input. Please refer to the question description." << endl;
        return 0;
    }
}
