#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long a, b;
		cin >> a >> b;

		if (a == 0) {
			cout << "1\n";
		}
		else {
			cout << (2 * b + a) + 1 << "\n";
		}
	}

	return 0;
}