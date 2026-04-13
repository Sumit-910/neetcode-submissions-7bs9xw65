class Solution {
    vector<vector<char>> b;
    vector<vector<bool>> vis;
    int n, m;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};

    void dfs(int r, int c){
        vis[r][c] = true;

        for(int i=0;i<n;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && b[nr][nc] == 'O')dfs(nr, nc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        b = board;
        n = b.size(), m = b[0].size();
        vis.assign(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            if(b[i][0] == 'O' && !vis[i][0]) dfs(i, 0);
            if(m > 1 && b[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1);
        }
        for(int j=0;j<m;j++){
            if(b[0][j] == 'O' && !vis[0][j]) dfs(0, j);
            if(n > 1 && b[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1, j);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && !vis[i][j])board[i][j] = 'X';
            }
        }
    }
};
