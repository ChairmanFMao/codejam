#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int& i : numbers)
		cin >> i;

	sort(numbers.begin(),numbers.end());

	int out = 0, ptr = 0, current = 1;
	while (ptr < n) {
		if (numbers[ptr] >= current) {
			current++;
			out++;
		}
		ptr++;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

