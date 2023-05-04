#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;

const int MAX_N = 16;

int n;
double dist[MAX_N][MAX_N];
double dp[1 << MAX_N][MAX_N];

double tsp(int visited, int current) {
	if (visited == (1 << n) - 1) {
		return dist[current][0]; // ��� ���ø� �湮���� ���, �ٽ� ���������� ���ư��� ��� ��ȯ
	}
	double& ret = dp[visited][current];
	if (ret != 0) {
		return ret; // �̹� ���� ���� ���� ���, �ش� ���� ��ȯ
	}
	ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited & (1 << next)) { // �̹� �湮�� ������ ���
			continue;
		}
		ret = min(ret, dist[current][next] + tsp(visited | (1 << next), next)); // ���� ���÷� �̵��Ͽ� ��� ���
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
			dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)); // �� ���� ���� �Ÿ� ���
		}
	}
	printf("%.10lf\n", tsp(1, 0)); // ��Ʈ����ũ ������� TSP �ذ�
	return 0;
}