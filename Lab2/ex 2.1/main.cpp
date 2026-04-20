#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> g[i][j];
        
    int x, y, a, b; 
    cin >> x >> y >> a >> b;
    x--; y--; a--; b--; 
    
    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(m, -1));
    q.push({x, y});
    d[x][y] = 1; 
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if (cx == a && cy == b) break;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 0 && d[nx][ny] == -1) {
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << d[a][b];
    return 0;
}
