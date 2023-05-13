#include <bits/stdc++.h>
#define ll long long
//너무 어려움... 시간초과 해결 못함
//greedy에서 multiset 항상 생각해보기
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll jew, bag;
	cin >> jew >> bag;
	multiset<pair<ll, ll>>jewelry;
	multiset<ll> possible;
	vector<int>backpack(bag);
	queue<ll>temp_bag;
	long long cost = 0;
	for (ll i = 0; i < jew; i++)
	{
		ll t1, t2;
		cin >> t1 >> t2;
		jewelry.insert({ t1,t2 });
	}

	for (ll i = 0; i < bag; i++)
	{
		ll temp;
		cin >> backpack[i];
	}

	sort(backpack.begin(), backpack.end());
	priority_queue<ll> pq;
	//multiset을 써야 시간 초과가 해결이 된다.
	for (ll i = 0; i < bag; i++)
	{
		//가방 무게
		ll cap = backpack[i];
		//가방 무게를 초과하는 보석중 가장 가벼운 보석 위치 auto는 multiset에서 접근을 하기 위한 주소
		auto upper = jewelry.upper_bound({cap,INT_MAX});
		//가방에 들어가는 보석은 다 채워넣는다
		for(auto j=jewelry.begin();j != upper;)
		{
			possible.insert((*j).second);
			j=jewelry.erase(j);
		}
		//그중에서 가장 가치가 높은것을 가방에 넣어준다.
		if(possible.size()>0)
		{
			ll m = *prev(possible.end());
			possible.erase(prev(possible.end()));
			cost += m;
		}
	}
	cout << cost;
}