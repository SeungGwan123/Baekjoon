#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int people;
	int total = 0;
	cin >> people;
	vector<int> time(people);
	for (int i = 0; i < people; i++){
		cin >> time[i];
	}
	sort(time.begin(), time.end());
	for (int i = 0; i < people; i++) {
		total += time[i] * (people - i);
	}
	cout << total;
}