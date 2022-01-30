#include<iostream>
#include<math.h>
#include<string>
#define FastIO std::ios_base::sync_with_stdio(false);std::cin.tie(NULL); std::cout.tie(NULL)

int main() {
    FastIO;
    
    try {
        int test;
        std::cin >> test;
        if(!std::cin || test < 1 || test > 20) {
	    throw -1;
	}
	
        for(int t = 0; t < test; t++) { 
           
	    std::string s;
	    std::cin >> s;

	    size_t n = s.length();
	    if(!std::cin || n < 1 || n > 250) {
                throw -1;
	    }

	    // check if string has all lowercase letters.
	    // also store the string in a character array (more efficient than using cpp strings with the transform() method to solve the question)

	    char* result = new char[n+1];
	    for(int i = 0; i < n; i++) {
	        if(!(s[i] >= 'a' && s[i] <= 'z')) {
		    throw -2;
		}
		result[i] = s[i];
	    }
	    result[n] = '\0';
		
	    int prev = 1, current = 2;
		
	    result[0] = result[0] - 32;
            std::cout << result[0];

	    if(n >= 2) {
                result[1] = result[1] - 32;
		std::cout << result[1];
	    }

            for(int i = 2; i < n; i++) {
                if(i == current) {
		    result[i] = result[i] - 32;
		        
		    // also find the next fibonacci index
		    int tmp = current;
		    current = current + prev;
		    prev = tmp;
		}

                std::cout << result[i];
	    }

            std::cout<< result[n] << "\n";
	    delete[] result;
	}
    } catch(...) {
        std::cout << "Invalid input. Please refer to the question description.\n";
        return 1;
    }

    return 0;
}
