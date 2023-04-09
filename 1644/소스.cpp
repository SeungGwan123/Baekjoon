#include <bits/stdc++.h>

using namespace std;

int arr[4000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> prime;
	int target;
	int result = 0;
	int temp = 0;

	cin >> target;
	fill(arr, arr + target + 1, 1);
	for (int i = 2; i*i <=target; i++) {
		if (arr[i] == 0) continue;
		for (int j = i*i; j <= target; j+=i) {
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= target; i++) {
		if (arr[i] != 0) {
			prime.push_back(i);
		}
	}
	int x = 0;
	int y = 0;
	while (true) {
		if (temp >= target) {
			temp -= prime[x++];
		}
		else if (y== prime.size()) {
			break;
		}
		else {
			temp += prime[y++];
		}
		if (temp == target)result++;
	}
	cout << result;
}