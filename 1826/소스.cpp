#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll gas,village,start_gas;
	ll total_gas = 0;
	bool village_arr = false;
	cin >> gas;
	vector<pair<ll, ll>> gas_station;
	vector<pair<ll, ll>> pass_gas;
	ll refeul = 0;
	for(ll i=0;i<gas;i++)
	{
		ll len, size;
		cin >> len >> size;
		gas_station.push_back({ len,size });
		total_gas += size;
	}
	sort(gas_station.begin(), gas_station.end());
	cin >> village >> start_gas;
	total_gas += start_gas;
	
	ll gas_num = 0;
	while (start_gas < village)
	{
		for (ll i = gas_num; i < gas; i++)
		{
			if (gas_station[i].first <= start_gas)
			{
				pass_gas.push_back({ gas_station[i].second,gas_station[i].first });
				gas_num++;//주유소가 중복해서 안들어가게 합니다.
			}
			else
			{
				break;
			}
		}
		if (pass_gas.size() == 0)
		{
			village_arr = true;
			break;
		}
		sort(pass_gas.begin(), pass_gas.end(), greater<>());
		start_gas += pass_gas[0].first;
		pass_gas.erase(pass_gas.begin());
		refeul++;
	}
	if(pass_gas.size()==0&&village_arr)
	{
		cout << "-1";
	}
	else {
		cout << refeul;
	}
}