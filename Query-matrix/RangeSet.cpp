//区間を set で管理するやつ 

template<typename T>
struct RangeSet{
    set<pair<T, T>> st;
    T TINF;
    RangeSet(){
        TINF = numeric_limits<T>::max()/2;
        st.emplace(TINF, TINF);
        st.emplace(-TINF, -TINF);
    }
    // [l,r] がカバーされているか？
    bool covered(T l,T r){
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        return (ite->first <= l && r <= ite->second);
    }
    // x をカバーしているか？
    bool covered(T x){
        return covered(x, x);
    }
    // [l, r]がカバーされているなら，その区間を返す. されていないなら[-TINF,-TINF]を返す
    pair<T, T> covered_by(T l, T r){
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if(ite->first <= l && r <= ite->second) return *ite;
        return make_pair(-TINF, -TINF);
    }
    // x がカバーされているなら，その区間を返す. されていないなら[-TINF,-TINF]を返す
    pair<T, T> covered_by(T x){
        return covered_by(x, x);
    }
    // [l,r] をカバーする．その時のカバーされた要素の個数を返す．
    T insert(T l, T r){
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if(ite->first <= l && r <= ite->second) return T(0);
        T sum_erased = T(0);
        if(ite->first <= l && l <= ite->second + 1){
            l = ite->first;
            sum_erased += ite->second - ite->first + 1;
            ite = st.erase(ite);
        }else ite = next(ite);
        while(r > ite->second){
            sum_erased += ite->second - ite->first + 1;
            ite = st.erase(ite);
        }
        if(ite->first - 1 <= r && r <= ite->second){
            sum_erased += ite->second - ite->first + 1;
            r = ite->second;
            st.erase(ite);
        }
        st.emplace(l, r);
        return r - l + 1 - sum_erased;
    }
    // x をカバーする．その時のカバーされた要素の個数を返す．
    T insert(T x){
        return insert(x, x);
    }
    // [l,r] を消去する．その時の消去された要素の個数を返す．
    T erase(T l, T r){
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if(ite->first <= l && r <= ite->second){
            if(ite->first < l) st.emplace(ite->first, l - 1);
            if(r < ite->second) st.emplace(r + 1, ite->second);
            st.erase(ite);
            return r - l + 1;
        }
        T ret=T(0);
        if(ite->first <= l && l <= ite->second){
            ret += ite->second - l + 1;
            if(ite->first < l) st.emplace(ite->first, l - 1);
            ite = st.erase(ite);
        }else ite = next(ite);
        while(ite->second <= r){
            ret += ite->second - ite->first + 1;
            ite = st.erase(ite);
        }
        if(ite->first <= r && r <= ite->second){
            ret += r - ite->first + 1;
            if(r < ite->second) st.emplace(r + 1, ite->second);
            st.erase(ite);
        }
        return ret;
    }
    // x を消去する．その時の消去された要素の個数を返す．
    T erase(T x){
        return erase(x, x);
    }
    // 区間の個数を出力
    int size(){
        return (int)st.size() - 2;
    }
    // [x,~) の mex を出力
    int mex(T x = 0){
        auto ite = prev(st.lower_bound({x + 1, x + 1}));
        if(ite->first <= x && x <= ite->second) return ite->second + 1;
        else return x;
    }
    // デバッグ
    void output(){
        cout<<"RangeSet : ";
        for(auto &p : st){
            if(p.first == -TINF || p.second == TINF) continue;
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout<<"\n";
    }
};

//sample https://yukicoder.me/problems/1601
int main(){
    long long D; cin >> D;
    int Q; cin >> Q;
    RangeSet<long long> rs;
    long long mx = 0;
    for(int i = 0; i < Q; ++i){
        long long A, B; cin >> A >> B;
        rs.insert(A, B);
        auto [C, D] = rs.covered_by(A, B);
        mx = max(mx, D - C + 1);
        cout << mx << "\n";
    }
}