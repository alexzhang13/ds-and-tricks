#include <bits/stdc++.h>

using namespace std;

struct BIT {
	int N;
	vector<int> fenwick;
	void init (int N_) {N = N_; fenwick.assign(N, 0);}
	// largest exponent of 2 that divides n, aka least sig bit
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