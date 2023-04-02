#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll parent[10001];
priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (x > y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
}
int main() {
	int node, edge;
	int min_value = 0;
	cin >> node >> edge;
	//사이클찾기에 쓰이는 parent초기화
	for (int i = 1; i < node; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < edge; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(make_tuple(value, start, end));
	}
	while (!pq.empty()) {
		int value = get<0>(pq.top());
		int start = get<1>(pq.top());
		int end = get<2>(pq.top());
		pq.pop();
		if (Find(start) != Find(end)) {
			Union(start, end);
			min_value += value;
		}
	}
	cout << min_value;
}