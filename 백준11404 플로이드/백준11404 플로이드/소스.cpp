#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, m;
int map[101][101];
int main() {
	for (int i = 0; i < 101; i++)
		fill(map[i], map[i] + 101, INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		map[x-1][y-1] = min(d, map[x-1][y-1]);
	}

	for (int i = 0; i < n; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				map[r][c] = min(map[r][c], map[r][i] + map[i][c]);
			}
		}
	}

	for (int i = 0; i < n; i++) map[i][i] = 0;

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (map[r][c] != INF)
				cout << map[r][c] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}