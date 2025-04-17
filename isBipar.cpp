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

    // BFS
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

    // DFS
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

    // 二部グラフ判定
    bool isBipar() {
        vector<int> color(V, -1); // -1: 未訪問, 0: グループ1, 1: グループ2
        queue<int> q;

        for (int start = 0; start < V; ++start) {
            if (color[start] == -1) {
                color[start] = 0;
                q.push(start);

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();

                    for (int neighbor : adj[current]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[current];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[current]) {
                            return false; // 隣接頂点が同じ色なら二部グラフではない
                        }
                    }
                }
            }
        }

        return true;
    }

int main() {
    //int V = 6; 頂点数 
    //Graph g(V); グラフ作成

    //g.addEdge(0, 1); 辺追加

    //g.isBipar() 二部グラフ判定
    return 0;
}