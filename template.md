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
TrieTree TTree;//定義
TTree.insert("YAJU&U");//挿入
TTree.find("YAJU");//完全一致文字列探索
TTree.prefix_find("YAJU");//接頭辞探索
TTree.count_prefix("YA");//接頭辞の数を返す
TTree.erase("YAJUJIN");//削除
```
## 双対セグ木
```cpp
DualSegtree<ll> seg(n); //初期値0で長さnのセグ木
DualSegtree<ll> seg(v); //初期配列vから構築
seg.range_assign(l,r,c); //[l,r)をcに代入
seg.range_add(l,r,c); //[l,r)にcを加算
seg.get(i); //点iの値を取得
```
## フェニック木+転倒数
```cpp
fenwick_tree<int> bit(n); //長さnのBIT
bit.add(i,a); //i番目に+a
bit.sum(l,r); //[l,r) の和
// 転倒数の計算
fenwick_tree<int>::inversion_count(vector);
```
## セグ木
```cpp
//op定義(例)
ll op(ll a, ll b) {return max(a,b);}
ll e() {return LLONG_MIN;}
segtree<ll,op,e> seg(n);
seg.set(i,a); //位置iをaに更新
seg.get(p) //位置pの値を取得
seg.all_prod() //全区間にopを適用
seg.prod(l,r); // [l,r)にop適応
```
## union find
```cpp
UnionFind uf(n);
merge(x,y) //xとyを同じ集合に統合
same(x,y) //xとyが同じ集合か
leader(x) //xの属する集合の代表元
size(x) //xの属する集合の要素数
count_groups() //連結成分の数
groups() //全グループのリストを返す
```
## クラスカル法
```cpp
vector<Edge> edges={{u1,v1,w1},{u2,v2,w2}}; //定義
ll mst_cost =kruskal(t,edges); //最小全域木の重み合計(tは頂点数)
```
## BFS DFS
```cpp
Graph g(5);//グラフ構築
addEdge(u, v) //辺u-vを追加
BFS(start) //startからBFS（訪問順）
DFS(start) //startからDFS（訪問順）
```
## 二部グラフ判定
```cpp
BipartiteGraph g(4);//グラフ構築
g.addEdge(u,v);//辺追加
g.isBipar();//二部グラフ判定
```
## トポロジカルソート
```cpp
DirectedGraph g(3); //グラフ構築
g.addEdge(u,v); //辺追加
g.topologicalSort(); //トポロジカルソート
```
## グリッドBFS(例)
```cpp
vector<string> grid = {"....",".#..","...."};
GridBFS g(3,4,grid);//3*4のグリッド定義
g.bfs(0,0);//(0,0)からBFS
cout << g.distance(2, 3); //距離
cout << g.reachable(1, 1); //到達可能か
```
## ダイクストラ
```cpp
daijkstra g(4);//定義
add_edge(u, v, cap, cost)//辺追加
mcmf(src, sink)//最小費用流を(minCost,maxFlow)で返す
```
## 重み付きuf
```cpp
WeightUnionFind<int> uf(5);//定義
merge(x, y, w)//x-y=wの関係で統合
issame(x, y)//同じ集合か
diff(x, y)//y-x の重み差分を返す
weight(x)//xの根までの累積重み
```
## 遅延セグ木
```cpp
//関数定義(区間加算+区間最小の例)
using S=int;
using F=int;
S op(S a,S b) {return std::min(a, b);}
S e() {return 1e9;}
S mapping(F f,S x) { return f+x;}
F composition(F f, F g) {return f+g;}
F id() {return 0;}
//使用方法
vector<int> v;//vector定義
lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);//木構築
set(p,x)//p 番目を x に代入（即反映）
get(p)//p 番目の値を取得（遅延処理含む）
apply(l,r,f)//区間 [l,r) に作用素 f を適用
prod(l, r)//区間 [l,r) のモノイド積を取得
all_prod()//全体のモノイド積を取得
max_right(l,g)//g(prod(l,r)) がtrueな最大r
min_left(r,g)//g(prod(l,r)) がtrueな最小l
```
