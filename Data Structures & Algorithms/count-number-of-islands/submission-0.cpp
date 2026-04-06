// bfs solution
class Solution {
    vector<vector<char>> g;
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void bfs(vector<vector<bool>>& vis, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            for(int r=0;r<4;r++){
                int nx = x + dx[r];
                int ny = y + dy[r];

                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]=='1' && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int islands = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || g[i][j] == '0')continue;
                bfs(vis, i, j);
                islands++;
            }
        }

        return islands;
    }
};
