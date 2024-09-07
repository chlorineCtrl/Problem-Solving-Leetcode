#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;


vector<int> water_reach_time(int n, int m, const vector<vector<int>>& grid,
                             const vector<pair<int, int>>& border_cells,
                             const vector<pair<int, int>>& queries) {
    const int INF = INT_MAX;
    vector<vector<int>> distances(n, vector<int>(m, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    for (const auto& cell : border_cells) {
        int x = cell.first;
        int y = cell.second;
        pq.push({0, x, y});
        distances[x][y] = 0;
    }


    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        auto [current_time, x, y] = pq.top();
        pq.pop();

        if (current_time > distances[x][y]) {
            continue;
        }

        for (const auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int new_time = current_time + grid[x][y];
                if (new_time < distances[nx][ny]) {
                    distances[nx][ny] = new_time;
                    pq.push({new_time, nx, ny});
                }
            }
        }
    }


    vector<int> results;
    for (const auto& query : queries) {
        int q_x = query.first;
        int q_y = query.second;
        results.push_back(distances[q_x][q_y]);
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int b;
    cin >> b;
    vector<pair<int, int>> border_cells(b);
    for (int i = 0; i < b; ++i) {
        cin >> border_cells[i].first >> border_cells[i].second;
    }

    int t;
    cin >> t;
    vector<pair<int, int>> queries(t);
    for (int i = 0; i < t; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> results = water_reach_time(n, m, grid, border_cells, queries);
    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}
