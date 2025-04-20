# テンプレート概略

## 型定義・型省略(一部省略)
```cpp
#pragma GCC optimize("O3")
#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using it=__int128;
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
```
## レーベンシュタイン距離
```cpp
LP(string r,string l);
```
## タイマー
```cpp
Timer timer; // タイマー開始
timer.count() //時間取得
timer.isunder(t) //時間がtを超えているか判定
```
## 累積和
```cpp
sum_vec<int> sv(v); //vectorから構築
v.cul_sum(1, 4) //累積和再計算
v.cul_sum(int l, int r) //区間(l,r]の計算
v.push_back(6); //追加
v.pop_back(); //削除
```
## Mod Int
```cpp
modint::set_mod(1000000007);  //固定MOD
modint a=10; //動的
//四則演算可能
cout << (ll)f << endl; // 出力時はキャスト
```
## 二分探索
```cpp
search_min(vec, check); //check(vec[i])==true となる最小のiを返す。
search_max(vec, check); //check(vec[i])==true となる最大のiを返す。
search_min(l, r, check) //区間でcheck(x)==true となる最小のxを返す。
search_max(l, r, check) //区間でcheck(x)==true となる最小のxを返す。
```
## 確率pでtrueを返す関数
```cpp
prob(double p)
```
## 乱数生成
```cpp
Random_Gen rnd(l,r); //[l,r)の整数を生成
rnd.gen(); //乱数取得
rnd.get_range() //範囲取得
rnd.set_range(l,r);//範囲変更
```
## N進数構造体
```cpp
BaseN a(n,m); //n進数でのmとして定義
b.to_base(n); //基数変換
//演算・比較は通常通り
```
## hush string
```cpp
HashString hs(""); //初期化(cin>>hs;でも可)
hs.substr_hash(l,r); //部分ハッシュ取得
```
## ランレングス圧縮
```cpp
//例
RunLength<vector<char>, char>(s,' '); //{{'a',2},{'b',3},{'c',1}}
RunLength<vector<char>, char>(s,0); //{{'1',2},{'2',3},{'3',1}}
```
## トライ木
```cpp
```
## 双対セグ木
```cpp
```
## フェニック木+転倒数
```cpp
```
## セグ木
```cpp
```
