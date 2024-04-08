#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, k; // k: 지울 숫자 개수
string input;
stack<int> S;

int main() {
	cin >> n >> k;
	int k_original = k;
	cin >> input;
	for (int i = 0; i < n; i++) {
		int num = input[i] - '0'; // 1 9 2 4
		while (!S.empty() && k > 0 && S.top() < num) {
			S.pop();
			k--;
		}
		S.push(num);
	}
	while (k > 0) {
		S.pop();
		k--;
	}
	vector<int> answer;
	while (!S.empty()) {
		answer.push_back(S.top());
		S.pop();
	}

	reverse(answer.begin(), answer.end()); // <algorithm> 헤더 필요
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
}