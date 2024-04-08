#include <iostream>
#include <queue>
using namespace std;

int m, n;
int graph[1000][1000];
queue<pair<int, int>> q;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int target = 0;

int bfs() {
	int cnt = 0;
	int result = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (graph[nx][ny] != 0)
				continue;
			graph[nx][ny] = graph[x][y] + 1;
			result = graph[nx][ny];
			q.push(make_pair(nx, ny));
			cnt += 1;
		}
	}
	if (target == 0)
		return 0;
	else if (cnt == target)
		return result - 1;
	else
		return -1;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				target += 1;
			else if (graph[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	cout << (bfs());
	return 0;
}