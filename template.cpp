#pragma GCC optimize("O3")
#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using it=__int128;
using vl=vector<ll>;
using vvl=vector<vl>;
using vvvl=vector<vvl>;
using vvvvl=vector<vvvl>;
using vvvvvl=vector<vvvvl>;
using vi=vector<it>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vvvvvi=vector<vvvvi>;
using vd=vector<double>;
using vvd=vector<vd>;
using vvvd=vector<vvd>;
using vvvvd=vector<vvvd>;
using vvvvvd=vector<vvvvd>;
using vs=vector<string>;
using vvs=vector<vs>;
using vvvs=vector<vvs>;
using pls=pair<ll,string>;
using vpls=vector<pls>;
using vvpls=vector<vpls>;
using vvvpls=vector<vvpls>;
using pss=pair<string,string>;
using vpss=vector<pss>;
using vvpss=vector<vpss>;
using vvvpss=vector<vvpss>;
using ql=queue<ll>;
using dql=deque<ll>;
using pql=priority_queue<ll,vl,greater<>>;
using pqbl=priority_queue<ll>;
using sl=set<ll>;
using vsl=vector<sl>;
using vvsl=vector<vsl>;
using vvvsl=vector<vvsl>;
using spls=set<pls>;
using vspls=vector<spls>;
using spss=set<pss>;
using vspss=vector<spss>;
using mll=map<ll,ll>;
using vmll=vector<mll>;
using mls=map<ll,string>;
using vmls=vector<mls>;
using msl=map<string,ll>;
using vmsl=vector<msl>;
using mss=map<string,string>;
using vmss=vector<mss>;
#define rep(i,n) for(ll i=0;i<n;++i)
#define reph(i,n) for(ll i=0;i<=n;++i)
#define repr(i,a,b) for(ll i=a;i<b;++i)
#define reprh(i,a,b) for(ll i=a;i<=b;++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
struct ob5{
    ll a,b,c,d,e;
    friend auto operator<=>(const ob5&x,const ob5&y)=default;
};
struct ob4{
    ll a,b,c,d;
    friend auto operator<=>(const ob4&x,const ob4&y)=default;
};
struct ob3{
    ll a,b,c;
    friend auto operator<=>(const ob3&x,const ob3&y)=default;
};
struct ob2{
    ll a,b;
    friend auto operator<=>(const ob2&x,const ob2&y)=default;
};
constexpr ll mod=998244353LL;
constexpr ll mod2=1000000007LL;
constexpr ll inf=1LL<<60;
constexpr ll inf2=1LL<<30;
constexpr ll minf=-inf;
constexpr ll minf2=-inf2;
constexpr ll e3=1000LL;
constexpr ll e6=1000000LL;
constexpr ll e9=1000000000LL;
constexpr ll e10=10000000000LL;
constexpr ll e12=1000000000000LL;
constexpr ll e15=1000000000000000LL;
constexpr ll e18=1000000000000000000LL;
constexpr ob2 d4[]={{-1,0},{0,-1},{0,1},{1,0}};
constexpr ob2 d8[]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
constexpr char Alph[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr char alph[]="abcdefghijklmnopqrstuvwxyz";
//レーべンシュタイン距離--------------------------------------------------------------------------
int LP(string &s,string &t){
    int j=1,k=1;
    vector<vector<int>> dp((int)s.size()+5,vector<int>((int)t.size()+5));
    for(j=1;j<=(int)s.size();j++){
        dp[j][0]=j;
    }
    for(k=1;k<=(int)t.size();k++){
        dp[0][k]=k;
    }
    for(j=1;j<=(int)s.size();j++){
        for(k=1;k<=(int)t.size();k++){
            int m=min(dp[j-1][k]+1,dp[j][k-1]+1);
            if(s[j-1]==t[k-1]){
                m=min(m,dp[j-1][k-1]);
                dp[j][k]=m;
            }else{
                m=min(m,dp[j-1][k-1]+1);
                dp[j][k]=m;
            }
        }
    }
    return dp[s.size()][t.size()];
}
//タイマー---------------------------------------------------------------
class Timer{
    chrono::system_clock::time_point start;
    public:
    Timer():start(chrono::system_clock::now()){}
    double count(){
        chrono::duration<double> Time_=chrono::system_clock::now()-start;
        return Time_.count();
    }
    bool isunder(double x){
        return (this -> count())<x;
    }
};
//累世和---------------------------------------------------------------
template<typename T> struct sum_vec{
    vector<T> data;
    vector<T> sum;
    int N;
    sum_vec(const vector<T> &vec){
        int N=vec.size();
        data.resize(N);
        sum.resize(N+1,0);
        for(int i=0;i<N;i++){
            data[i]=vec[i];
            sum[i+1]=sum[i]+data[i];
        }
    }
    sum_vec(int n){
        N=n;
        data.resize(N,0);
        sum.resize(N,0);
    }
    sum_vec(){
        N=0;
    }
    void cal(){
        sum[0]=0;
        for(int i=0;i<N;i++){
            sum[i+1]=data[i]+sum[i];
        }
        return;
    }
    T cul_sum(int l,int r){
        return sum[r]-sum[l];
    }
    void push_back(T x){
        data.push_back(x);
        T b=sum.back();
        sum.push_back(b+x);
        N++;
    }
    void pop_back(){
        assert(1<=(int)data.size());
        data.pop_back();
        sum.pop_back();
    }
};
//Mod Int----------------------------------------------------------------
struct modint {
    using ll = long long;
    ll num;
    static ll mod;

    // コンストラクタ
    modint() : num(0) {}
    modint(ll n) {
        num = normalize(n);
    }

    // normalize：負の数やmod超えを処理
    static ll normalize(ll n) {
        n %= mod;
        if (n < 0) n += mod;
        return n;
    }

    // MOD設定（必要なら）
    static void set_mod(ll m) {
        mod = m;
    }

    // 演算子オーバーロード
    modint& operator+=(const modint& rhs) {
        num += rhs.num;
        if (num >= mod) num -= mod;
        return *this;
    }

    modint& operator-=(const modint& rhs) {
        num -= rhs.num;
        if (num < 0) num += mod;
        return *this;
    }

    modint& operator*=(const modint& rhs) {
        num = (num * rhs.num) % mod;
        return *this;
    }

    modint operator+(const modint& rhs) const {
        modint res = *this;
        res += rhs;
        return res;
    }

    modint operator-(const modint& rhs) const {
        modint res = *this;
        res -= rhs;
        return res;
    }

    modint operator*(const modint& rhs) const {
        modint res = *this;
        res *= rhs;
        return res;
    }

    bool operator==(const modint& rhs) const {
        return num == rhs.num;
    }

    bool operator!=(const modint& rhs) const {
        return num != rhs.num;
    }

    // 除算（逆元使用）
    modint inv() const {
        return pow(mod - 2); // Fermatの小定理（modが素数のとき）
    }

    modint pow(ll e) const {
        modint res = 1, base = *this;
        while (e) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }

    modint& operator/=(const modint& rhs) {
        return *this *= rhs.inv();
    }

    modint operator/(const modint& rhs) const {
        modint res = *this;
        res /= rhs;
        return res;
    }

    explicit operator ll() const {
        return num;
    }
};
//にぶたん-------------------------------------------------------------------------
template<class T> 
int search_min(vector<T> &vec, bool(*check)(T)){
    int N=(int)vec.size();
    int ok=N;
    int ng=-1;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(check(vec[mid])){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
template<class T>
int search_max(vector<T> &vec,bool(*check)(T)){
    int ok=-1;
    int ng=(int)vec.size();
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
//以下半開区間[l,r)についての二分探索
ll search_min(ll l,ll r,bool(*check)(ll)){
    ll ok=r;
    ll ng=l-1;
    while(abs(ok-ng)>1){
        ll mid=ok/2+ng/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
ll search_max(ll l,ll r,bool(*check)(ll)){
    ll ok=l-1;
    ll ng=r;
    while(abs(ok-ng)){
        ll mid=ok/2+ng/2;
        if(check(mid)){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
int comp;
bool check(int ai){
    if(comp<=ai){
        return true;
    }
    return false;
}
//確率pでtrueを返す関数--------------------------------------------------------
bool prob(double p){
  static mt19937_64 mt64(0);
  uniform_real_distribution<double> uni(0.0, 1.0);
  if(p>=uni(mt64)){
    return true;
  }
  return false;
}
//乱数生成-------------------------------------------------------------
class Random_Gen{
    random_device seed_gen;
    mt19937 engine;
    uniform_int_distribution<int64_t> dist;
    public:
        // Constructor [l,r]で生成する値の範囲を指定
        Random_Gen() : engine(seed_gen()) {}
        Random_Gen(int64_t l, int64_t r) : engine(seed_gen()), dist(l,r) {}
        
        // 現在の生成する値の範囲をstd::pairで返す
        pair<int64_t,int64_t> get_range(){
            return make_pair(dist.min(),dist.max());
        }
        // 生成する値の範囲を[l,r]に変更する
        void set_range(int64_t l, int64_t r){
            uniform_int_distribution<int64_t>::param_type Param(l,r);
            dist.param(Param);
        }
        // [l,r]内の一様分布の整数を返す
        int64_t gen(){
            return dist(engine);
        }
        int64_t operator()(){ return gen(); }
};
//N進数構造体-------------------------------------------------------------------
struct BaseN{
    ll num;
    string snum;
    int base=10;
    BaseN(){
        num=0;
        snum="0";
    }
    BaseN(int bas){
        num=0;
        base=bas;
        snum="0";
    }
    string to_base(ll num){
        string ret="";
        ll divi=base;
        while(num!=0){
            ret.push_back('0'+num%base);
            num-=num%divi;
            num/=base;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    BaseN(int bas,ll n){
        base=bas;
        num=n;
        snum=to_base(n);
    }
    bool operator==(const BaseN &other){
        return num==other.num;
    }
    bool operator!=(const BaseN &other){
        return num!=other.num;
    }
    BaseN operator+(const BaseN &other){
        BaseN ret(base,num+other.num);
        return ret;
    }
    BaseN operator+(const int &other){
        BaseN ret(base,num+other);
        return ret;
    }
    BaseN operator-(const BaseN &other){
        BaseN ret(base,num-other.num);
        return ret;
    }
    BaseN operator-(const int &other){
        BaseN ret(base,num+other);
        return ret;
    }
    void operator++(){
        num++;
        snum=to_base(num);
        return;
    }
    void operator--(){
        num--;
        snum=to_base(num);
        return;
    }

};
//hush string--------------------------------------------------------
struct HashString{
    using ll=long long;
    int N=0;
    vector<pair<ll,ll>> hash_data;
    string str;
    const ll mod=998244353;
    const ll mod2=79020979;
    const ll r=2092427;
    const ll r2=870083;
    ll mypow(ll x,ll n,ll MOD){
        ll ret=1;
        while(n>0){
            if(n&1){
                ret=ret*x%MOD;
            }
            x=x*x%MOD;
            n>>=1;
        }
        return ret;
    }
    HashString(){
        N=0;
        str="";
        hash_data.resize(1,make_pair(0,0));
    }
    HashString(const string &s){
        N=s.size();
        hash_data.resize(N+1,make_pair(0,0));
        str=s;
        for(int i=0;i<N;i++){
            hash_data[i+1].first=hash_data[i].first+s[i]*mypow(r,i+1,mod);
            hash_data[i+1].second=hash_data[i].second+s[i]*mypow(r2,i+1,mod2);
            hash_data[i+1].first%=mod;
            hash_data[i+1].second%=mod2;
        }
    }
    HashString(const HashString &hs){
        N=hs.N;
        str=hs.str;
        hash_data=hs.hash_data;
    }
    pair<ll,ll> substr_hash(int left,int right){
        pair<ll,ll> ret=hash_data[right];
        ret.first-=hash_data[left].first-mod;
        ret.second-=hash_data[left].second-mod2;
        ret.first%=mod;
        ret.second%=mod2;
        ret.first*=mypow(r,5000000-left,mod);
        ret.second*=mypow(r2,5000000-left,mod2);
        ret.first%=mod;
        ret.second%=mod2;
        return ret;
    }
    int size(){
        return str.size();
    }
    void print_hash(int left,int right){
      cout<<substr_hash(left,right).first<<" "<<substr_hash(left,right).second<<'\n';
    }
};
istream& operator>>(istream& is, HashString& hs) {
    is >> hs.str;
    hs.N=hs.str.size();
    hs.hash_data.resize(hs.N+1,make_pair(0,0));
    for(int i=0;i<hs.N;i++){
        hs.hash_data[i+1].first=hs.hash_data[i].first+hs.str[i]*hs.mypow(hs.r,i+1,hs.mod);
        hs.hash_data[i+1].second=hs.hash_data[i].second+hs.str[i]*hs.mypow(hs.r2,i+1,hs.mod2);
        hs.hash_data[i+1].first%=hs.mod;
        hs.hash_data[i+1].second%=hs.mod2;
    }
    return is;
}
//ランレングス圧縮--------------------------------------------------------------------
template<typename v,typename val>
vector<pair<val,long long>> RunLength(v &vec,val tmp){
    vector<pair<val,long long>> ret;
    if((int)vec.size()==0){
        return ret;
    }
    ret.push_back(make_pair(vec[0],1));
    for(int i=1;i<(int)vec.size();i++){
        if(vec[i]==ret.back().first){
            ret.back().second++;
        }else{
            ret.push_back(make_pair(vec[i],1));
        }
    }
    return ret;
}
//トライ木-------------------------------------------------------------
struct TrieNode{
    char ch;
    map<char,TrieNode *> chi;
    int cnt=0;
    int isend=0;
    int during=0;
    TrieNode(char c){
        ch=c;
    }
};
using pn=TrieNode *;
struct TrieTree{
    map<char,pn> root;
    void insert(const string &s){
        int N=(int)s.size();
        if(s.empty()){
            return;
        }
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            root[s[0]]=new TrieNode(s[0]);
            now=root[s[0]];
        }
        for(int i=0;i<N-1;i++){
            now->cnt++;
            now->during++;
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                now->chi[s[i+1]]=new TrieNode(s[i+1]);
                now=now->chi[s[i+1]];
            }
        }
        now->cnt++;
        now->isend++;
        return;
    }
    bool find(const string &s){
        if(s.empty()){
            return false;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return false;
        }
        for(int i=0;i<N-1;i++){
            if(!(now->during)){
                return false;
            }
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return false;
            }
        }
        if(now->isend){
            return true;
        }else{
            return false;
        }
    }
    bool prefix_find(const string &s){
        if(s.empty()){
            return false;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return false;
        }
        for(int i=0;i<N-1;i++){
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return false;
            }
        }
        return true;
    }
    int prefix_count(const string &s){
        if(s.empty()){
            return 0;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return 0;
        }
        for(int i=0;i<N-1;i++){
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return 0;
            }
        }
        return now->cnt;
    }
    bool erase(const string &s){
        if (!find(s)) {
            return false; // 存在しない単語は削除できない
        }   

        int N = s.size();
        vector<pn> path; // たどったノードを保存
        pn now = root[s[0]];

        path.push_back(now);
        for (int i = 1; i < N; i++) {
            now = now->chi[s[i]];
            path.push_back(now);
        }
        // 逆順に削除処理を行う
        for (int i = N - 1; i >= 0; i--) {
            now = path[i];
            now->cnt--;  // cntを減算
            if (now->cnt <= 0) { // もう使われていなければ削除
                if (i > 0) {
                    path[i - 1]->chi.erase(s[i]);
                    delete now;
                } else {
                    root.erase(s[0]);
                    delete now;
                }
            }
        }
 
        return true;
    } 
    
};
//双対セグ木-----------------------------------------------------
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
//フェニック木+転倒数---------------------------------------------------
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
//セグ木--------------------------------------------------------
template <class S, S(*op)(S,S), S(*e)()> struct segtree{
    vector<S> d;
    int size;
    int N;
    int log;
    //log計算
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    void update(int p){
        d[p]=op(d[p*2],d[p*2+1]);
    }
    segtree(int n){
        log = ceil_pow2(n);
        size = 1 << log;
        d.resize(size*2+1,e());
        N=n;
    }
    void set(int p,S x){
        assert(0<=p && p<N);
        p+=size;
        d[p]=x;
        for(int i=1;i<=log;i++){
            update(p>>i);
        }
        return;
    }
    S get(int p){
        assert(0<=p && p<N);
        return d[p+size];
    }
    S prod(int l,int r){
        assert(0<=l && l<=r && r<=N);
        S sml=e();
        S smr=e();
        l+=size;
        r+=size;
        while(l<r){
            if(l & 1){
                sml=op(sml,d[l++]);
            }
            if(r & 1){
                smr = op(d[--r], smr);
            }
            l >>=1;
            r >>=1;
        }
        return op(sml,smr);
    }
    S all_prod(){
        return d[1];
    }
    S operator[](int idx){
        return get(idx);
    }
};
//union-find+kruskal--------------------------------------------
struct UnionFind {
    int N;
    vector<int> par, rank, siz;
    int cnt;
    UnionFind(int n) {
        assert(0 <= n);
        N = n;
        cnt = n;
        par.assign(N, -1);
        rank.assign(N, 0);
        siz.assign(N, 1);
    }
    // x の根を返す（経路圧縮あり）
    int leader(int x) {
        assert(0 <= x && x < N);
        return par[x] < 0 ? x : par[x] = leader(par[x]);
    }
    // 同じ集合か？
    bool same(int x, int y) {
        assert(0 <= x && x < N);
        assert(0 <= y && y < N);
        return leader(x) == leader(y);
    }
    // x, y をマージし、根を返す
    int merge(int x, int y) {
        assert(0 <= x && x < N);
        assert(0 <= y && y < N);
        x = leader(x);
        y = leader(y);
        if (x == y) return x;
        --cnt;
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
        siz[x] += siz[y];
        return x;
    }
    // x の集合のサイズ
    int size(int x) {
        assert(0 <= x && x < N);
        return siz[leader(x)];
    }
    // 現在のグループ数
    int count_groups() const {
        return cnt;
    }
    // 各要素の属するグループをまとめて返す
    vector<vector<int>> groups() {
        vector<vector<int>> m(N);
        for (int v = 0; v < N; v++) {
            m[leader(v)].push_back(v);
        }
        vector<vector<int>> res;
        for (auto &grp : m) if (!grp.empty()) res.push_back(grp);
        return res;
    }
};

// ---------- Kruskal 法用の Edge と kruskal 関数 ----------
struct Edge {
    int u, v;
    ll weight;
    bool operator<(Edge const& o) const {
        return weight < o.weight;
    }
};

// n: 頂点数, edges: (u, v, weight) のリスト
// 最小全域木の重み合計を返す
ll kruskal(int n, vector<Edge>& edges) {
    UnionFind uf(n);
    sort(edges.begin(), edges.end());
    ll total_weight = 0;
    for (auto const& e : edges) {
        if (!uf.same(e.u, e.v)) {
            uf.merge(e.u, e.v);
            total_weight += e.weight;
        }
    }
    return total_weight;
}
//BFS DFS-----------------------------------------------------------
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS: ";
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            cout << cur << " ";
            for (int nb : adj[cur]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        cout << "\n";
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        cout << "DFS: ";
        while (!s.empty()) {
            int cur = s.top(); s.pop();
            if (!visited[cur]) {
                visited[cur] = true;
                cout << cur << " ";
            }
            for (auto it = adj[cur].rbegin(); it != adj[cur].rend(); ++it) {
                if (!visited[*it]) s.push(*it);
            }
        }
        cout << "\n";
    }
};
//二部グラフ判定------------------------------------------------------
class BipartiteGraph {
    int V;
    vector<vector<int>> adj;
public:
    BipartiteGraph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isBipar() {
        vector<int> color(V, -1);
        queue<int> q;
        for (int st = 0; st < V; ++st) {
            if (color[st] != -1) continue;
            color[st] = 0;
            q.push(st);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int nb : adj[cur]) {
                    if (color[nb] == -1) {
                        color[nb] = 1 - color[cur];
                        q.push(nb);
                    } else if (color[nb] == color[cur]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//トポロジカルソート-------------------------------------------------------
class DirectedGraph {
    int V;
    vector<vector<int>> adj;
public:
    DirectedGraph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    vector<int> topologicalSort() {
        vector<int> inDeg(V, 0);
        for (int u = 0; u < V; ++u)
            for (int v : adj[u])
                ++inDeg[v];
        queue<int> q;
        for (int i = 0; i < V; ++i)
            if (inDeg[i] == 0) q.push(i);
        vector<int> res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            for (int v : adj[u]) {
                if (--inDeg[v] == 0)
                    q.push(v);
            }
        }
        if ((int)res.size() != V)
            throw runtime_error("Graph has a cycle. Topo sort not possible.");
        return res;
    }
};
//GridBFS-------------------------------------------------------------
struct GridBFS {
    int H, W;
    vector<string> grid;
    vector<vector<int>> dist;

    // dx, dy: 上下左右
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    GridBFS(int H, int W, const vector<string>& grid)
        : H(H), W(W), grid(grid), dist(H, vector<int>(W, -1)) {}

    // (si, sj) を起点に BFS 実行
    void bfs(int si, int sj) {
        assert(0 <= si && si < H && 0 <= sj && sj < W);
        // 初期化
        for (int i = 0; i < H; ++i)
            fill(dist[i].begin(), dist[i].end(), -1);

        queue<pair<int,int>> q;
        if (grid[si][sj] == '#') return;  // 壁からは出発不可
        dist[si][sj] = 0;
        q.emplace(si, sj);

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (grid[ni][nj] == '#') continue;      // 壁はスキップ
                if (dist[ni][nj] != -1) continue;      // 既訪問
                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
            }
        }
    }

    // (ti, tj) に到達可能か？
    bool reachable(int ti, int tj) const {
        assert(0 <= ti && ti < H && 0 <= tj && tj < W);
        return dist[ti][tj] != -1;
    }

    // (ti, tj) までの最短距離。到達不可なら -1 を返す
    int distance(int ti, int tj) const {
        assert(0 <= ti && ti < H && 0 <= tj && tj < W);
        return dist[ti][tj];
    }
};
//ダイクストラ-----------------------------------------------------------------------------
const int INF = 1e9;
const int MAXN = 500; // 必要に応じて調整

struct daijkstra {
    int n;
    vector<int> adjs[MAXN];
    int cost[MAXN][MAXN], cap[MAXN][MAXN];
    int flow[MAXN][MAXN];
    int dist[MAXN], parent[MAXN], pi[MAXN];  // shortest path用

    daijkstra(int n_) : n(n_) {
        memset(cost, 0, sizeof(cost));
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(pi, 0, sizeof(pi));
    }

    void add_edge(int u, int v, int c, int w) {
        adjs[u].push_back(v);
        adjs[v].push_back(u); // 逆辺も必要（残余グラフ用）
        cap[u][v] = c;
        cost[u][v] = w;
        cost[v][u] = -w;
    }

    inline int pot(int u, int v) const {
        return dist[u] + pi[u] - pi[v];
    }

    int dijkstra(int src, int dest) {
        memset(dist, 0x3f, sizeof(dist));
        memset(parent, -1, sizeof(parent));

        priority_queue<pair<int, int>> q;
        q.emplace(0, src);
        dist[src] = 0;

        while (!q.empty()) {
            int curr = q.top().second;
            q.pop();

            if (parent[curr] >= 0) continue;
            parent[curr] = -parent[curr] - 1;

            for (int adj : adjs[curr]) {
                if (parent[adj] >= 0) continue;

                if (flow[adj][curr] && pot(curr, adj) - cost[adj][curr] < dist[adj]) {
                    dist[adj] = pot(curr, adj) - cost[adj][curr];
                    parent[adj] = -curr - 1;
                    q.emplace(-dist[adj], adj);
                }

                if (flow[curr][adj] < cap[curr][adj] && pot(curr, adj) + cost[curr][adj] < dist[adj]) {
                    dist[adj] = pot(curr, adj) + cost[curr][adj];
                    parent[adj] = -curr - 1;
                    q.emplace(-dist[adj], adj);
                }
            }
        }

        for (int i = 0; i < n; ++i)
            pi[i] += dist[i];

        return dist[dest];
    }

    pair<int, int> mcmf(int src, int sink) {
        memset(flow, 0, sizeof(flow));
        memset(pi, 0, sizeof(pi));

        int minCost = 0, maxFlow = 0;

        while (dijkstra(src, sink) < INF) {
            int bot = INF;

            for (int v = sink, u = parent[v]; v != src; u = parent[v = u]) {
                bot = min(bot, flow[v][u] ? flow[v][u] : cap[u][v] - flow[u][v]);
            }

            for (int v = sink, u = parent[v]; v != src; u = parent[v = u]) {
                if (flow[v][u]) {
                    flow[v][u] = false;
                    minCost -= cost[v][u];
                } else {
                    flow[u][v] = true;
                    minCost += cost[u][v];
                }
            }

            maxFlow += bot;
        }

        return make_pair(minCost, maxFlow);
    }
};
//重みつきuf--------------------------------------------
template<class Abel> struct WeightUnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    WeightUnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
//遅延セグ木-----------------------------------------------------------
namespace internal {

#if __cplusplus >= 201703L

using std::bit_ceil;

#else

// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < n) x <<= 1;
    return x;
}

#endif

// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1u << x))) x++;
    return x;
}

}  // namespace internal

#if __cplusplus >= 201703L

template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct lazy_segtree {

    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>, "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>, "e must work as S()");
    static_assert(std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>, "mapping must work as S(F, S)");
    static_assert(std::is_convertible_v<decltype(composition), std::function<F(F, F)>>, "composition must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>, "id must work as F()");

#else

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

#endif

  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }

    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = 2 * l;
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }

    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = 2 * r + 1;
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
//------------------------------------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
