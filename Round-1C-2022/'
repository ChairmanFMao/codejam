#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Sum of all individual squares equals square of the sum
// add at most k elements
// adding a 1 adds 2 total + 1 to the sq of sm and 1 to sm of sq
// we can increase the sq of sm by total*even by adding that even to sm of sq

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll total = 0, stotal = 0;
	for (ll i : a) {
		total += i;
		stotal += i*i;
	}

	if (total*total == stotal) {
		cout << 0;
		return;
	}

	if (!total) {
		cout << "IMPOSSIBLE";
		return;
	}

	vector<int> out;
	bool flag = 1;
	while (k) {
		if (!(abs(stotal - total*total) % (total+total))) {
			for (int i : out)
				cout << i << " ";
			cout << (stotal - total*total) / (total+total);
			return;
		} else if (total != 1 && flag) {
			out.push_back(1-total);
			stotal += (1-total)*(1-total);
			total += (1-total);
		} else {
			out.push_back(1);
			stotal++;
			total++;
		}
		k--;
		flag = 0;
	}

	cout << "IMPOSSIBLE";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
}

