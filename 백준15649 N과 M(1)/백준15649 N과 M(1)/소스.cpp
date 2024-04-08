#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visited[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			arr[k] = i;
			visited[i] = 1;
			func(k + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	func(0);
}
