class Solution {
    vector<vector<int>> g;
    vector<vector<bool>> vis;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n,m;
public:
    int dfs(int x, int y){
        if(vis[x][y] || g[x][y] == 0)return 0;
        vis[x][y] = true;
        int ans = 1;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m)ans += dfs(nx, ny);
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();
        vis.resize(n, vector<bool>(m, false));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 1 && !vis[i][j])ans = max(ans, dfs(i,j));
            }
        }

        return ans;
    }
};
