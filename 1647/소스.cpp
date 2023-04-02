#include <bits/stdc++.h>
#define ll long long

using namespace std;

priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
ll parent[100001];
ll tree[100001];
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int edge, node;
	ll short_path = 0;
	ll result = 0;
	cin >> edge >> node;

	for (int i = 0; i < node; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(make_tuple(value, start, end));
	}

	for (int i = 1; i <= edge; i++) {
		parent[i] = i;
	}

	while (!pq.empty()) {
		int start, end, value;
		tie(value, start, end) = pq.top();
		pq.pop();
		if (Find(start) != Find(end)) {
			Union(start, end);
			result = value;
			short_path += value;
		}
	}
	cout << (short_path-result);
}