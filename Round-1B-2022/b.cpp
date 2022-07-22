#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Need better way to decide wether to go down then up or up then down
// I think that O(n^2) will be fine due to 2 <= n <= 1000
// wa on test 1 - wrong answer not TLE
// This just does it greedily for the next one
// Can't seem to find a defying test case
// There is some kind of logic error
// This is just dp, I need to practice dp a lot
// I had to look at the solution to get the good dp solution
// Its all dp

const int mxN = 1e3;
ll dp[mxN+1][2];

void solve() {
	memset(dp, 0, sizeof dp);
	ll n, p;
	cin >> n >> p;
	vector<vector<ll> > x(n, vector<ll>(p));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < p; j++)
			cin >> x[i][j];
	vector<pair<ll,ll> > minMax(n+1);
	minMax[0] = {0,0};
	for (ll i = 0; i < n; i++)
		minMax[i+1] = {*min_element(all(x[i])), *max_element(all(x[i]))};

	for (ll i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + abs(minMax[i-1].second - minMax[i].first);
		dp[i][0] = min(dp[i][0], dp[i-1][1] + abs(minMax[i-1].first - minMax[i].first));
		dp[i][0] += minMax[i].second - minMax[i].first;

		dp[i][1] = dp[i-1][0] + abs(minMax[i-1].second - minMax[i].second);
		dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(minMax[i-1].first - minMax[i].second));
		dp[i][1] += minMax[i].second - minMax[i].first;
	}
	
	cout << min(dp[n][0],dp[n][1]) << "\n";
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

