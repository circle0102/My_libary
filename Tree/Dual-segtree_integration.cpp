//U
template<typename T>
struct DualSegtree {
    struct Action {
        bool assign;    // trueなら「区間代入」
        T assign_val;   // 代入値
        T add;          // 加算値
        ll time;        // 代入のタイムスタンプ
        Action(): assign(false), assign_val(0), add(0), time(0) {}
    };

    int N, log, siz;
    ll timestamp = 1;          // 代入の順序管理用
    vector<Action> data;       // セグ木のタグ配列
    vector<T> init;            // 元の値（point query時に使用）

    DualSegtree(int n, T init_val = T()) {
        N = n;
        log = 0;
        while ((1 << log) < N) ++log;
        siz = 1 << log;
        data.assign(2*siz, Action());
        init.assign(siz, init_val);
    }

    DualSegtree(const vector<T>& v) {
        N = v.size();
        log = 0;
        while ((1 << log) < N) ++log;
        siz = 1 << log;
        data.assign(2*siz, Action());
        init.assign(siz, T());
        for (int i = 0; i < N; i++) init[i] = v[i];
    }

    // タグ a をノード k に合成して上書き
    void apply_node(int k, const Action& a) {
        data[k] = compose(a, data[k]);
    }

    // a を先に適用、その後 b を適用するときの合成結果
    // -> 代入が来たら古いタグをクリアし、加算は積み重ね
    static Action compose(const Action& a, const Action& b) {
        // a のあとに b を適用
        Action res;
        if (b.assign) {
            res.assign     = true;
            res.assign_val = b.assign_val;
            res.add        = b.add;
            res.time       = b.time;
        } else {
            res.assign     = a.assign;
            res.assign_val = a.assign_val;
            res.add        = a.add + b.add;
            res.time       = a.time;
        }
        return res;
    }

    // 区間 [l, r) にタグ a を設定
    void range_apply(int l, int r, const Action& a) {
        l += siz; r += siz;
        while (l < r) {
            if (l & 1) apply_node(l++, a);
            if (r & 1) apply_node(--r, a);
            l >>= 1; r >>= 1;
        }
    }

    // 区間代入 [l, r): a.assign = true
    void range_assign(int l, int r, T x) {
        Action a;
        a.assign     = true;
        a.assign_val = x;
        a.add        = 0;
        a.time       = timestamp++;
        range_apply(l, r, a);
    }

    // 区間加算 [l, r): a.assign = false
    void range_add(int l, int r, T x) {
        Action a;
        a.assign     = false;
        a.assign_val = 0;
        a.add        = x;
        a.time       = timestamp; // add は順序影響なし
        range_apply(l, r, a);
    }

    // 点 p の現在値を取得
    T get(int p) {
        int k = p + siz;
        Action acc;  // 蓄積タグ（初期化：identity）
        // ルートから葉までの経路上のタグを順に合成
        vector<int> path;
        for (int i = k; i > 0; i >>= 1) path.push_back(i);
        for (int i = path.size() - 1; i >= 0; --i) {
            acc = compose(data[path[i]], acc);
        }
        // 代入タグがあればそれ + 加算、なければ元の値 + 加算
        if (acc.assign) return acc.assign_val + acc.add;
        else             return init[p] + acc.add;
    }
};
