#include <bits/stdc++.h>

using namespace std;

vector<int> tree[100001];
bool visited[100001] = { 0, };
int root[100001] = { 0, };
int check = 0;
void bfs(int a) {
	int size = tree[a].size();
	for (int i = 0; i < size; i++) {
		int child = tree[a][i];
		if (visited[child] == false) {
			visited[child] = true;
			root[child] = a;
			bfs(child);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node;
	root[1] = 1;
	cin >> node;
	for (int i = 1; i < node; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= node; i++) {
		cout << root[i] << "\n";
	}
}