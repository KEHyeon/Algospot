#include <bits/stdc++.h>
using namespace std;
int tc, memo[100000];
string pi;
int check(int start, int len) {
    string str = pi.substr(start, len + 1);
    bool oneflag = 1;
    char first = str[0];
    for(int i = 1; i <= len; i++) {
        if(str[i] != first) {
            oneflag = 0;
            break;
        }
    }
    if(oneflag) {
        return 1;
    }
    bool twoflag = 1;
    for(int i = 0; i <= len - 1; i++) {
        if(str[i] - '0' + 1 != str[i + 1] - '0') {
            twoflag = 0;
            break;
        }
    }
    if(twoflag) return 2;
    twoflag = 1;
    for(int i = 0; i <= len - 1; i++) {
        if(str[i] - '0' - 1 != str[i + 1] - '0') {
            twoflag = 0;
            break;
        }
    }
    if(twoflag) return 2;
    bool fourflag = 1;
    first = str[0];
    char second = str[1];
    for(int i = 2; i <= len; i++) {
        if(i % 2 == 0) {
            if(str[i] != first) {
                fourflag = 0;
                break;
            }
        }
        else {
            if(str[i] != second) {
                fourflag = 0;
                break;
            }
        }
    }
    if(fourflag) return 4;

    bool fiveflag = 1;
    int dis = (str[1] - '0') - (str[0] - '0');
    for(int i = 2; i <= len; i++) {
        if(str[i - 1] - '0' + dis != str[i] - '0') {
            fiveflag = 0;
            break;
        }
    }
    if(fiveflag) return 5;
    return 10;
}
int memorize(int start) {
    if(start == pi.size()) return 0;
    int &ret = memo[start];
    if(ret != 0) return ret;
    ret = 123456789;
    for(int i = 2; i <= 4; i++) {
        if(start + i < pi.size()) {
            ret = min(ret, check(start, i) + memorize(start + i + 1));
        }
    }
    return ret;
}
int main() {
    cin >> tc;
    while(tc--) {
        cin >> pi;
        memset(memo, 0, sizeof(memo));
        cout << memorize(0) << "\n";
    }
}