#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<ll> Time[501];
	ll new_Time[501]={0,};
	vector<ll> graph[501];
	ll degree[501] = { 0, };
	queue<ll> q;
	int building;
	cin >> building;
	for (int i = 1; i <= building; i++) {
		int num = 1;
		while (true) {
			ll temp;
			cin >> temp;
			if (temp == -1) {
				if (num == 2) {
					q.push(i);
					new_Time[i] = Time[i][0];
				}
				break;
			}
			if (num == 1) {
				Time[i].push_back(temp);
			}
			else {
				graph[temp].push_back(i);
				degree[i]++;
			}
			num++;
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
			new_Time[end] = max(new_Time[end], Time[end][0] + new_Time[start]);
		}
	}
	for (int i = 1; i <= building; i++) {
		cout << new_Time[i] << "\n";
	}
}