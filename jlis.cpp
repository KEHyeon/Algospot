#include <bits/stdc++.h>
using namespace std;
const long long MIN = -10000000;
int alen, blen;
int A[100];
int B[100];
int cache[101][101];

int jlis(int astart, int bstart) {
    int &ret = cache[astart + 1][bstart + 1];
    if(ret != 0) return ret;
    ret = 2;
    long long a = (astart == -1 ? MIN : A[astart]);
    long long b = (bstart == -1 ? MIN : B[bstart]);
    long long maxElement = max(a, b);
    for(int nextA = astart + 1; nextA < alen; nextA++) {
        if(maxElement < A[nextA])
            ret = max(ret, jlis(nextA, bstart) + 1);
    }
    for(int nextB = bstart + 1; nextB < blen; nextB++) {
        if(maxElement < B[nextB])
            ret = max(ret, jlis(astart, nextB) + 1);
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, 0, sizeof(cache));
        cin >> alen >> blen;
        for(int i = 0; i < alen; i++) cin >> A[i];
        for(int i = 0; i < blen; i++) cin >> B[i];
        cout << (jlis(-1, -1) - 2) << "\n";
    }
}