#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000

using namespace std;

pair<ll,ll> garbage_graph[51][51];
bool visited[51][51];
int graph[51][51];
int G_spot = 0;
int G_near = 0;
int width, height;
//¿À ¿Þ ¾Æ À§
int direction_1[4] = { 0,0,1,-1 };
int direction_2[4] = { 1,-1,0,0 };

void Dijkstra(pair<int,int> start, pair<int,int> end) {
	priority_queue<tuple<int,int,int, int>, vector<tuple<int,int,int, int>>, greater<tuple<int,int,int, int>>> pq;
	fill(&garbage_graph[0][0], &garbage_graph[height][width+1], make_pair(INF, INF));
	fill(&visited[0][0],&visited[height][width + 1], false);
	pq.push(make_tuple(0,0,start.first,start.second));
	garbage_graph[start.first][start.second] = make_pair(0, 0);
	visited[start.first][start.second] = true;
	while (!pq.empty()) {
		int G = get<0>(pq.top());
		int GN = get<1>(pq.top());
		int x = get<2>(pq.top());
		int y = get<3>(pq.top());
		visited[x][y] = true;
		if (x == end.first && y == end.second) {
			G_spot = G;
			G_near = GN;
			break;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> garbage_number = make_pair(0, 0);
			int X = x + direction_1[i];
			int Y = y + direction_2[i];
			if (X < 0 || X >= height || Y < 0 || Y >= width)continue;
			if (graph[X][Y] == 1) {
				garbage_number = make_pair(G, GN);
				for (int j = 0; j < 4; j++) {
					int X_j = X + direction_1[j];
					int Y_j = Y + direction_2[j];
					if (X_j < 0 || X_j >= height || Y_j < 0 || Y_j >= width)continue;
					if (graph[X_j][Y_j] == 30) {
						garbage_number = make_pair(garbage_number.first,garbage_number.second + 1);
					}
				}
				if (garbage_graph[X][Y].first > garbage_number.first&&visited[X][Y]!=true) {
					if (garbage_graph[X][Y].second > garbage_number.second) {
						garbage_graph[X][Y] = garbage_number;
						pq.push(make_tuple(garbage_number.first, garbage_number.second, X, Y));
					}
				}
			}
			else if (graph[X][Y] == 30) {
				garbage_number = make_pair(G+1, GN);
				if (garbage_graph[X][Y].first > garbage_number.first && visited[X][Y] != true) {
					if (garbage_graph[X][Y].second > garbage_number.second) {
						garbage_graph[X][Y] = garbage_number;
						pq.push(make_tuple(garbage_number.first, garbage_number.second, X, Y));
					}
				}
			}
			else if (graph[X][Y] == 4) {
				garbage_number = make_pair(G, GN+1);
				if (garbage_graph[X][Y].first > garbage_number.first && visited[X][Y] != true) {
					if (garbage_graph[X][Y].second > garbage_number.second) {
						garbage_graph[X][Y] = garbage_number;
						pq.push(make_tuple(garbage_number.first, garbage_number.second, X, Y));
					}
				}
			}
			else if(graph[X][Y]==0) {
				if (garbage_graph[X][Y].first > garbage_number.first && visited[X][Y] != true) {
					if (garbage_graph[X][Y].second > garbage_number.second) {
						garbage_graph[X][Y] = garbage_number;
						pq.push(make_tuple(G, GN, X, Y));
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<pair<int, int>>garbage;
	pair<int, int> Flower;
	pair<int, int> Start;
	
	fill(&graph[0][0], &graph[50][51], INF);
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < width; j++) {
			if (temp[j] == '.') {
				graph[i][j] = 1;
			}
			else if (temp[j] == 'g') {
				graph[i][j] = 30;
				garbage.push_back(make_pair(i, j));
			}
			else if (temp[j] == 'F') {
				graph[i][j] = 0;
				Flower = make_pair(i, j);
			}
			else {
				graph[i][j] = 2;
				Start = make_pair(i, j);
			}
		}
	}
	for (int i = 0; i < garbage.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int C = garbage[i].first + direction_1[j];
			int R = garbage[i].second + direction_2[j];

			if (C < 0 || C >= height || R < 0 || R >= width)continue;
			if (graph[C][R] == 1) {
				graph[C][R] = 4;
			}
		}
	}
	Dijkstra(Start, Flower);
	cout << G_spot<< " " << G_near;
}