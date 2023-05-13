#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	long long sum = 0;
	cin >> num;
	vector<long long> total(num);
	vector<long long> total_re(num);
	for (int i = 0; i < num; i++) {
		cin >> total[i];
		total_re[i] = total[i];
	}
	sort(total.begin(), total.end(), greater<>());
	sort(total_re.begin(), total_re.end());
	bool meet = num % 2 == 0 ? false : true; //false ´Â Â¦¼ö true´Â È¦¼ö
	int even_check = 0;
	if(num<4)
	{
		
	}
	else {
		if (meet == false) {
			for (int i = 1; i <= num/2; i++)
			{
				int plus = 0;
				long long temp = total[i] * total[i - 1];
				
				if(temp>total[i]+total[i-1])
				{
					sum += temp;
					i++;
				}else
				{
					sum += total[i - 1];
					if(i==num/2-1)
					{
						even_check = 1;
					}
				}
			}
			for (int i = 1; i <= num / 2; i++)
			{
				long long temp_re = total_re[i] * total_re[i - 1];
				if (temp_re > total_re[i] + total_re[i - 1])
				{
					sum += temp_re;
					i++;
				}
				else
				{
					sum += total_re[i - 1];
					if (i == num / 2 - 1)
					{
						if (even_check == 1)
						{
							even_check = 2;
						}
						else
						{
							even_check = 3;
						}
					}
				}
			}
			int i = num / 2 - 1;
			if (even_check == 1)
			{
				sum += total[i];
			}
			else if (even_check == 2)
			{
				if (total[i] * total_re[i] > total[i] + total_re[i])
				{
					sum += total[i] * total_re[i];
				}
				else
				{
					sum += total[i] + total_re[i];

				}
			}
			else if (even_check == 3)
			{
				sum += total_re[i];
			}
		}
		else {
			for (int i = 1; i < (num-1) / 2; i++)
			{
				int plus = 0;
				long long temp = total[i] * total[i - 1];
				
				if (temp > total[i] + total[i - 1])
				{
					sum += temp;
					i++;
				}
				else
				{
					sum += total[i - 1];
					if (i == (num-1) / 2 - 2)
					{
						even_check = 1;
					}
				}
				
			}
			for (int i = 1; i < (num - 1) / 2; i++)
			{
				long long temp_re = total_re[i] * total_re[i - 1];
				if(i==(num-1)/2-1)
				{
					
				}
				if (temp_re > total_re[i] + total_re[i - 1])
				{
					sum += temp_re;
					i++;
				}
				
			}
			int i = (num - 1) / 2 - 2;
			if(even_check==1)
			{
				
			}
		}
	}
	/*for (int i = 1; i < num-1; i++) {
		long long pre = total[i] * total[i - 1];
		long long nex = total[i] * total[i + 1];
		if(pre>nex)
		{
			if(pre>total[i]+total[i-1])
			{
				sum += pre;
				i++;
				continue;
			}else
			{
				sum += total[i - 1];
				continue;
			}
		}else
		{
			if(nex>total[i]+total[i+1])
			{
				sum += total[i - 1];
				sum += nex;
				if(i==num-4)
				{
					if(total[i+2]*total[i+3]>total[i+2]+total[i+3])
					{
						sum += total[i + 2] * total[i + 3];
						break;
					}else
					{
						sum += (total[i + 2] + total[i + 3]);
						break;
					}
				}else if(i==num-3)
				{
					sum += total[i + 2];
					break;
				}else
				{
					i++;
				}
			}else
			{
				sum += total[i - 1];
				i++;
			}
		}
	}*/
}