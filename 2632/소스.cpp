#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int size, a, b;
	vector<ll> pizza_a;
	vector<ll> pizza_b;
	vector<ll> pizza;
	ll result = 0;
	ll sub_a = 0;
	ll sub_b = 0;
	cin >> size >> a >> b;
	for (int i = 0; i < a; i++) {
		int temp;
		cin >> temp;
		sub_a += temp;
		pizza_a.push_back(temp);
		if (i == (a - 1)) {
			for (int j = 0; j < a - 1; j++) {
				pizza_a.push_back(pizza_a[j]);
			}
		}
	}
	for (int i = 0; i < b; i++) {
		int temp;
		cin >> temp;
		sub_b += temp;
		pizza_b.push_back(temp);
		if (i == (b - 1)) {
			for (int j = 0; j < b - 1; j++) {
				pizza_b.push_back(pizza_b[j]);
			}
		}
	}
	for (int i = 0; i < a; i++) {
		ll sum = pizza_a[i];
		for (int j = i + 1; j < a+i; j++) {
			sum += pizza_a[j];
			if (sum == sub_a)continue;
			pizza_a.push_back(sum);
		}
	}
	pizza_a.push_back(sub_a);
	for (int i = 0; i < b; i++) {
		ll sum = pizza_b[i];
		for (int j = i + 1; j < b+i; j++) {
			sum += pizza_b[j];
			if (sum == sub_b)continue;
			pizza_b.push_back(sum);
		}
	}
	pizza_b.push_back(sub_b);
	pizza_a.erase(pizza_a.begin() + a, pizza_a.begin() + (2 * a - 1));
	sort(pizza_a.begin(), pizza_a.end());
	//pizza_a.erase(unique(pizza_a.begin(), pizza_a.end()), pizza_a.end());
	pizza_b.erase(pizza_b.begin() + b, pizza_b.begin() + (2 * b - 1));
	sort(pizza_b.begin(), pizza_b.end());
	//pizza_b.erase(unique(pizza_b.begin(), pizza_b.end()), pizza_b.end());
	//혼합
	for (int i = 0; i < pizza_a.size(); i++) {
		ll low = lower_bound(pizza_b.begin(), pizza_b.end(), size - pizza_a[i]) - pizza_b.begin();
		ll high = upper_bound(pizza_b.begin(), pizza_b.end(), size - pizza_a[i]) - pizza_b.begin();
		ll sum = high - low;
		if(sum>0) result += sum;
	}
	//개별 피자
	ll sum_a = upper_bound(pizza_a.begin(), pizza_a.end(), size) - lower_bound(pizza_a.begin(), pizza_a.end(), size);
	ll sum_b = upper_bound(pizza_b.begin(), pizza_b.end(), size) - lower_bound(pizza_b.begin(), pizza_b.end(), size);
	if (sum_a > 0) result += sum_a;
	if (sum_b > 0) result += sum_b;
	cout << result;
}