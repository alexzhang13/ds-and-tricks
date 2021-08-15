#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
ll fact[N], inv[N], invfact[N];

void factInverse() {
	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (long long i = 2; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
		invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
	}
}
 
int add(int a, int b) {
	if ((a += b) >= MOD)
		a -= MOD;
	else if (a < 0)
		a += MOD;
	return a;
}
 
ll mul(int x, int y) {
	return (1LL * x * y) % MOD;
}
 
ll nCr(int n, int r) {
	if (r > n)
		return 0;
	return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}

int main () {
	factInverse();

	return 0;
}