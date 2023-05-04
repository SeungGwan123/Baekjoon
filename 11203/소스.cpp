#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line;
	long locate=1;
	long height;
	getline(cin,line);
	if ((line[1] == ' '&&line.length()>1)||line.length()<=1) {
		height = (long)pow(2, (line[0] - 47))-1;
		if (line.length() > 1) {
			for (int i = 2; i < line.length(); i++) {
				if (line[i] == 'L') {
					locate = locate * 2;
				}
				else if (line[i] == 'R') {
					locate = locate * 2 + 1;
				}
			}
		}
	}
	else {
		height = (long)(line[0] - 48)*10 + (long)(line[1] - 48);
		height = (long)pow(2, height + 1)-1;
		if (line.length() > 2) {
			for (int i = 3; i < line.length(); i++) {
				if (line[i] == 'L') {
					locate = locate * 2;
				}
				else if (line[i] == 'R') {
					locate = locate * 2 + 1;
				}
			}
		}
	}
	cout << (height - locate)+1;
}