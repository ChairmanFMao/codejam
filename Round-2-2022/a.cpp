#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

ll n, k, target;
vector<pair<ll,ll> > out;
map<ll, pair<ll,ll> > dist;

void solve() {
	out.clear();
	cin >> n >> k;

	if (k < n-1 || k & 1) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	vector<ll> starts = {n/2+1, n + n/2, n+n-1 + n/2, n+n+n-2 + n/2};
	for (int i = 1; i < 9; i+=2) {
		ll jump = 4 * (n-1)-i, start = starts[(i-1)/2];
		while (jump >= 1) {
			dist[jump] = {start, start+jump};
			start += jump;
			jump -= 8;
		}
	}

	ll skip = n*n-1-k, maxDist = 4*(n-1)-1;
	while (skip) {
		if (maxDist <= skip) {
			out.push_back(dist[maxDist]);
			skip -= maxDist;
			maxDist -= 8;
		} else
			maxDist -= 2;
	}

	cout << sz(out) << "\n";
	for (pair<ll,ll> i : out)
		cout << i.first << " " << i.second << "\n";
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


