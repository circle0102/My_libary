//U
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
