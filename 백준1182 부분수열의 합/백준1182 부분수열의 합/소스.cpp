#include <iostream>
using namespace std;

int n, s;
int list[20];
int isused[20];
int result = 0;

void func(int k, int sum) {
	if (k == n) {
		if (sum == s)
			result++;
		return;
	}
	func(k + 1, sum);
	func(k + 1, sum + list[k]);

}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	func(0, 0);
	if (s == 0)
		result--;
	cout << result;
}