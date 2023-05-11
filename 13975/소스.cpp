#include <bits/stdc++.h>

using namespace std;

int main() {
	int Case;
	cin >> Case;
	for (int C = 0; C < Case; C++) {
		int file;
		int cost = 0;
		cin >> file;
		priority_queue<int, vector<int>, greater<int>> book;
		for (int i = 0; i < file; i++) {
			int temp;
			cin >> temp;
			book.push(temp);
		}
		while (book.size() > 1) {
			int temp = book.top(); book.pop();
			temp += book.top(); book.pop();
			book.push(temp);
			cost += temp;
		}
		cout << cost<<"\n";
	}
}