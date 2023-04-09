#include <bits/stdc++.h>
#define ll long long
#define INF 10000000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> liquid(n);
	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}
	vector<ll>::iterator start = liquid.begin(); 
	vector<ll>::iterator end = liquid.end() - 1;
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
	while (start != end) {
		pq.push({abs(*start + *end), *start, *end});
		ll L = abs(*start);
		ll R = abs(*end);
		if (L < R) {
			end--;
		}
		else if (start == liquid.end() || end == liquid.begin())break;
		else {
			start++;
		}
	}
	ll first, second, value;
	tie(value, first, second) = pq.top();
	first = min(first, second);
	second = max(first, second);
	cout << first <<" " << second;
}