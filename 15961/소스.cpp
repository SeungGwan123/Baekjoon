#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> rail;
	int dish, sushi, event, coupon;
	int result = 0;
	cin >> dish >> sushi >> event >> coupon;
	for (int i = 0; i < dish; i++) {
		int temp;
		cin >> temp;
		rail.push_back(temp);
	}
	vector<int> s;
	vector<int>::iterator x = rail.begin();
	vector<int>::iterator y = rail.begin()+ event - 1;
	for (vector<int>::iterator i = x; i <= y; i++) {
		s.push_back(*i);
	}
	while (y!=(rail.begin()+event-2)) {
		vector<int> temp=s;
		int same = 0;
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()),temp.end());
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == coupon) {
				same = 1;
				break;
			}
		}
		if (same == 1) {
			result = max(result, (int)temp.size());
		}
		else {
			result = max(result, (int)temp.size()+1);
		}
		s.erase(s.begin());
		if (y == rail.end()) {
			y = rail.begin();
		}
		else {
			y++;
		}
		s.push_back(*y);
	}
	cout << result;
}