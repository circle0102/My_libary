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
struct modint{
    using ll=long long;
    ll mod=998244353;
    ll num=0;
    modint(){
        mod=998244353;
        num=0;
    }
    modint(ll n){
        num=n;
        mod=998244353;
    }
    modint(ll n,ll m){
        mod=m;
        num=n;
    }
    operator long long(){
        return num;
    }
    void operator=(ll n){
        num=n;
    }
    void operator+=(ll add){
        num+=add;
    }
    void operator-=(ll sub){
        num-=sub;
    }
    void operator*=(ll tim){
        num*=tim%mod;
        num%=mod;
    }
    bool operator==(ll other){
        return num==other%mod;
    }
    bool operator!=(ll other){
        return num!=other%mod;
    }
    bool operator<(ll other){
        return num<other;
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
        int mid=(ok+mid)/2;
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
//---------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
