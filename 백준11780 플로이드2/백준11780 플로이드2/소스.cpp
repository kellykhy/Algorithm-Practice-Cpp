#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, m;
int map[1001][101];
int nxt[101][101];

int main() {
	for (int i = 1; i <= 100; i++)
		fill(map[i], map[i] + 101, INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		map[x][y] = min(d, map[x][y]);
		nxt[x][y] = y;
	}

	for (int i = 1; i <= n; i++) map[i][i] = 0;

	for (int i = 1; i <= n; i++) 
		for (int r = 1; r <= n; r++) 
			for (int c = 1; c <= n; c++) {
				if (map[r][c] > map[r][i] + map[i][c]) {
					map[r][c] = map[r][i] + map[i][c];
					nxt[r][c] = nxt[r][i];
				}
			}


	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			if (map[r][c] != INF)
				cout << map[r][c] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}

	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= n; c++) {
			if (nxt[r][c] == 0)
				cout << 0 << '\n';
			else {
				int cnt = 1;
				int start = r;
				int end = c;
				int route[101] = { start,};
				while (nxt[start][end] != end) {
					route[cnt++] = nxt[start][end];
					start = nxt[start][end];
				}
				route[cnt++] = end;
				cout << cnt << ' ';
				for (int i = 0; i < cnt; i++)
					cout << route[i] << ' ';
				cout << '\n';
			}
		}

	return 0;
}