#include <bits/stdc++.h>
using namespace std;
int n, m;
bool relation[10][10];
bool isUsed[10];
int count() {
	int first = -1;
	for(int i = 0; i < n; i++) {
		if(!isUsed[i]) {
			first = i;
			break;
		}
	}
	if(first == -1) return 1;
	int ret = 0;
	for(int i = first + 1; i < n; i++) {
		if(!isUsed[i] && relation[i][first]) {
			isUsed[i] = isUsed[first] = 1;
			ret += count();
			isUsed[i] = isUsed[first] = 0;
		}
	}
	return ret;
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			relation[a][b] = 1; 
			relation[b][a] = 1; 
		}
		cout << count() << "\n";
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				relation[i][j] = 0;
				relation[j][i] = 0;
			}
		}
	}
}
