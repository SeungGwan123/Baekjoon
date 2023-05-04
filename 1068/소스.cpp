#include <bits/stdc++.h>

using namespace std;
vector<int> tree[51];
int node_num = 0;
int remove_num = 0;
void dfs(int a) {
	int size = tree[a].size();
	for (int i = 0; i < size; i++) {
		int child = tree[a][i];
		if (child == remove_num) {
			if (size == 1) {
				node_num++;
			}
			continue;
		}
		dfs(child);
	}
	if (size == 0) {
		node_num++;
	}
}
int main() {
	int node,root;
	cin >> node;
	for (int i = 0; i < node; i++) {
		int parent;
		cin >> parent;
		if (parent != -1) {
			tree[parent].push_back(i);
		}
		else {
			root = i;
		}
	}
	cin >> remove_num;
	if (remove_num == root) {
		cout << '0';
	}
	else {
		dfs(root);
		cout << node_num;
	}
}