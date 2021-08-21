#include <bits/stdc++.h>

using namespace std;


struct RMQ {
	int n; vector<int> seg;
	const int ID = 0; // at minimum, the length of a subsequence is 0 (-INF won't work here for example)
	void init(int n0) { n = n0; seg.assign(2 * n, ID); }
	void upd(int p, int v) {
		seg[p += n] = v;
		for(p /= 2; p; p /= 2) seg[p] = max(seg[2 * p], seg[2 * p + 1]);
	}
	int qry(int l, int r) {
		int ql = ID, qr = ID;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) ql = max(ql, seg[l++]);
			if(r & 1) qr = max(seg[--r], qr);
		}
		return max(ql, qr);
	}
} dp;


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

struct BIT {
	int N;
	vector<int> fenwick;
	void init (int N_) {N = N_; fenwick.assign(N, 0);}
	// largest exponent of 2 that divides n
	int lsb(int pos) {
    	return pos & -pos;
	}

	void update (int pos, int val) {
		while (pos <= N) {
			fenwick[pos] += val;
			pos += lsb(pos);
		}
	}

	int query (int pos) {
		int sum = 0;
		while (pos > 0) {
			sum += fenwick[pos];
			pos -= lsb(pos);
		}
		return sum;
	}

};