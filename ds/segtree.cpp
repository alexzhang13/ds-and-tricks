#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template <typename T> struct Seq {
    const T ID = 0;
    T comb(T a, T b) {
        return a+b;
    }
    int n; vector<T> seg;

    void init(int _n) {n = _n; seg.assign(2*n, ID); }
    void pull(int p) { seg[p] = comb(seg[2*p], seg[2*p+1]); }
    void update(int p, T val) { // set pos to val
        seg[p += n] = val;
        for (p /= 2; p > 0; p /= 2) pull(p);
    }

    T query(int l, int r) {
        T lseg = ID; T rseg = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) lseg = comb(lseg, seg[l++]);
            if (r&1) rseg = comb(rseg, seg[--r]);
        }
        return comb(lseg, rseg);
    }
};

Seq<ll> st;

int main () {
    int n,q;
    cin >> n >> q;
    st.init(n+1); int a;
    for (int i = 1; i <= n; i++) {
        cin >> a; st.update(i, a);
    }
    int t,l,r;
    for (int i = 0; i < q; i++) {
        cin >> t >> l >> r;
        if (t == 1) st.update(l,r);
        if (t == 2) cout << st.query(l,r) << endl;
    }
    return 0;
    
}