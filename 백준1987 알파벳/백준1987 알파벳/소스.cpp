#include <iostream>
using namespace std;

int n, m;
char graph[20][20];

int visited[50];
int result;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int max_result = 0;

void back_tracking(int x, int y, int k) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[graph[nx][ny] - 'A'])
			continue;
		visited[graph[nx][ny] - 'A'] = 1;
		back_tracking(nx, ny, k+1);
		visited[graph[nx][ny] - 'A'] = 0;
	}
	max_result = max(max_result, k);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	}
	visited[graph[0][0] - 'A'] = 1;
	back_tracking(0,0,1);
	cout << max_result;
}