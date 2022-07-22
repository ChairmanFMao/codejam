#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i <= r+r; i++) {
		if (i == 0) {
			cout << "..+";
			for (int j = 0; j < c-1; j++)
				cout << "-+";
		} else if (i == 1) {
			cout << "..|";
			for (int j = 0; j < c-1; j++)
				cout << ".|";
		} else if (i&1) {
			cout << "|";
			for (int j = 0; j < c; j++)
				cout << ".|";
		} else {
			cout << "+";
			for (int j = 0; j < c; j++)
				cout << "-+";
		}

		cout << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ":\n";
		solve();
	}
}

