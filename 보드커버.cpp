#include <bits/stdc++.h>
using namespace std;
int board[21][21];
int h, w;
int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {1, -1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {0, 1}, {1, 0}},
	{{0, 0}, {0, 1}, {1, 1}}
};
bool set_(int x, int y, int type, int delta) {
	bool ok = true;
 	for(int i = 0; i < 3; i++) {
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		if(nx < 0 || nx >= h || ny < 0 || ny >= w) ok = false;
		if((board[nx][ny] += delta) > 1) ok =  false;
	}
	return true;
}
int cover() {
	int ret = 0;
	int firstX = -1;
	int firstY = -1;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(board[i][j] == 0) {
				firstX = i;
				firstY = j;
				i = h;
				break;
			}
		}
	}
	if(firstX == -1) return 1;
	for(int i = 0; i < 4; i++) {
		if(set_(firstX, firstY, i, 1)) {
			ret += cover();
		}
		set_(firstX, firstY, i, -1);
	}
	return ret;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		cin >> h >> w;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				char x; cin >> x;
				if(x == '#') board[i][j] = 1;
				else board[i][j] = 0;
			}
		}
		cout << cover() << "\n";
	}
}
