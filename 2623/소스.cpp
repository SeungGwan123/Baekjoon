#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll parent[1001];
ll degree[1001] = { 0, };
vector<ll>graph[1001];
queue<ll> q;
vector<ll>final_squence;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int singer, group;
	cin >> singer >> group;
	for (int i = 1; i <= singer; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < group; i++) {
		ll group_num;
		ll temp_group[1001];
		cin >> group_num;
		for (int j = 0; j < group_num; j++) {
			int temp;
			cin >> temp;
			temp_group[j] = temp;
			if (j > 0) {
				graph[temp_group[j-1]].push_back(temp);
				degree[temp]++;
			}
		}
	}
	for (int i = 1; i <= singer; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int start = q.front();
		final_squence.push_back(start);
		q.pop();
		for (int i = 0; i < graph[start].size(); i++) {
			int end = graph[start][i];
			degree[end]--;
			if (degree[end] == 0) {
				q.push(end);
			}
		}
	}
	if (final_squence.size() != singer) {
		cout << "0";
	}
	else {
		for (int i = 0; i < final_squence.size(); i++) {
			cout << final_squence[i] << "\n";
		}
	}
}