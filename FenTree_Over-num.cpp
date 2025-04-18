template <typename T>
struct fenwick_tree {
    vector<T> data;
    int N = 0;

    fenwick_tree() {
        data.resize(0, 0);
    }

    fenwick_tree(int n) {
        N = n;
        data.resize(n, 0);
    }

    void add(int i, T x) {
        assert(0 <= i && i < N);
        i++;
        while (i <= N) {
            data[i - 1] += x;
            i += i & -i;
        }
    }

    T sum(int r) {
        assert(0 <= r && r <= N);
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= N);
        return sum(r) - sum(l);
    }

    T get(int i) {
        return sum(i + 1) - sum(i);
    }

    void set(int i, T x) {
        add(i, x - get(i));
    }

    T operator[](int idx) {
        return get(idx);
    }

    // 転倒数を計算：配列 a の中の転倒数（0-indexed, 要座圧）
    static long long count_inversions(vector<int> a) {
        int n = a.size();
        // 値の範囲が広い場合は座標圧縮が必要
        vector<int> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int &x : a) {
            x = lower_bound(b.begin(), b.end(), x) - b.begin(); // 座圧
        }

        // BITで転倒数を数える
        fenwick_tree<int> bit(b.size());
        long long inv = 0;
        for (int i = n - 1; i >= 0; --i) {
            inv += bit.sum(a[i]);  // a[i] 未満の数の個数
            bit.add(a[i], 1);      // a[i] を1個追加
        }
        return inv;
    }
};
