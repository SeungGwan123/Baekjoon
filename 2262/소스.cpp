#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

int main()
{
	int member;
	cin >> member;
	vector<int>rank[257];
	vector<int> sub;
	int sub_rank[257];
	set<tuple<int, int, int>>rank_sub;
	bool visited[257] = { 0, };
	int total = 0;
	int win = 0;
	for(int i=0;i<member;i++)
	{
		cin >> sub_rank[i];
		sub.push_back(sub_rank[i]);
	}
	sort(sub_rank, sub_rank + member, greater<>());
	for(int i=1;i<member;i++)
	{
		rank[sub[i]].push_back(sub[i - 1]);
		rank[sub[i - 1]].push_back(sub[i]);
	}
	for(int i=0;i<member-1;i++)
	{
		int min_distance = INF;
		int min_end = 0;
		for(int j=0;j<sub.size();j++)
		{
			if(sub[j]==sub_rank[i])
			{
				if(j==0)
				{
					total += abs(sub[j + 1] - sub[j]);
					sub.erase(sub.begin() + j);
				}else if(j==sub.size()-1)
				{
					total += abs(sub[j - 1] - sub[j]);
					sub.erase(sub.begin() + j);
				}else
				{
					total += min(abs(sub[j - 1] - sub[j]), abs(sub[j + 1] - sub[j]));
					sub.erase(sub.begin() + j);
				}
			}
		}
	}
	cout << total;
}