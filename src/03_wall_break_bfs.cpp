#include <bits/stdc++.h>
using namespace std;

struct State{
    int r;
    int c;
    int used;
};

int main(){
    int H,W;
    cin >> H >> W;
    int x,y;
    vector<vector<char>> grid(H,vector<char>(W));
    vector<vector<vector<int>>> dist(
        H,
        vector<vector<int>>(W,vector<int>(2,-1))
    );
    queue<State> q;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                q.push({i,j,0});
                dist[i][j][0] = 0;
            }else if(grid[i][j] == 'T'){
                x = i;
                y = j;
            }
        }
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()){
        int r = q.front().r;
        int c = q.front().c;
        int used = q.front().used;
        q.pop();
        for(int k=0;k<4;k++){
            int nr = r+dr[k];
            int nc = c+dc[k];
            if(0<=nr and nr<H and 0<=nc and nc<W){
                if(used == 0){
                    if(dist[nr][nc][1] == -1){
                        if(grid[nr][nc] == '#'){ 
                            dist[nr][nc][1] = dist[r][c][0]+1;
                            q.push({nr,nc,1});
                        }
                    }
                    if(dist[nr][nc][0] == -1){
                        if(grid[nr][nc] != '#'){ 
                            dist[nr][nc][0] = dist[r][c][0]+1;
                            q.push({nr,nc,0});
                        }
                    }
                    
                }else{
                    if(dist[nr][nc][1] == -1 and grid[nr][nc] != '#'){
                        dist[nr][nc][1] = dist[r][c][1]+1;
                        q.push({nr,nc,1});
                    }
                }
            }
        }
    }
    if(dist[x][y][0] == -1 and dist[x][y][1] == -1) cout << -1;
    else if(dist[x][y][0] == -1) cout << dist[x][y][1];
    else if(dist[x][y][1] == -1) cout << dist[x][y][0];
    else if(dist[x][y][0] > dist[x][y][1]) cout << dist[x][y][1];
    else cout << dist[x][y][0];
}