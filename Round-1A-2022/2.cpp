#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Numbers between 1 and 1e9 and all should be distinct
// You only need to do it with n = 100
// Looked at a youtube video, saw the powers of two and I knew
// Just think about powers of two!

void solve() {
	int n;
	cin >> n;
	ll total = 0;
	for (int i = 0; i < 30; i++) {
		total += 1<<i;
		cout << (1<<i) << " ";
	}
	vector<int> useable;
	for (int i = 129; i < 199; i++) {
		cout << i << " ";
		useable.push_back(i);
		total += i;
	}
	
	// Flushes everything out of the buffer
	cout << endl;
	
	for (int i = 0,a; i < n; i++) {
		cin >> a;
		total += a;
		useable.push_back(a);
	}

	total >>= 1;
	vector<int> out;
	sort(all(useable));
	while (total > (ll)1e9 && useable.size()) {
		total -= useable.back();
		out.push_back(useable.back());
		useable.pop_back();
	}

	for (int i = 0; i < 30; i++)
		if (total & (1<<i))
			out.push_back(1<<i);

	for (int i : out)
		cout << i << " ";

	cout << endl;
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

