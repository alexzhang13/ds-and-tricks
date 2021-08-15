#include <bits/stdc++.h>
using namespace std;

int main () {
	int m,n;
	cin >> m >> n;
	vector<vector<pair<int, int>>> v(n);
	vector<int> id;
	while (m--) {
		int i, l, r;
		cin >> i >> l >> r;
		id.push_back(l);
		id.push_back(r);
		v[i - 1].push_back({ l,r });
	}
	sort(all(id));
	id.erase(unique(all(id)), id.end());
	for (int i = 0; i < n; i++) {
		for (auto& it : v[i]) {
			it.first = upper_bound(all(id), it.first) - id.begin();
			it.second = upper_bound(all(id), it.second) - id.begin();
		}
	}
}