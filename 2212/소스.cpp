#include <bits/stdc++.h>
#define ll long long
using namespace std;
//왜 빼줘야할까??? 마지막 범위가 focus-sen_num이거나 최대거리를 focus-1만큼 빼줘야한다. 안그러면 out of bound생긴다. 왜그럴까...
int main()
{
	ll sen_num, focus;
	cin >> sen_num >> focus;
	vector<ll>con(sen_num);
	bool visited[10001]={0,};
	ll vis_num = 0;
	ll total_num = 0;
	ll total_dis = 0;
	
	for (ll i = 0; i < sen_num; i++)
	{
		cin >> con[i];
	}
	if (sen_num > focus || con.size() > 1)
	{
		sort(con.begin(), con.end());
		vector<ll> con_dis;
		for (ll i = 1; i < con.size(); i++)
		{
			ll distance = con[i] - con[i - 1];
			con_dis.push_back(distance);
			total_dis += distance;
		}
		sort(con_dis.begin(), con_dis.end(),greater<>());
		for (ll i = 0; i < focus-1; i++)
		{
			if (i + 1 >= sen_num)break;
			total_dis -= con_dis[i];
		}
	}
	cout << total_dis;
}