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
        adj[v].push_back(u); 
    }

    // 幅優先探索
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // 深さ優先探索
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS: ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
            }

            for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    //int V = 6; 頂点数
    
    //Graph g(V); グラフ構築
    
    //g.addEdge(a, b); 辺を追加

    //int startNode = 0; 開始ノード
    //g.BFS(startNode); BFS
    //g.DFS(startNode); DFS
    
    return 0;
}