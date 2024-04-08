#include <iostream>
using namespace std;

int n, m;
char map[51][51];

int row_cnt, col_cnt;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			map[i][j] = row[j];
			if (row[j] == 'X')
				cnt++;
		}
		if (cnt == 0)
			row_cnt++;
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (map[j][i] == 'X')
				cnt++;
		if (cnt == 0)
			col_cnt++;
	}
	cout << max(col_cnt, row_cnt);
}