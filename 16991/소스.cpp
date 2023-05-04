#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;

const int MAX_N = 16;

int n;
double dist[MAX_N][MAX_N];
double dp[1 << MAX_N][MAX_N];

double tsp(int visited, int current) {
	if (visited == (1 << n) - 1) {
		return dist[current][0]; // 모든 도시를 방문했을 경우, 다시 시작점으로 돌아가는 비용 반환
	}
	double& ret = dp[visited][current];
	if (ret != 0) {
		return ret; // 이미 계산된 값이 있을 경우, 해당 값을 반환
	}
	ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next)) { // 이미 방문한 도시인 경우
			continue;
		}
		ret = min(ret, dist[current][next] + tsp(visited | (1 << next), next)); // 다음 도시로 이동하여 비용 계산
	}
	return ret;
}

int main() {
	cin >> n;
	double x[17], y[17];
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)); // 두 도시 간의 거리 계산
		}
	}
	printf("%.10lf\n", tsp(1, 0)); // 비트마스크 방법으로 TSP 해결
	return 0;
}