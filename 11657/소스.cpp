#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 100000000000000;
vector<pair<int, int>> city_map[501];
ll city_length[501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long city, bus;
	long long Minus = 0;

	cin >> city >> bus;
	fill(city_length, city_length+501, INF);
	for (long long i = 0; i < bus; i++) {
		int start, end, Time;
		cin >> start >> end >> Time;
		city_map[start].push_back(make_pair(end,Time));
	}
	city_length[1] = 0;
	for (int i = 0; i < city; i++) {
		for (int j = 1; j <= city; j++) {
			int Begin = j;
			for (int z = 0; z < city_map[Begin].size(); z++) {
				int End = city_map[Begin][z].first;
				ll value = city_map[Begin][z].second;
				if (city_length[Begin] != INF&&city_length[End]>city_length[Begin]+value) {
					city_length[End] = city_length[Begin] + value;
					if (i == city - 1) {
						Minus = 1;
					}
				}
			}
		}
	}
	if (Minus == 1) {
		cout << "-1";
	}
	else {
		for (int i = 2; i <= city; i++) {
			if (city_length[i] == INF) {
				cout << "-1" << "\n";
			}
			else {
				cout << city_length[i] << "\n";
			}
		}
	}
}