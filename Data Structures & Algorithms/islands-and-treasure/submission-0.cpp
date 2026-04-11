#define f(i,s,e) for(int i=s;i<e;i++)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<vector<int>> q;
        f(i,0,n){
            f(j,0,m){
                if(g[i][j] == 0)q.push({i,j,0}), vis[i][j] = true;
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it[0];
            int y = it[1];
            int v = it[2];

            f(i,0,4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny] == INT_MAX && !vis[nx][ny]){
                    g[nx][ny] = v+1;
                    vis[nx][ny] = true;
                    q.push({nx, ny, v+1});
                }
            }
        }
    }
};
