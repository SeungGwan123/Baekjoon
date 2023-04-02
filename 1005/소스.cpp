#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Game;
	cin >> Game;
	for (int G = 0; G < Game; G++) {
		int building, rule,win;
		ll Time[1001] = { 0, };
		ll new_Time[1001] = { 0, };
		ll degree[1001] = { 0, };
		vector<ll>graph[1001];
		queue<ll> q;
		cin >> building >> rule;
		for (int i = 1; i <= building; i++) {
			int temp;
			cin >> temp;
			Time[i] = temp;
		}
		for (int i = 1; i <= rule; i++) {
			int start, end;
			cin >> start >> end;
			degree[end]++;
			graph[start].push_back(end);
		}
		cin >> win;
		for (int i = 1; i <= building; i++) {
			if (degree[i] == 0) {
				q.push(i);
				new_Time[i] = Time[i];
			}
		}
		while (!q.empty()) {
			int start = q.front();
			q.pop();
			for (int i = 0; i < graph[start].size(); i++) {
				int end = graph[start][i];
				degree[end]--;
				if (degree[end] == 0) {
					q.push(end);
				}
				new_Time[end] = max(new_Time[end], new_Time[start] + Time[end]);
			}
		}
		cout << new_Time[win] << "\n";
	}
}