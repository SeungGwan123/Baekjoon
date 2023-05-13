#include <bits/stdc++.h>
#define ll long long
//�ʹ� �����... �ð��ʰ� �ذ� ����
//greedy���� multiset �׻� �����غ���
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
	//multiset�� ��� �ð� �ʰ��� �ذ��� �ȴ�.
	for (ll i = 0; i < bag; i++)
	{
		//���� ����
		ll cap = backpack[i];
		//���� ���Ը� �ʰ��ϴ� ������ ���� ������ ���� ��ġ auto�� multiset���� ������ �ϱ� ���� �ּ�
		auto upper = jewelry.upper_bound({cap,INT_MAX});
		//���濡 ���� ������ �� ä���ִ´�
		for(auto j=jewelry.begin();j != upper;)
		{
			possible.insert((*j).second);
			j=jewelry.erase(j);
		}
		//���߿��� ���� ��ġ�� �������� ���濡 �־��ش�.
		if(possible.size()>0)
		{
			ll m = *prev(possible.end());
			possible.erase(prev(possible.end()));
			cost += m;
		}
	}
	cout << cost;
}