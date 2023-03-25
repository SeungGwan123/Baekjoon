#include <iostream>
#include <vector>
#include<queue>
#include<cmath>
#define ll long long
#define INF 10000000000
using namespace std;
vector<pair<ll, ll>> graph[10001];
ll Mc_len[10001];
ll temp_len[10001];
ll Star_len[10001];
bool visited[10001];
vector<ll>M;
vector<ll>S;
void Dijkstra(int b, int c) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	fill(temp_len, temp_len + 10001, INF);
	fill(visited, visited + 10001, false);
	if (c == 0) {
		for (int i = 0; i < M.size(); i++) {
			pq.push(make_pair(0, M[i]));
			temp_len[M[i]] = 0;
			visited[M[i]] = true;
		}
	}
	else {
		for (int i = 0; i < S.size(); i++) {
			pq.push(make_pair(0, S[i]));
			temp_len[S[i]] = 0;
			visited[S[i]] = true;
		}
	}
	while (!pq.empty()) {
		int start = pq.top().second;
		ll value = pq.top().first;
		if (value > b) {
			break;
		}
		if (c == 0) {//¸Æµµ³¯µå
			Mc_len[start] = min(Mc_len[start], value);
		}
		else {
			Star_len[start] = min(Star_len[start], value);
		}
		pq.pop();

		for (int i = 0; i < graph[start].size(); i++) {
			int end = graph[start][i].first;
			int end_value = graph[start][i].second;
			if (visited[end] == true)continue;
			if (temp_len[end] > end_value + value) {
				temp_len[end] = end_value + value;
				pq.push(make_pair(temp_len[end], end));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(Mc_len, Mc_len + 10001, INF);
	fill(Star_len, Star_len + 10001, INF);

	int Mc, Star;
	ll shortpath = INF;
	int node, edge;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		graph[start].push_back(make_pair(end, value));
		graph[end].push_back(make_pair(start, value));
	}
	int temp_M, temp;
	cin >> temp_M >> Mc;
	for (int i = 0; i < temp_M; i++) {
		cin >> temp;
		M.push_back(temp);
	}
	Dijkstra(Mc, 0);
	int temp_S;
	cin >> temp_S >> Star;

	for (int i = 0; i < temp_S; i++) {
		cin >> temp;
		S.push_back(temp);
	}
	Dijkstra(Star, 1);
	for (int i = 1; i <= node; i++) {
		if (Mc_len[i] != 0 && Star_len[i] != 0 && Mc_len[i] != INF && Star_len[i] != INF) {
			shortpath = min(shortpath, Mc_len[i] + Star_len[i]);
		}
	}
	if (shortpath == INF) {
		cout << "-1";
	}
	else {
		cout << shortpath;
	}
}