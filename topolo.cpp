#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v); 
    }

    // トポロジカルソート
    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                ++inDegree[neighbor];
            }
        }

        queue<int> q;

        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int neighbor : adj[current]) {
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != V) {
            throw runtime_error("Graph has a cycle. Topological sort not possible.");
        }

        return result;
    }
};

int main() {
    //int V = 5;  頂点数
    //Graph g(V); グラフ

    // 有向辺を追加
    //g.addEdge(0, 1);
    
    //使用例
    /*
    try {
        vector<int> topoSort = g.topologicalSort();
        cout << "Topological Sort: ";
        for (int node : topoSort) {
            cout << node << " ";
        }
        cout << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    */
    return 0;
}