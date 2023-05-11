#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string article;
	while (true) {
		getline(cin, article);
		if (cin.eof() == true) {
			break;
		}
		regex r(R"([Pp][Rr][Oo][Bb][Ll][Ee][Mm])");


		if (regex_search(article, r)) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
}