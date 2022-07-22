#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We get TLE on test 2
// Still TLE on test 2 even with improvements
// Still TLE, I think I need to rethink my method drastically
// I need to think of a way without the dfs as it has factorial time

const int mxN = 100;
vector<string> s(mxN);
bool used[mxN+1];
int n, length;
map<char,int> seen;
char last;

bool dfs(string current, int id) {
	if (sz(current) == length) {
		cout << current;
		return 1;
	}
	used[id] = 1;
	
	bool out = 0;
	for (int i = 0; i < n && !out; i++)
		if (!used[i]) {
			bool good = 1;
			for (char c : s[i]) {
				if (seen[c] && c != last) {
					good = 0;
				} else if (!seen[c]) {
					seen[c] = i+10;
				}
				last = c;
			}
			if (good)
				out |= dfs(current+s[i], i);

			for (char c : s[i])
				if (seen[c] == i+10)
					seen[c] = 0;
			last = current[sz(current)-1];
		}

	used[id] = 0;
	return out;
}


void solve() {
	cin >> n;
	length = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		length += sz(s[i]);
	}

	last = ' ';
	cout << (dfs("", mxN) ? "" : "IMPOSSIBLE");
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


