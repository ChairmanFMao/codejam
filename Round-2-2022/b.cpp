#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This will definitely fail test case 2

void solve() {
	int r;
	cin >> r;

	set<pair<int,int> > real, fake;

	for (int i = -r; i <= r; i++) {
		for (int j = -r; j <= r; j++) {
			if (round(sqrt(i*i + j*j)) <= r)
				real.insert({i,j});
		}
	}

	for (int i = 0; i <= r; i++) {
		for (int j = -i; j <= i; j++) {
			int y = round(sqrt(i*i - j*j));
			fake.insert({j,y});
			fake.insert({j,-y});
			fake.insert({y,j});
			fake.insert({-y,j});
		}
	}
	
	cout << sz(real) - sz(fake) << "\n";
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

