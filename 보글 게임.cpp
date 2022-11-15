#include <bits/stdc++.h>
using namespace std;
char arr[6][6];
int dx[8] = {0, 1, -1, 0, 1, 1,-1,-1};
int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
bool hasWord(int x, int y, const string& str) {
	if(x < 0 || x >= 5 || y < 0 || y >= 5) return 0;
	if(str[0] != arr[x][y]) return 0;
	if(str.size() == 1) return 1;
	for(int i = 0; i < 8; i++) {
		int fx = x + dx[i];
		int fy = y + dy[i];
		if(hasWord(fx, fy, str.substr(1))) return 1;
	}
	return 0;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				cin >> arr[i][j];
			}
		}
		int m; cin >> m;
		while(m--) {
			string str; cin >> str;
			cout << str << " ";
			int flag = 1;
			for(int i = 0; i < 5; i++) {
				for(int j = 0; j < 5; j++) {
					if(hasWord(i,j,str)) {
						cout << "YES\n";
						flag = 0;
						i = 5; break;
					}
				}
			}
			if(flag) cout << "NO\n"; 
		}
	}
}
