#include<iostream>

#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

void solve(long long a, long long b, long long c, long long d, long long n) {
    int i = 1;
    for(i = 1; i < n; i++) {
        if(i%2 == 1) {
            // AP
            std::cout << a << " ";
            a += c;
        } else {
            // GP
            std::cout << b << " ";
            b *= d;
        }
    }
    if(i%2 == 0) {
        std::cout << b << "\n";
    } else {
        std::cout << a << "\n";
    }
}

int main() {
    FastIO;

    try {
        int test;
        std::cin >> test;
        if(!std::cin || test < 1 || test > 150) {
            throw -1;
        }

        for(int t = 0; t < test; t++) {
            long long a,b,c,d,n;
            std::cin >> a >> b >> c >> d >> n;
            
            if(!std::cin || a < 1 || a > 25 || b < 1 || b > 25 || c < 1 || c > 25 || d < 1 || d > 25 || n < 1 || n > 25 ) {
                throw -2;
            }
            
            solve(a,b,c,d,n);
        }

    } catch(...) {
        std::cout << "Invalid input. Please check the question description.\n";
        return 1;
    }
    
    return 0;
}

