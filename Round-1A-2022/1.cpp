#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()

// A use of run length encoding

void solve() {
	string s, out = "";
	cin >> s;
	vector<pair<int,char>> v;
	int streak = 1;
	for (int i = 0; i < sz(s)-1; i++) {
		if (s[i] == s[i+1])
			streak++;
		else {
			v.push_back({streak,s[i]});
			streak = 1;
		}
	}
	v.push_back({streak,s[sz(s)-1]});

	for (int i = 0; i < sz(v); i++) {
		for (int j = 0; j < (i == sz(v)-1 || v[i].second > v[i+1].second ? v[i].first : 2*v[i].first); j++) {
			out += v[i].second;
		}
	}

	cout << out << "\n";
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

