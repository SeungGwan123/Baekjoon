#include <bits/stdc++.h>

using namespace std;
//regex �Լ��� ���ڿ����� ���� �߰��ϰų� �Ҷ� ���� ����
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