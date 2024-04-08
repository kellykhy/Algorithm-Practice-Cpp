#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[9][9];
vector<pair<int,int>> ary;
int flag = 0;

void sudoku(int k) {
	if (k == ary.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << graph[i][j] << ' ';
			cout << '\n';
		}
		flag = 1;
		return;
	}
	int x = ary[k].first;
	int y = ary[k].second;

	int visited1[10] = {0,};
	int visited2[10] = {0,};
	int visited3[10] = {0,};

	for (int n = 1; n <= 9; n++) {
		// 가로, 세로
		for (int i = 0; i < 9; i++) {
			visited1[graph[x][i]] = 1;
			visited2[graph[i][y]] = 1;
		}

		// 정사각형
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				int row = 3 * (x / 3) + i;
				int col = 3 * (y / 3) + j;
				visited3[graph[row][col]] = 1;
			}

		if (!visited1[n] && !visited2[n] && !visited3[n]) {
			graph[x][y] = n;
			sudoku(k + 1);
			if (flag == 1)
				return;
			graph[x][y] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0)
				ary.push_back(make_pair(i, j));
		}
	sudoku(0); // k : 채워넣은 빈칸의 개수
	return 0;
}