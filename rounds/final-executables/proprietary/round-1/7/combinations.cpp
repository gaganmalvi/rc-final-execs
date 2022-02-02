#include<iostream>

#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

long long factorial(int x) {
    long long result = 1;
    for(int i = 1; i <= x; i++) {
        result *= (long long) i;
    }
    return result;
}

int main() {
    FastIO;
    
    try {
        int test;
        std::cin >> test;
        if(!std::cin || test < 1 || test > 100) {
            throw -1;
        }

        for(int t = 0; t < test; t++) {
            int a,b;
            std::cin >> a >> b;
            
            if(!std::cin || a < 0 || a > 20 || b < 0 || b > 20 || b > a) {
                throw -2;
            }

            long long ans = factorial(a) / (factorial(a-b)*factorial(b));
            std::cout << ans << "\n";            

        }
    } catch(...) {
        std::cout << "Invalid input. Please refer to the question's description.\n";
    }

    return 0;
}
