#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>graph[1001];
priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
ll parent[1001];

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

	int computer, line;
	int finish = 0;
	int short_path = 0;
	cin >> computer >> line;

	for (int i = 0; i < line; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		pq.push(make_tuple(value, start, end));
		graph[start].push_back(end);
	}
	//위상정렬 위해서 부모노드 설정
	for (int i = 1; i <= computer; i++) {
		parent[i] = i;
	}
	
	while (!pq.empty()) {
		int start, end, value;
		tie(value, start, end) = pq.top();
		pq.pop();
		if (finish == computer + 2) {
			break;
		}
		if (Find(start) != Find(end)) {
			Union(start, end);
			short_path += value;
		}
	}
	cout << short_path;
}