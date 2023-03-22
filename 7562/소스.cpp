#include <bits/stdc++.h>

using namespace std;
int board[301][301] = { {0,}, };
int visited[301][301] = { {0,}, };
int move_num[301][301] = { {0,}, };

int Move;
int result = 0;
int start_x, start_y, end_x, end_y;
int Knight_x[8] = { 1,1,2,2,-1,-1,-2,-2 };
int Knight_y[8] = { 2,-2,1,-1,2,-2,1,-1 };
void bfs(int x,int y,int a,int b,int Len) {
	queue<pair<int,int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int sub_x = X + Knight_x[i];
			int sub_y = Y + Knight_y[i];

			if (sub_x<0 || sub_x>=Len || sub_y<0 || sub_y>=Len)continue;

			if (visited[sub_x][sub_y] == 0) {
				move_num[sub_x][sub_y] = move_num[X][Y] + 1;
				visited[sub_x][sub_y] = 1;
				q.push(make_pair(sub_x, sub_y));
				if (sub_x == a && sub_y == b) {
					cout << move_num[sub_x][sub_y] << "\n";
					result = 1;
				}
			}
			if (result == 1) {
				break;
			}
		}
		if (result == 1) {
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Game;
	cin >> Game;
	for (int G = 0; G < Game; G++) {
		int Len;
		Move = 0;
		result = 0;
		memset(visited, 0, sizeof(visited));
		memset(move_num, 0, sizeof(move_num));
		cin >> Len;
		cin >> start_x >> start_y >> end_x >> end_y;
		if (start_x == end_x && start_y == end_y) {
			cout << "0" << "\n";
		}
		else {
			bfs(start_x, start_y, end_x, end_y,Len);
		}
	}
}