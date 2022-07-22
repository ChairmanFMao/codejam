#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at neal wu and tmwilliam solutions - just need to consider
// the points where the tree splits really

void solve() {
	int n;
	cin >> n;
	// We store the fun values for each node and where it points to
	vector<int> fun(n), ptr(n);
	// This stores all of the children for each node
	vector<vector<int>> children(n);
	for (int& i : fun)
		cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> ptr[i];
		// We have to decrement the values that are pointing to because they are indexed with 1 as the smallest value
		ptr[i]--;
		// If it is pointing to a valid index we will push it back as a child
		if (ptr[i] >= 0)
			children[ptr[i]].push_back(i);
	}

	// Stores the value of the worst node above
	vector<int> up(n,0);
	ll out = 0;
	// We can build up the tree by going from the leaves first
	for (int i = n-1; ~i; i--) {
		vector<int> current;
		// Goes through the children of the node and adds their up values
		// to a list
		for (int child : children[i])
			current.push_back(up[child]);
		
		// Sorts the up values of the children
		sort(current.begin(),current.end());
		
		// If there is more than one starting point then every node after
		// the first has its up value added together
		while ((int)current.size() > 1) {
			out += current.back();
			current.pop_back();
		}
		
		// If the node has no up children then we just set current to 0
		if (!((int)current.size()))
			current = {0};
		
		// We then update the up value for the current node for future use
		up[i] = max(current[0],fun[i]);
	}
	
	// This goes through all of the up vector and if a node points to the void then its value is added to out as they aren't properly processed in the normal loop
	for (int i = 0; i < n; i++)
		if (ptr[i] == -1)
			out += up[i];

	cout << out << '\n';
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

