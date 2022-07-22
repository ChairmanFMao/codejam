#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// You are given the number of sides to play with
// Potentially dp?
// I can think of an O(n^2) solution for test set 1, need something better
const int mxN = 1e6;

void solve() {
	int n;
	cin >> n;
	
	int smallestP = 0;
	for (int i = 3; i*i <= n; i+=2)
		if (!(n % i)) {
			smallestP = i;
			break;
		}

	if (!smallestP) {
		cout << "1\n";
		return;
	}

	int times = n / smallestP;
	int best = 0;
	for (int i = 1; i <= 31; i++)
		if ((1<<i)-1 <= times)
			best = i;

	cout << best << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

