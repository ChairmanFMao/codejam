#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		d.push_back(a);
	}

	int highest = 0;
	ll out = 0;
	while (!d.empty()) {
		if (d.front() < d.back()) {
			if (d.front() >= highest)
				out++;
			highest = max(highest, d.front());
			d.pop_front();
		} else {
			if (d.back() >= highest)
				out++;
			highest = max(highest, d.back());
			d.pop_back();
		}
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

