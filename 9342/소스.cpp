#include <bits/stdc++.h>

using namespace std;
//regex 함수는 문자열에서 패턴 발견하거나 할때 정말 좋다
int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		string gene;
		regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
		cin >> gene;

		if (regex_match(gene, r)) {
			cout << "Infected!" << "\n";
		}
		else {
			cout << "Good" << "\n";
		}
	}
}