#include <bits/stdc++.h>
using ll = long long;

static constexpr int MAXB = 60;
struct XorBasis {
    ll basis[MAXB];
    int sz;
    XorBasis() : sz(0) {
        std::fill(basis, basis + MAXB, 0);
    }
    bool insert(ll x) {
        for (int i = MAXB - 1; i >= 0; --i) {
            if (!(x & (1LL << i))) continue;
            if (!basis[i]) {
                basis[i] = x;
                ++sz;
                return true;
            }
            x ^= basis[i];
        }
        return false;
    }
    ll get_max() const {
        ll res = 0;
        for (int i = MAXB - 1; i >= 0; --i) {
            res = std::max(res, res ^ basis[i]);
        }
        return res;
    }
    bool can_represent(ll x) const {
        for (int i = MAXB - 1; i >= 0; --i) {
            if (!(x & (1LL << i))) continue;
            if (!basis[i]) return false;
            x ^= basis[i];
        }
        return true;
    }
    int rank() const {
        return sz;
    }
    ll kth(ll k) const {
        std::vector<ll> b;
        b.reserve(sz);
        for (int i = 0; i < MAXB; ++i) {
            if (basis[i]) b.push_back(basis[i]);
        }
        std::sort(b.begin(), b.end());
        ll res = 0;
        for (int i = 0; i < (int)b.size(); ++i) {
            if (k & (1LL << i)) res ^= b[i];
        }
        return res;
    }
    void merge(const XorBasis& other) {
        for (int i = 0; i < MAXB; ++i) {
            if (other.basis[i]) insert(other.basis[i]);
        }
    }
};

int main() {
    //XorBasis xb; 基底
    //xb.insert(v);　挿入
    //xb.rank()　基底ランク
    //xb.get_max()　最大xor
    //(xb.can_represent(n) nを作成可能か(bool)
    //xb.kth(K) k番目の最小xor 
    //xb.merge(xb2) マージ
    //xb.get_max() マージ後の最大XOR
}
