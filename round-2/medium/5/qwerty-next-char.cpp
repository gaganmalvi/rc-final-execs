#include<iostream>
#include<math.h>
#include<unordered_map>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(string s, int n, unordered_map<char, char> map) {
    for(int i = 0; i < n; i++) {
        cout << map[s[i]];
    }
    cout << "\n";
}

int main() {
    FastIO;

    unordered_map<char, char> map;
    char values[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                    'z', 'x', 'c', 'v', 'b', 'n', 'm' };
    
    for(int i = 0; i < 26; i++) {
        if(i != 25) {
            map[values[i]] = values[(i+1)%26];
        }
    }

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 50) {
            throw -1;
        }

        int n;
        string s;
        for(int T = 0; T < testcases; T++) {

            cin >> s;
            n = s.length();
            if(!cin || n < 1 || n > 100) {
                throw -2;
            }

            for(int i = 0; i < n; i++) {
                if(s[i] < 'a' || s[i] > 'z') {
                    throw -3;
                }
            }

            solve(s, n, map);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
