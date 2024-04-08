#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int num_list[1000001]; // 입력 받은 값 저장
int result[1000001];
stack<int> S;

int main() {
	fill(result, result + 1000001, -1);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num_list[i];
		while (S.size() != 0 && num_list[S.top()] < num_list[i]) {
			result[S.top()] = num_list[i];
			S.pop();
		}
		S.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << ' ';
}