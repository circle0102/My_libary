#include <algorithm>
#include <vector>
#include <tuple>
#include <numeric>
#include <iostream>
using namespace std;

struct dsu {
public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        return -parent_or_size[leader(a)];
    }

private:
    int _n;
    vector<int> parent_or_size;
};

struct Edge {
    int u, v;
    int weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    // Union-Findの初期化
    dsu d(n);
    // 辺の重みの昇順にソート
    sort(edges.begin(), edges.end());
    int total_weight = 0;
    for (const auto& edge : edges) {
        // 辺の両端が同じ連結成分に属していない場合、辺を追加
        if (!d.same(edge.u, edge.v)) {
            d.merge(edge.u, edge.v);
            total_weight += edge.weight;
        }
    }
    return total_weight;
}

int main() {
    //int n = 頂点数
    //vector<Edge> edges = 辺({頂点１, 頂点２, 重み})
    //kruskal(n, edges);　クラスカル法
    
    //以下　union findの使い方はACL同様
    //dsu d(int n)
    //int d.merge(int a, int b)
    //bool d.same(int a, int b)
    //int d.leader(int a)
    //int d.size(int a)
    //vector<vector<int>> d.groups()
}