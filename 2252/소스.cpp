#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll degree[32001] = { 0, };
vector<ll> graph[32001];
queue<ll> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int student, compare;
	
	cin >> student >> compare;
	for (int i = 0; i < compare; i++) {
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		degree[end]++;
	}
	for (int i = 1; i <= student; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int start = q.front();
		cout << start << " ";
		q.pop();
		for (int i = 0; i < graph[start].size(); i++) {
			int end = graph[start][i];
			degree[end]--;
			if (degree[end] == 0) {
				q.push(end);
			}
		}
	}
}