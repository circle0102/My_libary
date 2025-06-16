#include <bits/stdc++.h>
using namespace std;

// Implicit Treapを使い、split/mergeで区間を切り出し、新しい文字列ノード群に置き換える。
// 各ノードにハッシュ値とサイズを保持し、マージ時にハッシュを再計算。

using ull = unsigned long long;
const ull BASE = 131;      // ハッシュの基数
vector<ull> pow_base;      // pow_base[i] = BASE^i

struct Node {
    char c;
    int prio, sz;
    ull hash;               // この部分木のハッシュ（mod 2^64）
    Node *l, *r;
    Node(char _c): c(_c), prio(rand()), sz(1), hash(_c), l(nullptr), r(nullptr) {}
};

int  sz(Node* t) { return t ? t->sz : 0; }
ull hsh(Node* t) { return t ? t->hash : 0; }

void upd(Node* t) {
    if (!t) return;
    t->sz   = 1 + sz(t->l) + sz(t->r);
    // こ↑こ↓：左ハッシュ * BASE^(1+右サイズ) + 自ノード * BASE^右サイズ + 右ハッシュ
    t->hash = (hsh(t->l) * pow_base[1 + sz(t->r)])
             + (ull(t->c) * pow_base[sz(t->r)])
             + hsh(t->r);
}

void split(Node* t, int k, Node*& a, Node*& b) {
    // 先頭k文字をaに、残りをbに
    if (!t) { a = b = nullptr; return; }
    if (sz(t->l) >= k) {
        split(t->l, k, a, t->l);
        b = t;
    } else {
        split(t->r, k - sz(t->l) - 1, t->r, b);
        a = t;
    }
    upd(t);
}

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->prio > b->prio) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

struct RollingHash {
    Node* root;
    RollingHash(const string& s) : root(nullptr) {
        int n = s.size();
        pow_base.resize(n+5);
        pow_base[0] = 1;
        for (int i = 1; i <= n+4; i++) pow_base[i] = pow_base[i-1] * BASE;
        // build
        for (char c : s) {
            root = merge(root, new Node(c));
        }
    }

    // [l, r) を s の文字列で置き換え
    void update(int l, int r, const string& s) {
        Node *a, *b, *c;
        split(root, l, a, b);           // a = [0,l), b = [l, end)
        split(b, r-l, b, c);            // b = [l,r), c = [r, end)
        // b を捨てて、s のノード列を構築してマージ
        Node* mid = nullptr;
        for (char ch : s) mid = merge(mid, new Node(ch));
        root = merge(a, merge(mid, c));
    }

    // [l, r) のハッシュを取得
    ull getHash(int l, int r) {
        Node *a, *b, *c;
        split(root, l, a, b);
        split(b, r-l, b, c);
        ull res = hsh(b);
        root = merge(a, merge(b, c));
        return res;
    }

    // 全体文字列を取得（デバッグ用）
    string toString() {
        string s;
        function<void(Node*)> dfs = [&](Node* t){
            if (!t) return;
            dfs(t->l);
            s.push_back(t->c);
            dfs(t->r);
        };
        dfs(root);
        return s;
    }
};
int main(){
    //string s = "abcdefg";
    //RollingHash rh(s);
    // 置き換え前のハッシュ
    //ull h1 = rh.getHash(2, 5);   // "cde"
    //cout << hex << h1 << "\n";

    //rh.update(2, 5, "XYZ");      // s = "abXYZfg"
    //cout << rh.toString() << "\n"; // 出力: abXYZfg

    //ull h2 = rh.getHash(2, 5);   // "XYZ"
}
