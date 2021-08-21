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
};