#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> parent;
	vector<int> height;
	void init(int N) {
		parent.assign(N,-1);
		height.assign(N,0);
		for (int i = 0; i < N; ++i) {
			parent[i] = i;
			// height[i] = 0;
		}
	}

	int find(int node) {
		if (parent[node] != node) {
			parent[node] = find(parent[node]);
		}
		return parent[node];
	}

	void unite(int A, int B) {
		int rootA = find(A);
		int rootB = find(B);
		if (height[rootA] > height[rootB]) {
			parent[rootB] = rootA;
			height[rootA] = max(height[rootA], height[rootB] + 1);
		} else {
			parent[rootA] = rootB;
			height[rootB] = max(height[rootB], height[rootA] + 1);
		}
	}
};
