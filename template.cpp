#pragma GCC optimize("O3")
#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
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
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
