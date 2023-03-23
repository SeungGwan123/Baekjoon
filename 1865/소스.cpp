#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Case;
	cin >> Case;
	for (int C = 0; C < Case; C++) {
		int node, road, blackhole;
		int possible = 0;
		vector<pair<int,int>> Nodes[501];
		ll cycle[501];
		bool check[501];
		fill(cycle, cycle + node + 1, 0);
		fill(check, check + node + 1, false);
		cin >> node >> road >> blackhole;
		for (int i = 0; i < road; i++) {
			int start,end,value;
			cin >> start >> end >> value;
			Nodes[start].push_back(make_pair(end, value));
			Nodes[end].push_back(make_pair(start, value));
		}
		for (int i = 0; i < blackhole; i++) {
			int start, end, value;
			cin >> start >> end >> value;
			Nodes[start].push_back(make_pair(end, -value));
		}
		
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++) {
				int start = j;
				for (int l = 0; l < Nodes[start].size(); l++) {
					int end = Nodes[start][l].first;
					int value = Nodes[start][l].second;
					if (cycle[start] != INF && cycle[end] > cycle[start] + value) {
						cycle[end] = cycle[start] + value;
						if (i == node) {
							check[end] = true;
							possible = 1;
						}
					}
				}
			}
		}
		
		if (possible == 0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
}