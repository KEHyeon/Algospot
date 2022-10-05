#include <bits/stdc++.h>
using namespace std;
int clocks[16];
const int INF = 9999;
char linked[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"...x.....x....xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};
bool is12() {
	for(int i = 0; i < 16; i++) {
		if(clocks[i] != 12) return false;
	}
	return true;
}
void click(int button) {
	for(int i = 0; i < 16; i++) {
		if(linked[button][i] == 'x') {
			clocks[i] += 3;
			if(clocks[i] == 15) clocks[i] = 3;
		}
	}
}
int solve(int button) {
	if(button == 10) {
		return is12() ? 0 : INF;
	}
	int ret = INF;
	for(int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(button + 1));
		click(button);
	}
	return ret;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		for(int i = 0; i < 16; i++) cin >> clocks[i];
		int ans = solve(0);
		cout << ((ans==INF)?-1:ans) << '\n';
	}
}
