//U
template <typename T>
struct fenwick_tree {
    vector<T> data;
    int N = 0;

    fenwick_tree() {}
    fenwick_tree(int n) : N(n), data(n, 0) {}

    // i 番目（0-indexed）に x を加算
    void add(int i, T x) {
        assert(0 <= i && i < N);
        for (++i; i <= N; i += i & -i) data[i-1] += x;
    }

    // [0, r) の和
    T sum(int r) const {
        assert(0 <= r && r <= N);
        T s = 0;
        while (r > 0) {
            s += data[r-1];
            r -= r & -r;
        }
        return s;
    }

    // [l, r) の和
    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= N);
        return sum(r) - sum(l);
    }

    // i 番目の値を取得
    T get(int i) const {
        return sum(i+1) - sum(i);
    }

    // i 番目の値を x にセット
    void set(int i, T x) {
        add(i, x - get(i));
    }

    // 転倒数を数える静的メソッド
    // 配列 a の転倒数を O(n log n) で返す
    static long long inversion_count(vector<T> a) {
        int n = a.size();
        // 座標圧縮
        vector<T> xs = a;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        // 圧縮後の値域で BIT を用意
        fenwick_tree<long long> bit(xs.size());

        long long inv = 0;
        // 右から左へスキャンし、「より小さい要素の個数」を足し合わせ
        for (int i = n - 1; i >= 0; --i) {
            int idx = int(lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin());
            inv += bit.sum(idx);  // 圧縮値 < idx の要素数
            bit.add(idx, 1);
        }
        return inv;
    }
};
