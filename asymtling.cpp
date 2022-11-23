#include <bits/stdc++.h>

using namespace std;

int n, memo[101];
int solve(int n) {
    if(n == 1 || n == 0) return 1;
    int &ret = memo[n];
    if(ret != 0) return ret;
    ret += solve(n - 1);
    ret += solve(n - 2);
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        cout << solve(n) - 2 - (n % 2 == 0) << '\n';
    }
}