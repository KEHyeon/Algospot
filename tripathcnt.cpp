#include <bits/stdc++.h>
using namespace std;
int n, tri[100][100], Max[100][100], Path[100][100];
int getMax(int x, int y) {
    if(x == n - 1) return tri[x][y];
    int &ret = Max[x][y];
    if(ret != 0) return ret;
    ret = tri[x][y] + max(getMax(x + 1, y), getMax(x + 1, y + 1));
    return ret;
}
int getCnt(int x, int y) {
    if(x == n - 1) return 1;
    int &ret = Path[x][y];
    if(ret != 0) return ret;
    if(getMax(x + 1, y) > getMax(x + 1, y + 1)) {
        ret = getCnt(x + 1, y);
    }
    else if(getMax(x + 1, y) < getMax(x + 1, y + 1)) {
        ret = getCnt(x + 1, y + 1);
    }
    else ret = getCnt(x + 1, y + 1) + getCnt(x + 1, y);
    return ret;
}
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n;
        memset(Max, 0, sizeof(Max));
        memset(Path, 0, sizeof(Path));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) cin >> tri[i][j];
        }
        cout << getCnt(0, 0) << "\n";
    }
}