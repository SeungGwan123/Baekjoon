#include <bits/stdc++.h>
#define ll long long
#define INF 9987654321
using namespace std;

vector<pair<int, int>> graph[801];
ll short_path[801];

ll Dijkstra(int a, int b) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	short_path[a] = 0;
	pq.push(make_pair(short_path[a], a));
	while (!pq.empty()) {
		int start = pq.top().second;
		int value = pq.top().first;
		short_path[start] = value;
		if (start == b) {
			while (!pq.empty()) {
				pq.pop();
			}
			break;
		}
		for (int i = 0; i < graph[start].size(); i++) {
			int end = graph[start][i].first;
			int sub_value = graph[start][i].second;
			if (short_path[end] > sub_value + value) {
				pq.push(make_pair(sub_value + value, end));
			}
		}
		pq.pop();
	}
	return short_path[b];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int node, edge,v1,v2;
	ll v1_v2 = INF;
	ll v2_v1 = INF;
	
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		graph[start].push_back(make_pair(end, value));
		graph[end].push_back(make_pair(start, value));
	}
	cin >> v1 >> v2;

	fill(short_path, short_path + node + 1, INF);
	v1_v2 = Dijkstra(1, v1);
	fill(short_path, short_path + node + 1, INF);
	v1_v2+= Dijkstra(v1,v2);
	fill(short_path, short_path + node + 1, INF);
	v1_v2 += Dijkstra(v2,node);
	fill(short_path, short_path + node + 1, INF);
	v2_v1 = Dijkstra(1, v2);
	fill(short_path, short_path + node + 1, INF);
	v2_v1 += Dijkstra(v2, v1);
	fill(short_path, short_path + node + 1, INF);
	v2_v1 += Dijkstra(v1, node);

	if (v1_v2 >= INF && v2_v1 >= INF) {
		cout << "-1";
	}
	else {
		cout << min(v1_v2, v2_v1);
	}
}