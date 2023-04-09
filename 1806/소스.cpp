#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;
//ó������ �̺�Ž������ �˾Ҵµ� �������͸� ����ؾ� �Ѵٰ��ߴ�.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, s;
	ll impossible = 0;
	ll final = INF;
	cin >> n >> s;
	vector<ll> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		impossible += num[i];
	}
	if (impossible >= s) {
		vector<ll>::iterator L = num.begin();
		vector<ll>::iterator R = num.begin();
		ll result = 0;
		while (L<=R) {
			if (result >= s) {
				final = min(final, (ll)(R-L));
				result -= *L++;
			}
			else if (R == num.end())break;
			else {
				result += *R++;
			}
		}
		cout << final;
	}
	else {
		cout << "0";
	}
}