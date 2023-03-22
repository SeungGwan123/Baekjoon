#include <bits/stdc++.h>

using namespace std;
int x, y;
int num = 0;
int area = 1;
vector<int> area_num;
int visited[101][101] = { {0,}, };
int direction_f[4] = { 0,0,1,-1 };
int direction_s[4] = { 1,-1,0,0 };
void bfs(int a,int b) {
	queue<pair<int,int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int sub_x = q.front().first + direction_f[i];
			int sub_y = q.front().second + direction_s[i];

			if (sub_x < 0 || sub_x >= x || sub_y < 0 || sub_y >= y)continue;

			if (visited[sub_x][sub_y] == 0) {
				visited[sub_x][sub_y] = 1;
				q.push(make_pair(sub_x, sub_y));
				area++;
			}
		}
		q.pop();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int square;
	cin >> y >> x >> square;
	for (int i = 0; i < square; i++) {
		int block_x, block_y,block_a,block_b;
		cin >> block_x >> block_y>>block_a>>block_b;
		for (int a = block_x; a < block_a; a++) {
			for (int b = block_y; b < block_b; b++) {
				visited[a][b] = 1;
			}
		}
	}
	//사각형 위치 알아보기 위해서 만든 코드
	/*for (int i = 0; i < y; i++) { 
		for (int j = 0; j < x; j++) {
			cout << visited[j][i] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			area = 1;
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				bfs(i, j);
				num++;
				area_num.push_back(area);
			}
		}
	}
	sort(area_num.begin(),area_num.end());
	cout << num << "\n";
	for (auto P : area_num) {
		cout << P << " ";
	}
}