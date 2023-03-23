#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>> graph[20001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp_graph;
	bool visited[20001];
	ll Length[20001];
	fill(Length, Length + 20001, INF);
	fill(visited, visited + 20001, false);
	int node, edge, start;
	cin >> node >> edge >> start;

	for (int i = 0; i < edge; i++) {
		int begin, end, value;
		cin >> begin >> end >> value;
		graph[begin].push_back(make_pair(end, value));
	}
	Length[start] = 0;//시작 노드 길이 0 으로 초기화
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		temp_graph.push(make_pair(graph[start][i].second, graph[start][i].first));
	}
	while (!temp_graph.empty()) {
		int now = temp_graph.top().second;
		if (visited[now] == true) {
			temp_graph.pop();
			continue;
		}
		visited[now] = true;
		Length[now] = temp_graph.top().first;
		for (int i = 0; i < graph[now].size(); i++) {
			if (visited[graph[now][i].first] == false) {
				temp_graph.push(make_pair(graph[now][i].second + Length[now], graph[now][i].first));
			}
		}
		temp_graph.pop();
	}
	for (int i = 1; i <= node; i++) {
		if (Length[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << Length[i] << "\n";
		}
	}
}