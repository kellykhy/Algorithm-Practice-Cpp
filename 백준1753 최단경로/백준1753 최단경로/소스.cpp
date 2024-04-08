#include <bits/stdc++.h>
using namespace std;

#define distance first
#define vertex second

int v, e, st;
const int INF = 1e9 + 10;
vector<pair<int, int>> adj[20001];
int d[20001];

int main() {
	cin >> v >> e;
	fill(d, d + v + 1, INF);
	cin >> st;

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w,v)); // w: �Ÿ�(���), v: �� ����
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		pair<int,int> cur = pq.top(); pq.pop();
		if (d[cur.vertex] != cur.distance) continue;
		for (auto nxt : adj[cur.vertex])  // nxt : cur�κ��� ������ ������
			if (d[nxt.vertex] > d[cur.vertex] + nxt.distance) { // cur�� ������ ���� �Ÿ� ����Ͽ� ����
				d[nxt.vertex] = d[cur.vertex] + nxt.distance;
				pq.push(make_pair(d[nxt.vertex], nxt.vertex));
			}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << "\n";
	}
}