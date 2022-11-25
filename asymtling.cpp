#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
int n, memo[101];
int tiling(int x) {
    if(x == 1 || x == 0) return 1;
    int &ret = memo[x];
    if(ret != 0) return ret;
    ret = (tiling(x - 1) + tiling(x - 2)) % MOD;
    return ret;
}
int asymtiling(int x) {
    if(x % 2 == 1) return (tiling(x) - tiling(x / 2) + MOD) % MOD;
    int ret = tiling(x);
    ret = (ret - tiling(x / 2) + MOD) % MOD;
    ret = (ret - tiling(x/2-1) + MOD) % MOD;
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        cout << asymtiling(n) << '\n';
    }
}