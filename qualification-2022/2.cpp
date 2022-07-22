#include <bits/stdc++.h>
using namespace std;
#define ll long long

// We need to output a value less than or equal to each of them and it should sum to 1e6

void solve() {
	vector<int> c, m, y, k;
	for (int i = 0,a,b,d,e; i < 3; i++) {
		cin >> a >> b >> d >> e;
		c.push_back(a);
		m.push_back(b);
		y.push_back(d);
		k.push_back(e);
	}

	int cmin = *min_element(c.begin(),c.end());
	int mmin = *min_element(m.begin(),m.end());
	int ymin = *min_element(y.begin(),y.end());
	int kmin = *min_element(k.begin(),k.end());

	int total = 1e6;
	if (cmin + mmin + ymin + kmin < 1e6) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	vector<int> out(4,0), iter = {cmin,mmin,ymin,kmin};
	for (int i = 0; i < 4; i++) {
		out[i] = min(total, iter[i]);
		total -= min(total, iter[i]);
	}

	for (int i : out)
		cout << i << " ";
	cout << "\n";
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

