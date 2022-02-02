/*
    Author: Jay Kaoshik
    Question: Count Rooms
*/

#include <iostream>
#include <vector>
using namespace std;

// clang-format off
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el '\n'
// clang-format on

long long n, m;
char plan[1001][1001];
bool visit[1001][1001];
vector<vector<long long> > r(4, vector<long long>(2, 0));

void dfs(long long i, long long j) {
    visit[i][j] = true;
    for (vector<long long> k : r) {
        long long x = i + k[0], y = j + k[1];
        if (x >= 0 && x < n && y >= 0 && y < m)
            if (!visit[x][y] && plan[x][y] == '.')
                dfs(x, y);
    }
}

void solve() {
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (!visit[i][j] && plan[i][j] == '.') {
                count += 1;
                dfs(i, j);
            }
        }
    }
    cout << count << el;
}

int main() {
    FastIO;
    try {
        for (int i = 0; i < 4; i++) {
            if (i == 0)
                r[i][0] = 0, r[i][1] = 1;
            else if (i == 1)
                r[i][0] = 1, r[i][1] = 0;
            else if (i == 2)
                r[i][0] = -1, r[i][1] = 0;
            else
                r[i][0] = 0, r[i][1] = -1;
        }
        cin >> n;
        if (!cin || (n < 1 || n > 1000))
            throw -1;
        cin >> m;
        if (!cin || (m < 1 || m > 1000))
            throw -1;
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> plan[i][j];
                if (!cin || (plan[i][j] != '.' && plan[i][j] != '#'))
                    throw -1;
            }
        }
        solve();
    } catch (...) { cout << "Invalid Input. Please Check The Question Description." << endl; }
    return 0;
}