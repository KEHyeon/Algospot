#include <bits/stdc++.h>

using namespace std;
int n, m;
double memo[1000][1000];

double solve(int days, int dis) {
    if(days == m) return dis >= n;
    double &ret = memo[days][dis];
    if(ret != -1) return ret;
    ret = 0;
    ret += 0.75 * solve(days + 1, dis + 2);
    ret += 0.25 * solve(days + 1, dis + 1);
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) memo[i][j] = -1;
        }
        printf("%.8f\n", solve(0, 0));
    }
}