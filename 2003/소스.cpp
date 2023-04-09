//이 문제는 i~j까지의 합을 구하는 문제이기 때문에 포인터 두개를 사용하여 쉽게 풀었습니다.
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