//�� ������ i~j������ ���� ���ϴ� �����̱� ������ ������ �ΰ��� ����Ͽ� ���� Ǯ�����ϴ�.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> number;
	int n, m;
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		number.push_back(temp);
	}
	vector<int>::iterator x = number.begin();
	vector<int>::iterator y = number.begin();
	while (y != number.end()) {
		int Sum = 0;
		for (vector<int>::iterator i = x; i <= y; i++) {
			Sum += *i;
		}
		if (Sum == m) {
			x++;
			result++;
		}
		else if (Sum < m) {
			y++;
		}
		else {
			x++;
		}
	}
	cout << result;
}