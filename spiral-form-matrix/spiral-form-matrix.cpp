#include<iostream>
#include<vector>

#define FastIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)

void solve(std::vector<std::vector<int>> matrix, int n, int m) {

    int i = 0, j = 0;
    int xLimit = n-1, yLimit = m-1;
    int xLower = 0, yLower = 1;
    int incrementingI = 0; // start by incrementing j first
                           // 0 = increment j
                           // 1 = increment i
                           // 2 = decrement j
                           // 3 = decrement i

    int visited = 0;
    int total = n*m;
    
    while(visited < total) {
        std::cout << matrix[i][j] << " ";
        visited++;

        if(incrementingI == 0) {
            if(j < yLimit) {
                j++;
            } else {
                incrementingI = 1;
                yLimit--;
                i++;
            }
        } else if(incrementingI == 1) {
            if(i < xLimit) {
                i++;
            } else {
                incrementingI = 2;
                xLimit--;
                j--;
            }
        } else if(incrementingI == 2) {
            if(j > xLower) {
                j--;
            } else {
                incrementingI = 3;
                xLower++;
                i--;
            }
        } else if(incrementingI == 3) {
            if(i > yLower) {
                i--;
            } else {
                incrementingI = 0;
                yLower++;
                j++;
            }
        }
    }
    std::cout << "\n";
}

int main() {
    FastIO;

    try {
        int test;
        std::cin >> test;
        if(!std::cin || test < 1 || test > 10) {
            throw -1;
        }

        for(int t = 0; t < test; t++) {
            int n,m;
            std::cin >> n >> m;
            std::vector<std::vector<int>> matrix(n);

            if(!std::cin || n < 1 || n > 25 || m < 1 || m > 25) {
                throw -2;
            }

            for(int i = 0; i < n; i++) {
                std::vector<int> row(m);
                for(int j = 0; j < m; j++) {
                    std::cin >> row[j];
                    if(!std::cin || row[j] < 1 || row[j] > 1000) {
                        throw -3;
                    }
                }
                matrix[i] = row;
            }
            solve(matrix, n, m);
        }

    } catch(...) {
        std::cout << "Invalid input. Please check the question description.\n";
        return 1;
    }
    return 0;
}


