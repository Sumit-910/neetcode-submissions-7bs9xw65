class Solution {
    vector<vector<int>> h,v;
    vector<vector<bool>> vis;
    int n, m;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
public:
    void dfs(int r, int c){
        v[r][c]++;
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && h[r][c]<=h[nr][nc]){
                vis[nr][nc] = true;
                dfs(nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        this->h = h;
        n = h.size(), m = h[0].size();
        v.assign(n, vector<int>(m, 0));
        vis.assign(n, vector<bool>(m, false));

        // pacific
        for(int i=0;i<n;i++){
            if(!vis[i][0])vis[i][0] = true, dfs(i,0);
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j])vis[0][j] = true, dfs(0,j);
        }

        for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j] = false;

        //atlantic
        for(int i=0;i<n;i++){
            if(!vis[i][m-1])vis[i][m-1] = true, dfs(i,m-1);
        }
        for(int j=0;j<m;j++){
            if(!vis[n-1][j])vis[n-1][j] = true, dfs(n-1,j);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j] >= 2)ans.push_back({i, j});
            }
        }
        return ans;
    }
};
