#include <bits/stdc++.h>
using namespace std;
int tc, n, arr[100][100];
int memo[100][100];

int getSum(int x, int y) {
    if(x == n - 1) return arr[x][y];
    int &ret = memo[x][y];
    if(ret != 0) return ret;
    ret += arr[x][y] + max(getSum(x + 1, y), getSum(x + 1, y + 1));
    return ret;
}
int main() {
    cin >> tc;
    while(tc--) {
        cin >> n;
        memset(memo, 0, sizeof(memo));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                cin >> arr[i][j];
            }
        }
        cout << getSum(0, 0) << "\n";
    }
}