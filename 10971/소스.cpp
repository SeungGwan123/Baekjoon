#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;

int city;
int total_route = INF;
int temp_route = 0;
int level = 1;
ll visited[11];
ll world[11][11];
int start_city = 0;
void backtracking(int a) {
	visited[a] = true;
	for (int i = 0; i < city; i++) {
		if (visited[i] == true)continue;
		if (temp_route > total_route)continue;
		if (world[a][i] == 0)continue;
		temp_route += world[a][i];
		level++;
		backtracking(i);
		visited[i] = false;
		temp_route -= world[a][i];
		level--;
	}
	if (level == city&&world[a][start_city]!=0) {
		total_route = min(total_route, (temp_route+(int)world[a][start_city]));
	}
}
int main() {
	fill(visited, visited + 11, false);
	cin >> city;
	for (int i = 0; i < city; i++) {
		for (int j = 0; j < city; j++) {
			cin >> world[i][j];
		}
	}
	for (int i = 0; i < city; i++) {
		start_city = i;
		backtracking(i);
	}
	cout << total_route;
}