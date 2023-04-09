#include <bits/stdc++.h>
#define ll long long
using namespace std;
//그냥 하나하나 비교하면 시간초과가 난다. 그래서 이분탐색을 썼습니다.
int main() {
	ll t, n, m;
	vector<ll> n_array;
	vector<ll> m_array;
	ll result = 0;
	cin >> t>>n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		n_array.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		m_array.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		ll sum = n_array[i];
		for (int j = i+1; j < n; j++) {
			sum += n_array[j];
			n_array.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		ll sum = m_array[i];
		for (int j = i + 1; j < m; j++) {
			sum += m_array[j];
			m_array.push_back(sum);
		}
	}
	sort(n_array.begin(), n_array.end());
	sort(m_array.begin(), m_array.end());
	//이분탐색
	for (int i = 0; i < n_array.size(); i++) {
		ll low = lower_bound(m_array.begin(), m_array.end(), t - n_array[i]) - m_array.begin();
		ll high = upper_bound(m_array.begin(), m_array.end(), t - n_array[i]) - m_array.begin();

		result += high - low;
	}
	cout << result;
}