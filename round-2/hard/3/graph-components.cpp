#include<iostream>
#include<vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool isSymmetric(vector<vector<int> > matrix, int n) {
    return true;
}

void solve(vector<vector<int> > matrix, int n) {
    // perform bfs
    int result = 1;
    int start = 0;

    vector<bool> visited(n, false);
    vector<int> q;
    q.push_back(start);

    visited[start] = true;
    int vis;

    while(!q.empty()) {
        vis = q[0];
        q.erase(q.begin());

        for(int i = 0; i < n; i++) {
            if(matrix[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
        
        if(q.empty()) {        
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    q.push_back(i);
                    result++;
                    visited[i] = true;
                    break;
                }
            }
        }
        
    }

    cout << result << "\n";
}

int main() {
    FastIO;

    try {
        int testcases;
        cin >> testcases;
        if(!cin || testcases < 1 || testcases > 20) {
            throw -1;
        }

        int n;
        for(int T = 0; T < testcases; T++) {
            cin >> n;
            if(!cin || n < 1 || n > 100) {
                throw -2;
            }

            vector<vector<int> > matrix(n, vector<int>(n));
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cin >> matrix[i][j];
                    if(!cin || matrix[i][j] != 0 && matrix[i][j] != 1) {
                        throw -3;
                    }
                }
            }

            if(!isSymmetric(matrix, n)) {
                throw -4;
            }

            solve(matrix, n);
        }
    } catch(...) {
        cout << "Invalid Input. Please Check the Question Description.\n";
    }
    return 0;
}
