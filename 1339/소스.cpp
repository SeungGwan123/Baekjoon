#include <bits/stdc++.h>

using namespace std;
bool compare(pair<char,int> a,pair<char,int>b)
{
	if(a.second==b.second)
	{
		return a.second>b.second;
	}
	return a.second > b.second;
}
int main()
{
	int num;
	int max_len = 0;
	int a2n = 9;
	int sum = 0;
	cin >> num;
	vector<string> word(num);
	vector<char> vari;
	map<char, int> rank;
	for(int N=0;N<num;N++)
	{
		cin >> word[N];
		max_len = max(max_len, (int)word[N].length());
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<word[i].length();j++)
		{
			vari.push_back(word[i][j]);
			if(rank.count(word[i][j])==0)
			{
				rank.insert({ word[i][j],pow(10,word[i].length() - j) });
			}else
			{
				rank[word[i][j]] += pow(10, word[i].length() - j);
			}
		}
	}
	vector<pair<char, int>> final_rank(rank.begin(), rank.end());
	sort(final_rank.begin(), final_rank.end(), compare);
	for(int i=0;i<final_rank.size();i++)
	{
		final_rank[i].second = a2n;
		a2n--;
	}
	map<char, int>rank_2(final_rank.begin(), final_rank.end());
	for (int N = 0; N < num; N++)
	{
		for(int i=0;i<word[N].length();i++)
		{
			sum += rank_2[word[N][i]] * pow(10, word[N].length() - i-1);
		}
	}
	cout << sum;
}