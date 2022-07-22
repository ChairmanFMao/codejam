#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

const int minCost = 6e8;

// Swap operations don't have cost
// Minimum range queries cost, larger ranges are cheaper
// n = 100 for all test cases as well
// Had a terrible time formatting all of the code to work

void swapPos(int a, int b) {
	cout << "S " << a << " " << b << endl;
	cout.flush();
	int c;
	cin >> c;
}

int minQ(int a, int b) {
	cout << "M " << a << " " << b << endl;
	cout.flush();
	int i;
	cin >> i;
	return i;
}

// I think you need to use binary search logic somewhere
// Potentially if you worked out some high numbers you could set it
// so that you could find the values of all the numbers
// Just build up the list using binary search for each of the minimum
// values, unsure about cost of this approach
// Looked at tutorial, kinda like what I was thinking
// I was overthinking it a little

int n;

void solve() {
	for (int i = 1; i < n; i++) {
		int j = minQ(i, n);
		if (i != j)
			swapPos(i,j);
	}

	cout << "D" << endl;
	cout.flush();
	int i;
	cin >> i;
}		

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	int t;
	cin >> t >> n;
	for (int i = 1; i <= t; ++i)
		solve();
}

