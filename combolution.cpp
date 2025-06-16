#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

struct Comb {
    int n;
    vector<mint> fact, ifact;
    Comb(int _n, int mod) : n(_n), fact(n+1), ifact(n+1) {
        mint::set_mod(mod);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; i--) ifact[i-1] = ifact[i] * i;
    }
    mint facto(int x) const {
        return (0 <= x && x <= n) ? fact[x] : mint(0);
    }
    mint inv(int x) const {
        return (0 < x && x <= n) ? fact[x-1] * ifact[x] : mint(0);
    }
    mint inv_fact(int x) const {
        return (0 <= x && x <= n) ? ifact[x] : mint(0);
    }
    mint C(int a, int b) const {
        if (b < 0 || b > a || a > n) return mint(0);
        return fact[a] * ifact[b] * ifact[a-b];
    }
};
int main(){
    //int mod=1000000007;
    //Comb comb(1000000, mod); 最大10^6
    //comb.facto(5);    ->  5!
    //comb.inv(5);    ->5^{-1}
    //comb.inv_fact(5);     ->(5!)^{-1}
    //comb.C(10, 3);    ->C(10,3) = 120
}
