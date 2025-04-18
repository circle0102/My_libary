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
//-------------------------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
