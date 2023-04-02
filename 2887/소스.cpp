#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll,ll>>x_dis;
vector<pair<ll,ll>>y_dis;
vector<pair<ll,ll>>z_dis;
vector<tuple<ll, ll, ll>> planet_group;
ll parent[100001];
//priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
vector<tuple<ll, ll, ll>> pq;

int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (x > y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int planet;
	int short_path = 0;
	cin >> planet;

	for (int i = 0; i < planet; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x_dis.push_back({ x,i });
		y_dis.push_back({ y,i });
		z_dis.push_back({ z,i });
		parent[i] = i;
	}
	sort(x_dis.begin(), x_dis.end());
	sort(y_dis.begin(), y_dis.end());
	sort(z_dis.begin(), z_dis.end());
	for (int i = 0; i < planet-1; i++) {
		pq.push_back({ abs(x_dis[i + 1].first - x_dis[i].first),x_dis[i].second,x_dis[i + 1].second});
		pq.push_back({ abs(y_dis[i + 1].first - y_dis[i].first),y_dis[i].second,y_dis[i + 1].second });
		pq.push_back({ abs(z_dis[i + 1].first - z_dis[i].first),z_dis[i].second,z_dis[i + 1].second });
	}
	sort(pq.begin(), pq.end());
	for (int i = 0; i < pq.size();i++) {
		int start, end, value;
		tie(value, start, end) = pq[i];
		if (Find(start) != Find(end)) {
			Union(start, end);
			short_path += value;
		}
	}
	cout << short_path;
}