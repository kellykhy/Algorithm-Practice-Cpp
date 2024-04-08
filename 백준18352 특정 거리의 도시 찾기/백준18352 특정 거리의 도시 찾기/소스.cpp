#include <bits/stdc++.h>
using namespace std;

const int INF = 300001;
int n, m, k, x;
int d[300001];
vector<pair<int, int>> adj[300001];
int main() {
	int result = 0;
	cin >> n >> m >> k >> x; //N:도시 개수, M:도로 개수, K:거리 정보, X:출발 도시 번호

	fill(d, d + n + 1, INF);

	while (m--) {
		int r, c;
		cin >> r >> c;
		adj[r].push_back({ 1,c });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[x] = 0;
	pq.push({ d[x], x });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second])
		{
			if (d[nxt.second] > d[cur.second] + nxt.first) {
				d[nxt.second] = d[cur.second] + nxt.first;
				pq.push({ d[nxt.second], nxt.second });
			}
		}
	}

	int flag = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] == k) {
			flag++;
			cout << i << '\n';
		}
	if (!flag)
		cout << -1;

	return 0;
}